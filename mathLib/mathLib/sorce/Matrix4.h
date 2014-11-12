#include "Vector3.h"
#include <cmath>

#ifndef _Matrix4_h_
#define _Matrix4_h_

class Matrix4 {
public:
	Matrix4();
	~Matrix4();

	Matrix4 Rotation(float in_degrees);
	Matrix4 Scale(float in_xScale, float in_yScale);
	Matrix4 TransformVector(float in_xTransform, float in_yTransform);
	Matrix4 Transpose();

	Matrix4 operator+(Matrix4 other);
	Matrix4 operator-(Matrix4 other);
	Matrix4 operator+=(Matrix4 other);
	Matrix4 operator-=(Matrix4 other);

	Matrix4 operator*(Matrix4 other);
	Matrix4 operator*=(Matrix4 other);

	Vector3 operator*(Vector3 other);

	friend std::ostream& operator<<(std::ostream& os, const Matrix4& mx3);

	float matrix[3][3];

private:
	void reset();
};

#endif