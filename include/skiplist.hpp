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
    template <class T> class SkipList {
    private:
        template <class TPriv> class Element {
        private:
            std::vector<Element<TPriv> *> next;
            TPriv value;
        public:
            Element(unsigned size, Element* newNext = nullptr, TPriv newValue = TPriv()) noexcept : value(newValue) {
                next.resize(size);
                for (unsigned i = 0; i < size; i++) {
                    next[i] = newNext;
                }
            }
            virtual ~Element() noexcept {
                for (auto item : next) {
                    delete item;
                }
                next.clear();
            }
            Element<TPriv>* getNext(unsigned offset) const noexcept(false) { 
                if (offset >= size()) {
                    return nullptr;
                }
                return next[offset]; 
            }
            void setNext(Element<TPriv> * newValue, unsigned offset) noexcept(false) { 
                if (offset >= size()) {
                    next.resize(offset + 1);
                }
                next[offset] = newValue; 
            }
            const TPriv & getValue() const noexcept { 
                return value; 
            }
            unsigned size() const noexcept {
                return next.size();
            }
        };
        Element<T> * head, * z;
        
        unsigned N, lgN;
        unsigned lgNMax;
        std::default_random_engine generator;
        std::uniform_int_distribution<int> distribution;

    public:
        template <class T> class SkipListIterator;
        //friend class SkipListIterator<T>;

        SkipList(unsigned _lgNMax = 4) : lgNMax(_lgNMax), N(0), lgN(0), distribution(0, RAND_MAX) {
            // order matters
            z = new Element<T>(0);
            head = new Element<T>(_lgNMax, z);
        }
        virtual ~SkipList() {
            // TODO
        }
        void add(const T value) {
            addHelper(head, new Element<T>(randX(), z, value), lgN);
            N += 1;
        }
        void remove(const SkipListIterator<T>& pos) {
            // TODO
        }
        SkipListIterator<T> find(const T value) {
            // TODO
        }
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
        unsigned randX() {
            
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
            // lgN = 3;
            // return 3;
        }
        void addHelper(Element<T>* t, Element<T>* x, unsigned k) {
            /*if (k >= t->size()) {
                k = t->size() - 1;
            }*/
            auto next = t->getNext(k);
            if (next == nullptr) {
                next = z;
            }
            if (next == z || x->getValue() < next->getValue()) {
                if (k < x->size()) {
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
    };
    template <class T> class SkipListIterator {
    private:
        SkipList<T>& list;
        SkipList::Element<T>* cursor;
        unsigned offsetInCursor;
        bool endValue;
    public:
        /*! \brief Constructor

            \param value SkipList used by iterator
            \param end Is this the end marker?
        */
        SkipListIterator(SkipList<T>& value, bool end) noexcept : list(value), endValue(end), offsetInCursor(0), cursor(list.head) {
        }
        /*! \brief Comparison operator

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
        const T & operator ++() noexcept {
           //  return list.next();
           // TODO
        }
        /*! \brief Advances the iterator
          \returns The current value
        */
        const T & operator ++(int) noexcept {
            // T retval = list.current();
            // ++(*this);
            // return retval;
            // TODO
        }
        /*! \brief Pointer operator used by loops

        \returns The current value
        */
        const T& operator*() noexcept {
            return cursor->getValue();
        }
    protected:
        bool hasNext() {
            if (cursor == list.z) {
                return false;
            }
            for (unsigned i = 0; i < cursor->size(); i++) {
                if (cursor->getNext(i) != list.z) {
                    return true;
                }
            }
            return false;
        }
    };
};