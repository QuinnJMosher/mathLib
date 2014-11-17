#include "Vector2.h"
#include "Vector3.h"
#include <cmath>

#ifndef _Genral_h_
#define _Genral_h_

class Genral {
public:
	static float ScalarLerp(Vector2 in_begin, Vector2 in_end, float scalar);
	static float ScalarLerp(Vector3 in_begin, Vector3 in_end, float scalar);

	static float ToDegrees(float in_radians);
	static float ToRadians(float in_Degrees);

	static float ShiftPowOfTwo(float in_scalar);

	//bitwiwse operators
};

#endif