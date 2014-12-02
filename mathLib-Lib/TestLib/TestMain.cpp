#include <iostream>
#include "gtest\gtest.h";
#include "QuinnMathLibAll.h"

using namespace std;

TEST(sample_test_case, sample_test)
{
	EXPECT_EQ(1, 1);
}

int main(int argc, char** argv)
{

	testing::InitGoogleTest(&argc, argv);
	RUN_ALL_TESTS();
	std::getchar(); // keep console window open until Return keystroke
}