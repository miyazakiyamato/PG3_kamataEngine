#include "EnemyBullet.h"
#include "CollisionConfig.h"
#include <Novice.h>


void EnemyBullet::Initialize(const Vector2& position, const Vector2& velocity)
{
	SetName(ENEMYBULLET);
	worldTransform_.Initialize(16);
	worldTransform_.translation_ = position;
	worldTransform_.scale_ = { 1.0f, 1.0f };
	worldTransform_.TransferMatrix();
	velocity_ = velocity;
	textureHandle_ = Novice::LoadTexture("./NoviceResources/tama.png");
	SetCollisionAttribute(kCollisionAttributeEnemy);
	//
	SetCollisionMask(GetCollisionMask() - kCollisionAttributeEnemy);
}

void EnemyBullet::Update(const Vector2& velocity)
{
	Vector2 toPlayer = { velocity.x - GetWorldPosition().x,velocity.y - GetWorldPosition().y };
	velocity_ = MyMath::Multiply(3, MyMath::Normalize(toPlayer));
	worldTransform_.translation_ = MyMath::Add(worldTransform_.translation_, velocity_);
	worldTransform_.TransferMatrix();
	if (--deathTimer_ <= 0) {
		isDead_ = true;
	}
}

void EnemyBullet::Draw(const ViewProjection2D& viewProjection) {
	Matrix3x3 wvpVpMatrix = MyMath::Multiply(worldTransform_.matWorld_, viewProjection.wvpVpMatrix_);
	worldTransform_.screen_ = MyMath::MakeScreenVertex(worldTransform_.local_, wvpVpMatrix);
	MyMath::DrawSprite(worldTransform_.screen_, 16, 16, textureHandle_, 0xffffffff);
}

void EnemyBullet::OnCollision(ColliderName name) {
	if (name == PLAYER) {

	}
	isDead_ = true; 
}


Vector2 EnemyBullet::GetWorldPosition() {
	Vector2 worldPos;
	worldPos.x = worldTransform_.matWorld_.m[2][0];
	worldPos.y = worldTransform_.matWorld_.m[2][1];
	return worldPos;
}

