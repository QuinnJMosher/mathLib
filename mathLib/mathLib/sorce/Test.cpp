#include "Matrix4.h"
#include <iostream>

using namespace std;

void main() {
	Matrix4 mx1 = Matrix4();
	mx1.OrthoProj(1, 2, 3, 4, 5, 6);

	Matrix4 mx2 = Matrix4();
	Matrix4::OrthoProj(1, 2, 3, 4, 5, 6, &mx2);

	cout << mx1 << endl;
	cout << mx2 << endl;
	system("pause");
}