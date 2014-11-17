#include "Vector2.h"
#include <iostream>

using namespace std;

void main() {
	Vector2 vec1 = Vector2(20, 20);
	Vector2 vec2 = Vector2(10, 10);
	Vector2 vec3 = Vector2::Lerp(vec1, vec2, .5);

	cout << vec3<< endl;
	system("pause");
}