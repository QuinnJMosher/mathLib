#include <cmath>

#ifndef _General_h_
#define _General_h_

class General {
public:
	static float Lerp(float in_begin, float in_end, float in_percent);

	static float ToDegrees(float in_radians);
	static float ToRadians(float in_Degrees);

	static float ShiftPowOfTwo(float in_scalar);

	//bitwiwse operators
};

#endif