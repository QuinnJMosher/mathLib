#include "Vector2.h"

using namespace std;

void main() {
	Vector2 vec1 = Vector2(1, 2);
	Vector2 vec2 = vec1.Normalize();
	vec1.NormalizeThis();

	cout << vec2 << endl;
	cout << vec1 << endl;
	system("pause");
}