//#include "stdafx.h"
#include <iostream>
#include "gtest/gtest.h"
#include "QuinnMathLibAll.h"
#include "General.cpp"

TEST(General_Functions_test, To_Degrees)
{
	EXPECT_FLOAT_EQ(0, General::ToDegrees(0));
	EXPECT_FLOAT_EQ(57.2957802, General::ToDegrees(1));
	EXPECT_FLOAT_EQ(114.591559, General::ToDegrees(2));
	EXPECT_FLOAT_EQ(171.887339, General::ToDegrees(3));
	EXPECT_FLOAT_EQ(-114.591559, General::ToDegrees(-2));
}

TEST(General_Functions_test, To_Radians)
{
	EXPECT_FLOAT_EQ(0, General::ToDegrees(0));
	EXPECT_FLOAT_EQ(0.0174532925, General::ToRadians(1));
	EXPECT_FLOAT_EQ(0.174532925, General::ToRadians(10));
	EXPECT_FLOAT_EQ(1.74532925, General::ToRadians(100));
	EXPECT_FLOAT_EQ(-0.174532925, General::ToRadians(-10));
}

TEST(General_Functions_test, Lerp_positives)
{
	EXPECT_FLOAT_EQ(5, General::Lerp(0, 10, .5));
	EXPECT_FLOAT_EQ(19, General::Lerp(10, 20, .9));
	EXPECT_FLOAT_EQ(10, General::Lerp(0, 10, 1));
}

TEST(General_Functions_test, Lerp_negitives)
{
	EXPECT_FLOAT_EQ(0, General::Lerp(-10, 10, .5));
	EXPECT_FLOAT_EQ(-11, General::Lerp(-20, -10, .9));
	EXPECT_FLOAT_EQ(0, General::Lerp(-2, 0, 1));
}

TEST(General_Functions_test, Lerp_edgecases)
{
	EXPECT_FLOAT_EQ(0, General::Lerp(0, 10, 0));
	EXPECT_FLOAT_EQ(10, General::Lerp(0, 10, 1));
	EXPECT_FLOAT_EQ(0, General::Lerp(-2, 0, 1));
	EXPECT_FLOAT_EQ(0, General::Lerp(0, 0, 0));
	EXPECT_FLOAT_EQ(1, General::Lerp(1, 1, 1));
}

TEST(General_Functions_test, Lerp_badInput)
{
	EXPECT_FLOAT_EQ(-1, General::Lerp(0, -10, .5));
	EXPECT_FLOAT_EQ(-1, General::Lerp(0, 10, -1));
}

TEST(General_Functions_test, ShiftPowOfTwo_valid)
{
	EXPECT_FLOAT_EQ(2, General::ShiftPowOfTwo(1));
	EXPECT_FLOAT_EQ(2, General::ShiftPowOfTwo(2));
	EXPECT_FLOAT_EQ(2, General::ShiftPowOfTwo(3));
	EXPECT_FLOAT_EQ(4, General::ShiftPowOfTwo(4));
	EXPECT_FLOAT_EQ(4, General::ShiftPowOfTwo(5));
}

TEST(General_Functions_test, ShiftPowOfTwo_invalid)
{
	EXPECT_FLOAT_EQ(-1, General::ShiftPowOfTwo(-1));
	EXPECT_FLOAT_EQ(-1, General::ShiftPowOfTwo(-2));
	EXPECT_FLOAT_EQ(-1, General::ShiftPowOfTwo(0));
}

int main(int argc, char** argv)
{
	testing::InitGoogleTest(&argc, argv);
	RUN_ALL_TESTS();
	std::getchar(); // keep console window open until Return keystroke
}