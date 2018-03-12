//
//  singlelinkedlist.cpp
//  experimental
//
//  Created by Robert Sandilands on 3/6/18.
//  Copyright © 2018 Robert Sandilands. All rights reserved.
//
//  Check LICENSE file for License
#pragma once

#include <functional>
#include <exception>

namespace experimental {
    template <class T> class SingleLinkedListIterator;
    /*! \brief A single linked list

        A single linked list is one that can only be traversed in one direction.
        It can be used as a stack. Inserts and removes are extremely fast.
        Find is linear.
    */
    template <class T> class SingleLinkedList {
    private:
        template <class TPriv> class Element {
        private:
            Element<TPriv> * next;
            TPriv value;
        public:
            Element(Element * newNext = nullptr, TPriv newValue = TPriv()) noexcept : next(newNext), value(newValue) {}
            Element<TPriv> * getNext() const noexcept { return next; }
            void setNext(Element<TPriv> * newValue) noexcept { next = newValue; }
            TPriv getValue() const noexcept { return value; }
        };
        Element<T> * head;
        Element<T> * cursor;

        void resetConditionally(bool always = false) noexcept {
            if (always || !cursor) {
                cursor = head;
            }
        }
    public:
        /*! \brief Default constructors
            Creates a new empty SingleLinkedList
        */
        SingleLinkedList() noexcept : head(new Element<T>()), cursor(nullptr) {}
        /*! \brief Initializer constructor

            Creates a new SingleLinkedList and push() the initialValues

            \param initialValues Values to be added to the list at construction time
        */
        SingleLinkedList(std::initializer_list<T> initialValues) noexcept : head(new Element<T>()), cursor(nullptr) {
            for (auto item: initialValues) {
                push(item);
            }
        }
        /*! \brief Copy constructor
            \param that SingleLinkedList to be copied
         */
        SingleLinkedList(const SingleLinkedList& that) noexcept(false) {
            cursor = nullptr; // TODO - feasible to copy the cursor?
            head = new Element<T>();
            Element<T> * thatCursor = that.head;
            if (!thatCursor) {
                throw std::invalid_argument("Copying SingleLinkedList without a head");
            }
            if (thatCursor->getNext()) {
                push(thatCursor->getValue());
                thatCursor = thatCursor->getNext();
            }
            Element<T> * originalHead = head->getNext();
            Element<T> * myCursor = head;
            while (thatCursor->getNext()) {
                myCursor->setNext(new Element<T>(originalHead, thatCursor->getValue()));
                myCursor = myCursor->getNext();
                thatCursor = thatCursor->getNext();
            }
        }
        /*! \brief Move constructor
         
            Leaves the original list empty, but valid and moves the original list to the new list
         
            \param that SingleLinkedList to be moved
         */
        SingleLinkedList(SingleLinkedList && that) noexcept : head(that.head), cursor(that.cursor) {
            that.cursor = nullptr;
            that.head = new Element<T>();
        }
        /// Destructor
        virtual ~SingleLinkedList() noexcept {
            while (!isEmpty()) {
                pop();
            }
            delete head;
            head = cursor = nullptr;
        }
        /*! \brief Insert a new item at head
          \param value Value of new element
        */
        void push(T value) noexcept(false) {
            head = new Element<T>(head, value);
        }
        /*! \brief Insert new item at cursor as the next item, if cursor == null then do a push
          \param value Value of the new element
        */
        void insert(T value) noexcept(false) {
            if (!cursor) {
                push(value);
            } else {
                if (hasNext()) {
                    cursor->setNext(new Element<T>(cursor->getNext(), value));
                } else {
                    throw std::out_of_range("Trying to insert a new element in an invalid position");
                }
            }
        }
        /// Reset iteration of the list to head
        void reset() noexcept {
            resetConditionally(true);
        }
        /*! \brief Is there a next item in the list?
          \returns true if we are not at the end of the lists
          */
        bool hasNext() noexcept {
            resetConditionally();
            return cursor->getNext() != nullptr;
        }
        /*! \brief Return the current item while advancing the cursor

          Does not modify the list but it does advance the cursor

          \returns The value of the current element
          */
        T next() noexcept(false) {
            resetConditionally();
            if (cursor->getNext() == nullptr) {
                throw std::out_of_range("Trying to access an item beyond the end of the list");
            }
            T retval = cursor->getValue();
            cursor = cursor->getNext();
            return retval;
        }
        /*! \brief Return the current item

          Does not modify the list or advance the cursor

          \returns The value of the current element
          */
        T current() noexcept {
            resetConditionally();
            return cursor->getValue();
        }
        /*! Is the list empty?

        \returns Return true if the list is empty
        */
        bool isEmpty() const noexcept {
            return head->getNext() == nullptr;
        }
        /*! \brief Remove first item and return its value
          \returns Value of first item
          */
        T pop() noexcept(false) {
            Element<T> * newNext = head->getNext();
            if (newNext) {
                T retval = head->getValue();
                Element<T> * toDelete = head;
                cursor = head = newNext;
                delete toDelete;
                return retval;
            } else {
                throw std::out_of_range("Trying to pop too many entries");
            }
        }
        /*! \brief Remove element at cursor

          If the cursor is at an invalid position may throw
          an exception
          */
        void remove() noexcept(false) {
            if (cursor) {
                Element<T> * item = head;
                if (cursor == head) {
                    if (head->getNext() == nullptr) {
                        throw std::logic_error("Trying to remove head");
                    }
                    Element<T> * toDelete = head;
                    head = head->getNext();
                    cursor = head;
                    delete toDelete;
                    return;
                }
                while (item->getNext() != cursor) {
                    item = item->getNext();
                    if (item == nullptr) {
                        throw std::logic_error("Trying to remove something that is no longer there");
                    }
                }
                Element<T> * toDelete = cursor;
                item->setNext(cursor->getNext());
                cursor = cursor->getNext();
                delete toDelete;
            } else {
                throw std::out_of_range("Cursor not set");
            }
        }
        /*! \brief resets cursor and iterates list until test() == true

          \param test Lamba/function that will be called with values until it
                      returns true.

          \return True if test returned true.
        */
        bool find(std::function<bool(T)> test) noexcept {
            resetConditionally(true);
            return findNext(test);
        }
        /*! \brief Iterates list until test returns true
        \param test Lamba/function that will be called with values until it
                    returns true.

        \return True if test returned true.
      */
        bool findNext(std::function<bool(T)> test) noexcept {
            while (hasNext()) {
                if (test(cursor->getValue())) {
                    return true;
                }
                next();
            }
            return false;
        }
        /*! \brief Returns iterator for use in loops

              Resets the cursor and returns iterator

            \returns SingleLinkedListIterator
        */
        SingleLinkedListIterator<T> begin() noexcept {
            resetConditionally(true);
            return SingleLinkedListIterator<T>(*this, false);
        }
        /*! \brief Returns end iterator for use in loops

          \returns SingleLinkedListIterator
        */
        const SingleLinkedListIterator<T> end() noexcept {
            return SingleLinkedListIterator<T>(*this, true);
        }
    };
    /*! \brief Iterator helper for SingleLinkedList

      If `list` is of type SingleLinkedList then it is used in one of two ways:

      1. `for (auto i: list) { ... }`
      2. `for (auto i = list.begin(); i != list.end(); i++) { ... }`
    */
    template <class T> class SingleLinkedListIterator {
    private:
        SingleLinkedList<T> & list;
        bool endValue;
    public:
      /*! \brief Constructor

          \param value SingleLinkedList used by iterator
          \param end Is this the end marker?
      */
        SingleLinkedListIterator(SingleLinkedList<T> & value, bool end) noexcept : list(value), endValue(end) {
        }
        /*! \brief Comparison operator

            \param other Other SingleLinkedList used to compare

            \returns Returns false if we are at the end of the list
        */
        bool operator != (const SingleLinkedListIterator & other) const noexcept {
            if (endValue == other.endValue) {
                if (endValue) {
                    return false;  // both at the end
                } else {
                    return true;  // technically not true, but should be sufficient
                }
            }
            if (endValue) {
                // I am the end pointer
                return other.list.hasNext();
            } else {
                // other is the end pointer
                return list.hasNext();
            }
        }
        /*! \brief Advances the iterator
          \returns The current value
        */
        T operator ++() noexcept {
            return list.next();
        }
        /*! \brief Advances the iterator
          \returns The current value
        */
        T operator ++(int) noexcept {
            T retval = list.current();
            ++(*this);
            return retval;
        }
        /*! \brief Pointer operator used by loops

        \returns The current value
        */
        T operator*() noexcept {
            return list.current();
        }
    };
};
