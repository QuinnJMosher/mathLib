#include "Matrix3.h"
#include <iostream>

using namespace std;

void main() {
	Matrix3 mx1 = Matrix3();
	Matrix3 mx2 = Matrix3();
	mx1.TransformVector(1, 2);
	mx2.TransformVector(4, 5);
	mx2.Transpose();

	cout << mx1 * mx2 << endl;
	mx1 *= mx2;
	cout << mx1 << endl;
	system("pause");
}