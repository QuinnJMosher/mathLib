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

static float Vector2::DotProduct(Vector2 in_a, Vector2 in_b) {
	return ((in_a.x * in_b.x) + (in_a.y * in_b.y));
}

float Vector2::Magnitude() {
	return std::sqrt(pow(this->x, 2) + pow(this->y, 2));
}

static float Vector2::Magnitude(Vector2 input);

Vector2 Vector2::Normalize();
static Vector2 Vector2::Normalize(Vector2 input);

void NormalizeThis();//edits the vector2 called upon instead of outputing

Vector2 Vector2::operator+(Vector2 other);
Vector2 Vector2::operator-(Vector2 other);
Vector2 Vector2::operator*(Vector2 other);
Vector2 Vector2::operator*(float input);

Vector2 Vector2::operator+=(Vector2 other);
Vector2 Vector2::operator-=(Vector2 other);
Vector2 Vector2::operator*=(Vector2 other);
Vector2 Vector2::operator*=(float input);