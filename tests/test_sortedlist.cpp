//
//  test_sortedlist.cpp
//  experimental
//
//  Created by Robert Sandilands on 1/16/20.
//  Copyright © 2020 Robert Sandilands. All rights reserved.
//
//  Check LICENSE file for License

#include "../3rdparty/Catch2/single_include/catch.hpp"
#include "../include/sortedlist.hpp"

TEST_CASE("Empty sorted list tests", "[sorted_list]") {
    GIVEN("An empty list") {
        experimental::SortedList<int> test;
        REQUIRE(test.empty());
        REQUIRE(test.end() != test.begin());
        REQUIRE(test.end() == test.end());
        REQUIRE(test.begin() == test.begin());
        WHEN("An item is added") {
            test.add(10);
            THEN("The list is no longer empty") {
                REQUIRE_FALSE(test.empty());
            }
            AND_THEN("We can retrieve the item") {
                REQUIRE(10 == test[0]);
            }
        }
        WHEN("That initial entry is removed") {
            test.add(10);
            test.remove(test.begin());
            THEN("The list is empty") {
                REQUIRE(test.empty());
            }
        }
        WHEN("We add two entries (10, 5)") {
            test.add(10);
            test.add(5);
            THEN("The list must have 2 entries") {
                REQUIRE(2 == test.size());
            }
            AND_THEN("The first entry must be 5") {
                REQUIRE(5 == test[0]);
            }
            AND_THEN("The second entry must be 10") {
                REQUIRE(10 == test[1]);
            }
        }
        WHEN("We add two entries (10, 20)") {
            test.add(10);
            test.add(20);
            THEN("Iterator math should make a little sense") {
                auto begin = test.begin();
                auto two = test.begin();
                begin += 1;
                REQUIRE(begin == (two + 1));
                REQUIRE(test.begin() == two);
                REQUIRE(begin - 1 == test.begin());
                REQUIRE(begin != test.begin());
                begin -= 1;
                REQUIRE(begin == test.begin());
            }
            THEN("The list must have 2 entries") {
                REQUIRE(2 == test.size());
            }
            AND_THEN("The first entry must be 10") {
                REQUIRE(10 == test[0]);
            }
            AND_THEN("The second entry must be 20") {
                REQUIRE(20 == test[1]);
            }        
        }
        WHEN("We add 10 entries (5, 4, 3, 2, 1, 6, 7, 8, 9, 0") {
            test.add(5);
            test.add(4);
            test.add(3);
            test.add(2);
            test.add(1);
            test.add(6);
            test.add(7);
            test.add(8);
            test.add(9);
            test.add(0);
            THEN("The list must have 10 entries") {
                REQUIRE(10 == test.size());
            }
            AND_THEN("All the values should match 0...9") {
                for (int i = 0; i < 10; i++) {
                    REQUIRE(i == test[i]);
                }
            }
        }
        WHEN("We add 10 entries 0..9") {
            for (int i = 0; i < 10; i++) {
                test.add(i);
            }
            THEN("The list must have 10 entries") {
                REQUIRE(10 == test.size());
            }
            AND_THEN("All the values should match 0...9") {
                for (int i = 0; i < 10; i++) {
                    REQUIRE(i == test[i]);
                }
            }            
        }
        WHEN("We add 10 entries 9..0") {
            for (int i = 0; i < 10; i++) {
                test.add(9-i);
            }
            THEN("The list must have 10 entries") {
                REQUIRE(10 == test.size());
            }
            AND_THEN("All the values should match 0...9") {
                for (int i = 0; i < 10; i++) {
                    REQUIRE(i == test[i]);
                }
            }            
        }
    }
}
TEST_CASE("Sorted list with some entries", "[sorted_list]") {
    GIVEN("A list with 100 entries") {
        experimental::SortedList<int> test;
        REQUIRE(test.empty());
        for (auto i = 0; i < 100; i++) {
            test.add(99 - i);
        }
        REQUIRE(100 == test.size());
        for (auto i = 0; i < 100; i++) {
            REQUIRE(i == test[i]);
        }
        WHEN("We try to find an item not in the list") {
            THEN("The result should be the end() iterator") {
                auto result = test.find(1000);
                REQUIRE(test.end() == result);
            }
        }
        WHEN("We try to find a second item not in the list") {
            THEN("The result should be the end() iterator") {
                auto result = test.find(-1);
                REQUIRE(test.end() == result);
            }
        }
        WHEN("We try to find an item that is actually on the list") {
            THEN("The result should point to that value") {
                auto result = test.find(45);
                REQUIRE(test.end() != result);
                REQUIRE(*result == 45);
                WHEN("We remove the item we found") {
                    test.remove(result);
                    THEN("The list should be 1 smaller") {
                        REQUIRE(99 == test.size());
                    }
                    AND_THEN("We should not be able to find it") {
                        auto result2 = test.find(45);
                        REQUIRE(test.end() == result2);
                    }
                }                

            }
        }
    }
}