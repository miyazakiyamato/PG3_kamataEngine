#pragma once

struct Vector2 {
	float x;
	float y;
};
struct Matrix3x3 {
	float m[3][3];
};
struct Vertex {
	Vector2 leftTop;
	Vector2 rightTop;
	Vector2 leftBottom;
	Vector2 rightBottom;
};
class MyMath
{
public:
	static float Length(float x, float y);
	static float ScalarLength(float a);
	static float Normalize(float aPos, float length);
	static Vector2 VectorNormalize(const Vector2& vector);
	static bool LeftRight(Vector2 playerPos, Vector2 pos, Vector2 pos2);
	static float Clamp(float num, float min, float max);
	static void CTCount(int& ct, int time);
	static int NumSet(int num, char* keys);
	static int NumSet(int num, char* keys, char* preKeys);
	static void PrintMap(int posX, int posY, int size, int scsX, int scsY, int tilenumX, int tilenumY, int texture, unsigned int color);
	static void PrintQuad(int posX, int posY, int radiusX, int radiusY, int scsX, int scsY, int tilenumX, int tilenumY, int texture, unsigned int color);
	static void PrintRotate(Vertex world, Vector2 radius, Vector2 scs, int tilenumX, int tilenumY, int texture, unsigned int color);
	static void DrawSprite(const Vertex& screen, int textureSizeX, int textureSizeY, int texture, unsigned int color);
	static float GetPI();
	static float CalculateAngle(float vx, float vy);
	static Vector2 Bezier(const Vector2& pos, const Vector2& pos2, const Vector2& pos3, float t);
	static Vector2 CatmullRom(const Vector2& p0, const Vector2& p1, const Vector2& p2, const Vector2& p3, float t);
	static float Length(const Vector2& v);
	static Vector2 Normalize(const Vector2& v);
	static Vector2 Add(const Vector2& v1, const Vector2& v2);
	static Vector2 Multiply(const float& scalar, const Vector2& v2);
	static float Dot(const Vector2& v1, const Vector2& v2);
	//Color CalculateColor(Vector2 velocity, float maxVelocity);
	//Color CalculateColor_2(float distanceTravelled, float maxDistance);
	static Vector2 Lerp(Vector2 startPos, Vector2 endPos, float t);
	static Vector2 Slerp(const Vector2& v1, const Vector2& v2, float t);
	static Matrix3x3 Multiply(Matrix3x3 matrix1, Matrix3x3 matrix2);
	static Matrix3x3 MakeScaleMatrix(Vector2 scale);
	static Matrix3x3 MakeTranslateMatrix(Vector2 translate);
	static Vector2 TransForm(Vector2 v, Matrix3x3 matrix);
	static Matrix3x3 MakeRotateMatrix(float theta);
	static Matrix3x3 MakeWorldMatrix(Vector2 size, float theta, Vector2 translate);
	static Matrix3x3 InverseMatrix(Matrix3x3 matrix);
	static Matrix3x3 MakeOrthographicMatrix(float left, float top, float right, float bottom);
	static Matrix3x3 MakeViewportMatrix(float left, float top, float width, float height);
	static Vertex MakeScreenVertex(const Vertex& local, const Matrix3x3& wvpVpMatrix);
	static Vector2 CalculateCenterPos(Vector2 pos1, Vector2 pos2, Vector2 pos3);

	/*=================================
		線形補完 イージング */

	static float EaseLerp(float startPos, float endPos, float t, float easedT);
	static float EaseIn(float t);
	static float EaseOut(float t);
	static float EaseInSine(float t);

	static float EaseOutSine(float t);
};

