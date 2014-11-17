#include <cmath>
#include <iostream>

#ifndef _Vector4_h_
#define _Vector4_h_

class Vector4 {
public:
	float w;
	float x;
	float y;
	float z;

	Vector4();//x = 0 y = 0 z = 0 w = 0
	Vector4(float in_x, float in_y, float in_z, float in_w);
	~Vector4();

	Vector4 ConstructFromColor(float in_perA, float in_perR, float in_perG, float in_perB);
	Vector4 ConstructFromColor(unsigned int in_hexColor);

	float Magnitude();
	static float Magnitude(Vector4 input);

	Vector4 Normalize();
	static Vector4 Normalize(Vector4 input);

	//overloads << operator
	friend std::ostream& operator<<(std::ostream& os, const Vector4& vec);
};

#endif