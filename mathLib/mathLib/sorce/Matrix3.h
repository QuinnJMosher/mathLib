#include "Vector2.h"
#include <cmath>

#ifndef _Matrix3_h_
#define _Matrix3_h_

class Matrix3 {
public:
	Matrix3();
	~Matrix3();

	Matrix3 Rotation(float in_degrees);
	Matrix3 Scale(float in_xScale, float in_yScale);
	Matrix3 TransformVector(float in_xTransform, float in_yTransform);
	Matrix3 Transpose();

	Matrix3 operator+(Matrix3 other);
	Matrix3 operator-(Matrix3 other);
	Matrix3 operator+=(Matrix3 other);
	Matrix3 operator-=(Matrix3 other);

	Matrix3 operator*(Matrix3 other);
	Matrix3 operator*=(Matrix3 other);

	Vector2 operator*(Vector2 other);

	friend std::ostream& operator<<(std::ostream& os, const Matrix3& mx3);

	float matrix[3][3];

private:
	void reset();
};

#endif