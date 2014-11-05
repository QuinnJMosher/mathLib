#include "Vector3.h"

Vector3::Vector3() {
	this->x = 0;
	this->y = 0;
	this->z = 0;
}

Vector3::Vector3(float in_x, float in_y, int in_z) {
	this->x = in_x;
	this->y = in_y;
	this->z = in_z;
}

float Vector3::DotProduct(Vector3 other) {
	return ((this->x * other.x) + (this->y * other.y) + (this->z * other.z));
}

float Vector3::DotProduct(Vector3 in_a, Vector3 in_b) {
	return ((in_a.x * in_b.x) + (in_a.y * in_b.y) + (in_a.z * in_b.z));
}

Vector3 Vector3::CrossProduct(Vector3 other) {
	return Vector3((this->y * other.z) - (this->z * other.y), (this->z * other.x) - (this->x * other.z), (this->x * other.y) - (this->y * other.x));
}

Vector3 Vector3::CrossProduct(Vector3 in_a, Vector3 in_b) {
	return Vector3((in_a.y * in_b.z) - (in_a.z * in_b.y), (in_a.z * in_b.x) - (in_a.x * in_b.z), (in_a.x * in_b.y) - (in_a.y * in_b.x));
}

float Vector3::Magnitude();
float Vector3::Magnitude(Vector3 input);

Vector3 Vector3::Normalize();
Vector3 Vector3::Normalize(Vector3 input);

void Vector3::NormalizeThis();//edits the vector3 called upon instead of outputing

Vector3 Vector3::operator+(Vector3 other);
Vector3 Vector3::operator-(Vector3 other);
Vector3 Vector3::operator*(Vector3 other);
Vector3 Vector3::operator*(float input);

void Vector3::operator+= (Vector3 other);
void Vector3::operator-=(Vector3 other);
void Vector3::operator*=(Vector3 other);
void Vector3::operator*=(float input);

std::ostream& operator<<(std::ostream& os, const Vector3& vec);