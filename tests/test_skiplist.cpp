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
			list.add(5);
			list.add(7);
			list.add(6);
			list.add(2);
			list.add(20);			
			list.add(-1);
		}
	}
}