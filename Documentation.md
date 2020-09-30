# Summary

 Members                        | Descriptions                                
--------------------------------|---------------------------------------------
`namespace `[`experimental`](#namespaceexperimental) | 
`class `[`experimental::SingleLinkedList::Element`](#classexperimental_1_1_single_linked_list_1_1_element) | 

# namespace `experimental` 

## Summary

 Members                        | Descriptions                                
--------------------------------|---------------------------------------------
`class `[`experimental::MathVector`](#classexperimental_1_1_math_vector) | A class to do simple vector math.
`class `[`experimental::SingleLinkedList`](#classexperimental_1_1_single_linked_list) | A single linked list.
`class `[`experimental::SingleLinkedListIterator`](#classexperimental_1_1_single_linked_list_iterator) | Iterator helper for [SingleLinkedList](#classexperimental_1_1_single_linked_list).
`class `[`experimental::SkipList`](#classexperimental_1_1_skip_list) | 
`class `[`experimental::SkipListIterator`](#classexperimental_1_1_skip_list_iterator) | 
`class `[`experimental::SLElement`](#classexperimental_1_1_s_l_element) | Skip List.
`class `[`experimental::SortedList`](#classexperimental_1_1_sorted_list) | A simple sorted list that tries to be efficient.
`class `[`experimental::SortedListIterator`](#classexperimental_1_1_sorted_list_iterator) | Iterator helper for [SortedList](#classexperimental_1_1_sorted_list).

# class `experimental::MathVector` 

A class to do simple vector math.

Called [MathVector](#classexperimental_1_1_math_vector) so as to not confuse with std::vector

## Summary

 Members                        | Descriptions                                
--------------------------------|---------------------------------------------
`public inline  `[`MathVector`](#classexperimental_1_1_math_vector_1af82c1b6c6e6c92668f685e8a51cbbe7c)`()` | Default constructor.
`public inline  `[`MathVector`](#classexperimental_1_1_math_vector_1ab48e298d012d0f932cf079fb1a65a7fe)`(const `[`MathVector`](#classexperimental_1_1_math_vector)` & other)` | Copy constructor.
`public inline  `[`MathVector`](#classexperimental_1_1_math_vector_1a50e0a8fa1b47a5e502e26de69e1f402b)`(const std::initializer_list< T > list)` | List constructor.
`public inline `[`MathVector`](#classexperimental_1_1_math_vector)`< T > & `[`operator=`](#classexperimental_1_1_math_vector_1a7ab63baa4dff9b81fceea36b745fbe50)`(const `[`MathVector`](#classexperimental_1_1_math_vector)`< T > & other)` | Assignment operator.
`public inline `[`MathVector`](#classexperimental_1_1_math_vector)`< T > & `[`operator=`](#classexperimental_1_1_math_vector_1ac4b315e5eed97e92883c5789672e4283)`(`[`MathVector`](#classexperimental_1_1_math_vector)`< T > && other) noexcept` | Move operator.
`public inline size_t `[`size`](#classexperimental_1_1_math_vector_1ae8829ab480412060eba3a3caef78c225)`() const noexcept` | Returns the size of the vector.
`public inline T `[`magnitude`](#classexperimental_1_1_math_vector_1ad7a17f6393b8aeb1badf50092021cd87)`() const noexcept` | Calculates the magnitude of the vector.
`public inline const T & `[`operator[]`](#classexperimental_1_1_math_vector_1af40e6d331960a62da43becfb4e020157)`(std::size_t idx) const` | Array subscript operator. Allows individual scalars in the vector to be accessed. Will throw exception on out of bounds access.
`public inline `[`MathVector`](#classexperimental_1_1_math_vector)`< T > & `[`operator+=`](#classexperimental_1_1_math_vector_1a16087f53170807f0e68f4074d4b4edf4)`(const `[`MathVector`](#classexperimental_1_1_math_vector)`< T > & rhs)` | operator +=. Adds a vector to the current one. If the vectors are not the same size then it will throw an exception
`public inline `[`MathVector`](#classexperimental_1_1_math_vector)`< T > & `[`operator-=`](#classexperimental_1_1_math_vector_1a76b154c0a55bd4ad64d78de5b1e62307)`(const `[`MathVector`](#classexperimental_1_1_math_vector)`< T > & rhs)` | operator -=. Subtracts a vector from the current one. If the vectors are not the same size then it will throw an exception
`public inline `[`MathVector`](#classexperimental_1_1_math_vector)`< T > & `[`operator*=`](#classexperimental_1_1_math_vector_1a5cd1e0cb542ccfebaa9ab4b6e7af4ebf)`(const T & rhs)` | Multiply a vector with a scalar.

## Members

#### `public inline  `[`MathVector`](#classexperimental_1_1_math_vector_1af82c1b6c6e6c92668f685e8a51cbbe7c)`()` 

Default constructor.

#### `public inline  `[`MathVector`](#classexperimental_1_1_math_vector_1ab48e298d012d0f932cf079fb1a65a7fe)`(const `[`MathVector`](#classexperimental_1_1_math_vector)` & other)` 

Copy constructor.

#### Parameters
* `other` Other vector to copy

#### `public inline  `[`MathVector`](#classexperimental_1_1_math_vector_1a50e0a8fa1b47a5e502e26de69e1f402b)`(const std::initializer_list< T > list)` 

List constructor.

#### Parameters
* `list` List of values to assign

#### `public inline `[`MathVector`](#classexperimental_1_1_math_vector)`< T > & `[`operator=`](#classexperimental_1_1_math_vector_1a7ab63baa4dff9b81fceea36b745fbe50)`(const `[`MathVector`](#classexperimental_1_1_math_vector)`< T > & other)` 

Assignment operator.

#### Parameters
* `other` Other vector to assign

#### `public inline `[`MathVector`](#classexperimental_1_1_math_vector)`< T > & `[`operator=`](#classexperimental_1_1_math_vector_1ac4b315e5eed97e92883c5789672e4283)`(`[`MathVector`](#classexperimental_1_1_math_vector)`< T > && other) noexcept` 

Move operator.

#### Parameters
* `other` Other vector to move from

#### `public inline size_t `[`size`](#classexperimental_1_1_math_vector_1ae8829ab480412060eba3a3caef78c225)`() const noexcept` 

Returns the size of the vector.

#### Returns
Size of the vector

#### `public inline T `[`magnitude`](#classexperimental_1_1_math_vector_1ad7a17f6393b8aeb1badf50092021cd87)`() const noexcept` 

Calculates the magnitude of the vector.

#### Returns
The magnitude of the vector

#### `public inline const T & `[`operator[]`](#classexperimental_1_1_math_vector_1af40e6d331960a62da43becfb4e020157)`(std::size_t idx) const` 

Array subscript operator. Allows individual scalars in the vector to be accessed. Will throw exception on out of bounds access.

#### Parameters
* `idx` Offset into vector 

#### Returns
Indexed scalar from vector

#### `public inline `[`MathVector`](#classexperimental_1_1_math_vector)`< T > & `[`operator+=`](#classexperimental_1_1_math_vector_1a16087f53170807f0e68f4074d4b4edf4)`(const `[`MathVector`](#classexperimental_1_1_math_vector)`< T > & rhs)` 

operator +=. Adds a vector to the current one. If the vectors are not the same size then it will throw an exception

#### Parameters
* `rhs` vector to add 

#### Returns
An instance of the target vector

#### `public inline `[`MathVector`](#classexperimental_1_1_math_vector)`< T > & `[`operator-=`](#classexperimental_1_1_math_vector_1a76b154c0a55bd4ad64d78de5b1e62307)`(const `[`MathVector`](#classexperimental_1_1_math_vector)`< T > & rhs)` 

operator -=. Subtracts a vector from the current one. If the vectors are not the same size then it will throw an exception

#### Parameters
* `rhs` vector to subtract 

#### Returns
An instance of the target vector

#### `public inline `[`MathVector`](#classexperimental_1_1_math_vector)`< T > & `[`operator*=`](#classexperimental_1_1_math_vector_1a5cd1e0cb542ccfebaa9ab4b6e7af4ebf)`(const T & rhs)` 

Multiply a vector with a scalar.

#### Parameters
* `rhs` Scalar 

#### Returns
Updated vector

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

# class `experimental::SkipList` 

## Summary

 Members                        | Descriptions                                
--------------------------------|---------------------------------------------
`public inline  `[`SkipList`](#classexperimental_1_1_skip_list_1aa197aa722ba663df1fd44cf69ff1cd35)`(unsigned _lgNMax)` | Constructor.
`public inline virtual  `[`~SkipList`](#classexperimental_1_1_skip_list_1a5dbc3cc61798407e2afe5045ebc49617)`()` | Destructor.
`public inline void `[`add`](#classexperimental_1_1_skip_list_1a688dbdcccccf8bb5d975df76a8d0f2e0)`(const T value) noexcept` | Adds an item to the list and keep the list in sorted order.
`public inline `[`SkipListIterator`](#classexperimental_1_1_skip_list_iterator)`< T > `[`find`](#classexperimental_1_1_skip_list_1a31cb8f3f943136d21cb4b6f59c758351)`(const T value)` | Finds a value in the list. T must implement < and ==.
`public inline bool `[`isEmpty`](#classexperimental_1_1_skip_list_1a7ce0e2481a9b9039f056479125721e3f)`() noexcept` | Returns true if the list is empty.
`public inline `[`SkipListIterator`](#classexperimental_1_1_skip_list_iterator)`< T > `[`begin`](#classexperimental_1_1_skip_list_1a4e78931a58173885ca93ebda3e3c9316)`() noexcept` | Returns iterator for use in loops.
`public inline const `[`SkipListIterator`](#classexperimental_1_1_skip_list_iterator)`< T > `[`end`](#classexperimental_1_1_skip_list_1af32847efc2539a34e1864b8afb80ac09)`() noexcept` | Returns end iterator for use in loops.
`protected inline unsigned `[`randX`](#classexperimental_1_1_skip_list_1a8850b5a5cf76e050282e432f96f22fca)`() noexcept` | Returns a random size for a node.
`protected inline void `[`addHelper`](#classexperimental_1_1_skip_list_1a433baae50e676513372d13f5128e5bcc)`(`[`SLElement`](#classexperimental_1_1_s_l_element)`< T > * t,`[`SLElement`](#classexperimental_1_1_s_l_element)`< T > * x,unsigned k) noexcept` | Recursively adds an item to a node.
`protected inline `[`SLElement`](#classexperimental_1_1_s_l_element)`< T > * `[`findHelper`](#classexperimental_1_1_skip_list_1a261a20a57356d5bf59295a722fae65e8)`(`[`SLElement`](#classexperimental_1_1_s_l_element)`< T > * t,const T & value) const noexcept` | Recursively finds value in the list.
`protected inline void `[`deleteHelper`](#classexperimental_1_1_skip_list_1a161b79f98011401cc968d65d43c681f1)`(`[`SLElement`](#classexperimental_1_1_s_l_element)`< T > * item) noexcept` | Used by the destructor to cleanup recursively.

## Members

#### `public inline  `[`SkipList`](#classexperimental_1_1_skip_list_1aa197aa722ba663df1fd44cf69ff1cd35)`(unsigned _lgNMax)` 

Constructor.

#### Parameters
* `_lgNMax` A magic number that controls how big the skiplist can get. Experimentation should be used to find an optimal value for your data

#### `public inline virtual  `[`~SkipList`](#classexperimental_1_1_skip_list_1a5dbc3cc61798407e2afe5045ebc49617)`()` 

Destructor.

#### `public inline void `[`add`](#classexperimental_1_1_skip_list_1a688dbdcccccf8bb5d975df76a8d0f2e0)`(const T value) noexcept` 

Adds an item to the list and keep the list in sorted order.

#### Parameters
* `value` The value to add

#### `public inline `[`SkipListIterator`](#classexperimental_1_1_skip_list_iterator)`< T > `[`find`](#classexperimental_1_1_skip_list_1a31cb8f3f943136d21cb4b6f59c758351)`(const T value)` 

Finds a value in the list. T must implement < and ==.

#### Parameters
* `value` The value to find 

#### Returns
[end()](#classexperimental_1_1_skip_list_1af32847efc2539a34e1864b8afb80ac09) if not found, otherwise an iterator to the value

#### `public inline bool `[`isEmpty`](#classexperimental_1_1_skip_list_1a7ce0e2481a9b9039f056479125721e3f)`() noexcept` 

Returns true if the list is empty.

#### Returns
True if the list is empty

#### `public inline `[`SkipListIterator`](#classexperimental_1_1_skip_list_iterator)`< T > `[`begin`](#classexperimental_1_1_skip_list_1a4e78931a58173885ca93ebda3e3c9316)`() noexcept` 

Returns iterator for use in loops.

#### Returns
[SkipListIterator](#classexperimental_1_1_skip_list_iterator)

#### `public inline const `[`SkipListIterator`](#classexperimental_1_1_skip_list_iterator)`< T > `[`end`](#classexperimental_1_1_skip_list_1af32847efc2539a34e1864b8afb80ac09)`() noexcept` 

Returns end iterator for use in loops.

#### Returns
[SkipListIterator](#classexperimental_1_1_skip_list_iterator)

#### `protected inline unsigned `[`randX`](#classexperimental_1_1_skip_list_1a8850b5a5cf76e050282e432f96f22fca)`() noexcept` 

Returns a random size for a node.

Updates lgN

#### Returns
A size that will be < lgNMax and >= 1

#### `protected inline void `[`addHelper`](#classexperimental_1_1_skip_list_1a433baae50e676513372d13f5128e5bcc)`(`[`SLElement`](#classexperimental_1_1_s_l_element)`< T > * t,`[`SLElement`](#classexperimental_1_1_s_l_element)`< T > * x,unsigned k) noexcept` 

Recursively adds an item to a node.

#### Parameters
* `t` The current node to process 

* `x` The node to add 

* `k` The current working offset

#### `protected inline `[`SLElement`](#classexperimental_1_1_s_l_element)`< T > * `[`findHelper`](#classexperimental_1_1_skip_list_1a261a20a57356d5bf59295a722fae65e8)`(`[`SLElement`](#classexperimental_1_1_s_l_element)`< T > * t,const T & value) const noexcept` 

Recursively finds value in the list.

#### Returns
z if not found, otherwise the node 

#### Parameters
* `t` The current node to search 

* `value` The value to match

#### `protected inline void `[`deleteHelper`](#classexperimental_1_1_skip_list_1a161b79f98011401cc968d65d43c681f1)`(`[`SLElement`](#classexperimental_1_1_s_l_element)`< T > * item) noexcept` 

Used by the destructor to cleanup recursively.

# class `experimental::SkipListIterator` 

## Summary

 Members                        | Descriptions                                
--------------------------------|---------------------------------------------
`public inline bool `[`operator==`](#classexperimental_1_1_skip_list_iterator_1a33734050999965858c9d194d755a7b53)`(const `[`SkipListIterator`](#classexperimental_1_1_skip_list_iterator)` & other) const noexcept` | == Comparison operator
`public inline bool `[`operator!=`](#classexperimental_1_1_skip_list_iterator_1a1607a635c93b210f252e66473f397207)`(const `[`SkipListIterator`](#classexperimental_1_1_skip_list_iterator)` & other) const noexcept` | != Comparison operator
`public inline const T & `[`operator++`](#classexperimental_1_1_skip_list_iterator_1a99a8a267db7c3a33b6954331e4eaf586)`()` | Advances the iterator.
`public inline const T & `[`operator++`](#classexperimental_1_1_skip_list_iterator_1af476ca42e1eb56a9e6b654e8ea2fb64e)`(int)` | Advances the iterator.
`public inline const T & `[`operator*`](#classexperimental_1_1_skip_list_iterator_1aaa61547b96fb0a2972752267f4c0a1eb)`() noexcept` | Pointer operator used by loops.
`protected inline  `[`SkipListIterator`](#classexperimental_1_1_skip_list_iterator_1a4ada8e6b5dfb61e330dbdea31e63367c)`(const `[`SkipList`](#classexperimental_1_1_skip_list)`< T > & value,`[`SLElement`](#classexperimental_1_1_s_l_element)`< T > * item) noexcept` | Constructor.
`protected inline  `[`SkipListIterator`](#classexperimental_1_1_skip_list_iterator_1a68e1df21c799b41bc6f48ffdf119e142)`(const `[`SkipList`](#classexperimental_1_1_skip_list)`< T > & value,bool end) noexcept` | Constructor.
`protected inline bool `[`hasNext`](#classexperimental_1_1_skip_list_iterator_1a65db39ff5620d81cc63619cc8448c24a)`() const noexcept` | Returns whether we are at the end of the list or not.

## Members

#### `public inline bool `[`operator==`](#classexperimental_1_1_skip_list_iterator_1a33734050999965858c9d194d755a7b53)`(const `[`SkipListIterator`](#classexperimental_1_1_skip_list_iterator)` & other) const noexcept` 

== Comparison operator

#### Parameters
* `other` Other [SkipList](#classexperimental_1_1_skip_list) used to compare

#### Returns
Returns true if both lists are at the same location

#### `public inline bool `[`operator!=`](#classexperimental_1_1_skip_list_iterator_1a1607a635c93b210f252e66473f397207)`(const `[`SkipListIterator`](#classexperimental_1_1_skip_list_iterator)` & other) const noexcept` 

!= Comparison operator

#### Parameters
* `other` Other [SkipList](#classexperimental_1_1_skip_list) used to compare

#### Returns
Returns false if we are at the end of the list

#### `public inline const T & `[`operator++`](#classexperimental_1_1_skip_list_iterator_1a99a8a267db7c3a33b6954331e4eaf586)`()` 

Advances the iterator.

#### Returns
The current value

#### `public inline const T & `[`operator++`](#classexperimental_1_1_skip_list_iterator_1af476ca42e1eb56a9e6b654e8ea2fb64e)`(int)` 

Advances the iterator.

#### Returns
The current value

#### `public inline const T & `[`operator*`](#classexperimental_1_1_skip_list_iterator_1aaa61547b96fb0a2972752267f4c0a1eb)`() noexcept` 

Pointer operator used by loops.

#### Returns
The current value

#### `protected inline  `[`SkipListIterator`](#classexperimental_1_1_skip_list_iterator_1a4ada8e6b5dfb61e330dbdea31e63367c)`(const `[`SkipList`](#classexperimental_1_1_skip_list)`< T > & value,`[`SLElement`](#classexperimental_1_1_s_l_element)`< T > * item) noexcept` 

Constructor.

#### Parameters
* `value` [SkipList](#classexperimental_1_1_skip_list) used by iterator 

* `item` The current position in the list

#### `protected inline  `[`SkipListIterator`](#classexperimental_1_1_skip_list_iterator_1a68e1df21c799b41bc6f48ffdf119e142)`(const `[`SkipList`](#classexperimental_1_1_skip_list)`< T > & value,bool end) noexcept` 

Constructor.

#### Parameters
* `value` [SkipList](#classexperimental_1_1_skip_list) used by iterator 

* `end` Is this the end marker?

#### `protected inline bool `[`hasNext`](#classexperimental_1_1_skip_list_iterator_1a65db39ff5620d81cc63619cc8448c24a)`() const noexcept` 

Returns whether we are at the end of the list or not.

# class `experimental::SLElement` 

Skip List.

A skip list is a mix between a tree and a linked list. It keeps the items in a sorted order but by having links that can skip other links allows for finding items faster than you would in a standard linked list. The algorithm looks expensive for inserting as multiple links can be updated on insertion but balancing that against a tree rebalance or a memory move as you would get in a std::vector it may just end up not being as expensive as you think. It will probably be most efficient for larger data sets.

Items in the list are considered constant and modifications of the objects will not re-sort the list.

## Summary

 Members                        | Descriptions                                
--------------------------------|---------------------------------------------
`public inline  `[`SLElement`](#classexperimental_1_1_s_l_element_1aa5ab7842d143895d082886085ebc637f)`(unsigned size,`[`SLElement`](#classexperimental_1_1_s_l_element)` * newNext,TPriv newValue) noexcept` | 
`public inline virtual  `[`~SLElement`](#classexperimental_1_1_s_l_element_1a252ecbf0148166f90d088679020bbd1e)`() noexcept` | 
`public inline `[`SLElement`](#classexperimental_1_1_s_l_element)`< TPriv > * `[`getNext`](#classexperimental_1_1_s_l_element_1aa6f1f902289549af8e6317354f32e4db)`(unsigned offset) const noexcept` | 
`public inline void `[`setNext`](#classexperimental_1_1_s_l_element_1a2bf0c8c668a2e504f4d431fb4e934efa)`(`[`SLElement`](#classexperimental_1_1_s_l_element)`< TPriv > * newValue,unsigned offset) noexcept` | 
`public inline const TPriv & `[`getValue`](#classexperimental_1_1_s_l_element_1a6d80dd7e03827efb5dc9307c8972c261)`() const noexcept` | 
`public inline unsigned `[`size`](#classexperimental_1_1_s_l_element_1a6368302356f72f067988a1063af10620)`() const noexcept` | 

## Members

#### `public inline  `[`SLElement`](#classexperimental_1_1_s_l_element_1aa5ab7842d143895d082886085ebc637f)`(unsigned size,`[`SLElement`](#classexperimental_1_1_s_l_element)` * newNext,TPriv newValue) noexcept` 

#### `public inline virtual  `[`~SLElement`](#classexperimental_1_1_s_l_element_1a252ecbf0148166f90d088679020bbd1e)`() noexcept` 

#### `public inline `[`SLElement`](#classexperimental_1_1_s_l_element)`< TPriv > * `[`getNext`](#classexperimental_1_1_s_l_element_1aa6f1f902289549af8e6317354f32e4db)`(unsigned offset) const noexcept` 

#### `public inline void `[`setNext`](#classexperimental_1_1_s_l_element_1a2bf0c8c668a2e504f4d431fb4e934efa)`(`[`SLElement`](#classexperimental_1_1_s_l_element)`< TPriv > * newValue,unsigned offset) noexcept` 

#### `public inline const TPriv & `[`getValue`](#classexperimental_1_1_s_l_element_1a6d80dd7e03827efb5dc9307c8972c261)`() const noexcept` 

#### `public inline unsigned `[`size`](#classexperimental_1_1_s_l_element_1a6368302356f72f067988a1063af10620)`() const noexcept` 

# class `experimental::SortedList` 

A simple sorted list that tries to be efficient.

This list will keep all items in sorted order. It uses a std::vector as backing store so large lists will be less efficient. Items in the list are considered constant and modifications of the objects will not re-sort the list.

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