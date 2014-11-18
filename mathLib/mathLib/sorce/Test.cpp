#include "Matrix4.h"
#include <iostream>

using namespace std;

void main() {
	Matrix4 mx1 = Matrix4();
	Matrix4 mx2 = Matrix4();
	mx1.TransformVector(1, 2, 3);
	mx2.TransformVector(4, 5, 6);
	mx2.Transpose();

	cout << mx1 * mx2 << endl;
	mx1 *= mx2;
	cout << mx1 << endl;
	system("pause");
}