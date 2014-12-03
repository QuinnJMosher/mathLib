#ifndef _quinnlib_h_
#define _quinnlib_h_

#ifdef DLL
#define DLLEXPORT __declspec(dllexport)
#else
#define DLLEXPORT __declspec(dllimport)
#endif

//req includes here
#include <cmath>//vector4/3/2
#include <iostream>//all

namespace qlib {

	DLLEXPORT class Vector4 {
	public:
		float w;
		float x;
		float y;
		float z;

		Vector4();//x = 0 y = 0 z = 0 w = 0
		Vector4(float in_x, float in_y, float in_z, float in_w);
		~Vector4();

		static Vector4 ConstructFromColor(float in_Alpha, float in_Red, float in_Green, float in_Blue);
		static Vector4 ConstructFromColor(unsigned int in_hexColor);

		float Magnitude();
		static float Magnitude(Vector4 input);

		Vector4 Normalize();
		static Vector4 Normalize(Vector4 input);

		//overloads << operator
		friend std::ostream& operator<<(std::ostream& os, const Vector4& vec);
	};


	DLLEXPORT bool operator==(Vector4 left, Vector4 right);
	DLLEXPORT bool operator!=(Vector4 left, Vector4 right);

	DLLEXPORT class Vector3{

	public:
		float x;
		float y;
		float z;

		Vector3();//x = 0 y = 0 z = 0
		Vector3(float in_x, float in_y, float in_z);

		float DotProduct(Vector3 other);
		static float DotProduct(Vector3 in_a, Vector3 in_b);

		Vector3 CrossProduct(Vector3 other);
		static Vector3 CrossProduct(Vector3 in_a, Vector3 in_b);

		float Magnitude();
		static float Magnitude(Vector3 input);

		Vector3 Normalize();
		static Vector3 Normalize(Vector3 input);

		void NormalizeThis();//edits the vector3 called upon instead of outputing

		Vector3 Lerp(Vector3 other, float in_percent);
		static Vector3 Lerp(Vector3 in_first, Vector3 in_second, float in_percent);

		Vector3 operator+(Vector3 other);
		Vector3 operator-(Vector3 other);
		Vector3 operator*(Vector3 other);
		Vector3 operator*(float input);

		void operator+=(Vector3 other);
		void operator-=(Vector3 other);
		void operator*=(Vector3 other);
		void operator*=(float input);

		//overloads << operator
		friend std::ostream& operator<<(std::ostream& os, const Vector3& vec);

	};

	DLLEXPORT bool operator==(Vector3 left, Vector3 right);
	DLLEXPORT bool operator!=(Vector3 left, Vector3 right);

	class DLLEXPORT Vector2{

	public:
		float x;
		float y;

		Vector2();//x = 0 y = 0
		Vector2(float in_x, float in_y);

		float DotProduct(Vector2 other);
		static float DotProduct(Vector2 in_a, Vector2 in_b);

		Vector2 CrossProduct(Vector2 other);
		static Vector2 CrossProduct(Vector2 in_a, Vector2 in_b);

		float Magnitude();
		static float Magnitude(Vector2 input);

		Vector2 Normalize();
		static Vector2 Normalize(Vector2 input);

		void NormalizeThis();//edits the vector2 called upon instead of outputing

		Vector2 Lerp(Vector2 other, float in_percent);
		static Vector2 Lerp(Vector2 in_first, Vector2 in_second, float in_percent);

		Vector2 operator+(Vector2 other);
		Vector2 operator-(Vector2 other);
		Vector2 operator*(Vector2 other);
		Vector2 operator*(float input);

		void operator+=(Vector2 other);
		void operator-=(Vector2 other);
		void operator*=(Vector2 other);
		void operator*=(float input);

		//overloads << operator
		friend std::ostream& operator<<(std::ostream& os, const Vector2& vec);

	};

	DLLEXPORT bool operator==(Vector2 left, Vector2 right);
	DLLEXPORT bool operator!=(Vector2 left, Vector2 right);

	DLLEXPORT class Matrix4{
	public:
		Matrix4();
		~Matrix4();

		Matrix4 XRotation(float in_degrees);
		Matrix4 YRotation(float in_degrees);
		Matrix4 ZRotation(float in_degrees);

		Matrix4 Scale(float in_xScale, float in_yScale, float in_zScale);
		Matrix4 TransformVector(float in_xTransform, float in_yTransform, float in_zTransform);
		Matrix4 Transpose();

		void Set(int in_col, int in_row, float in_value);
		void Set(float in_00, float in_01, float in_02, float in_03, float in_10, float in_11, float in_12, float in_13, float in_20, float in_21, float in_22, float in_23, float in_30, float in_31, float in_32, float in_33);

		Matrix4 OrthoProj(float in_top, float in_bottom, float in_right, float in_left, float in_far, float in_near);

		Matrix4 operator+(Matrix4 other);
		Matrix4 operator-(Matrix4 other);
		Matrix4 operator+=(Matrix4 other);
		Matrix4 operator-=(Matrix4 other);

		Matrix4 operator*(Matrix4 other);
		Matrix4 operator*=(Matrix4 other);

		Vector3 operator*(Vector3 other);

		friend std::ostream& operator<<(std::ostream& os, const Matrix4& mx4);

		float matrix[4][4];

	private:
		void reset();
	};

	DLLEXPORT bool operator==(Matrix4 left, Matrix4 right);
	DLLEXPORT bool operator!=(Matrix4 left, Matrix4 right);

	DLLEXPORT class Matrix3{
	public:
		Matrix3();
		~Matrix3();

		Matrix3 Rotation(float in_degrees);
		Matrix3 Scale(float in_xScale, float in_yScale);
		Matrix3 TransformVector(float in_xTransform, float in_yTransform);
		Matrix3 Transpose();

		void Set(int in_col, int in_row, float in_value);
		void Set(float in_00, float in_01, float in_02, float in_10, float in_11, float in_12, float in_20, float in_21, float in_22);

		Matrix3 operator+(Matrix3 other);
		Matrix3 operator-(Matrix3 other);
		Matrix3 operator+=(Matrix3 other);
		Matrix3 operator-=(Matrix3 other);

		Matrix3 operator*(Matrix3 other);
		Matrix3 operator*=(Matrix3 other);

		Vector2 operator*(Vector2 other);

		friend std::ostream& operator<<(std::ostream& os, const Matrix3& mx3);

		float matrix[3][3];

	private:
		void reset();
	};

	DLLEXPORT bool operator==(Matrix3 right, Matrix3 left);
	DLLEXPORT bool operator!=(Matrix3 right, Matrix3 left);

	DLLEXPORT class General{
	public:
		static float Lerp(float in_begin, float in_end, float in_percent);

		static float ToDegrees(float in_radians);
		static float ToRadians(float in_Degrees);

		static float ShiftPowOfTwo(float in_scalar);

		//bitwiwse operators
	};

}

#endif