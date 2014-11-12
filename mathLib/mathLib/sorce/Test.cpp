#include "Vector3.h"
#include "Matrix4.h"

using namespace std;

void main() {
	Matrix4 mx1 = Matrix4(); 
	Matrix4 mx2 = Matrix4();
	Vector3 vec1 = Vector3(1, 2, 3);
	mx1.TransformVector(4, 5, 6);
	cout << mx1 * vec1 << endl;
	system("pause");
}