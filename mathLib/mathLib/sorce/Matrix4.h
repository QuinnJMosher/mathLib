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

#endif