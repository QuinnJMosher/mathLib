//#include "stdafx.h"
#include <iostream>
#include "gtest/gtest.h"
#include "QuinnMathLibAll.h"
#include "General.cpp"
#include "Vector2.cpp";
#include "Vector3.cpp";
#include "Vector4.cpp";
#include "Matrix3.cpp";
#include "Matrix4.cpp";

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
	EXPECT_FLOAT_EQ(32, Vector3(1, 2, 3).DotProduct(Vector3(4, 5, 6)));
	EXPECT_FLOAT_EQ(32, Vector3(-1, -2, -3).DotProduct(Vector3(-4, -5, -6)));
	EXPECT_FLOAT_EQ(-32, Vector3(1, 2, 3).DotProduct(Vector3(-4, -5, -6)));
}

TEST(Vector3_test, DotProduct_static) {
	EXPECT_FLOAT_EQ(0, Vector3::DotProduct(Vector3(0, 0, 0), Vector3(0, 0, 0)));
	EXPECT_FLOAT_EQ(3, Vector3::DotProduct(Vector3(1, 1, 1), Vector3(1, 1, 1)));
	EXPECT_FLOAT_EQ(32, Vector3::DotProduct(Vector3(4, 5, 6), Vector3(1, 2, 3)));
	EXPECT_FLOAT_EQ(32, Vector3::DotProduct(Vector3(-4, -5, -6), Vector3(-1, -2, -3)));
	EXPECT_FLOAT_EQ(-32, Vector3::DotProduct(Vector3(-4, -5, -6), Vector3(1, 2, 3)));
}

TEST(Vector3_test, CrossProduct_inst) {
	EXPECT_EQ(Vector3(0, 0, 0), Vector3(0, 0, 0).CrossProduct(Vector3(0, 0, 0)));
	EXPECT_EQ(Vector3(-3, 6, -3), Vector3(1, 2, 3).CrossProduct(Vector3(4, 5, 6)));
	EXPECT_EQ(Vector3(-3, 6, -3), Vector3(-1, -2, -3).CrossProduct(Vector3(-4, -5, -6)));
	EXPECT_EQ(Vector3(-3, -6, -3), Vector3(1, -2, 3).CrossProduct(Vector3(-4, 5, -6)));
}

TEST(Vector3_test, CrossProduct_static) {
	EXPECT_EQ(Vector3(0, 0, 0), Vector3::CrossProduct(Vector3(0, 0, 0), Vector3(0, 0, 0)));
	EXPECT_EQ(Vector3(3, -6, 3), Vector3::CrossProduct(Vector3(4, 5, 6), Vector3(1, 2, 3)));
	EXPECT_EQ(Vector3(3, -6, 3), Vector3::CrossProduct(Vector3(-4, -5, -6), Vector3(-1, -2, -3)));
	EXPECT_EQ(Vector3(3, 6, 3), Vector3::CrossProduct(Vector3(-4, 5, -6), Vector3(1, -2, 3)));
}

TEST(Vector3_test, Magnitude_inst) {
	EXPECT_FLOAT_EQ(0, Vector3(0, 0, 0).Magnitude());
	EXPECT_FLOAT_EQ(1, Vector3(1, 0, 0).Magnitude());
	EXPECT_FLOAT_EQ(1, Vector3(0, 1, 0).Magnitude());
	EXPECT_FLOAT_EQ(1, Vector3(0, 0, 1).Magnitude());
	EXPECT_FLOAT_EQ(2, Vector3(0, 0, 2).Magnitude());
	EXPECT_FLOAT_EQ(1, Vector3(0, 0, -1).Magnitude());
	EXPECT_FLOAT_EQ(1.4142135, Vector3(0, 1, 1).Magnitude());
	EXPECT_FLOAT_EQ(1.4142135, Vector3(1, 0, -1).Magnitude());
	EXPECT_FLOAT_EQ(1.7320508, Vector3(1, 1, 1).Magnitude());
}

TEST(Vector3_test, Magnitude_static) {
	EXPECT_FLOAT_EQ(0, Vector3::Magnitude(Vector3(0, 0, 0)));
	EXPECT_FLOAT_EQ(1, Vector3::Magnitude(Vector3(1, 0, 0)));
	EXPECT_FLOAT_EQ(1, Vector3::Magnitude(Vector3(0, 1, 0)));
	EXPECT_FLOAT_EQ(1, Vector3::Magnitude(Vector3(0, 0, 1)));
	EXPECT_FLOAT_EQ(2, Vector3::Magnitude(Vector3(0, 0, 2)));
	EXPECT_FLOAT_EQ(1, Vector3::Magnitude(Vector3(0, 0, -1)));
	EXPECT_FLOAT_EQ(1.4142135, Vector3::Magnitude(Vector3(0, 1, 1)));
	EXPECT_FLOAT_EQ(1.4142135, Vector3::Magnitude(Vector3(1, 0, -1)));
	EXPECT_FLOAT_EQ(1.7320508, Vector3::Magnitude(Vector3(1, 1, 1)));
}

TEST(Vector3_test, Normalize_inst) {
	EXPECT_EQ(Vector3(0, 0, 0), Vector3(0, 0, 0).Normalize());
	EXPECT_EQ(Vector3(1, 0, 0), Vector3(2, 0, 0).Normalize());
	EXPECT_EQ(Vector3(0, 1, 0), Vector3(0, 3, 0).Normalize());
	EXPECT_EQ(Vector3(0, 0, 1), Vector3(0, 0, 4).Normalize());
	EXPECT_EQ(Vector3(0, 0, -1), Vector3(0, 0, -5).Normalize());
	EXPECT_EQ(Vector3(0, 0.707107, 0.707107), Vector3(0, 2, 2).Normalize());
	EXPECT_EQ(Vector3(0, 0.707107, -0.707107), Vector3(0, 2, -2).Normalize());
	EXPECT_EQ(Vector3(0, 0.447214, 0.894427), Vector3(0, 2, 4).Normalize());
}

TEST(Vector3_test, Normalize_static) {
	EXPECT_EQ(Vector3(0, 0, 0), Vector3::Normalize(Vector3(0, 0, 0)));
	EXPECT_EQ(Vector3(1, 0, 0), Vector3::Normalize(Vector3(2, 0, 0)));
	EXPECT_EQ(Vector3(0, 1, 0), Vector3::Normalize(Vector3(0, 3, 0)));
	EXPECT_EQ(Vector3(0, 0, 1), Vector3::Normalize(Vector3(0, 0, 4)));
	EXPECT_EQ(Vector3(0, 0, -1), Vector3::Normalize(Vector3(0, 0, -5)));
	EXPECT_EQ(Vector3(0, 0.707107, 0.707107), Vector3::Normalize(Vector3(0, 2, 2)));
	EXPECT_EQ(Vector3(0, 0.707107, -0.707107), Vector3::Normalize(Vector3(0, 2, -2)));
	EXPECT_EQ(Vector3(0, 0.447214, 0.894427), Vector3::Normalize(Vector3(0, 2, 4)));
}

TEST(Vector3_test, NormalizeThis_) {
	Vector3 temp = Vector3(0, 0, 0);
	temp.NormalizeThis();
	EXPECT_EQ(Vector3(0, 0, 0), temp);
	temp = Vector3(2, 0, 0);
	temp.NormalizeThis();
	EXPECT_EQ(Vector3(1, 0, 0), temp);
	temp = Vector3(0, 3, 0);
	temp.NormalizeThis();
	EXPECT_EQ(Vector3(0, 1, 0), temp);
	temp = Vector3(0, 0, 4);
	temp.NormalizeThis();
	EXPECT_EQ(Vector3(0, 0, 1), temp);
	temp = Vector3(0, 0, -5);
	temp.NormalizeThis();
	EXPECT_EQ(Vector3(0, 0, -1), temp);
	temp = Vector3(0, 2, 2);
	temp.NormalizeThis();
	EXPECT_EQ(Vector3(0, 0.707107, 0.707107), temp);
	temp = Vector3(0, 2, -2);
	temp.NormalizeThis();
	EXPECT_EQ(Vector3(0, 0.707107, -0.707107), temp);
	temp = Vector3(0, 2, 4);
	temp.NormalizeThis();
	EXPECT_EQ(Vector3(0, 0.447214, 0.894427), temp);
}

TEST(Vector3_test, Lerp_inst) {
	EXPECT_EQ(Vector3(0, 0, 0), Vector3(0, 0, 0).Lerp(Vector3(0, 0, 0), 0));
	EXPECT_EQ(Vector3(0.5, 0.5, 0.5), Vector3(0, 0, 0).Lerp(Vector3(1, 1, 1), 0.5));
	EXPECT_EQ(Vector3(0.5, 0.5, 1), Vector3(0, 0, 0).Lerp(Vector3(1, 1, 2), 0.5));
	EXPECT_EQ(Vector3(0.5, 1, 1.5), Vector3(0, 0, 0).Lerp(Vector3(1, 2, 3), 0.5));
	EXPECT_EQ(Vector3(0, 0, 0), Vector3(-1, -1, -1).Lerp(Vector3(1, 1, 1), 0.5));
	EXPECT_EQ(Vector3(0.7, 0.7, 0.7), Vector3(0, 0, 0).Lerp(Vector3(1, 1, 1), 0.7));
	EXPECT_EQ(Vector3(0.5, 0.5, 0.5), Vector3(1, 1, 1).Lerp(Vector3(0, 0, 0), 0.5));
	EXPECT_EQ(Vector3(1, 2, 3), Vector3(0, 0, 0).Lerp(Vector3(1, 2, 3), 1));

}

TEST(Vector3_test, Lerp_static) {
	EXPECT_EQ(Vector3(0, 0, 0), Vector3::Lerp(Vector3(0, 0, 0), Vector3(0, 0, 0), 0));
	EXPECT_EQ(Vector3(0.5, 0.5, 0.5), Vector3::Lerp(Vector3(0, 0, 0), Vector3(1, 1, 1), 0.5));
	EXPECT_EQ(Vector3(0.5, 0.5, 1), Vector3::Lerp(Vector3(0, 0, 0), Vector3(1, 1, 2), 0.5));
	EXPECT_EQ(Vector3(0.5, 1, 1.5), Vector3::Lerp(Vector3(0, 0, 0), Vector3(1, 2, 3), 0.5));
	EXPECT_EQ(Vector3(0, 0, 0), Vector3::Lerp(Vector3(-1, -1, -1), Vector3(1, 1, 1), 0.5));
	EXPECT_EQ(Vector3(0.7, 0.7, 0.7), Vector3::Lerp(Vector3(0, 0, 0), Vector3(1, 1, 1), 0.7));
	EXPECT_EQ(Vector3(0.5, 0.5, 0.5), Vector3::Lerp(Vector3(1, 1, 1), Vector3(0, 0, 0), 0.5));
	EXPECT_EQ(Vector3(1, 2, 3), Vector3::Lerp(Vector3(0, 0, 0), Vector3(1, 2, 3), 1));
}

//vector 4 tests
TEST(Vector4_test, op_equal) {
	EXPECT_TRUE(Vector4(1, 2, 3, 4) == Vector4(1, 2, 3, 4));
	EXPECT_FALSE(Vector4(1, 2, 3, 4) == Vector4(5, 6, 7, 8));
}

TEST(Vector4_test, op_not_equal) {
	EXPECT_FALSE(Vector4(1, 2, 3, 4) != Vector4(1, 2, 3, 4));
	EXPECT_TRUE(Vector4(1, 2, 3, 4) != Vector4(5, 6, 7, 8));
}

TEST(Vector4_test, constructFromColor_4_floats) {
	EXPECT_EQ(Vector4(0,0,0,0), Vector4::ConstructFromColor(0, 0, 0, 0));
	EXPECT_EQ(Vector4(10.f/255, 20.f/255, 30.f/255, 40.f/255), Vector4::ConstructFromColor(10, 20, 30, 40));
	EXPECT_EQ(Vector4(0, 0, 0, 0), Vector4::ConstructFromColor(10, 20, -30, 40));
}

TEST(Vector4_test, constructFromColor_hex_number) {
	EXPECT_EQ(Vector4(0, 0, 0, 0), Vector4::ConstructFromColor(0x00000000));
	EXPECT_EQ(Vector4(1.f / 255, 2.f / 255, 3.f / 255, 4.f / 255), Vector4::ConstructFromColor(0x01020304));
}

TEST(Vector4_test, magnitude_inst) {
	EXPECT_FLOAT_EQ(0, Vector4(0, 0, 0, 0).Magnitude());
	EXPECT_FLOAT_EQ(2, Vector4(1, 1, -1, -1).Magnitude());
	EXPECT_FLOAT_EQ(2, Vector4(1, 1, 1, 1).Magnitude());
	EXPECT_FLOAT_EQ(2, Vector4(-1, -1, -1, -1).Magnitude());
	EXPECT_FLOAT_EQ(2, Vector4(0, 0, 0, 2).Magnitude());
	
}

TEST(Vector4_test, magnitude_static) {
	EXPECT_FLOAT_EQ(0, Vector4::Magnitude(Vector4(0, 0, 0, 0)));
	EXPECT_FLOAT_EQ(2, Vector4::Magnitude(Vector4(1, 1, -1, -1)));
	EXPECT_FLOAT_EQ(2, Vector4::Magnitude(Vector4(1, 1, 1, 1)));
	EXPECT_FLOAT_EQ(2, Vector4::Magnitude(Vector4(-1, -1, -1, -1)));
	EXPECT_FLOAT_EQ(2, Vector4::Magnitude(Vector4(0, 0, 0, 2)));

}

TEST(Vector4_test, Normalize_inst) {
	EXPECT_EQ(Vector4(0, 0, 0, 0), Vector4(0, 0, 0, 0).Normalize());
	EXPECT_EQ(Vector4(0.5f, 0.5f, 0.5f, 0.5f), Vector4(1, 1, 1, 1).Normalize());
	EXPECT_EQ(Vector4(0.5f, 0.5f, 0.5f, 0.5f), Vector4(2, 2, 2, 2).Normalize());
	EXPECT_EQ(Vector4(-0.5f, -0.5f, 0.5f, 0.5f), Vector4(-1, -1, 1, 1).Normalize());
}

TEST(Vector4_test, Normalize_static) {
	EXPECT_EQ(Vector4(0, 0, 0, 0), Vector4::Normalize(Vector4(0, 0, 0, 0)));
	EXPECT_EQ(Vector4(0.5f, 0.5f, 0.5f, 0.5f), Vector4::Normalize(Vector4(1, 1, 1, 1)));
	EXPECT_EQ(Vector4(0.5f, 0.5f, 0.5f, 0.5f), Vector4::Normalize(Vector4(2, 2, 2, 2)));
	EXPECT_EQ(Vector4(-0.5f, -0.5f, 0.5f, 0.5f), Vector4::Normalize(Vector4(-1, -1, 1, 1)));
}

//matrix3 tests
TEST(Matrix3_test, op_equal) {
	Matrix3 mx1 = Matrix3();
	Matrix3 mx2 = Matrix3();
	mx1.set(1, 2, 3);
	mx2.set(1, 2, 3);
	EXPECT_TRUE(mx1 == mx2);
	mx2.set(1, 1, 2);
	EXPECT_FALSE(mx1 == mx2);
}

TEST(Matrix3_test, op_not_equal) {
	Matrix3 mx1 = Matrix3();
	Matrix3 mx2 = Matrix3();
	mx1.set(1, 2, 3);
	mx2.set(1, 2, 3);
	EXPECT_FALSE(mx1 != mx2);
	mx2.set(1, 1, 2);
	EXPECT_TRUE(mx1 != mx2);
}

TEST(Matrix3_test, rotation) {
	Matrix3 expected = Matrix3();
	Matrix3 actual = Matrix3();

	actual.Rotation(10);
	expected.set(std::cos(10), -(std::sin(10)), 0, std::sin(10), std::cos(10), 0, 0, 0, 1);
	EXPECT_EQ(expected, actual);

	actual.Rotation(-10);
	expected.set(std::cos(-10), -(std::sin(-10)), 0, std::sin(-10), std::cos(-10), 0, 0, 0, 1);
	EXPECT_EQ(expected, actual);

	actual.Rotation(0);
	expected.set(1, 0, 0, 0, 1, 0, 0, 0, 1);
	EXPECT_EQ(expected, actual);
}

TEST(Matrix3_test, Scale) {
	Matrix3 expected = Matrix3();
	Matrix3 actual = Matrix3();

	actual.Scale(2,3);
	expected.set(2, 0, 0, 0, 3, 0, 0, 0, 1);
	EXPECT_EQ(expected, actual);

	actual.Scale(0.4f, 0.5f);
	expected.set(0.4f, 0, 0, 0, 0.5f, 0, 0, 0, 1);
	EXPECT_EQ(expected, actual);

	actual.Scale(-2, -3);
	expected.set(1, 0, 0, 0, 1, 0, 0, 0, 1);
	EXPECT_EQ(expected, actual);

	actual.Scale(0, 0);
	expected.set(1, 0, 0, 0, 1, 0, 0, 0, 1);
	EXPECT_EQ(expected, actual);
}

TEST(Matrix3_test, Transform_Vector) {
	Matrix3 expected = Matrix3();
	Matrix3 actual = Matrix3();

	actual.TransformVector(1, 2);
	expected.set(1, 0, 1, 0, 1, 2, 0, 0, 1);
	EXPECT_EQ(expected, actual);

	actual.TransformVector(0, 0);
	expected.set(1, 0, 0, 0, 1, 0, 0, 0, 1);
	EXPECT_EQ(expected, actual);

	actual.TransformVector(-3, -4);
	expected.set(1, 0, -3, 0, 1, -4, 0, 0, 1);
	EXPECT_EQ(expected, actual);
}

TEST(Matrix3_test, Transpose) {
	Matrix3 expected = Matrix3();
	Matrix3 actual = Matrix3();

	actual.set(1, 2, 3,
			   4, 5, 6,
			   7, 8, 9);
	actual.Transpose();

	expected.set(1, 4, 7,
				 2, 5, 8, 
				 3, 6, 9);
	EXPECT_EQ(expected, actual);
}

TEST(Matrix3_test, op_mult) {
	Matrix3 expected = Matrix3();
	Matrix3 mult1 = Matrix3();
	Matrix3 mult2 = Matrix3();

	mult1.set(1, 2, 3, 4, 5, 6, 7, 8, 9);
	mult2.set(10, 11, 12, 13, 14, 15, 16, 17, 18);

	expected.set(84, 90, 96, 201, 216, 231, 318, 342, 366);

	EXPECT_EQ(expected, mult1 * mult2);
}

TEST(Matrix3_test, op_mult_vector) {
	Vector2 expected = Vector2(8, 20);
	Vector2 mult = Vector2(1, 2);
	Matrix3 actual = Matrix3();


	actual.set(1, 2, 3, 4, 5, 6, 7, 8, 9);

	EXPECT_EQ(expected, actual * mult);
}

//Matrix4 tests
TEST(Matrix4_test, op_equal) {
	Matrix4 mx1 = Matrix4();
	Matrix4 mx2 = Matrix4();
	mx1.set(1, 2, 3);
	mx2.set(1, 2, 3);
	EXPECT_TRUE(mx1 == mx2);
	mx2.set(1, 1, 2);
	EXPECT_FALSE(mx1 == mx2);
}

TEST(Matrix4_test, op_not_equal) {
	Matrix4 mx1 = Matrix4();
	Matrix4 mx2 = Matrix4();
	mx1.set(1, 2, 3);
	mx2.set(1, 2, 3);
	EXPECT_FALSE(mx1 != mx2);
	mx2.set(1, 1, 2);
	EXPECT_TRUE(mx1 != mx2);
}

TEST(Matrix4_test, X_Rotation) {
	Matrix4 expected = Matrix4();
	Matrix4 actual = Matrix4();

	actual.XRotation(50);
	expected.set(1, 0, 0, 0, 0, std::cos(-50), -std::sin(-50), 0, 0, std::sin(-50), std::cos(-50), 0, 0, 0, 0, 1);
	EXPECT_EQ(expected, actual);

	actual.XRotation(-50);
	expected.set(1, 0, 0, 0, 0, std::cos(50), -std::sin(50), 0, 0, std::sin(50), std::cos(50), 0, 0, 0, 0, 1);
	EXPECT_EQ(expected, actual);

	actual.XRotation(0);
	expected.set(1, 0, 0, 0, 0, 1, 0, 0, 0, 0, 1, 0, 0, 0, 0, 1);
	EXPECT_EQ(expected, actual);
}

TEST(Matrix4_test, Y_Rotation) {
	Matrix4 expected = Matrix4();
	Matrix4 actual = Matrix4();

	actual.YRotation(50);
	expected.set(std::cos(-50), 0, std::sin(-50), 0, 0, 1, 0, 0, -std::sin(-50), 0, cos(-50), 0, 0, 0, 0, 1);
	EXPECT_EQ(expected, actual);

	actual.YRotation(-50);
	expected.set(std::cos(50), 0, std::sin(50), 0, 0, 1, 0, 0, -std::sin(50), 0, cos(50), 0, 0, 0, 0, 1);
	EXPECT_EQ(expected, actual);

	actual.YRotation(0);
	expected.set(1, 0, 0, 0, 0, 1, 0, 0, 0, 0, 1, 0, 0, 0, 0, 1);
	EXPECT_EQ(expected, actual);
}

TEST(Matrix4_test, Z_Rotation) {
	Matrix4 expected = Matrix4();
	Matrix4 actual = Matrix4();

	actual.ZRotation(50);
	expected.set(std::cos(-50), -std::sin(-50), 0, 0, std::sin(-50), std::cos(-50), 0, 0, 0, 0, 1, 0, 0, 0, 0, 1);
	EXPECT_EQ(expected, actual);

	actual.ZRotation(-50);
	expected.set(std::cos(50), -std::sin(50), 0, 0, std::sin(50), std::cos(50), 0, 0, 0, 0, 1, 0, 0, 0, 0, 1);
	EXPECT_EQ(expected, actual);

	actual.ZRotation(0);
	expected.set(1, 0, 0, 0, 0, 1, 0, 0, 0, 0, 1, 0, 0, 0, 0, 1);
	EXPECT_EQ(expected, actual);
}

int main(int argc, char** argv)
{
	testing::InitGoogleTest(&argc, argv);
	RUN_ALL_TESTS();
	std::getchar(); // keep console window open until Return keystroke
}