#include "Vector2.h"
#include "Matrix3.h"

using namespace std;

void main() {
	Matrix3 mx1 = Matrix3(); 
	Matrix3 mx2 = Matrix3();
	Vector2 vec1 = Vector2(1, 2);
	mx1.TransformVector(2, 5);
	cout << (mx1 * vec1) << endl;
	system("pause");
}