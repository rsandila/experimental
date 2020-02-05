//
//  test_skiplist.cpp
//  experimental
//
//  Created by Robert Sandilands on 1/28/2020.
//  Copyright © 2020 Robert Sandilands. All rights reserved.
//
//  Check LICENSE file for License
#include "../3rdparty/Catch2/single_include/catch.hpp"
#include "../include/skiplist.hpp"

TEST_CASE("Empty skip list tests", "[skiplist]") {
	GIVEN("An empty list") {
		experimental::SkipList<int> list;
		REQUIRE(list.isEmpty());
		WHEN("An item is added") {
			list.add(10);
			THEN("The list is no longer empty") {
				REQUIRE_FALSE(list.isEmpty());
			}
			WHEN("Multiple items are added") {
				std::default_random_engine generator;
				std::uniform_int_distribution<int> distribution;
				std::vector<int> expected_order;
				expected_order.push_back(10);
				for (int i = 0; i < 1000; i++) {
					auto number = distribution(generator);
					list.add(number);
					expected_order.push_back(number);
				}
				std::sort(expected_order.begin(), expected_order.end());
				THEN("The list is in sorted order") {
					unsigned expectedOffset = 0;
					for (auto it : list) {
						REQUIRE(expected_order[expectedOffset] == it);
						expectedOffset += 1;
					}
					AND_THEN("We iterated all the items") {
						REQUIRE(expectedOffset == expected_order.size());
					}
				}
				AND_THEN("We can find all the items") {
					for (auto expectedIt : expected_order) {
						auto it = list.find(expectedIt);
						REQUIRE(it != list.end());
						REQUIRE(it != list.begin());
						REQUIRE(expectedIt == *it);
					}
				}
				AND_THEN("We don't find an item that is not there") {
					int missingNumber;
					do {
						missingNumber = distribution(generator);
					} while (std::find(expected_order.begin(), expected_order.end(), missingNumber) != expected_order.end());
					auto it = list.find(missingNumber);
					REQUIRE(it == list.end());
					REQUIRE(it != list.begin());
					REQUIRE(missingNumber != *it);
				}
				AND_THEN("We don't find a very small item") {
					auto it = list.find(expected_order[0]-1);
					REQUIRE(it == list.end());
					REQUIRE(it != list.begin());
					REQUIRE((expected_order[0] - 1) != *it);
				}
				AND_THEN("We don't find a very large item") {
					auto it = list.find(expected_order[expected_order.size()-1]+1);
					REQUIRE(it == list.end());
					REQUIRE(it != list.begin());
					REQUIRE((expected_order[expected_order.size() - 1] + 1) != *it);
				}
			}
		}
	}
}