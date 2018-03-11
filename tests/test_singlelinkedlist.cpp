//
//  test_singlelinkedlist.cpp
//  experimental
//
//  Created by Robert Sandilands on 3/7/18.
//  Copyright © 2018 Robert Sandilands. All rights reserved.
//
#include "../3rdparty/Catch2/single_include/catch.hpp"
#include "singlelinkedlist.hpp"

TEST_CASE("Empty list tests", "[single_linked_list]") {
    GIVEN("An empty list") {
        experimental::SingleLinkedList<int> test;
        REQUIRE(test.isEmpty());
        
        WHEN("An item is added") {
            test.push(10);
            THEN("The list is no longer empty") {
                REQUIRE_FALSE(test.isEmpty());
            }
            WHEN("The item is popped") {
                REQUIRE(test.pop() == 10);
                THEN("The list must be empty again") {
                    REQUIRE(test.isEmpty());
                }
            }
        }
        WHEN("Another item is added") {
            test.push(20);
            THEN("The list is no longer empty") {
                REQUIRE_FALSE(test.isEmpty());
            }
            WHEN("The cursor is reset and the item is removed") {
                test.reset();
                test.remove();
                THEN("The list is empty again") {
                    REQUIRE(test.isEmpty());
                }
            }
        }
        WHEN("We iterate an empty list things work") {
            int count = 0;
            for (auto iter: test) {
                count += 1;
            }
            THEN("We should not have iterated anything") {
                REQUIRE(count == 0);
            }
        }
        WHEN("We try to find things in an empty list") {
            THEN("We find nothing") {
                REQUIRE_FALSE(test.find([](int){ return true;}));
            }
        }
        WHEN("We try findNext in an empty list") {
            THEN("We still find nothing") {
                REQUIRE_FALSE(test.findNext([](int){ return true;}));
            }
            
        }
    }
}

TEST_CASE("List is LIFO", "[single_linked_list]") {
    GIVEN("A list of items") {
        experimental::SingleLinkedList<int> test;
        REQUIRE(test.isEmpty());
        WHEN("Items are added") {
            for (int i = 1; i < 1000; i++) {
                test.push(i);
            }
            THEN("The list should not be empty") {
                REQUIRE_FALSE(test.isEmpty());
            }
            THEN("The items should be retreived in reverse order") {
                test.reset();
                for (int i = 999; i > 0; --i) {
                    REQUIRE(test.current() == i);
                    REQUIRE(test.next() == i);
                }
                THEN("We have iterated the whole list") {
                    REQUIRE_FALSE(test.hasNext());
                }
            }
            WHEN("We reset the list and pop items") {
                THEN("The items should be retreived in reverse order") {
                    test.reset();
                    for (int i = 999; i > 0; --i) {
                        REQUIRE(test.current() == i);
                        REQUIRE(test.pop() == i);
                    }
                    THEN("We have iterated the whole list") {
                        REQUIRE_FALSE(test.hasNext());
                    }
                    THEN("The list is empty") {
                        REQUIRE(test.isEmpty());
                    }
                }
            }
        }
    }
}

// test find and findNext
TEST_CASE("find and findNext", "[single_linked_list]") {
    GIVEN("A list of items") {
        experimental::SingleLinkedList<int> test;
        REQUIRE(test.isEmpty());
        WHEN("Items are added") {
            for (int i = 1; i < 1000; i++) {
                test.push(i);
            }
            THEN("It finds the first instance of 10") {
                REQUIRE(test.find([](int val){ return val == 10;}));
                AND_THEN("It does not findNext an instance of 20") {
                    REQUIRE_FALSE(test.findNext([](int val){ return val == 20;}));
                    AND_THEN("It does find an instance of 20") {
                        REQUIRE(test.find([](int val){ return val == 20;}));
                        AND_THEN("It finds an instance of 18") {
                            REQUIRE(test.findNext([](int val){ return val == 18;}));
                        }
                    }
                }
            }
            THEN("It does not find an instance of 2000") {
                REQUIRE_FALSE(test.find([](int val){ return val == 2000;}));
                AND_THEN("It does not findNext an instance of 10") {
                    REQUIRE_FALSE(test.findNext([](int val){ return val == 10;}));
                }
            }
            THEN("It finds every number added") {
                for (int i = 1; i < 1000; ++i) {
                    REQUIRE(test.find([i](int val){ return val == i;}));
                }
            }
            THEN("It findNext every number added") {
                test.reset();
                for (int i = 999; i > 0; --i) {
                    REQUIRE(test.findNext([i](int val){ return val == i;}));
                }
            }
        }
    }
}

// test insert
TEST_CASE("test insert", "[single_linked_list]") {
    GIVEN("An empty list") {
        experimental::SingleLinkedList<int> test;
        REQUIRE(test.isEmpty());
        WHEN("Insert a single entry") {
            test.insert(10);
            THEN ("It is no longer empty") {
                REQUIRE_FALSE(test.isEmpty());
            }
            THEN ("It contains a single entry") {
                REQUIRE(test.next() == 10);
                REQUIRE_FALSE(test.hasNext());
            }
            WHEN("Insert another entry at the start") {
                test.reset();
                test.insert(20);
                THEN("It contains 2 entries") {
                    REQUIRE(test.next() == 10);
                    REQUIRE(test.next() == 20);
                    REQUIRE_FALSE(test.hasNext());
                }
            }
        }
    }
    GIVEN("A list with 3, 6, 9, 12, 15...") {
        experimental::SingleLinkedList<int> test({21, 18, 15, 12, 9, 6, 3});
        REQUIRE_FALSE(test.isEmpty());
        WHEN("We find 15 and insert 14 then it is after 15") {
            REQUIRE(test.find([](int val){ return val == 15;}));
            test.insert(14);
            test.reset();
            for (auto i: {3, 6, 9, 12, 15, 14, 18, 21}) {
                REQUIRE(test.next() == i);
            }
        }
        WHEN("We find the last item, then insert") {
            REQUIRE(test.find([](int val) { return val == 21; }));
            test.insert(23);
            test.reset();
            THEN("We have the new item as the last one") {
                for (auto i: {3,6,9,12,15,18,21,23}) {
                    REQUIRE(test.next() == i);
                }
            }
        }
        WHEN("We iterate the whole list and then insert") {
            test.reset();
            while (test.hasNext()) {
                test.next();
            }
            THEN("We expect an exception") {
                REQUIRE_THROWS_AS(test.insert(25), std::logic_error);
            }
            WHEN("We try to find the last item and then insert") {
                REQUIRE(test.find([](int val){ return val == 21;}));
                test.insert(26);
                
                THEN("We expect the new item to be at the end") {
                    test.reset();
                    for (auto i: {3,6,9,12,15,18,21,26}) {
                        REQUIRE(test.next() == i);
                    }
                }
            }
        }
        WHEN("We find an item, and insert multiple items") {
            REQUIRE(test.find([](int val) { return val == 15; }));
            test.insert(16);
            test.insert(17);
            THEN("We expect the list to contain the right entries") {
                test.reset();
                for (auto i: {3,6,9,12,15,17,16,18,21}) {
                    REQUIRE(test.next() == i);
                }
            }
        }
    }
}

TEST_CASE("test remove","[single_linked_list]") {
    GIVEN("An empty list") {
        experimental::SingleLinkedList<int> test;
        REQUIRE(test.isEmpty());
        THEN("Removing an item throws") {
            REQUIRE_THROWS_AS(test.remove(), std::logic_error);
        }
        THEN("Going to the beginning, still throws") {
            test.reset();
            REQUIRE_THROWS_AS(test.remove(), std::logic_error);
        }
    }
    GIVEN("A list of a single item") {
        experimental::SingleLinkedList<int> test({3});
        REQUIRE(!test.isEmpty());
        THEN("Removing an item throws") {
            REQUIRE_THROWS_AS(test.remove(), std::logic_error);
        }
        THEN("Going to the beginning and removing an item does not throw") {
            test.reset();
            test.remove();
            REQUIRE(test.isEmpty());
        }
    }
    GIVEN("A list with multiple items") {
        experimental::SingleLinkedList<int> test({3,4,5,6,7,8,9,10});
        REQUIRE(!test.isEmpty());
        THEN("Removing all the items work") {
            test.reset();
            while (test.hasNext()) {
                test.remove();
            }
            REQUIRE(test.isEmpty());
        }
        THEN("Removing 7 works") {
            REQUIRE(test.find([](int val){ return val == 7;}));
            test.remove();
            test.reset();
            for (auto item:{10,9,8,6,5,4,3}) {
                REQUIRE(test.next() == item);
            }
            REQUIRE_FALSE(test.hasNext());
        }
        THEN("Removing the first item works") {
            test.reset();
            test.remove();
            test.reset();
            for (auto item:{9,8,7,6,5,4,3}) {
                REQUIRE(test.next() == item);
            }
            REQUIRE_FALSE(test.hasNext());
        }
        THEN("Removing the last item works") {
            REQUIRE(test.find([](int val){ return val == 3; }));
            test.remove();
            test.reset();
            for (auto item:{10,9,8,7,6,5,4}) {
                REQUIRE(test.next() == item);
            }
            REQUIRE_FALSE(test.hasNext());
        }
    }
}

TEST_CASE("iterator","[single_linked_list]") {
    GIVEN("An empty list") {
        experimental::SingleLinkedList<int> test;
        REQUIRE(test.isEmpty());
        THEN("A loop will iterate over nothing") {
            for (auto item: test) {
                REQUIRE_FALSE(true);
            }
        }
        THEN("A for loop will iterator over nothing") {
            for (auto item = test.begin(); item != test.end(); item++) {
                REQUIRE_FALSE(true);
            }
        }
    }
    GIVEN("A list with one item") {
        experimental::SingleLinkedList<int> test({3});
        REQUIRE_FALSE(test.isEmpty());
        THEN("A loop will iterate over 1 item") {
            int count = 0;
            for (auto item: test) {
                count += 1;
            }
            REQUIRE(count == 1);
        }
        THEN("A for loop will iterate over 1 item") {
            int count = 0;
            for (auto item = test.begin(); item != test.end(); item++) {
                count += 1;
            }
            REQUIRE(count == 1);
        }
    }
    GIVEN("A list with multiple items") {
        std::initializer_list<int> param = {1,2,3,4,5,6,7,8,9,10};
        experimental::SingleLinkedList<int> test(param);
        REQUIRE_FALSE(test.isEmpty());
        THEN("A loop wil iterate over all items") {
            int count = 0;
            for (auto item: test) {
                count += 1;
            }
            REQUIRE(count == param.size());
        }
        THEN("A for loop will iterate over all items") {
            int count = 0;
            for (auto item = test.begin(); item != test.end(); item++) {
                count += 1;
            }
            REQUIRE(count == param.size());
        }
    }
}

