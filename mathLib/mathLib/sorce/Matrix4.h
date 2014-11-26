#include "Vector3.h"
#include <cmath>

#ifndef _Matrix4_h_
#define _Matrix4_h_

class Matrix4 {
public:
	Matrix4();
	~Matrix4();

	Matrix4 XRotation(float in_degrees);
	Matrix4 YRotation(float in_degrees);
	Matrix4 ZRotation(float in_degrees);

	Matrix4 Scale(float in_xScale, float in_yScale, float in_zScale);
	Matrix4 TransformVector(float in_xTransform, float in_yTransform, float in_zTransform);
	Matrix4 Transpose();

	void Set(int in_col, int in_row, float in_value);
	void Set(float in_00, float in_01, float in_02, float in_03, float in_10, float in_11, float in_12, float in_13, float in_20, float in_21, float in_22, float in_23, float in_30, float in_31, float in_32, float in_33);

	Matrix4 OrthoProj(float in_top, float in_bottom, float in_right, float in_left, float in_far, float in_near);
	
	Matrix4 operator+(Matrix4 other);
	Matrix4 operator-(Matrix4 other);
	Matrix4 operator+=(Matrix4 other);
	Matrix4 operator-=(Matrix4 other);

	Matrix4 operator*(Matrix4 other);
	Matrix4 operator*=(Matrix4 other);

	Vector3 operator*(Vector3 other);

	friend std::ostream& operator<<(std::ostream& os, const Matrix4& mx4);

	float matrix[4][4];

private:
	void reset();
};

bool operator==(Matrix4 left, Matrix4 right);
bool operator!=(Matrix4 left, Matrix4 right);

#endif