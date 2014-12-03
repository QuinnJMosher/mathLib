#ifdef DLL
#define DLLEXPORT __declspec(dllexport)
#else
#define DLLEXPORT __declspec(dllimport)
#endif

#include "Vector2.h"
#include <cmath>

#ifndef _Matrix3_h_
#define _Matrix3_h_

class DLLEXPORT Matrix3{
public:
	Matrix3();
	~Matrix3();

	Matrix3 Rotation(float in_degrees);
	Matrix3 Scale(float in_xScale, float in_yScale);
	Matrix3 TransformVector(float in_xTransform, float in_yTransform);
	Matrix3 Transpose();

	void Set(int in_col, int in_row, float in_value);
	void Set(float in_00, float in_01, float in_02, float in_10, float in_11, float in_12, float in_20, float in_21, float in_22);

	Matrix3 operator+(Matrix3 other);
	Matrix3 operator-(Matrix3 other);
	Matrix3 operator+=(Matrix3 other);
	Matrix3 operator-=(Matrix3 other);

	Matrix3 operator*(Matrix3 other);
	Matrix3 operator*=(Matrix3 other);

	Vector2 operator*(Vector2 other);

	DLLEXPORT friend std::ostream& operator<<(std::ostream& os, const Matrix3& mx3);

	float matrix[3][3];

private:
	void reset();
};

DLLEXPORT bool operator==(Matrix3 right, Matrix3 left);
DLLEXPORT bool operator!=(Matrix3 right, Matrix3 left);

#endif