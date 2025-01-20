#include "CollisionManager.h"

CollisionManager::~CollisionManager() { ColliderClear(); }

void CollisionManager::CheckCollisionPair(Collider* colliderA, Collider* colliderB) {
	if ((colliderA->GetCollisionAttribute() & colliderB->GetCollisionMask()) == 0 || (colliderB->GetCollisionAttribute() & colliderA->GetCollisionMask()) == 0) {
		return;
	}
	if (colliderA->GetIsAlive() == false || colliderB->GetIsAlive() == false) {
		return;
	}
	Vector2 posA = colliderA->GetWorldPosition();
	Vector2 posB = colliderB->GetWorldPosition();

	float length = powf(posB.x - posA.x, 2) + powf(posB.y - posA.y, 2);

	if (length <= powf(colliderA->GetRadius() + colliderB->GetRadius(), 2)) {
		colliderA->OnCollision(colliderB->GetName());
		colliderB->OnCollision(colliderA->GetName());
	}
}

void CollisionManager::CheckAllCollisions() {
#pragma region 当たり判定
	std::list<Collider*>::iterator itrA = colliders_.begin();
	for (; itrA != colliders_.end(); ++itrA) {
		std::list<Collider*>::iterator itrB = itrA;
		itrB++;
		for (; itrB != colliders_.end(); ++itrB) {
			CheckCollisionPair(*itrA, *itrB);
		}
	}
#pragma endregion 
}

void CollisionManager::ColliderClear() {
	colliders_.clear();
}
