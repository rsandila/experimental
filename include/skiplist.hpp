//
//  skiplist.hpp
//  experimental
//
//  Created by Robert Sandilands on 1/28/20.
//  Copyright © 2020 Robert Sandilands. All rights reserved.
//
//  Check LICENSE file for License
#pragma once

#include <vector>
#include <memory>
#include <random>

namespace experimental {    
    template <class T> class SkipListIterator;
    /*! \brief Skip List

        A skip list is a mix between a tree and a linked list. It keeps the items in a sorted order but by having links that can skip other links allows for finding items faster
        than you would in a standard linked list. The algorithm looks expensive for inserting as multiple links can be updated on insertion but balancing that against a tree rebalance
        or a memory move as you would get in a std::vector it may just end up not being as expensive as you think. It will probably be most efficient for larger data sets.

        Items in the list are considered constant and modifications of the objects will not re-sort the list.
    */
    template <class TPriv> class SLElement {
    private:
        std::vector<SLElement<TPriv>*> next;
        TPriv value;
    public:
        SLElement(unsigned size, SLElement* newNext = nullptr, TPriv newValue = TPriv()) noexcept : value(newValue) {
            next.resize(size);
            for (unsigned i = 0; i < size; i++) {
                next[i] = newNext;
            }
        }
        virtual ~SLElement() noexcept {
            next.clear();
        }
        SLElement<TPriv>* getNext(unsigned offset) const noexcept {
            if (offset >= size()) {
                return nullptr;
            }
            return next[offset];
        }
        void setNext(SLElement<TPriv>* newValue, unsigned offset) noexcept {
            if (offset >= size()) {
                next.resize(offset + 1);
            }
            next[offset] = newValue;
        }
        const TPriv& getValue() const noexcept {
            return value;
        }
        unsigned size() const noexcept {
            return next.size();
        }
    };
    template <class T> class SkipList {
    private:
        SLElement<T> * head;
        SLElement<T> * z;
        
        unsigned N, lgN;
        unsigned lgNMax;
        std::default_random_engine generator;
        std::uniform_int_distribution<int> distribution;

    public:
        friend class SkipListIterator<T>;
        /*! \brief Constructor
            \param _lgNMax A magic number that controls how big the skiplist can get. Experimentation should be used to find an optimal value for your data
        */
        SkipList(unsigned _lgNMax = 4) : N(0), lgN(0), lgNMax(_lgNMax), distribution(0, RAND_MAX) {
            // order matters
            z = new SLElement<T>(0);
            head = new SLElement<T>(_lgNMax, z);
        }
        /*! \brief Destructor
        */
        virtual ~SkipList() {
            deleteHelper(head);
            delete z;
            head = nullptr;
            z = nullptr;
            N = 0;
            lgN = 0;
            lgNMax = 0;
        }
        /*! \brief Adds an item to the list and keep the list in sorted order
            \param value The value to add
        */
        void add(const T value) noexcept {
            addHelper(head, new SLElement<T>(randX(), z, value), lgN);
            N += 1;
        }
        /*! \brief Finds a value in the list. T must implement < and ==
            \param value The value to find
            \returns end() if not found, otherwise an iterator to the value
        */
        SkipListIterator<T> find(const T value) {
            return std::move(SkipListIterator<T>(*this, findHelper(head, value)));
        }
        /*! \brief Returns true if the list is empty 
            \returns True if the list is empty */
        bool isEmpty() noexcept {
            return N == 0;
        }
        /*! \brief Returns iterator for use in loops

            \returns SkipListIterator
        */
        SkipListIterator<T> begin() noexcept {
            return std::move(SkipListIterator<T>(*this, false));
        }
        /*! \brief Returns end iterator for use in loops

          \returns SkipListIterator
        */
        const SkipListIterator<T> end() noexcept {
            return std::move(SkipListIterator<T>(*this, true));
        }
    protected:
        /*! \brief Returns a random size for a node

            Updates lgN

            \returns A size that will be < lgNMax and >= 1
        */
        unsigned randX() noexcept {
            
            unsigned i, j;
            unsigned t = distribution(generator);  

            for (i = 1, j = 2; i < lgNMax; i++, j += j) {
                if (t > RAND_MAX / j) {
                    break;
                }
            }
            if (i > lgN) {
                lgN = i;
            }
            return i;
        }
        /*! \brief Recursively adds an item to a node 
            \param t The current node to process
            \param x The node to add 
            \param k The current working offset 
            */
        void addHelper(SLElement<T>* t, SLElement<T>* x, unsigned k) noexcept {
            auto next = t->getNext(k);
            if (next == nullptr) {
                next = z;
            }
            if (next == z || x->getValue() < next->getValue()) {
                if (k < x->size() && k < t->size()) {
                    x->setNext(t->getNext(k), k);
                    t->setNext(x, k);
                }
                if (k == 0) {
                    return;
                }
                addHelper(t, x, k - 1);
                return;
            }
            if (next == z) {
                t->setNext(x, k);
                return;
            }
            addHelper(next, x, k);
        }
        /*! \brief Recursively finds value in the list 
            \returns z if not found, otherwise the node 
            \param t The current node to search
            \param value The value to match 
            */
        SLElement<T>* findHelper(SLElement<T>* t, const T& value) const noexcept {
            if (t == nullptr || t == z) {
                return z;
            }
            if (value == t->getValue()) {
                return t;
            }
            for (int i = t->size() - 1; i >= 0; i--) {
                auto item = t->getNext(i);
                if (item != nullptr && item != z) {
                    if (value == item->getValue()) {
                        return item;
                    }
                    auto nextItem = item->getNext(i);
                    if (nextItem == nullptr || nextItem == z) {
                        continue;
                    }
                    if (nextItem->getValue() == value) {
                        return nextItem;
                    }
                    if (nextItem->getValue() < value) {
                        return findHelper(nextItem, value);
                    }
                }
            }
            return z;
        }
        /*! \brief Used by the destructor to cleanup recursively
        */
        void deleteHelper(SLElement<T>* item) noexcept {
            if (item == nullptr || item == z) {
                return;
            }
            auto next = item->getNext(0);
            delete item;
            deleteHelper(next);
        }
    };
    template <class T> class SkipListIterator {
    private:
        const SkipList<T>& list;
        SLElement<T> * cursor;
        bool endValue;
    public:
        friend class SkipList<T>;
        /*! \brief == Comparison operator

            \param other Other SkipList used to compare

            \returns Returns true if both lists are at the same location
        */
        bool operator == (const SkipListIterator& other) const noexcept {
            return (cursor == other.cursor);
        }
        /*! \brief != Comparison operator

            \param other Other SkipList used to compare

            \returns Returns false if we are at the end of the list
        */
        bool operator != (const SkipListIterator& other) const noexcept {
            if (endValue == other.endValue) {
                if (endValue) {
                    return false;  // both at the end
                }
                else {
                    return true;  // technically not true, but should be sufficient
                }
            }
            if (endValue) {
                // I am the end pointer
                return other.hasNext();
            }
            else {
                // other is the end pointer
                return hasNext();
            }
        }
        /*! \brief Advances the iterator
          \returns The current value
        */
        const T & operator ++() noexcept(false) {
            if (cursor == list.z) {
                throw new std::out_of_range("Enumerating past the end of the list");
            }
            // if we follow next[0] we will enumerate all, so we only need to keep track of the current node
            cursor = cursor->getNext(0);
            return cursor->getValue();
        }
        /*! \brief Advances the iterator
          \returns The current value
        */
        const T & operator ++(int) noexcept(false) {
            T retval = cursor->getValue();
            ++(*this);
            return retval;
        }
        /*! \brief Pointer operator used by loops

        \returns The current value
        */
        const T& operator*() noexcept {
            return cursor->getValue();
        }
    protected:
        /*! \brief Constructor

            \param value SkipList used by iterator
            \param item The current position in the list
        */
        SkipListIterator(const SkipList<T>& value, SLElement<T>* item) noexcept : list(value), cursor(item) {
            if (cursor == nullptr) {
                cursor = list.z;
            }
            endValue = (cursor == list.z);
        }
        /*! \brief Constructor

            \param value SkipList used by iterator
            \param end Is this the end marker?
        */
        SkipListIterator(const SkipList<T>& value, bool end) noexcept : list(value), cursor(list.head->getNext(0)), endValue(end) {
            if (cursor == nullptr || endValue) {
                cursor = list.z;
            }
        }
        /*! \brief Returns whether we are at the end of the list or not
        */
        bool hasNext() const noexcept {
            return cursor != list.z;
        }
    };
};