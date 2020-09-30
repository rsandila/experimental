//
//  test_mathvector.cpp
//  experimental
//
//  Created by Robert Sandilands on 9/28/20.
//  Copyright © 2020 Robert Sandilands. All rights reserved.
//
//  Check LICENSE file for License
#include "../3rdparty/Catch2/single_include/catch.hpp"
#include "../include/mathvector.hpp" 

TEST_CASE("Basic vector tests", "[math][vector]") {
	GIVEN("vector (1,2,3,4,5)") {
		experimental::MathVector<long> test1({ 1, 2, 3, 4, 5 });
		THEN("The list is 5 in size") {
			REQUIRE(test1.size() == 5);
		}
		WHEN("Accessing an out of bounds item") {
			REQUIRE_THROWS_AS(test1[5], std::out_of_range);
		}
		AND_THEN("The individual members have the right values") {
			REQUIRE(test1[0] == 1);
			REQUIRE(test1[1] == 2);
			REQUIRE(test1[2] == 3);
			REQUIRE(test1[3] == 4);
			REQUIRE(test1[4] == 5);
		}
		WHEN("Another vector (2,3,4,5,6)") {
			experimental::MathVector<long> test2({ 2,3,4,5,6 });
			REQUIRE(test2.size() == 5);
			THEN("Comparisons work as expected") {
				REQUIRE(test1 != test2);
				REQUIRE(test2 > test1);
				REQUIRE(test1 < test2);
			}
			AND_WHEN("Another vector (2,3,4,5,6") {
				experimental::MathVector<long> test3({ 2,3,4,5,6 });
				REQUIRE(test3.size() == 5);
				REQUIRE(test3 == test2);
			}
		}
	}
}
TEST_CASE("Vector addition/subtraction tests", "[math][vector]") {
	GIVEN("vector (10, 12, 16, 20, 24, 30)") {
		experimental::MathVector<double> testBase({ 10.0, 12.0, 16.0, 20.0, 24.0, 30.0 });
		REQUIRE(testBase.size() == 6);
		WHEN("Doing addition on a different sized vector") {
			experimental::MathVector<double> badSize({ 1, 2, 3 });
			REQUIRE_THROWS(testBase += badSize);
		}
		THEN("Adding a vector works") {
			experimental::MathVector<double> addBase({ -5.0, 3.0, 4.0, 1.0, 12.0, 30.0 });
			auto result1 = testBase + addBase;
			REQUIRE(result1.size() == 6);
			REQUIRE(result1[0] == 5.0);
			REQUIRE(result1[1] == 15.0);
			REQUIRE(result1[2] == 20.0);
			REQUIRE(result1[3] == 21.0);
			REQUIRE(result1[4] == 36.0);
			REQUIRE(result1[5] == 60.0);
			testBase += addBase;
			REQUIRE(testBase.size() == 6);
			REQUIRE(testBase[0] == 5.0);
			REQUIRE(testBase[1] == 15.0);
			REQUIRE(testBase[2] == 20.0);
			REQUIRE(testBase[3] == 21.0);
			REQUIRE(testBase[4] == 36.0);
			REQUIRE(testBase[5] == 60.0);
			REQUIRE(testBase == result1);
		}
		WHEN("Doing subtraction on a different sized vector") {
			experimental::MathVector<double> badSize({ 1, 2, 3 });
			REQUIRE_THROWS(testBase -= badSize);
		}
		THEN("Subtracting a vector works") {
			experimental::MathVector<double> addBase({ -5.0, 3.0, 4.0, 1.0, 12.0, 30.0 });
			auto result1 = testBase - addBase;
			REQUIRE(result1.size() == 6);
			REQUIRE(result1[0] == 15.0);
			REQUIRE(result1[1] == 9.0);
			REQUIRE(result1[2] == 12.0);
			REQUIRE(result1[3] == 19.0);
			REQUIRE(result1[4] == 12.0);
			REQUIRE(result1[5] == 0.0);
			testBase -= addBase;
			REQUIRE(testBase.size() == 6);
			REQUIRE(testBase[0] == 15.0);
			REQUIRE(testBase[1] == 9.0);
			REQUIRE(testBase[2] == 12.0);
			REQUIRE(testBase[3] == 19.0);
			REQUIRE(testBase[4] == 12.0);
			REQUIRE(testBase[5] == 0.0);
			REQUIRE(testBase == result1);
		}
	}
}
TEST_CASE("Vector magnitude tests", "[math][vector]") {
	GIVEN("vector (10, 12, 16, 20, 24, 30)") {
		experimental::MathVector<double> testBase({ 10.0, 12.0, 16.0, 20.0, 24.0, 30.0 });
		REQUIRE(testBase.magnitude() == Approx(48.744230427815762162759301409596));
	}
}
TEST_CASE("Vector multiplication", "[math][vector]") {
	GIVEN("vector (10, 12, 16, 20, 24, 30)") {
		experimental::MathVector<double> testBase({ 10.0, 12.0, 16.0, 20.0, 24.0, 30.0 });
		WHEN("We multiply by 2") {
			auto result1 = testBase * 2;
			testBase *= 2;
			THEN("result is (20, 24, 32, 40, 48, 60)") {
				experimental::MathVector<double> expected({ 20, 24, 32, 40, 48, 60 });
				REQUIRE(testBase == expected);
				REQUIRE(result1 == expected);
			}
		}
		WHEN("We multiple by a different sized vector") {
			experimental::MathVector<double> wrongSize({ 2,3 });
			REQUIRE_THROWS(testBase * wrongSize);
		}
		WHEN("We multiply by (2, 2, 2, 2, 2, 2)") {
			experimental::MathVector<double> multiplier({ 2, 2, 2, 2, 2, 2 });
			REQUIRE(testBase * multiplier == 224);			
		}
	}
}
