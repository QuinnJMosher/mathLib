#include "Matrix3.h"

Matrix3::Matrix3() {
	this->reset();
}

Matrix3::~Matrix3() {}

void Matrix3::reset() {
	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < 3; j++) {
			matrix[i][j] = 0;
		}
	}
	matrix[0][0] = 1;
	matrix[1][1] = 1;
	matrix[2][2] = 1;
}

Matrix3 Matrix3::Rotation(float in_degrees) {
	this->reset();

	matrix[0][0] = std::cos(in_degrees);
	matrix[1][0] = std::sin(in_degrees);
	matrix[0][1] = -(std::sin(in_degrees));
	matrix[1][1] = std::cos(in_degrees);

	return *this;
}

Matrix3 Matrix3::Scale(float in_xScale, float in_yScale) {
	this->reset();

	matrix[0][0] = in_xScale;
	matrix[1][1] = in_yScale;

	return *this;
}

Matrix3 Matrix3::TransformVector(float in_xTransform, float in_yTransform) {
	this->reset();

	matrix[0][2] = in_xTransform;
	matrix[1][2] = in_yTransform;

	return *this;
}

Matrix3 Matrix3::Transpose() {
	float temp[3][3];

	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < 3; j++) {
			temp[i][j] = matrix[i][j];
		}
	}
	
	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < 3; j++) {
			matrix[i][j] = temp[j][i];
		}
	}

	return *this;
}

Matrix3 Matrix3::operator+(Matrix3 other) {
	Matrix3 temp = Matrix3();

	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < 3; j++) {
			temp.matrix[i][j] = matrix[i][j] + other.matrix[i][j];
		}
	}

	return temp;
}
Matrix3 Matrix3::operator-(Matrix3 other) {
	Matrix3 temp = Matrix3();

	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < 3; j++) {
			temp.matrix[i][j] = matrix[i][j] - other.matrix[i][j];
		}
	}

	return temp;
}

Matrix3 Matrix3::operator+=(Matrix3 other) {
	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < 3; j++) {
			matrix[i][j] += other.matrix[i][j];
		}
	}

	return *this;
}
Matrix3 Matrix3::operator-=(Matrix3 other) {
	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < 3; j++) {
			matrix[i][j] -= other.matrix[i][j];
		}
	}

	return *this;
}

Matrix3 Matrix3::operator*(Matrix3 other) {
	Matrix3 temp = Matrix3();

	temp.matrix[0][0] = (matrix[0][0] * other.matrix[0][0]) + (matrix[0][1] * other.matrix[1][0]) + (matrix[0][2] * other.matrix[2][0]);
	temp.matrix[0][1] = (matrix[0][0] * other.matrix[0][1]) + (matrix[0][1] * other.matrix[1][1]) + (matrix[0][2] * other.matrix[2][1]);
	temp.matrix[0][2] = (matrix[0][0] * other.matrix[0][2]) + (matrix[0][1] * other.matrix[1][2]) + (matrix[0][2] * other.matrix[2][2]);

	temp.matrix[1][0] = (matrix[1][0] * other.matrix[0][0]) + (matrix[1][1] * other.matrix[1][0]) + (matrix[1][2] * other.matrix[2][0]);
	temp.matrix[1][1] = (matrix[1][0] * other.matrix[0][1]) + (matrix[1][1] * other.matrix[1][1]) + (matrix[1][2] * other.matrix[2][1]);
	temp.matrix[1][2] = (matrix[1][0] * other.matrix[0][2]) + (matrix[1][1] * other.matrix[1][2]) + (matrix[1][2] * other.matrix[2][2]);

	temp.matrix[2][0] = (matrix[2][0] * other.matrix[0][0]) + (matrix[2][1] * other.matrix[1][0]) + (matrix[2][2] * other.matrix[2][0]);
	temp.matrix[2][1] = (matrix[2][0] * other.matrix[0][1]) + (matrix[2][1] * other.matrix[1][1]) + (matrix[2][2] * other.matrix[2][1]);
	temp.matrix[2][2] = (matrix[2][0] * other.matrix[0][2]) + (matrix[2][1] * other.matrix[1][2]) + (matrix[2][2] * other.matrix[2][2]);

	return temp;
}
Matrix3 Matrix3::operator*=(Matrix3 other) {
	Matrix3 temp = Matrix3();

	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < 3; j++) {
			temp.matrix[i][j] = matrix[i][j];
		}
	}

	matrix[0][0] = (temp.matrix[0][0] * other.matrix[0][0]) + (temp.matrix[0][1] * other.matrix[1][0]) + (temp.matrix[0][2] * other.matrix[2][0]);
	matrix[0][1] = (temp.matrix[0][0] * other.matrix[0][1]) + (temp.matrix[0][1] * other.matrix[1][1]) + (temp.matrix[0][2] * other.matrix[2][1]);
	matrix[0][2] = (temp.matrix[0][0] * other.matrix[0][2]) + (temp.matrix[0][1] * other.matrix[1][2]) + (temp.matrix[0][2] * other.matrix[2][2]);

	matrix[1][0] = (temp.matrix[1][0] * other.matrix[0][0]) + (temp.matrix[1][1] * other.matrix[1][0]) + (temp.matrix[1][2] * other.matrix[2][0]);
	matrix[1][1] = (temp.matrix[1][0] * other.matrix[0][1]) + (temp.matrix[1][1] * other.matrix[1][1]) + (temp.matrix[1][2] * other.matrix[2][1]);
	matrix[1][2] = (temp.matrix[1][0] * other.matrix[0][2]) + (temp.matrix[1][1] * other.matrix[1][2]) + (temp.matrix[1][2] * other.matrix[2][2]);

	matrix[2][0] = (temp.matrix[2][0] * other.matrix[0][0]) + (temp.matrix[2][1] * other.matrix[1][0]) + (temp.matrix[2][2] * other.matrix[2][0]);
	matrix[2][1] = (temp.matrix[2][0] * other.matrix[0][1]) + (temp.matrix[2][1] * other.matrix[1][1]) + (temp.matrix[2][2] * other.matrix[2][1]);
	matrix[2][2] = (temp.matrix[2][0] * other.matrix[0][2]) + (temp.matrix[2][1] * other.matrix[1][2]) + (temp.matrix[2][2] * other.matrix[2][2]);

	return temp;
}

Vector2 Matrix3::operator*(Vector2 other) {
	Vector2 out = Vector2();

	out.x = (matrix[0][0] * other.x) + (matrix[0][1] * other.y) + matrix[0][2];
	out.y = (matrix[1][0] * other.x) + (matrix[1][1] * other.y) + matrix[1][2];

	return out;
}

std::ostream& operator<<(std::ostream& os, const Matrix3& mx3) {
	os << "[[" << mx3.matrix[0][0] << ", " << mx3.matrix[0][1] << ", " << mx3.matrix[0][2] << "]\n";
	os << " [" << mx3.matrix[1][0] << ", " << mx3.matrix[1][1] << ", " << mx3.matrix[1][2] << "]\n";
	os << " [" << mx3.matrix[2][0] << ", " << mx3.matrix[2][1] << ", " << mx3.matrix[2][2] << "]]\n";
	return os;
}