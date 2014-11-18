#include "General.h"

float General::Lerp(float in_begin, float in_end, float in_percent) {
	float out = in_end - in_begin;

	out *= in_percent;
	out += in_begin;

	return out;
}

float General::ToDegrees(float in_radians) {
	return in_radians * 57.2957795;
}
float General::ToRadians(float in_Degrees) {
	return in_Degrees * 0.0174532925;
}

float General::ShiftPowOfTwo(float in_scalar) {
	int highPower = 0;
	while (pow(2, highPower) < in_scalar) {
		highPower++;
	}

	int highPowerDist = pow(2, highPower) - in_scalar;
	int lowPowerDist = in_scalar - pow(2, highPower - 1);

	if (highPowerDist < lowPowerDist) {
		return pow(2, highPower);
	} else {
		return pow(2, highPower - 1);
	}

}