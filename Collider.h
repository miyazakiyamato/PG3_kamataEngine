#pragma once
#include "CollisionConfig.h"
#include "MyMath.h"
#include "WorldTransform2D.h"
#include "ViewProjection2D.h"
enum ColliderName {
	PLAYER,
	ENEMY,
	PLAYERBULLET,
	ENEMYBULLET,
};

class Collider {
public:
	virtual ~Collider() {}

	virtual void OnCollision(ColliderName name) = 0;

protected:
	float radius_ = 1.0f;
	bool isAlive_ = true;
	ColliderName name_ = PLAYER;
private:
	//
	unsigned int collisionAttribute_ = 0xffffffff;
	unsigned int collisionMask_ = 0xffffffff;

public:
	ColliderName GetName() { return name_; }
	void SetName(ColliderName name) { name_ = name; }
	float GetRadius() { return radius_; }
	void SetRadius(const float& radius) { radius_ = radius; }
	virtual Vector2 GetWorldPosition() = 0;
	unsigned int GetCollisionAttribute() { return collisionAttribute_; }
	void SetCollisionAttribute(const unsigned int& collisionAttribute) { collisionAttribute_ = collisionAttribute; }
	unsigned int GetCollisionMask() { return collisionMask_; }
	void SetCollisionMask(const unsigned int& collisionMask) { collisionMask_ = collisionMask; }
	bool GetIsAlive() { return isAlive_; }
	void SetIsAlive(const bool& isAlive) { isAlive_ = isAlive; }
};
