//#include "stdafx.h"
#include <iostream>
#include "gtest/gtest.h"
#include "QuinnMathLibAll.h"
#include "General.cpp"
#include "Vector2.cpp";
#include "Vector3.cpp";

//General class test
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

//vector2 testing
TEST(Vector2_test, op_equal) {
	EXPECT_TRUE(Vector2(1, 1) == Vector2(1, 1));
	EXPECT_FALSE(Vector2(1, 2) == Vector2(3, 4));
}

TEST(Vector2_test, op_not_equal) {
	EXPECT_TRUE(Vector2(1, 2) != Vector2(3, 4));
	EXPECT_FALSE(Vector2(1, 1) != Vector2(1, 1));
}

TEST(Vector2_test, DotProduct_inst) {
	EXPECT_FLOAT_EQ(0, Vector2(0, 0).DotProduct(Vector2(0, 0)));
	EXPECT_FLOAT_EQ(0, Vector2(1, 1).DotProduct(Vector2(0, 0)));
	EXPECT_FLOAT_EQ(0, Vector2(0, 0).DotProduct(Vector2(1, 1)));
	EXPECT_FLOAT_EQ(11, Vector2(1, 2).DotProduct(Vector2(3, 4)));
	EXPECT_FLOAT_EQ(11, Vector2(4, 3).DotProduct(Vector2(2, 1)));
	EXPECT_FLOAT_EQ(-5, Vector2(1, -2).DotProduct(Vector2(3, 4)));
	EXPECT_FLOAT_EQ(5, Vector2(4, 3).DotProduct(Vector2(2, -1)));
}

TEST(Vector2_test, DotProduct_static) {
	EXPECT_FLOAT_EQ(0, Vector2::DotProduct(Vector2(0, 0), Vector2(0, 0)));
	EXPECT_FLOAT_EQ(0, Vector2::DotProduct(Vector2(1, 1), Vector2(0, 0)));
	EXPECT_FLOAT_EQ(0, Vector2::DotProduct(Vector2(0, 0), Vector2(1, 1)));
	EXPECT_FLOAT_EQ(11, Vector2::DotProduct(Vector2(1, 2), Vector2(3, 4)));
	EXPECT_FLOAT_EQ(11, Vector2::DotProduct(Vector2(4, 3), Vector2(2, 1)));
	EXPECT_FLOAT_EQ(-5, Vector2::DotProduct(Vector2(1, -2), Vector2(3, 4)));
	EXPECT_FLOAT_EQ(5, Vector2::DotProduct(Vector2(4, 3), Vector2(2, -1)));
}

TEST(Vector2_test, CrossProduct_inst) {
	EXPECT_EQ(Vector2(0, 0), Vector2(0, 0).CrossProduct(Vector2(0, 0)));
	EXPECT_EQ(Vector2(0, 0), Vector2(1, 1).CrossProduct(Vector2(0, 0)));
	EXPECT_EQ(Vector2(1, -1), Vector2(0, 0).CrossProduct(Vector2(1, 1)));
	EXPECT_EQ(Vector2(4, -3), Vector2(1, 2).CrossProduct(Vector2(3, 4)));
	EXPECT_EQ(Vector2(-4, -3), Vector2(1, 2).CrossProduct(Vector2(3, -4)));
	EXPECT_EQ(Vector2(4, 3), Vector2(1, 2).CrossProduct(Vector2(-3, 4)));
}

TEST(Vector2_test, CrossProduct_static) {
	EXPECT_EQ(Vector2(0, 0), Vector2::CrossProduct(Vector2(0, 0), Vector2(0, 0)));
	EXPECT_EQ(Vector2(0, 0), Vector2::CrossProduct(Vector2(1, 1), Vector2(0, 0)));
	EXPECT_EQ(Vector2(1, -1), Vector2::CrossProduct(Vector2(0, 0), Vector2(1, 1)));
	EXPECT_EQ(Vector2(4, -3), Vector2::CrossProduct(Vector2(5, 6), Vector2(3, 4)));
	EXPECT_EQ(Vector2(-4, -3), Vector2::CrossProduct(Vector2(5, 6), Vector2(3, -4)));
	EXPECT_EQ(Vector2(4, 3), Vector2::CrossProduct(Vector2(5, 6), Vector2(-3, 4)));
}

TEST(Vector2_test, Magnitude_inst) {
	EXPECT_FLOAT_EQ(0, Vector2(0, 0).Magnitude());
	EXPECT_FLOAT_EQ(1, Vector2(1, 0).Magnitude());
	EXPECT_FLOAT_EQ(1, Vector2(0, 1).Magnitude());
	EXPECT_FLOAT_EQ(1, Vector2(0, -1).Magnitude());
	EXPECT_FLOAT_EQ(1, Vector2(-1, 0).Magnitude());
	EXPECT_FLOAT_EQ(sqrt(2.f), Vector2(1, 1).Magnitude());
	EXPECT_FLOAT_EQ(sqrt(2.f), Vector2(1, -1).Magnitude());
}

TEST(Vector2_test, Magnitude_static) {
	EXPECT_FLOAT_EQ(0, Vector2::Magnitude(Vector2(0, 0)));
	EXPECT_FLOAT_EQ(1, Vector2::Magnitude(Vector2(1, 0)));
	EXPECT_FLOAT_EQ(1, Vector2::Magnitude(Vector2(0, 1)));
	EXPECT_FLOAT_EQ(1, Vector2::Magnitude(Vector2(0, -1)));
	EXPECT_FLOAT_EQ(1, Vector2::Magnitude(Vector2(-1, 0)));
	EXPECT_FLOAT_EQ(sqrt(2.f), Vector2::Magnitude(Vector2(1, 1)));
	EXPECT_FLOAT_EQ(sqrt(2.f), Vector2::Magnitude(Vector2(1, -1)));
}

TEST(Vector2_test, Normalize_inst) {
	EXPECT_EQ(Vector2(0, 0), Vector2(0, 0).Normalize());
	EXPECT_EQ(Vector2(0.707106769, 0.707106769), Vector2(2, 2).Normalize());
	EXPECT_EQ(Vector2(1, 0), Vector2(2, 0).Normalize());
	EXPECT_EQ(Vector2(0, 1), Vector2(0, 2).Normalize());
	EXPECT_EQ(Vector2(-1, 0), Vector2(-2, 0).Normalize());
	EXPECT_EQ(Vector2(0, -1), Vector2(0, -2).Normalize());
}

TEST(Vector2_test, Normalize_static) {
	EXPECT_EQ(Vector2(0, 0), Vector2::Normalize(Vector2(0, 0)));
	EXPECT_EQ(Vector2(0.707106769, 0.707106769), Vector2::Normalize(Vector2(2, 2)));
	EXPECT_EQ(Vector2(1, 0), Vector2::Normalize(Vector2(2, 0)));
	EXPECT_EQ(Vector2(0, 1), Vector2::Normalize(Vector2(0, 2)));
	EXPECT_EQ(Vector2(-1, 0), Vector2::Normalize(Vector2(-2, 0)));
	EXPECT_EQ(Vector2(0, -1), Vector2::Normalize(Vector2(0, -2)));
}

TEST(Vector2_test, NormalizeThis_) {
	Vector2 temp = Vector2();
	temp.NormalizeThis();
	EXPECT_EQ(Vector2(0, 0), temp);
	temp = Vector2(2, 2);
	temp.NormalizeThis();
	EXPECT_EQ(Vector2(0.707106769, 0.707106769), temp);
	temp = Vector2(2, 0);
	temp.NormalizeThis();
	EXPECT_EQ(Vector2(1, 0), temp);
	temp = Vector2(0, 2);
	temp.NormalizeThis();
	EXPECT_EQ(Vector2(0, 1), temp);
	temp = Vector2(-2, 0);
	temp.NormalizeThis();
	EXPECT_EQ(Vector2(-1, 0), temp);
	temp = Vector2(0, -2);
	temp.NormalizeThis();
	EXPECT_EQ(Vector2(0, -1), temp);
}

TEST(Vector2_test, Lerp_inst) {
	EXPECT_EQ(Vector2(0, 0), Vector2(0, 0).Lerp(Vector2(0, 0), 0));
	EXPECT_EQ(Vector2(1, 1), Vector2(0, 0).Lerp(Vector2(2, 2), .5));
	EXPECT_EQ(Vector2(3, 3), Vector2(2, 2).Lerp(Vector2(4, 4), .5));
	EXPECT_EQ(Vector2(1, 1), Vector2(2, 0).Lerp(Vector2(0, 2), .5));
	EXPECT_EQ(Vector2(5, 7), Vector2(5, 7).Lerp(Vector2(9, 9), 0));
	EXPECT_EQ(Vector2(9, 9), Vector2(5, 7).Lerp(Vector2(9, 9), 1));
	EXPECT_EQ(Vector2(0, 0), Vector2(1, 1).Lerp(Vector2(-1, -1), .5));
	EXPECT_EQ(Vector2(0, 0), Vector2(-1, -1).Lerp(Vector2(1, 1), .5));
}

TEST(Vector2_test, Lerp_static) {
	EXPECT_EQ(Vector2(0, 0), Vector2::Lerp(Vector2(0, 0), Vector2(0, 0), 0));
	EXPECT_EQ(Vector2(1, 1), Vector2::Lerp(Vector2(0, 0), Vector2(2, 2), .5));
	EXPECT_EQ(Vector2(3, 3), Vector2::Lerp(Vector2(2, 2), Vector2(4, 4), .5));
	EXPECT_EQ(Vector2(1, 1), Vector2::Lerp(Vector2(2, 0), Vector2(0, 2), .5));
	EXPECT_EQ(Vector2(5, 7), Vector2::Lerp(Vector2(5, 7), Vector2(9, 9), 0));
	EXPECT_EQ(Vector2(9, 9), Vector2::Lerp(Vector2(5, 7), Vector2(9, 9), 1));
	EXPECT_EQ(Vector2(0, 0), Vector2::Lerp(Vector2(1, 1), Vector2(-1, -1), .5));
	EXPECT_EQ(Vector2(0, 0), Vector2::Lerp(Vector2(-1, -1), Vector2(1, 1), .5));
}

//Vector3 test
TEST(Vector3_test, op_equal) {
	EXPECT_TRUE(Vector3(1, 2, 3) == Vector3(1, 2, 3));
	EXPECT_FALSE(Vector3(1, 2, 3) == Vector3(4, 5, 6));
}

TEST(Vector3_test, op_not_equal) {
	EXPECT_TRUE(Vector3(1, 2, 3) != Vector3(4, 5, 6));
	EXPECT_FALSE(Vector3(1, 2, 3) != Vector3(1, 2, 3));
}

TEST(Vector3_test, DotProduct_inst) {
	EXPECT_FLOAT_EQ(0, Vector3(0, 0, 0).DotProduct(Vector3(0, 0, 0)));
	EXPECT_FLOAT_EQ(3, Vector3(1, 1, 1).DotProduct(Vector3(1, 1, 1)));
}

int main(int argc, char** argv)
{
	testing::InitGoogleTest(&argc, argv);
	RUN_ALL_TESTS();
	std::getchar(); // keep console window open until Return keystroke
}