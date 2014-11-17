#include "Vector4.h"

Vector4::Vector4() {
	w = 0;
	x = 0;
	y = 0; 
	z = 0;
}

Vector4::Vector4(float in_w, float in_x, float in_y, float in_z) {
	w = in_w;
	x = in_x;
	y = in_y;
	z = in_z;
}

Vector4::~Vector4() { }

Vector4 Vector4::ConstructFromColor(float in_Alpha, float in_Red, float in_Green, float in_Blue) {
	return Vector4(in_Alpha / 255, in_Red / 255, in_Green / 255, in_Blue / 255);
}

Vector4 Vector4::ConstructFromColor(unsigned int in_hexColor) {
	Vector4 out = Vector4();

	out.w = ((in_hexColor >> 24) & 0xff) / 255.0f;
	out.x = ((in_hexColor >> 16) & 0xff) / 255.0f;
	out.y = ((in_hexColor >> 8) & 0xff) / 255.0f;
	out.z = ((in_hexColor) & 0xff) / 255.0f;

	return out;

}

float Vector4::Magnitude() {
	return sqrt(pow(this->y, 2) + pow(this->x, 2) + pow(this->y, 2) + pow(this->z, 2));
}

float Vector4::Magnitude(Vector4 input) {
	return sqrt(pow(input.y, 2) + pow(input.x, 2) + pow(input.y, 2) + pow(input.z, 2));
}

Vector4 Vector4::Normalize() {
	float normalW = this->w / this->Magnitude();
	float normalX = this->x / this->Magnitude();
	float normalY = this->y / this->Magnitude();
	float normalZ = this->z / this->Magnitude();

	return Vector4(normalW, normalX, normalY, normalZ);
}

Vector4 Vector4::Normalize(Vector4 input) {
	float normalW = input.w / input.Magnitude();
	float normalX = input.x / input.Magnitude();
	float normalY = input.y / input.Magnitude();
	float normalZ = input.z / input.Magnitude();

	return Vector4(normalW, normalX, normalY, normalZ);
}

std::ostream& operator<<(std::ostream& os, const Vector4& vec) {
	os << "(" << vec.w << ", "<< vec.x << ", " << vec.y << ", " << vec.z << ")";
	return os;
}