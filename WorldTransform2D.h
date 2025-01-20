#pragma once
#include "MyMath.h"
class WorldTransform2D
{
public:
	Vector2 scale_{ 1,1};
	float rotation_{};
	Vector2 translation_{};
	Matrix3x3 matWorld_{};
	Vertex local_{};
	Vertex screen_{};

	WorldTransform2D() = default;
	~WorldTransform2D() = default;

	void Initialize(const float& radius,Vector2 scale = { 1.f,1.f }, const float& rotation = 0, const Vector2& translation = { 0,0 });
	void TransferMatrix();
private:
	// コピー禁止
	WorldTransform2D(const WorldTransform2D&) = delete;
	WorldTransform2D& operator=(const WorldTransform2D&) = delete;
};
