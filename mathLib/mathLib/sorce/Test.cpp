#include "Vector2.h"

using namespace std;

void main() {
	Vector2 vec1 = Vector2(1, 2);
	Vector2 vec2 = Vector2(3, 4);
	cout << vec1.CrossProduct(vec2) << endl;
	cout << Vector2::CrossProduct(vec1, vec2) << endl;
	cout << vec1 << endl;
	system("pause");
}