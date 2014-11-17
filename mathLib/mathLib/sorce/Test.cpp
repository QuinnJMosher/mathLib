#include "Vector4.h"

using namespace std;

void main() {
	Vector4 vec1 = Vector4(); 
	vec1 = Vector4::ConstructFromColor(0xa1b2c3d4);
	cout << vec1 << endl;
	system("pause");
}