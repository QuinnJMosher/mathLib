#include "Vector2.h" 

Vector2::Vector2() {
	x = 0;
	y = 0;
}

Vector2::Vector2(float in_x, float in_y) {
	x = in_x;
	y = in_y;
}

float Vector2::DotProduct(Vector2 other) {
	return ((this->x * other.x) + (this->y * other.y));
}

float Vector2::DotProduct(Vector2 in_a, Vector2 in_b) {
	return ((in_a.x * in_b.x) + (in_a.y * in_b.y));
}

float Vector2::Magnitude() {
	return std::sqrt(pow(this->x, 2) + pow(this->y, 2));
}

float Vector2::Magnitude(Vector2 input) {
	return std::sqrt(pow(input.x, 2) + pow(input.y, 2));
}

Vector2 Vector2::Normalize() {
	float normalX = this->x / this->Magnitude();
	float normalY = this->y / this->Magnitude();

	return Vector2(normalX, normalY);

}

Vector2 Vector2::Normalize(Vector2 input) {
	float normalX = input.x / input.Magnitude();
	float normalY = input.y / input.Magnitude();

	return Vector2(normalX, normalY);
}

void Vector2::NormalizeThis() {//edits the vector2 called upon instead of outputing
	this->x = this->x / this->Magnitude();
	this->y = this->y / this->Magnitude();

}

Vector2 Vector2::operator+(Vector2 other) {
	return Vector2(this->x + other.x, this->y + other.y);
}

Vector2 Vector2::operator-(Vector2 other) {
	return Vector2(this->x - other.x, this->y - other.y);
}

Vector2 Vector2::operator*(Vector2 other) {
	return Vector2(this->x * other.x, this->y * other.y);
}

Vector2 Vector2::operator*(float input) {
	return Vector2(this->x * input, this->y * input);
}

void Vector2::operator+=(Vector2 other) {
	this->x += other.x;
	this->y += other.y;
}

void Vector2::operator-=(Vector2 other) {
	this->x -= other.x;
	this->y -= other.y;
}

void Vector2::operator*=(Vector2 other) {
	this->x *= other.x;
	this->y *= other.y;
}

void Vector2::operator*=(float input) {
	this->x *= input;
	this->y *= input;
}