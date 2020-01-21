# Summary

 Members                        | Descriptions                                
--------------------------------|---------------------------------------------
`namespace `[`experimental`](#namespaceexperimental) | 
`class `[`experimental::SingleLinkedList::Element`](#classexperimental_1_1_single_linked_list_1_1_element) | 

# namespace `experimental` 

## Summary

 Members                        | Descriptions                                
--------------------------------|---------------------------------------------
`class `[`experimental::SingleLinkedList`](#classexperimental_1_1_single_linked_list) | A single linked list.
`class `[`experimental::SingleLinkedListIterator`](#classexperimental_1_1_single_linked_list_iterator) | Iterator helper for [SingleLinkedList](#classexperimental_1_1_single_linked_list).
`class `[`experimental::SortedList`](#classexperimental_1_1_sorted_list) | A simple sorted list that tries to be efficient.
`class `[`experimental::SortedListIterator`](#classexperimental_1_1_sorted_list_iterator) | Iterator helper for [SortedList](#classexperimental_1_1_sorted_list).

# class `experimental::SingleLinkedList` 

A single linked list.

A single linked list is one that can only be traversed in one direction. It can be used as a stack. Inserts and removes are extremely fast. Find is linear.

## Summary

 Members                        | Descriptions                                
--------------------------------|---------------------------------------------
`public inline  `[`SingleLinkedList`](#classexperimental_1_1_single_linked_list_1a5efd9ecfa26ebe68da0b34f75daa14d1)`() noexcept` | Default constructors Creates a new empty [SingleLinkedList](#classexperimental_1_1_single_linked_list).
`public inline  `[`SingleLinkedList`](#classexperimental_1_1_single_linked_list_1aa56386b0d9297264e246e709a26ffd2a)`(std::initializer_list< T > initialValues) noexcept` | Initializer constructor.
`public inline  `[`SingleLinkedList`](#classexperimental_1_1_single_linked_list_1abc4c8fd989aedb94d72543dcbaaab9b3)`(const `[`SingleLinkedList`](#classexperimental_1_1_single_linked_list)` & that)` | Copy constructor.
`public inline  `[`SingleLinkedList`](#classexperimental_1_1_single_linked_list_1af1b55421626b7c0ce148d3b933b20853)`(`[`SingleLinkedList`](#classexperimental_1_1_single_linked_list)` && that) noexcept` | Move constructor.
`public inline virtual  `[`~SingleLinkedList`](#classexperimental_1_1_single_linked_list_1aaa7e76f3ec9637075a41a6b1c00126e4)`() noexcept` | Destructor.
`public inline void `[`push`](#classexperimental_1_1_single_linked_list_1a26826c880617830b5b445f2efcee2bb7)`(T value)` | Insert a new item at head.
`public inline void `[`insert`](#classexperimental_1_1_single_linked_list_1a6f8023e7603755d82ef0a6c1acc43ea1)`(T value)` | Insert new item at cursor as the next item, if cursor == null then do a push.
`public inline void `[`reset`](#classexperimental_1_1_single_linked_list_1a3878da9482356b7d06ceb4eeec780ec0)`() noexcept` | Reset iteration of the list to head.
`public inline bool `[`hasNext`](#classexperimental_1_1_single_linked_list_1a29cd1c8965aa5134b20609c30dccc676)`() noexcept` | Is there a next item in the list?
`public inline T `[`next`](#classexperimental_1_1_single_linked_list_1a9e87e020fe40b04cb454c9dedd4740be)`()` | Return the current item while advancing the cursor.
`public inline T `[`current`](#classexperimental_1_1_single_linked_list_1a78017d26b09160f13e44ead598abd08b)`() noexcept` | Return the current item.
`public inline bool `[`isEmpty`](#classexperimental_1_1_single_linked_list_1a94014b8dc6404ee998e2593890b15ac1)`() const noexcept` | Is the list empty?
`public inline T `[`pop`](#classexperimental_1_1_single_linked_list_1adf0e10ac3de9a0d0cd831706dd2ce5cc)`()` | Remove first item and return its value.
`public inline void `[`remove`](#classexperimental_1_1_single_linked_list_1acd9be89de452ec62a7fec3d123fdb56d)`()` | Remove element at cursor.
`public inline bool `[`find`](#classexperimental_1_1_single_linked_list_1ad737c8b463a7967433adf34e8c67fbb7)`(std::function< bool(T)> test) noexcept` | resets cursor and iterates list until test() == true
`public inline bool `[`findNext`](#classexperimental_1_1_single_linked_list_1a81648d778127b477eebcdc1c7773636d)`(std::function< bool(T)> test) noexcept` | Iterates list until test returns true.
`public inline `[`SingleLinkedListIterator`](#classexperimental_1_1_single_linked_list_iterator)`< T > `[`begin`](#classexperimental_1_1_single_linked_list_1ac24a5e3e4536449dd740dac0b82b229c)`() noexcept` | Returns iterator for use in loops.
`public inline const `[`SingleLinkedListIterator`](#classexperimental_1_1_single_linked_list_iterator)`< T > `[`end`](#classexperimental_1_1_single_linked_list_1a79ed9790314ac0e74e347b9501449064)`() noexcept` | Returns end iterator for use in loops.

## Members

#### `public inline  `[`SingleLinkedList`](#classexperimental_1_1_single_linked_list_1a5efd9ecfa26ebe68da0b34f75daa14d1)`() noexcept` 

Default constructors Creates a new empty [SingleLinkedList](#classexperimental_1_1_single_linked_list).

#### `public inline  `[`SingleLinkedList`](#classexperimental_1_1_single_linked_list_1aa56386b0d9297264e246e709a26ffd2a)`(std::initializer_list< T > initialValues) noexcept` 

Initializer constructor.

Creates a new [SingleLinkedList](#classexperimental_1_1_single_linked_list) and [push()](#classexperimental_1_1_single_linked_list_1a26826c880617830b5b445f2efcee2bb7) the initialValues

#### Parameters
* `initialValues` Values to be added to the list at construction time

#### `public inline  `[`SingleLinkedList`](#classexperimental_1_1_single_linked_list_1abc4c8fd989aedb94d72543dcbaaab9b3)`(const `[`SingleLinkedList`](#classexperimental_1_1_single_linked_list)` & that)` 

Copy constructor.

#### Parameters
* `that` [SingleLinkedList](#classexperimental_1_1_single_linked_list) to be copied

#### `public inline  `[`SingleLinkedList`](#classexperimental_1_1_single_linked_list_1af1b55421626b7c0ce148d3b933b20853)`(`[`SingleLinkedList`](#classexperimental_1_1_single_linked_list)` && that) noexcept` 

Move constructor.

Leaves the original list empty, but valid and moves the original list to the new list

#### Parameters
* `that` [SingleLinkedList](#classexperimental_1_1_single_linked_list) to be moved

#### `public inline virtual  `[`~SingleLinkedList`](#classexperimental_1_1_single_linked_list_1aaa7e76f3ec9637075a41a6b1c00126e4)`() noexcept` 

Destructor.

#### `public inline void `[`push`](#classexperimental_1_1_single_linked_list_1a26826c880617830b5b445f2efcee2bb7)`(T value)` 

Insert a new item at head.

#### Parameters
* `value` Value of new element

#### `public inline void `[`insert`](#classexperimental_1_1_single_linked_list_1a6f8023e7603755d82ef0a6c1acc43ea1)`(T value)` 

Insert new item at cursor as the next item, if cursor == null then do a push.

#### Parameters
* `value` Value of the new element

#### `public inline void `[`reset`](#classexperimental_1_1_single_linked_list_1a3878da9482356b7d06ceb4eeec780ec0)`() noexcept` 

Reset iteration of the list to head.

#### `public inline bool `[`hasNext`](#classexperimental_1_1_single_linked_list_1a29cd1c8965aa5134b20609c30dccc676)`() noexcept` 

Is there a next item in the list?

#### Returns
true if we are not at the end of the lists

#### `public inline T `[`next`](#classexperimental_1_1_single_linked_list_1a9e87e020fe40b04cb454c9dedd4740be)`()` 

Return the current item while advancing the cursor.

Does not modify the list but it does advance the cursor

#### Returns
The value of the current element

#### `public inline T `[`current`](#classexperimental_1_1_single_linked_list_1a78017d26b09160f13e44ead598abd08b)`() noexcept` 

Return the current item.

Does not modify the list or advance the cursor

#### Returns
The value of the current element

#### `public inline bool `[`isEmpty`](#classexperimental_1_1_single_linked_list_1a94014b8dc6404ee998e2593890b15ac1)`() const noexcept` 

Is the list empty?

#### Returns
Return true if the list is empty

#### `public inline T `[`pop`](#classexperimental_1_1_single_linked_list_1adf0e10ac3de9a0d0cd831706dd2ce5cc)`()` 

Remove first item and return its value.

#### Returns
Value of first item

#### `public inline void `[`remove`](#classexperimental_1_1_single_linked_list_1acd9be89de452ec62a7fec3d123fdb56d)`()` 

Remove element at cursor.

If the cursor is at an invalid position may throw an exception

#### `public inline bool `[`find`](#classexperimental_1_1_single_linked_list_1ad737c8b463a7967433adf34e8c67fbb7)`(std::function< bool(T)> test) noexcept` 

resets cursor and iterates list until test() == true

#### Parameters
* `test` Lamba/function that will be called with values until it returns true.

#### Returns
True if test returned true.

#### `public inline bool `[`findNext`](#classexperimental_1_1_single_linked_list_1a81648d778127b477eebcdc1c7773636d)`(std::function< bool(T)> test) noexcept` 

Iterates list until test returns true.

#### Parameters
* `test` Lamba/function that will be called with values until it returns true.

#### Returns
True if test returned true.

#### `public inline `[`SingleLinkedListIterator`](#classexperimental_1_1_single_linked_list_iterator)`< T > `[`begin`](#classexperimental_1_1_single_linked_list_1ac24a5e3e4536449dd740dac0b82b229c)`() noexcept` 

Returns iterator for use in loops.

Resets the cursor and returns iterator

#### Returns
[SingleLinkedListIterator](#classexperimental_1_1_single_linked_list_iterator)

#### `public inline const `[`SingleLinkedListIterator`](#classexperimental_1_1_single_linked_list_iterator)`< T > `[`end`](#classexperimental_1_1_single_linked_list_1a79ed9790314ac0e74e347b9501449064)`() noexcept` 

Returns end iterator for use in loops.

#### Returns
[SingleLinkedListIterator](#classexperimental_1_1_single_linked_list_iterator)

# class `experimental::SingleLinkedListIterator` 

Iterator helper for [SingleLinkedList](#classexperimental_1_1_single_linked_list).

If `list` is of type [SingleLinkedList](#classexperimental_1_1_single_linked_list) then it is used in one of two ways:

* `for (auto i: list) { ... }`

* `for (auto i = list.begin(); i != list.end(); i++) { ... }`

## Summary

 Members                        | Descriptions                                
--------------------------------|---------------------------------------------
`public inline  `[`SingleLinkedListIterator`](#classexperimental_1_1_single_linked_list_iterator_1a3354fa27685f43775a32f00d4b850697)`(`[`SingleLinkedList`](#classexperimental_1_1_single_linked_list)`< T > & value,bool end) noexcept` | Constructor.
`public inline bool `[`operator!=`](#classexperimental_1_1_single_linked_list_iterator_1ac2be4089a995db44f83d0e3ced37f5a3)`(const `[`SingleLinkedListIterator`](#classexperimental_1_1_single_linked_list_iterator)` & other) const noexcept` | Comparison operator.
`public inline T `[`operator++`](#classexperimental_1_1_single_linked_list_iterator_1a804764ae889caf59c8a495560812d4fd)`() noexcept` | Advances the iterator.
`public inline T `[`operator++`](#classexperimental_1_1_single_linked_list_iterator_1af11bea5feca85ea173a355b0f5214a6e)`(int) noexcept` | Advances the iterator.
`public inline T `[`operator*`](#classexperimental_1_1_single_linked_list_iterator_1ab6f8afba14b0396ff9e7e55cbb584fe8)`() noexcept` | Pointer operator used by loops.

## Members

#### `public inline  `[`SingleLinkedListIterator`](#classexperimental_1_1_single_linked_list_iterator_1a3354fa27685f43775a32f00d4b850697)`(`[`SingleLinkedList`](#classexperimental_1_1_single_linked_list)`< T > & value,bool end) noexcept` 

Constructor.

#### Parameters
* `value` [SingleLinkedList](#classexperimental_1_1_single_linked_list) used by iterator 

* `end` Is this the end marker?

#### `public inline bool `[`operator!=`](#classexperimental_1_1_single_linked_list_iterator_1ac2be4089a995db44f83d0e3ced37f5a3)`(const `[`SingleLinkedListIterator`](#classexperimental_1_1_single_linked_list_iterator)` & other) const noexcept` 

Comparison operator.

#### Parameters
* `other` Other [SingleLinkedList](#classexperimental_1_1_single_linked_list) used to compare

#### Returns
Returns false if we are at the end of the list

#### `public inline T `[`operator++`](#classexperimental_1_1_single_linked_list_iterator_1a804764ae889caf59c8a495560812d4fd)`() noexcept` 

Advances the iterator.

#### Returns
The current value

#### `public inline T `[`operator++`](#classexperimental_1_1_single_linked_list_iterator_1af11bea5feca85ea173a355b0f5214a6e)`(int) noexcept` 

Advances the iterator.

#### Returns
The current value

#### `public inline T `[`operator*`](#classexperimental_1_1_single_linked_list_iterator_1ab6f8afba14b0396ff9e7e55cbb584fe8)`() noexcept` 

Pointer operator used by loops.

#### Returns
The current value

# class `experimental::SortedList` 

A simple sorted list that tries to be efficient.

This list will keep all items in sorted order. It uses a std::vector as backing store so large lists will be less efficient. Items in the list is considered constant and modifications of the objects will not re-sort the list.

## Summary

 Members                        | Descriptions                                
--------------------------------|---------------------------------------------
`public inline void `[`add`](#classexperimental_1_1_sorted_list_1aa4629056413ad3751c96577355cfd5d1)`(const T value) noexcept` | Adds an item to the list. It will add it in the correct position to keep the list sorted.
`public inline void `[`remove`](#classexperimental_1_1_sorted_list_1a57deb2bd6b92756c7926d1f7ab5d46fb)`(const `[`SortedListIterator`](#classexperimental_1_1_sorted_list_iterator)`< T > & position)` | Removes an item from the list.
`public inline bool `[`empty`](#classexperimental_1_1_sorted_list_1ad970c6270412cb490e7eb3799050319f)`() const noexcept` | Is the list empty?
`public inline unsigned `[`size`](#classexperimental_1_1_sorted_list_1a8b013c9d99a2e2c201bef5efe350a868)`() const noexcept` | Returns the number of items in the list.
`public inline const T & `[`at`](#classexperimental_1_1_sorted_list_1a52e6809c119269d90aee5c8c95ed7c76)`(unsigned offset) const` | Returns the value at the specified offset.
`public inline const T & `[`operator[]`](#classexperimental_1_1_sorted_list_1a0fc1eff684f42204f86f51b0948a901e)`(unsigned offset) const` | []Operator
`public inline const `[`SortedListIterator`](#classexperimental_1_1_sorted_list_iterator)`< T > & `[`find`](#classexperimental_1_1_sorted_list_1a0c9f029aa30fb7a916293356425d9411)`(const T value) const noexcept` | Does a binary search on the list and returns an iterator to its location if found or [end()](#classexperimental_1_1_sorted_list_1aa0682ce91c93d195fa705da91713319d) if not.
`public inline `[`SortedListIterator`](#classexperimental_1_1_sorted_list_iterator)`< T > `[`begin`](#classexperimental_1_1_sorted_list_1aad5361948aae51451e73ae48c3d36c28)`() const noexcept` | Returns an iterator that indicates the beginning of the list.
`public inline const `[`SortedListIterator`](#classexperimental_1_1_sorted_list_iterator)`< T > `[`end`](#classexperimental_1_1_sorted_list_1aa0682ce91c93d195fa705da91713319d)`() const noexcept` | Returns a constant iterator that indicates the end of the list.
`protected std::vector< T > `[`content`](#classexperimental_1_1_sorted_list_1aafe0f9a30a784debf72cbde201264b2d) | 

## Members

#### `public inline void `[`add`](#classexperimental_1_1_sorted_list_1aa4629056413ad3751c96577355cfd5d1)`(const T value) noexcept` 

Adds an item to the list. It will add it in the correct position to keep the list sorted.

#### Parameters
* `value` The value to add. Type must support == and >

#### `public inline void `[`remove`](#classexperimental_1_1_sorted_list_1a57deb2bd6b92756c7926d1f7ab5d46fb)`(const `[`SortedListIterator`](#classexperimental_1_1_sorted_list_iterator)`< T > & position)` 

Removes an item from the list.

#### Parameters
* `position` Iterator to the item to be removed

#### `public inline bool `[`empty`](#classexperimental_1_1_sorted_list_1ad970c6270412cb490e7eb3799050319f)`() const noexcept` 

Is the list empty?

#### Returns
Return true if the list is empty

#### `public inline unsigned `[`size`](#classexperimental_1_1_sorted_list_1a8b013c9d99a2e2c201bef5efe350a868)`() const noexcept` 

Returns the number of items in the list.

#### Returns
The size of the list

#### `public inline const T & `[`at`](#classexperimental_1_1_sorted_list_1a52e6809c119269d90aee5c8c95ed7c76)`(unsigned offset) const` 

Returns the value at the specified offset.

#### Parameters
* `offset` Offset into list 

#### Returns
const reference to the value referenced

#### `public inline const T & `[`operator[]`](#classexperimental_1_1_sorted_list_1a0fc1eff684f42204f86f51b0948a901e)`(unsigned offset) const` 

[]Operator

#### Parameters
* `offset` Offset into list 

#### Returns
const reference to the value referenced

#### `public inline const `[`SortedListIterator`](#classexperimental_1_1_sorted_list_iterator)`< T > & `[`find`](#classexperimental_1_1_sorted_list_1a0c9f029aa30fb7a916293356425d9411)`(const T value) const noexcept` 

Does a binary search on the list and returns an iterator to its location if found or [end()](#classexperimental_1_1_sorted_list_1aa0682ce91c93d195fa705da91713319d) if not.

#### Parameters
* `value` The value to find 

#### Returns
An iterator to the position of the value or the [end()](#classexperimental_1_1_sorted_list_1aa0682ce91c93d195fa705da91713319d) iterator

#### `public inline `[`SortedListIterator`](#classexperimental_1_1_sorted_list_iterator)`< T > `[`begin`](#classexperimental_1_1_sorted_list_1aad5361948aae51451e73ae48c3d36c28)`() const noexcept` 

Returns an iterator that indicates the beginning of the list.

#### Returns
Iterator

#### `public inline const `[`SortedListIterator`](#classexperimental_1_1_sorted_list_iterator)`< T > `[`end`](#classexperimental_1_1_sorted_list_1aa0682ce91c93d195fa705da91713319d)`() const noexcept` 

Returns a constant iterator that indicates the end of the list.

#### Returns
Iterator

#### `protected std::vector< T > `[`content`](#classexperimental_1_1_sorted_list_1aafe0f9a30a784debf72cbde201264b2d) 

# class `experimental::SortedListIterator` 

Iterator helper for [SortedList](#classexperimental_1_1_sorted_list).

If `list` is of type [SortedList](#classexperimental_1_1_sorted_list) then it is used in one of two ways:

* `for (auto i: list) { ... }`

* `for (auto i = list.begin(); i != list.end(); i++) { ... }`

## Summary

 Members                        | Descriptions                                
--------------------------------|---------------------------------------------
`public inline bool `[`operator!=`](#classexperimental_1_1_sorted_list_iterator_1a5153e09066955ea473e7788a26440870)`(const `[`SortedListIterator`](#classexperimental_1_1_sorted_list_iterator)`< T > & other) const noexcept` | Non equal operator.
`public inline bool `[`operator==`](#classexperimental_1_1_sorted_list_iterator_1aac54cdb1c6992ff9cb5c991de4a4fda6)`(const `[`SortedListIterator`](#classexperimental_1_1_sorted_list_iterator)`< T > & other) const noexcept` | Equal operator.
`public inline T & `[`operator++`](#classexperimental_1_1_sorted_list_iterator_1a25e31ecc074bf92de0a88b2ea485c45f)`()` | Advances the iterator.
`public inline T & `[`operator++`](#classexperimental_1_1_sorted_list_iterator_1a55fd3b39d933c9b7690f99f3a023668b)`(int)` | Advances the iterator.
`public inline `[`SortedListIterator`](#classexperimental_1_1_sorted_list_iterator)`< T > & `[`operator+=`](#classexperimental_1_1_sorted_list_iterator_1aeb79ab51397d626d3fcecb5da0b7390e)`(int value)` | += Operator
`public inline `[`SortedListIterator`](#classexperimental_1_1_sorted_list_iterator)`< T > & `[`operator-=`](#classexperimental_1_1_sorted_list_iterator_1a576f14c339059a3e54125ff39c4d0f91)`(int value)` | -= Operator
`public inline const T & `[`operator*`](#classexperimental_1_1_sorted_list_iterator_1acfe632ec570fd43701aa1aec4803292c)`() const` | Pointer operator used by loops.
`protected inline  `[`SortedListIterator`](#classexperimental_1_1_sorted_list_iterator_1a412e44348fe690d28dc75fbeb8e7402f)`(const `[`SortedList`](#classexperimental_1_1_sorted_list)`< T > & that,bool end,unsigned startOffset)` | Constructor.

## Members

#### `public inline bool `[`operator!=`](#classexperimental_1_1_sorted_list_iterator_1a5153e09066955ea473e7788a26440870)`(const `[`SortedListIterator`](#classexperimental_1_1_sorted_list_iterator)`< T > & other) const noexcept` 

Non equal operator.

#### Parameters
* `other` The iterator to compare to 

#### Returns
True if the two iterators are not at the same position

#### `public inline bool `[`operator==`](#classexperimental_1_1_sorted_list_iterator_1aac54cdb1c6992ff9cb5c991de4a4fda6)`(const `[`SortedListIterator`](#classexperimental_1_1_sorted_list_iterator)`< T > & other) const noexcept` 

Equal operator.

#### Parameters
* `other` The iterator to compare to 

#### Returns
True if the two iterators are at the same position

#### `public inline T & `[`operator++`](#classexperimental_1_1_sorted_list_iterator_1a25e31ecc074bf92de0a88b2ea485c45f)`()` 

Advances the iterator.

#### Returns
The current value

#### `public inline T & `[`operator++`](#classexperimental_1_1_sorted_list_iterator_1a55fd3b39d933c9b7690f99f3a023668b)`(int)` 

Advances the iterator.

#### Returns
The current value

#### `public inline `[`SortedListIterator`](#classexperimental_1_1_sorted_list_iterator)`< T > & `[`operator+=`](#classexperimental_1_1_sorted_list_iterator_1aeb79ab51397d626d3fcecb5da0b7390e)`(int value)` 

+= Operator

#### Parameters
* `offet` The offset to apply 

#### Returns
The updated iterator

#### `public inline `[`SortedListIterator`](#classexperimental_1_1_sorted_list_iterator)`< T > & `[`operator-=`](#classexperimental_1_1_sorted_list_iterator_1a576f14c339059a3e54125ff39c4d0f91)`(int value)` 

-= Operator

#### Parameters
* `offet` The offset to apply 

#### Returns
The updated iterator

#### `public inline const T & `[`operator*`](#classexperimental_1_1_sorted_list_iterator_1acfe632ec570fd43701aa1aec4803292c)`() const` 

Pointer operator used by loops.

#### Returns
The current value

#### `protected inline  `[`SortedListIterator`](#classexperimental_1_1_sorted_list_iterator_1a412e44348fe690d28dc75fbeb8e7402f)`(const `[`SortedList`](#classexperimental_1_1_sorted_list)`< T > & that,bool end,unsigned startOffset)` 

Constructor.

#### Parameters
* `value` [SortedList](#classexperimental_1_1_sorted_list) used by iterator 

* `end` Is this the end marker? 

* `startOffset` starting offset of iterator

# class `experimental::SingleLinkedList::Element` 

## Summary

 Members                        | Descriptions                                
--------------------------------|---------------------------------------------
`public inline  `[`Element`](#classexperimental_1_1_single_linked_list_1_1_element_1af3e2c952bfd9f4560b19c55c6907c6c8)`(Element * newNext,TPriv newValue) noexcept` | 
`public inline Element< TPriv > * `[`getNext`](#classexperimental_1_1_single_linked_list_1_1_element_1a3da5d0401f59b524026498c268150fec)`() const noexcept` | 
`public inline void `[`setNext`](#classexperimental_1_1_single_linked_list_1_1_element_1a9c882fe4148300464a78f987e27cc25a)`(Element< TPriv > * newValue) noexcept` | 
`public inline TPriv `[`getValue`](#classexperimental_1_1_single_linked_list_1_1_element_1a5fcfd25bac225ee5bcc34219889e75f9)`() const noexcept` | 

## Members

#### `public inline  `[`Element`](#classexperimental_1_1_single_linked_list_1_1_element_1af3e2c952bfd9f4560b19c55c6907c6c8)`(Element * newNext,TPriv newValue) noexcept` 

#### `public inline Element< TPriv > * `[`getNext`](#classexperimental_1_1_single_linked_list_1_1_element_1a3da5d0401f59b524026498c268150fec)`() const noexcept` 

#### `public inline void `[`setNext`](#classexperimental_1_1_single_linked_list_1_1_element_1a9c882fe4148300464a78f987e27cc25a)`(Element< TPriv > * newValue) noexcept` 

#### `public inline TPriv `[`getValue`](#classexperimental_1_1_single_linked_list_1_1_element_1a5fcfd25bac225ee5bcc34219889e75f9)`() const noexcept` 

Generated by [Moxygen](https://sourcey.com/moxygen)