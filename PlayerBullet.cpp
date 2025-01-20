#include "PlayerBullet.h"
#include <cmath>
#include "Player.h"

PlayerBullet::~PlayerBullet()
{
}

void PlayerBullet::Initialize(int texture, const Vector2& position)
{
	SetName(PLAYERBULLET);
	gh_ = texture;
	SetRadius(48.0f);
	worldTransform_.Initialize(radius_, { 1,1 }, 0, position);

	SetCollisionAttribute(kCollisionAttributePlayer);
	//
	SetCollisionMask(GetCollisionMask() - kCollisionAttributePlayer);
}

void PlayerBullet::Update()
{
	worldTransform_.translation_ = MyMath::Add(worldTransform_.translation_, velocity_);
	worldTransform_.TransferMatrix();
	if (isAlive_) {
		
	}
	else {
		aliveCount++;
		if (aliveCount >= 180) {
			isAlive_ = true;
			aliveCount = 0;
		}
	}
}

void PlayerBullet::Draw(ViewProjection2D& viewProjection)
{
	Matrix3x3 wvpVpMatrix = MyMath::Multiply(worldTransform_.matWorld_, viewProjection.wvpVpMatrix_);
	worldTransform_.screen_ = MyMath::MakeScreenVertex(worldTransform_.local_, wvpVpMatrix);
	if (isAlive_) {
		MyMath::DrawSprite(worldTransform_.screen_, 64, 64, gh_, 0xff000088);
	}
}

void PlayerBullet::OnCollision(ColliderName name)
{
	if (player_->isShield()) {
		if (name == ENEMY) {
			isAlive_ = false;
		}
	}
}

Vector2 PlayerBullet::GetWorldPosition()
{
	Vector2 worldPos;
	worldPos.x = worldTransform_.matWorld_.m[2][0];
	worldPos.y = worldTransform_.matWorld_.m[2][1];
	return worldPos;
}
