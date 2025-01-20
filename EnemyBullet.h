#pragma once
#include "Collider.h"

class EnemyBullet : public Collider {
public:
	EnemyBullet() {}
	~EnemyBullet() {}
	
	void Initialize(const Vector2& position, const Vector2& velocity);
	void Update(const Vector2& velocity);
	void Draw(const ViewProjection2D& viewProjection);
	//
	void OnCollision(ColliderName name) override;

private:
	// 寿命
	static const int kLifeTime = 60 * 5;

	//
	WorldTransform2D worldTransform_{};
	//
	int textureHandle_ = 0;
	//
	Vector2 velocity_{};
	int count = 0;
	// デスタイマー
	int deathTimer_ = kLifeTime;
	// デスフラグ
	bool isDead_ = false;
	//関数
	

public:
	bool isDead() const { return isDead_; }
	Vector2 GetWorldPosition() override;
};
