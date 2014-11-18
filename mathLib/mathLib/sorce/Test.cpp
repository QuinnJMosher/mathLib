#include "Vector3.h"
#include <iostream>

using namespace std;

void main() {
	Vector3 vec1 = Vector3(20, 20, 20);
	Vector3 vec2 = Vector3(10, 10, 10);
	Vector3 vec3 = vec1.Lerp(vec2, .5);

	cout << vec3<< endl;
	system("pause");
}