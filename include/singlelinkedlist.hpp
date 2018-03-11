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
        SingleLinkedList() noexcept : head(new Element<T>()), cursor(nullptr) {}
        SingleLinkedList(std::initializer_list<T> initialValues) noexcept : head(new Element<T>()), cursor(nullptr) {
            for (auto item: initialValues) {
                push(item);
            }
        }
        virtual ~SingleLinkedList() noexcept {
            while (!isEmpty()) {
                pop();
            }
            delete head;
            head = cursor = nullptr;
        }
        // insert a new item at head
        void push(T value) noexcept(false) {
            head = new Element<T>(head, value);
        }
        // insert new item at cursor as the next item, if cursor == null then do a push
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
        // reset iteration of the list to head
        void reset() noexcept {
            resetConditionally(true);
        }
        // Is there a next item in the list
        bool hasNext() noexcept {
            resetConditionally();
            return cursor->getNext() != nullptr;
        }
        // return the next item without modifying the list
        T next() noexcept(false) {
            resetConditionally();
            if (cursor->getNext() == nullptr) {
                throw std::out_of_range("Trying to access an item beyond the end of the list");
            }
            T retval = cursor->getValue();
            cursor = cursor->getNext();
            return retval;
        }
        T current() noexcept {
            resetConditionally();
            return cursor->getValue();
        }
        // return true if the list is empty
        bool isEmpty() const noexcept {
            return head->getNext() == nullptr;
        }
        // remove head and return its value
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
        // remove current cursor
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
        // resets cursor and iterates list until test() == true.
        bool find(std::function<bool(T)> test) noexcept {
            resetConditionally(true);
            return findNext(test);
        }
        // iterastes list until test() == true without resetting the cursor
        bool findNext(std::function<bool(T)> test) noexcept {
            while (hasNext()) {
                if (test(cursor->getValue())) {
                    return true;
                }
                next();
            }
            return false;
        }
        SingleLinkedListIterator<T> begin() noexcept {
            resetConditionally(true);
            return SingleLinkedListIterator<T>(*this, false);
        }
        const SingleLinkedListIterator<T> end() noexcept {
            return SingleLinkedListIterator<T>(*this, true);
        }
    };

    template <class T> class SingleLinkedListIterator {
    private:
        SingleLinkedList<T> & list;
        bool endValue;
    public:
        SingleLinkedListIterator(SingleLinkedList<T> & value, bool end) noexcept : list(value), endValue(end) {
        }
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
        T operator ++() noexcept {
            return list.next();
        }
        T operator ++(int) noexcept {
            T retval = list.current();
            ++(*this);
            return retval;
        }
        T operator*() noexcept {
            return list.current();
        }
    };
};
