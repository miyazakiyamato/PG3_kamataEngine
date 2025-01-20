#include "Enemy.h"
#include <cassert>
#include "Player.h"
#include "Scene_Game.h"

Enemy::~Enemy() {
	for (TimedCall* timedCalls : timedCalls_) {
		delete timedCalls;
	}
}

void Enemy::Initialize(int texture, const Vector2& position) {
	SetName(ENEMY);
	textureHandle_ = texture;
	worldTransform_.Initialize(32);
	worldTransform_.translation_ = position;
	//
	SetCollisionAttribute(kCollisionAttributeEnemy);
	//
	SetCollisionMask(GetCollisionMask() - kCollisionAttributeEnemy);
	//
	FireTimed();
}

void Enemy::Update() {
	//
	timedCalls_.remove_if([](TimedCall* timedCalls) {
		if (timedCalls->IsFinished()) {
			delete timedCalls;
			return true;
		}
		return false;
	});
	for (TimedCall* timedCalls : timedCalls_) {
		timedCalls->Update();
	}
	//
	worldTransform_.TransferMatrix();
}

void Enemy::Draw(ViewProjection2D& viewProjection) { 
	Matrix3x3 wvpVpMatrix = MyMath::Multiply(worldTransform_.matWorld_, viewProjection.wvpVpMatrix_);
	worldTransform_.screen_ = MyMath::MakeScreenVertex(worldTransform_.local_, wvpVpMatrix);
	MyMath::DrawSprite(worldTransform_.screen_, 64, 64, textureHandle_, 0x008800ff);
}

void Enemy::FireTimed() {
	Fire();
	//
	timedCalls_.push_back(new TimedCall(std::bind_front(&Enemy::FireTimed, this), kFireInterval));
}

void Enemy::FireCancel() {
	timedCalls_.clear();
}

void Enemy::OnCollision(ColliderName name) {
	if (name == PLAYER) {

	}
	isDead_ = true;
	if (player_->isShield()) {
		
	}
}

void Enemy::Fire() {
	assert(player_);
	//
	const float kBulletSpeed = 1.0f;

	Vector2 velocity{ player_->GetWorldPosition().x - GetWorldPosition().x,player_->GetWorldPosition().y - GetWorldPosition().y };
	velocity = { MyMath::Normalize(velocity.x,MyMath::Length(velocity.x,velocity.y)),MyMath::Normalize(velocity.y,MyMath::Length(velocity.x,velocity.y)) };
	velocity = {kBulletSpeed * velocity.x , kBulletSpeed * velocity.y};

	EnemyBullet* newBullet = new EnemyBullet();
	newBullet->Initialize(worldTransform_.translation_, velocity);
	sceneGame_->AddEnemyBullet(newBullet);
}

void Enemy::SetWorldTransformTranslation(const Vector2& translation) { worldTransform_.translation_ = translation; }

Vector2 Enemy::GetWorldPosition() {
	Vector2 worldPos;
	worldPos.x = worldTransform_.matWorld_.m[2][0];
	worldPos.y = worldTransform_.matWorld_.m[2][1];
	return worldPos;
}
