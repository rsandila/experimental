# Summary

 Members                        | Descriptions                                
--------------------------------|---------------------------------------------
`namespace `[`experimental`](#namespaceexperimental) | 
`class `[`experimental::SingleLinkedList::Element`](#classexperimental_1_1_single_linked_list_1_1_element) | 

# namespace `experimental` 

## Summary

 Members                        | Descriptions                                
--------------------------------|---------------------------------------------
`class `[`experimental::SingleLinkedList`](#classexperimental_1_1_single_linked_list) | A single linked lists.
`class `[`experimental::SingleLinkedListIterator`](#classexperimental_1_1_single_linked_list_iterator) | Iterator helper for [SingleLinkedList](#classexperimental_1_1_single_linked_list).

# class `experimental::SingleLinkedList` 

A single linked lists.

A single linked list is one that can only be traversed in one direction. It can be used as a stack. Inserts and removes are extremely fast. Find is linear.

## Summary

 Members                        | Descriptions                                
--------------------------------|---------------------------------------------
`public inline  `[`SingleLinkedList`](#classexperimental_1_1_single_linked_list_1a5efd9ecfa26ebe68da0b34f75daa14d1)`() noexcept` | Default constructors Creates a new empty [SingleLinkedList](#classexperimental_1_1_single_linked_list).
`public inline  `[`SingleLinkedList`](#classexperimental_1_1_single_linked_list_1aa56386b0d9297264e246e709a26ffd2a)`(std::initializer_list< T > initialValues) noexcept` | Initializer constructor.
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