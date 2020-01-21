//
//  sortedlist.hpp
//  experimental
//
//  Created by Robert Sandilands on 1/16/20.
//  Copyright © 2020 Robert Sandilands. All rights reserved.
//
//  Check LICENSE file for License
#pragma once

#include <vector>
#include <iostream>

namespace experimental {
    template <class U> class SortedListIterator;
    /*! \brief A simple sorted list that tries to be efficient

        This list will keep all items in sorted order. It uses a std::vector as backing store so large lists will be less efficient. 
        Items in the list is considered constant and modifications of the objects will not re-sort the list.
    */
    template <class T> class SortedList {
        public:
            friend class SortedListIterator<T>;
            /*! \brief Adds an item to the list. It will add it in the correct position to keep the list sorted
                \param value The value to add. Type must support == and >
            */
            void add(const T value) noexcept {
                if (empty())
                {
                    content.push_back(value);
                    return;
                }
                bool found;
                // do binary search and use the search results to either skip (not adding duplicates) or to insert
                unsigned pos = binarySearch(content, 0, content.size(), value, found);
                if (found) {
                    return; // not adding duplicates
                }
                content.insert(content.begin() + pos, value);
            }
            /*! \brief Removes an item from the list
                \param position Iterator to the item to be removed                
            */
            void remove(const SortedListIterator<T>& position) noexcept(false) {
                // need to get offset into content
                content.erase(content.begin() + position.offset);
            }
            /*! \brief Is the list empty?
                \returns Return true if the list is empty
            */
            bool empty() const noexcept {
                return content.empty();
            }
            /*! \brief Returns the number of items in the list
                \returns The size of the list
            */
            unsigned size() const noexcept {
                return content.size();
            }
            /*! \brief Returns the value at the specified offset
                \param offset Offset into list
                \returns const reference to the value referenced
            */
            const T& at(unsigned offset) const noexcept(false) {
                if (offset > content.size())
                {
                    throw std::out_of_range("Trying to access an item beyond the end of the list");
                }
                return content.at(offset);
            }
            /*! \brief []Operator
                \param offset Offset into list
                \returns const reference to the value referenced
            */
            const T& operator[](unsigned offset) const noexcept(false) {
                return content[offset];
            }
            /*! \brief Does a binary search on the list and returns an iterator to its location if found or end() if not
                \param value The value to find
                \returns An iterator to the position of the value or the end() iterator
            */
            const SortedListIterator<T>& find(const T value) const noexcept {
                bool found;
                unsigned pos = binarySearch(content, 0, content.size(), value, found);
                if (found) {
                    return std::move(SortedListIterator<T>(*this, false, pos));
                } else {
                    return std::move(end());
                }
            }
            /*! \brief Returns an iterator that indicates the beginning of the list
                \returns Iterator
            */
            SortedListIterator<T> begin() const noexcept {
                return std::move(SortedListIterator<T>(*this, false));
            }
            /*! \brief Returns a constant iterator that indicates the end of the list
                \returns Iterator
            */
            const SortedListIterator<T> end() const noexcept {
                return std::move(SortedListIterator<T>(*this, true));
            }
        protected:
        // Lets start with trivial vector and then make it better
            std::vector<T> content;
        private:
            unsigned binarySearch(const std::vector<T>& source, unsigned start, unsigned end, const T& value, bool & found) const noexcept(false) {
                found = false;
                unsigned pos = start + ((end - start) >> 1);
                if (pos >= source.size())
                {
                    return pos;
                }
                const T& localValue = source.at(pos);
                if (localValue == value) {
                    found = true;
                    return pos;
                }
                if (start == end) {
                    // not found, but this is probably where we should insert
                    return start;
                }
                if (localValue > value) {
                    return binarySearch(source, start, pos, value, found);
                } else {
                    return binarySearch(source, pos + 1, end, value, found);
                }
            }
    };
    /*! \brief Iterator helper for SortedList

      If `list` is of type SortedList then it is used in one of two ways:

      1. `for (auto i: list) { ... }`
      2. `for (auto i = list.begin(); i != list.end(); i++) { ... }`
    */
    template <class T> class SortedListIterator {
        friend class SortedList<T>;
        public:
            /*! \brief Non equal operator
                \param other The iterator to compare to
                \returns True if the two iterators are not at the same position
            */
            bool operator != (const SortedListIterator<T> & other) const noexcept {
                return !(*this == other);
            }
            /*! \brief Equal operator
                \param other The iterator to compare to
                \returns True if the two iterators are at the same position
            */
            bool operator == (const SortedListIterator<T> & other) const noexcept {
                return offset == other.offset && isEnd == other.isEnd;
            }
            /*! \brief Advances the iterator
                \returns The current value
            */
            T& operator ++() noexcept(false) {
                offset += 1;
                return list.at(offset);
            }
            /*! \brief Advances the iterator                
                \returns The current value
            */
            T& operator ++(int) noexcept(false) {
                T retval = list.at(offset);
                offset += 1;
                return retval;
            }
            /*! \brief + Operator
                \param item The Iterator to operate on
                \param offet The offset to apply
                \returns The updated iterator
            */
            friend SortedListIterator<T> operator +(SortedListIterator<T> & item, int offset) noexcept(false) {
                if (item.isEnd) {
                    throw std::logic_error("Can not do arithmitic on end() iterator");
                }
                if (offset + item.offset > item.list.size()) {
                    throw std::out_of_range("Trying to access an item beyond the end of the list");
                }
                return SortedListIterator<T>(item.list, item.isEnd, item.offset + offset);
            }
            /*! \brief - Operator
                \param item The Iterator to operate on
                \param offet The offset to apply
                \returns The updated iterator
            */
            friend SortedListIterator<T> operator -(SortedListIterator<T> & item, int offset) noexcept(false) {
                if (item.isEnd) {
                    throw std::logic_error("Can not do arithmitic on end() iterator");
                }
                if (item.offset - offset < 0 || item.offset - offset > item.list.size()) {
                    throw std::out_of_range("Trying to access an item beyond the end of the list");
                }
                return SortedListIterator<T>(item.list, item.isEnd, item.offset - offset);
            }
            /*! \brief += Operator
                \param offet The offset to apply
                \returns The updated iterator
            */
            SortedListIterator<T>& operator +=(int value) {
                if (isEnd) {
                    throw std::logic_error("Can not do arithmitic on end() iterator");
                }
                if (offset + value > list.size()) {
                    throw std::out_of_range("Trying to access an item beyond the end of the list");
                }
                offset += value;
                return *this;
            }
            /*! \brief -= Operator
                \param offet The offset to apply
                \returns The updated iterator
            */
            SortedListIterator<T>& operator -=(int value) {
                if (isEnd) {
                    throw std::logic_error("Can not do arithmitic on end() iterator");
                }
                if (offset - value < 0 || offset - value > list.size()) {
                    throw std::out_of_range("Trying to access an item beyond the end of the list");
                }
                offset -= value;
                return *this;
            }
            /*! \brief Pointer operator used by loops
                \returns The current value
            */
            const T& operator*() const noexcept(false) {
                return list.at(offset);
            }
        protected:
            /*! \brief Constructor

                \param value SortedList used by iterator
                \param end Is this the end marker?
                \param startOffset starting offset of iterator
            */
            SortedListIterator(const SortedList<T> & that, bool end, unsigned startOffset = 0) noexcept(false)
                : list(that), isEnd(end), offset(end ? list.size() : startOffset)  {
                    if (startOffset > list.size()) {
                        throw std::out_of_range("Trying to access an item beyond the end of the list");
                    }
            }
        private:
            const SortedList<T> & list;
            bool isEnd;
            unsigned offset; 
    };
}