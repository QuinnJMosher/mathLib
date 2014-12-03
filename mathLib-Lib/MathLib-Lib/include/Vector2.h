#ifndef _Vector2_h_
#define _Vector2_h_

#include <cmath>
#include <iostream>

class Vector2 {

public:
	float x;
	float y;

	Vector2();//x = 0 y = 0
	Vector2(float in_x, float in_y);

	float DotProduct(Vector2 other);
	static float DotProduct(Vector2 in_a, Vector2 in_b);

	Vector2 CrossProduct(Vector2 other);
	static Vector2 CrossProduct(Vector2 in_a, Vector2 in_b);

	float Magnitude();
	static float Magnitude(Vector2 input);

	Vector2 Normalize();
	static Vector2 Normalize(Vector2 input);

	void NormalizeThis();//edits the vector2 called upon instead of outputing

	Vector2 Lerp(Vector2 other, float in_percent);
	static Vector2 Lerp(Vector2 in_first, Vector2 in_second, float in_percent);

	Vector2 operator+(Vector2 other);
	Vector2 operator-(Vector2 other);
	Vector2 operator*(Vector2 other);
	Vector2 operator*(float input);

	void operator+=(Vector2 other);
	void operator-=(Vector2 other);
	void operator*=(Vector2 other);
	void operator*=(float input);

	//overloads << operator
	friend std::ostream& operator<<(std::ostream& os, const Vector2& vec);

};

bool operator==(Vector2 left, Vector2 right);
bool operator!=(Vector2 left, Vector2 right);


#endif