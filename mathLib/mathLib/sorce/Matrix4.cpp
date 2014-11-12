#include "Matrix4.h"

Matrix4::Matrix4() {
	this->reset();
}

Matrix4::~Matrix4() {}

void Matrix4::reset() {
	for (int i = 0; i < 4; i++) {
		for (int j = 0; j < 4; j++) {
			matrix[i][j] = 0;
		}
	}

	matrix[0][0] = 1;
	matrix[1][1] = 1;
	matrix[2][2] = 1;
	matrix[3][3] = 1;
}

Matrix4 Matrix4::XRotation(float in_degrees) {
	this->reset();

	matrix[1][1] = std::cos(-in_degrees);
	matrix[1][2] = -std::sin(-in_degrees);
	matrix[2][1] = std::sin(-in_degrees);
	matrix[2][2] = cos(-in_degrees);

	return *this;
}

Matrix4 Matrix4::YRotation(float in_degrees) {
	this->reset();

	matrix[0][0] = std::cos(-in_degrees);
	matrix[0][2] = std::sin(-in_degrees);
	matrix[2][0] = -std::sin(-in_degrees);
	matrix[2][2] = cos(-in_degrees);

	return *this;
}

Matrix4 Matrix4::ZRotation(float in_degrees) {
	this->reset();

	matrix[0][0] = std::cos(-in_degrees);
	matrix[0][1] = -std::sin(-in_degrees);
	matrix[1][0] = std::sin(-in_degrees);
	matrix[1][1] = cos(-in_degrees);

	return *this;
}

Matrix4 Matrix4::Scale(float in_xScale, float in_yScale, float in_zScale) {
	this->reset();

	matrix[0][0] = in_xScale;
	matrix[1][1] = in_yScale;
	matrix[2][2] = in_zScale;

	return *this;
}

Matrix4 Matrix4::TransformVector(float in_xTransform, float in_yTransform, float in_zTransform) {
	this->reset();

	matrix[0][3] = in_xTransform;
	matrix[1][3] = in_yTransform;
	matrix[2][3] = in_zTransform;

	return *this;
}

Matrix4 Matrix4::Transpose() {
	float temp[4][4];

	for (int i = 0; i < 4; i++) {
		for (int j = 0; j < 4; j++) {
			temp[i][j] = matrix[i][j];
		}
	}

	for (int i = 0; i < 4; i++) {
		for (int j = 0; j < 4; j++) {
			matrix[i][j] = temp[j][i];
		}
	}

	return *this;
}

Matrix4 Matrix4::operator+(Matrix4 other) {
	Matrix4 temp = Matrix4();

	for (int i = 0; i < 4; i++) {
		for (int j = 0; j < 4; j++) {
			temp.matrix[i][j] = matrix[i][j] + other.matrix[i][j];
		}
	}

	return temp;
}

Matrix4 Matrix4::operator-(Matrix4 other) {
	Matrix4 temp = Matrix4();

	for (int i = 0; i < 4; i++) {
		for (int j = 0; j < 4; j++) {
			temp.matrix[i][j] = matrix[i][j] - other.matrix[i][j];
		}
	}

	return temp;
}
Matrix4 Matrix4::operator+=(Matrix4 other) {
	for (int i = 0; i < 4; i++) {
		for (int j = 0; j < 4; j++) {
			matrix[i][j] = matrix[i][j] += other.matrix[i][j];
		}
	}

	return *this;
}

Matrix4 Matrix4::operator-=(Matrix4 other) {
	for (int i = 0; i < 4; i++) {
		for (int j = 0; j < 4; j++) {
			matrix[i][j] = matrix[i][j] -= other.matrix[i][j];
		}
	}

	return *this;
}

Matrix4 Matrix4::operator*(Matrix4 other) {
	Matrix4 temp = Matrix4();

	temp.matrix[0][0] = (matrix[0][0] * other.matrix[0][0]) + (matrix[0][1] * other.matrix[1][0]) + (matrix[0][2] * other.matrix[2][0]) + (matrix[0][3] * other.matrix[3][0]);
	temp.matrix[0][1] = (matrix[0][0] * other.matrix[0][1]) + (matrix[0][1] * other.matrix[1][1]) + (matrix[0][2] * other.matrix[2][1]) + (matrix[0][3] * other.matrix[3][1]);
	temp.matrix[0][2] = (matrix[0][0] * other.matrix[0][2]) + (matrix[0][1] * other.matrix[1][2]) + (matrix[0][2] * other.matrix[2][2]) + (matrix[0][3] * other.matrix[3][2]);
	temp.matrix[0][3] = (matrix[0][0] * other.matrix[0][3]) + (matrix[0][1] * other.matrix[1][3]) + (matrix[0][2] * other.matrix[2][3]) + (matrix[0][3] * other.matrix[3][3]);

	temp.matrix[1][0] = (matrix[1][0] * other.matrix[0][0]) + (matrix[1][1] * other.matrix[1][0]) + (matrix[1][2] * other.matrix[2][0]) + (matrix[1][3] * other.matrix[3][0]);
	temp.matrix[1][1] = (matrix[1][0] * other.matrix[0][1]) + (matrix[1][1] * other.matrix[1][1]) + (matrix[1][2] * other.matrix[2][1]) + (matrix[1][3] * other.matrix[3][1]);
	temp.matrix[1][2] = (matrix[1][0] * other.matrix[0][2]) + (matrix[1][1] * other.matrix[1][2]) + (matrix[1][2] * other.matrix[2][2]) + (matrix[1][3] * other.matrix[3][2]);
	temp.matrix[1][3] = (matrix[1][0] * other.matrix[0][3]) + (matrix[1][1] * other.matrix[1][3]) + (matrix[1][2] * other.matrix[2][3]) + (matrix[1][3] * other.matrix[3][3]);

	temp.matrix[2][0] = (matrix[2][0] * other.matrix[0][0]) + (matrix[2][1] * other.matrix[1][0]) + (matrix[2][2] * other.matrix[2][0]) + (matrix[2][3] * other.matrix[3][0]);
	temp.matrix[2][1] = (matrix[2][0] * other.matrix[0][1]) + (matrix[2][1] * other.matrix[1][1]) + (matrix[2][2] * other.matrix[2][1]) + (matrix[2][3] * other.matrix[3][1]);
	temp.matrix[2][2] = (matrix[2][0] * other.matrix[0][2]) + (matrix[2][1] * other.matrix[1][2]) + (matrix[2][2] * other.matrix[2][2]) + (matrix[2][3] * other.matrix[3][2]);
	temp.matrix[2][3] = (matrix[2][0] * other.matrix[0][3]) + (matrix[2][1] * other.matrix[1][3]) + (matrix[2][2] * other.matrix[2][3]) + (matrix[2][3] * other.matrix[3][3]);

	temp.matrix[3][0] = (matrix[3][0] * other.matrix[0][0]) + (matrix[3][1] * other.matrix[1][0]) + (matrix[3][2] * other.matrix[2][0]) + (matrix[3][3] * other.matrix[3][0]);
	temp.matrix[3][1] = (matrix[3][0] * other.matrix[0][1]) + (matrix[3][1] * other.matrix[1][1]) + (matrix[3][2] * other.matrix[2][1]) + (matrix[3][3] * other.matrix[3][1]);
	temp.matrix[3][2] = (matrix[3][0] * other.matrix[0][2]) + (matrix[3][1] * other.matrix[1][2]) + (matrix[3][2] * other.matrix[2][2]) + (matrix[3][3] * other.matrix[3][2]);
	temp.matrix[3][3] = (matrix[3][0] * other.matrix[0][3]) + (matrix[3][1] * other.matrix[1][3]) + (matrix[3][2] * other.matrix[2][3]) + (matrix[3][3] * other.matrix[3][3]);

	return temp;
}

Matrix4 Matrix4::operator*=(Matrix4 other) {
	Matrix4 temp = Matrix4();

	for (int i = 0; i < 4; i++) {
		for (int j = 0; j < 4; j++) {
			temp.matrix[i][j] = matrix[i][j];
		}
	}

	matrix[0][0] = (temp.matrix[0][0] * other.matrix[0][0]) + (temp.matrix[0][1] * other.matrix[1][0]) + (temp.matrix[0][2] * other.matrix[2][0]) + (temp.matrix[0][3] * other.matrix[3][0]);
	matrix[0][1] = (temp.matrix[0][0] * other.matrix[0][1]) + (temp.matrix[0][1] * other.matrix[1][1]) + (temp.matrix[0][2] * other.matrix[2][1]) + (temp.matrix[0][3] * other.matrix[3][1]);
	matrix[0][2] = (temp.matrix[0][0] * other.matrix[0][2]) + (temp.matrix[0][1] * other.matrix[1][2]) + (temp.matrix[0][2] * other.matrix[2][2]) + (temp.matrix[0][3] * other.matrix[3][2]);
	matrix[0][3] = (temp.matrix[0][0] * other.matrix[0][3]) + (temp.matrix[0][1] * other.matrix[1][3]) + (temp.matrix[0][2] * other.matrix[2][3]) + (temp.matrix[0][3] * other.matrix[3][3]);

	matrix[1][0] = (temp.matrix[1][0] * other.matrix[0][0]) + (temp.matrix[1][1] * other.matrix[1][0]) + (temp.matrix[1][2] * other.matrix[2][0]) + (temp.matrix[1][3] * other.matrix[3][0]);
	matrix[1][1] = (temp.matrix[1][0] * other.matrix[0][1]) + (temp.matrix[1][1] * other.matrix[1][1]) + (temp.matrix[1][2] * other.matrix[2][1]) + (temp.matrix[1][3] * other.matrix[3][1]);
	matrix[1][2] = (temp.matrix[1][0] * other.matrix[0][2]) + (temp.matrix[1][1] * other.matrix[1][2]) + (temp.matrix[1][2] * other.matrix[2][2]) + (temp.matrix[1][3] * other.matrix[3][2]);
	matrix[1][3] = (temp.matrix[1][0] * other.matrix[0][3]) + (temp.matrix[1][1] * other.matrix[1][3]) + (temp.matrix[1][2] * other.matrix[2][3]) + (temp.matrix[1][3] * other.matrix[3][3]);

	matrix[2][0] = (temp.matrix[2][0] * other.matrix[0][0]) + (temp.matrix[2][1] * other.matrix[1][0]) + (temp.matrix[2][2] * other.matrix[2][0]) + (temp.matrix[2][3] * other.matrix[3][0]);
	matrix[2][1] = (temp.matrix[2][0] * other.matrix[0][1]) + (temp.matrix[2][1] * other.matrix[1][1]) + (temp.matrix[2][2] * other.matrix[2][1]) + (temp.matrix[2][3] * other.matrix[3][1]);
	matrix[2][2] = (temp.matrix[2][0] * other.matrix[0][2]) + (temp.matrix[2][1] * other.matrix[1][2]) + (temp.matrix[2][2] * other.matrix[2][2]) + (temp.matrix[2][3] * other.matrix[3][2]);
	matrix[2][3] = (temp.matrix[2][0] * other.matrix[0][3]) + (temp.matrix[2][1] * other.matrix[1][3]) + (temp.matrix[2][2] * other.matrix[2][3]) + (temp.matrix[2][3] * other.matrix[3][3]);

	matrix[3][0] = (temp.matrix[3][0] * other.matrix[0][0]) + (temp.matrix[3][1] * other.matrix[1][0]) + (temp.matrix[3][2] * other.matrix[2][0]) + (temp.matrix[3][3] * other.matrix[3][0]);
	matrix[3][1] = (temp.matrix[3][0] * other.matrix[0][1]) + (temp.matrix[3][1] * other.matrix[1][1]) + (temp.matrix[3][2] * other.matrix[2][1]) + (temp.matrix[3][3] * other.matrix[3][1]);
	matrix[3][2] = (temp.matrix[3][0] * other.matrix[0][2]) + (temp.matrix[3][1] * other.matrix[1][2]) + (temp.matrix[3][2] * other.matrix[2][2]) + (temp.matrix[3][3] * other.matrix[3][2]);
	matrix[3][3] = (temp.matrix[3][0] * other.matrix[0][3]) + (temp.matrix[3][1] * other.matrix[1][3]) + (temp.matrix[3][2] * other.matrix[2][3]) + (temp.matrix[3][3] * other.matrix[3][3]);

	return temp;
}

Vector3 Matrix4::operator*(Vector3 other) {
	Vector3 out = Vector3();

	out.x = (matrix[0][0] * other.x) + (matrix[0][1] * other.y) + (matrix[0][2] * other.z) + matrix[0][3];
	out.y = (matrix[1][0] * other.x) + (matrix[1][1] * other.y) + (matrix[1][2] * other.z) + matrix[1][3];
	out.z = (matrix[2][0] * other.x) + (matrix[2][1] * other.y) + (matrix[2][2] * other.z) + matrix[2][3];

	return out;
}

std::ostream& operator<<(std::ostream& os, const Matrix4& mx4) {
	os << "[[" << mx4.matrix[0][0] << ", " << mx4.matrix[0][1] << ", " << mx4.matrix[0][2] << ", " << mx4.matrix[0][3] << "]\n";
	os << " [" << mx4.matrix[1][0] << ", " << mx4.matrix[1][1] << ", " << mx4.matrix[1][2] << ", " << mx4.matrix[1][3] << "]\n";
	os << " [" << mx4.matrix[2][0] << ", " << mx4.matrix[2][1] << ", " << mx4.matrix[2][2] << ", " << mx4.matrix[2][3] << "]\n";
	os << " [" << mx4.matrix[3][0] << ", " << mx4.matrix[3][1] << ", " << mx4.matrix[3][2] << ", " << mx4.matrix[3][3] << "]]\n";
	return os;
}