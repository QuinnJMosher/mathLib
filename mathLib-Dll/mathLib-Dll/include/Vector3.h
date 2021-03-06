#ifdef DLL
#define DLLEXPORT __declspec(dllexport)
#else
#define DLLEXPORT __declspec(dllimport)
#endif

#ifndef _Vector3_h_
#define _Vector3_h_

#include <cmath>
#include <iostream>

class DLLEXPORT Vector3{

public:
	float x;
	float y;
	float z;

	Vector3();//x = 0 y = 0 z = 0
	Vector3(float in_x, float in_y, float in_z);

	float DotProduct(Vector3 other);
	static float DotProduct(Vector3 in_a, Vector3 in_b);

	Vector3 CrossProduct(Vector3 other);
	static Vector3 CrossProduct(Vector3 in_a, Vector3 in_b);

	float Magnitude();
	static float Magnitude(Vector3 input);

	Vector3 Normalize();
	static Vector3 Normalize(Vector3 input);

	void NormalizeThis();//edits the vector3 called upon instead of outputing

	Vector3 Lerp(Vector3 other, float in_percent);
	static Vector3 Lerp(Vector3 in_first, Vector3 in_second, float in_percent);

	Vector3 operator+(Vector3 other);
	Vector3 operator-(Vector3 other);
	Vector3 operator*(Vector3 other);
	Vector3 operator*(float input);

	void operator+=(Vector3 other);
	void operator-=(Vector3 other);
	void operator*=(Vector3 other);
	void operator*=(float input);

	//overloads << operator
	DLLEXPORT friend std::ostream& operator<<(std::ostream& os, const Vector3& vec);

};

DLLEXPORT bool operator==(Vector3 left, Vector3 right);
DLLEXPORT bool operator!=(Vector3 left, Vector3 right);



#endif