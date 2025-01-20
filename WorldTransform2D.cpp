#include "WorldTransform2D.h"

void WorldTransform2D::Initialize(const float& radius,Vector2 scale, const float& rotation, const Vector2& translation)
{
	scale_.x = scale.x;
	rotation_ = rotation;
	translation_ = translation;
	TransferMatrix();
	local_.leftTop = { -radius,radius };
	local_.rightTop = { radius,radius };
	local_.leftBottom = { -radius,-radius };
	local_.rightBottom = { radius,-radius };
}

void WorldTransform2D::TransferMatrix()
{
	matWorld_ = MyMath::MakeWorldMatrix(scale_, rotation_, translation_);
}
