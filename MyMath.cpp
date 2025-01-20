#include "MyMath.h"
#define _USE_MATH_DEFINES
#include <math.h>
#include <Novice.h>
#include <cassert>
#include <algorithm>

float MyMath::Length(float x, float y) {
	return sqrtf(x * x + y * y);
}
float MyMath::ScalarLength(float a) {
	return sqrtf(a * a);
}
float MyMath::Normalize(float aPos, float length) {
	if (length != 0) {
		return aPos / length;
	}
	else {
		return aPos;
	}
}
Vector2 MyMath::VectorNormalize(const Vector2& vector) {

	float length = sqrtf(vector.x * vector.x + vector.y * vector.y);

	if (length != 0.0f) {

		return { vector.x / length, vector.y / length };
	}
	else {

		return vector;
	}
}
bool MyMath::LeftRight(Vector2 playerPos, Vector2 pos, Vector2 pos2) {
	float dot = (pos2.x - pos.x) * (playerPos.y - pos.y) - (pos2.y - pos.y) * (playerPos.x - pos.x);
	if (dot < 0) {
		return true;
	}
	return false;
}
float MyMath::Clamp(float num, float min, float max) {
	if (num < min) {
		return min;
	}
	else if (num > max) {
		return max;
	}
	else {
		return num;
	}
}
void MyMath::CTCount(int& ct, int time) {
	if (ct != 0) {
		ct++;
	}
	if (ct > time) {
		ct = 0;
	}
}

int MyMath::NumSet(int num, char* keys) {
	if (keys[DIK_0]) {
		return 0;
	}
	for (int i = 1; i < 10; i++) {
		if (keys[i + 1]) {
			return i;
			break;
		}
	}
	return num;
}
int MyMath::NumSet(int num, char* keys, char* preKeys) {
	if (keys[DIK_0] && !preKeys[0]) {
		return 0;
	}
	for (int i = 1; i < 10; i++) {
		if (keys[i + 1] && !preKeys[i + 1]) {
			return i;
			break;
		}
	}
	return num;
}

void MyMath::PrintMap(int posX, int posY, int size, int scsX, int scsY, int tilenumX, int tilenumY, int texture, unsigned int color) {
	Novice::DrawQuad(
		posX * size + scsX, posY * size + scsY,
		posX * size + size + scsX, posY * size + scsY,
		posX * size + scsX, posY * size + size + scsY,
		posX * size + size + scsX, posY * size + size + scsY,
		tilenumX * size, tilenumY * size, size, size,
		texture, color);
}
void MyMath::PrintQuad(int posX, int posY, int radiusX, int radiusY, int scsX, int scsY, int tilenumX, int tilenumY, int texture, unsigned int color) {
	Novice::DrawQuad(
		posX - radiusX + scsX, posY - radiusY + scsY,
		posX + radiusX + scsX, posY - radiusY + scsY,
		posX - radiusX + scsX, posY + radiusY + scsY,
		posX + radiusX + scsX, posY + radiusY + scsY,
		tilenumX * radiusX * 2, tilenumY * radiusY * 2, radiusX * 2, radiusY * 2,
		texture, color);
}
void MyMath::PrintRotate(Vertex world, Vector2 radius, Vector2 scs, int tilenumX, int tilenumY, int texture, unsigned int color) {
	Novice::DrawQuad(
		(int)world.leftTop.x + (int)scs.x, (int)world.leftTop.y + (int)scs.y,
		(int)world.rightTop.x + (int)scs.x, (int)world.rightTop.y + (int)scs.y,
		(int)world.leftBottom.x + (int)scs.x, (int)world.leftBottom.y + (int)scs.y,
		(int)world.rightBottom.x + (int)scs.x, (int)world.rightBottom.y + (int)scs.y,
		tilenumX * (int)radius.x * 2, tilenumY * (int)radius.y * 2, (int)radius.x * 2, (int)radius.y * 2,
		texture, color);
}

void MyMath::DrawSprite(const Vertex& screen, int textureSizeX, int textureSizeY, int texture, unsigned int color)
{
	Novice::DrawQuad(
		(int)screen.leftTop.x, (int)screen.leftTop.y,
		(int)screen.rightTop.x, (int)screen.rightTop.y,
		(int)screen.leftBottom.x, (int)screen.leftBottom.y,
		(int)screen.rightBottom.x, (int)screen.rightBottom.y,
		0,0, textureSizeX, textureSizeY,
		texture, color);
}

float MyMath::GetPI() { return (float)M_PI; }

float MyMath::CalculateAngle(float vx, float vy) {

	return atan2f(vy, vx);
}
//Color CalculateColor(Vector2 velocity, float maxVelocity) {
//	Color color;
//
//	// 色の最大値と最小値
//	int maxColorValue = 255;
//	int minColorValue = 0;
//
//	// 速度の大きさを計算
//	float currentVelocity = sqrtf(velocity.x * velocity.x + velocity.y * velocity.y);
//
//	// 速度が最小の場合は完全に黒
//	if (currentVelocity <= 0.0f) {
//		color.red = minColorValue;
//		color.green = minColorValue;
//		color.blue = minColorValue;
//	}
//	// 速度が最大の場合は完全に白
//	else if (currentVelocity >= maxVelocity) {
//		color.red = maxColorValue;
//		color.green = maxColorValue;
//		color.blue = maxColorValue;
//	}
//	// それ以外の場合は速度に応じて白から黒に変化
//	else {
//		float normalizedVelocity = currentVelocity / maxVelocity;
//		color.red = static_cast<int>(normalizedVelocity * maxColorValue);
//		color.green = static_cast<int>(normalizedVelocity * maxColorValue);
//		color.blue = static_cast<int>(normalizedVelocity * maxColorValue);
//	}
//
//	color.alpha = 255; // 透明度は固定
//
//	return color;
//}
//
//Color CalculateColor_2(float distanceTravelled, float maxDistance) {
//	Color color;
//
//	// 色の最大値と最小値
//	int maxColorValue = 255;
//	int minColorValue = 0;
//
//	// 進捗を計算（0.0fから1.0fの範囲に正規化）
//	float progress = distanceTravelled / maxDistance;
//
//	// 色の計算
//	color.red = static_cast<int>(progress * maxColorValue);
//	color.green = minColorValue;
//	color.blue = static_cast<int>((1.0f - progress) * maxColorValue);
//	color.alpha = 255; // 透明度は固定
//
//	return color;
//}
Vector2 MyMath::Bezier(const Vector2& pos, const Vector2& pos2, const Vector2& pos3, float t) {
	Vector2 v;
	v.x = t * (t * pos.x + (1 - t) * pos2.x) + (1 - t) * (t * pos2.x + (1 - t) * pos3.x);
	v.y = t * (t * pos.y + (1 - t) * pos2.y) + (1 - t) * (t * pos2.y + (1 - t) * pos3.y);
	return v;
}
Vector2 MyMath::CatmullRom(const Vector2& p0, const Vector2& p1, const Vector2& p2, const Vector2& p3, float t) {
	Vector2 v;
	v.x = ((-p0.x + 3 * p1.x - 3 * p2.x + p3.x) * powf(t, 3) + (2 * p0.x - 5 * p1.x + 4 * p2.x - p3.x) * powf(t, 2) + (-p0.x + p2.x) * t + 2 * p1.x) / 2;
	v.y = ((-p0.y + 3 * p1.y - 3 * p2.y + p3.y) * powf(t, 3) + (2 * p0.y - 5 * p1.y + 4 * p2.y - p3.y) * powf(t, 2) + (-p0.y + p2.y) * t + 2 * p1.y) / 2;
	return v;
}
float MyMath::Length(const Vector2& v) {
	float pos;
	pos = sqrtf(v.x * v.x + v.y * v.y);
	return pos;
}
Vector2 MyMath::Normalize(const Vector2& v) {
	Vector2 v2;
	v2.x = v.x / Length(v);
	v2.y = v.y / Length(v);
	return v2;
}
Vector2 MyMath::Add(const Vector2& v1, const Vector2& v2) {
	return { v1.x + v2.x,v1.y + v2.y };
}
Vector2 MyMath::Multiply(const float& scalar, const Vector2& v2) {
	return { scalar * v2.x,scalar * v2.y };
}
float MyMath::Dot(const Vector2& v1, const Vector2& v2) {
	return v1.x * v2.x + v1.y * v2.y;
}
Vector2 MyMath::Lerp(Vector2 startPos, Vector2 endPos, float t) {
	Vector2 pos_ = {};

	pos_.x = (1.0f - t) * startPos.x + t * endPos.x;
	pos_.y = (1.0f - t) * startPos.y + t * endPos.y;

	return pos_;
}
Vector2 MyMath::Slerp(const Vector2& v1, const Vector2& v2, float t) {
	Vector2 v3;
	Vector2 nV1 = Normalize(v1);
	Vector2 nV2 = Normalize(v2);
	float dot = Dot(nV1, nV2);
	//
	if (dot > 1.0f) {
		dot = 1.0f;
	}
	float theta = acosf(dot);
	float sinTheta = sinf(theta);
	float sinThetaFrom = sinf((1 - t) * theta);
	float sinThetaTo = sinf(t * theta);
	//
	Vector2 nCompVector;
	if (sinTheta < 1.0e-5) {
		nCompVector = nV1;
	}
	else {
		nCompVector = Add(Multiply(sinThetaFrom / sinTheta, nV1), Multiply(sinThetaTo / sinTheta, nV2));
	}
	float length1 = Length(v1);
	float length2 = Length(v2);
	float length = Lerp({ length1 }, { length2 }, t).x;

	v3 = Multiply(length, nCompVector);
	return v3;
}
Matrix3x3 MyMath::Multiply(Matrix3x3 matrix1, Matrix3x3 matrix2) {
	Matrix3x3 m;
	m.m[0][0] = matrix1.m[0][0] * matrix2.m[0][0] + matrix1.m[0][1] * matrix2.m[1][0] + matrix1.m[0][2] * matrix2.m[2][0];
	m.m[0][1] = matrix1.m[0][0] * matrix2.m[0][1] + matrix1.m[0][1] * matrix2.m[1][1] + matrix1.m[0][2] * matrix2.m[2][1];
	m.m[0][2] = matrix1.m[0][0] * matrix2.m[0][2] + matrix1.m[0][1] * matrix2.m[1][2] + matrix1.m[0][2] * matrix2.m[2][2];
	m.m[1][0] = matrix1.m[1][0] * matrix2.m[0][0] + matrix1.m[1][1] * matrix2.m[1][0] + matrix1.m[1][2] * matrix2.m[2][0];
	m.m[1][1] = matrix1.m[1][0] * matrix2.m[0][1] + matrix1.m[1][1] * matrix2.m[1][1] + matrix1.m[1][2] * matrix2.m[2][1];
	m.m[1][2] = matrix1.m[1][0] * matrix2.m[0][2] + matrix1.m[1][1] * matrix2.m[1][2] + matrix1.m[1][2] * matrix2.m[2][2];
	m.m[2][0] = matrix1.m[2][0] * matrix2.m[0][0] + matrix1.m[2][1] * matrix2.m[1][0] + matrix1.m[2][2] * matrix2.m[2][0];
	m.m[2][1] = matrix1.m[2][0] * matrix2.m[0][1] + matrix1.m[2][1] * matrix2.m[1][1] + matrix1.m[2][2] * matrix2.m[2][1];
	m.m[2][2] = matrix1.m[2][0] * matrix2.m[0][2] + matrix1.m[2][1] * matrix2.m[1][2] + matrix1.m[2][2] * matrix2.m[2][2];
	return m;
}
Matrix3x3 MyMath::MakeScaleMatrix(Vector2 scale) {
	Matrix3x3 m;
	m.m[0][0] = scale.x;
	m.m[0][1] = 0;
	m.m[0][2] = 0;
	m.m[1][0] = 0;
	m.m[1][1] = scale.y;
	m.m[1][2] = 0;
	m.m[2][0] = 0;
	m.m[2][1] = 0;
	m.m[2][2] = 1;
	return m;
}
Matrix3x3 MyMath::MakeTranslateMatrix(Vector2 translate) {
	Matrix3x3 m;
	m.m[0][0] = 1;
	m.m[0][1] = 0;
	m.m[0][2] = 0;
	m.m[1][0] = 0;
	m.m[1][1] = 1;
	m.m[1][2] = 0;
	m.m[2][0] = translate.x;
	m.m[2][1] = translate.y;
	m.m[2][2] = 1;
	return m;
}
Vector2 MyMath::TransForm(Vector2 v, Matrix3x3 matrix) {
	Vector2 resalt;
	resalt.x = v.x * matrix.m[0][0] + v.y * matrix.m[1][0] + 1.0f * matrix.m[2][0];
	resalt.y = v.x * matrix.m[0][1] + v.y * matrix.m[1][1] + 1.0f * matrix.m[2][1];
	float w = v.x * matrix.m[0][2] + v.y * matrix.m[1][2] + 1.0f * matrix.m[2][2];
	assert(w != 0.0f);
	resalt.x /= w;
	resalt.y /= w;
	return resalt;
}
Matrix3x3 MyMath::MakeRotateMatrix(float theta) {
	Matrix3x3 m;
	m.m[0][0] = cosf(theta);
	m.m[0][1] = sinf(theta);
	m.m[0][2] = 0;
	m.m[1][0] = -sinf(theta);
	m.m[1][1] = cosf(theta);
	m.m[1][2] = 0;
	m.m[2][0] = 0;
	m.m[2][1] = 0;
	m.m[2][2] = 1;
	return m;
}
Matrix3x3 MyMath::MakeWorldMatrix(Vector2 size, float theta, Vector2 translate) {
	Matrix3x3 m;
	m = Multiply(Multiply(MakeScaleMatrix(size), MakeRotateMatrix(theta)), MakeTranslateMatrix(translate));
	return m;
}
Matrix3x3 MyMath::InverseMatrix(Matrix3x3 matrix) {
	Matrix3x3 m;
	float A = (matrix.m[0][0] * matrix.m[1][1] * matrix.m[2][2] + matrix.m[0][1] * matrix.m[1][2] * matrix.m[2][1] + matrix.m[0][2] * matrix.m[1][0] * matrix.m[2][1] - matrix.m[0][2] * matrix.m[1][1] * matrix.m[2][0] - matrix.m[0][1] * matrix.m[1][0] * matrix.m[2][2] - matrix.m[0][0] * matrix.m[1][2] * matrix.m[2][1]);
	m.m[0][0] = 1 / A * (matrix.m[1][1] * matrix.m[2][2] - matrix.m[1][2] * matrix.m[2][1]);
	m.m[0][1] = 1 / A * -(matrix.m[0][1] * matrix.m[2][2] - matrix.m[0][2] * matrix.m[2][1]);
	m.m[0][2] = 1 / A * (matrix.m[0][1] * matrix.m[1][2] - matrix.m[0][2] * matrix.m[1][1]);
	m.m[1][0] = 1 / A * -(matrix.m[1][0] * matrix.m[2][2] - matrix.m[1][2] * matrix.m[2][1]);
	m.m[1][1] = 1 / A * (matrix.m[0][0] * matrix.m[2][2] - matrix.m[0][2] * matrix.m[2][0]);
	m.m[1][2] = 1 / A * -(matrix.m[0][0] * matrix.m[1][2] - matrix.m[0][2] * matrix.m[1][0]);
	m.m[2][0] = 1 / A * (matrix.m[1][0] * matrix.m[2][1] - matrix.m[1][1] * matrix.m[2][1]);
	m.m[2][1] = 1 / A * -(matrix.m[0][0] * matrix.m[2][1] - matrix.m[0][1] * matrix.m[2][0]);
	m.m[2][2] = 1 / A * (matrix.m[0][0] * matrix.m[1][1] - matrix.m[0][1] * matrix.m[1][0]);
	return m;
}
Matrix3x3 MyMath::MakeOrthographicMatrix(float left, float top, float right, float bottom) {
	Matrix3x3 m;
	m.m[0][0] = 2.0f / (right - left);
	m.m[0][1] = 0;
	m.m[0][2] = 0;
	m.m[1][0] = 0;
	m.m[1][1] = 2.0f / (top - bottom);
	m.m[1][2] = 0;
	m.m[2][0] = (left + right) / (left - right);
	m.m[2][1] = (top + bottom) / (bottom - top);
	m.m[2][2] = 1;
	return m;
}
Matrix3x3 MyMath::MakeViewportMatrix(float left, float top, float width, float height) {
	Matrix3x3 m;
	m.m[0][0] = width / 2.0f;
	m.m[0][1] = 0;
	m.m[0][2] = 0;
	m.m[1][0] = 0;
	m.m[1][1] = -height / 2.0f;
	m.m[1][2] = 0;
	m.m[2][0] = left + width / 2.0f;
	m.m[2][1] = top + height / 2.0f;
	m.m[2][2] = 1;
	return m;
}
Vertex MyMath::MakeScreenVertex(const Vertex& local,const Matrix3x3& wvpVpMatrix)
{
	Vertex world;
	world.leftTop = TransForm(local.leftTop, wvpVpMatrix);
	world.rightTop = TransForm(local.rightTop, wvpVpMatrix);
	world.leftBottom = TransForm(local.leftBottom, wvpVpMatrix);
	world.rightBottom = TransForm(local.rightBottom, wvpVpMatrix);
	return world;
}

Vector2 MyMath::CalculateCenterPos(Vector2 pos1, Vector2 pos2, Vector2 pos3) {

	Vector2 centerPos{};
	centerPos.x = (pos1.x + pos2.x + pos3.x) / 3.0f;
	centerPos.y = (pos1.y + pos2.y + pos3.y) / 3.0f;

	return centerPos;
}

float MyMath::EaseLerp(float startPos, float endPos, float t, float easedT) {
	float pos_ = {};

	pos_ = (1.0f - t) * startPos + easedT * endPos;

	return pos_;
}

float MyMath::EaseIn(float t) {

	return t * t;
};

float MyMath::EaseOut(float t) {

	return 1.0f - (1.0f - t) * (1.0f - t);
}

float MyMath::EaseInSine(float t) {
	return 1 - cosf((t * static_cast<float>(M_PI)) / 2);
}

float MyMath::EaseOutSine(float t) {
	return sinf((t * static_cast<float>(M_PI)) / 2);
}
