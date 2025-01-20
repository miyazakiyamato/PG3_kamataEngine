#pragma once
#include "Collider.h"
#include "InputManager.h"

class PlayerBullet;

class Player:public Collider
{
public:
	Player() {};

	~Player();
	/// <summary>
	/// 初期化
	/// </summary>
	void Initialize(int texture, const Vector2& position);

	/// <summary>
	/// 毎フレーム処理
	/// </summary>
	void Update();

	/// <summary>
	/// 描画
	/// </summary>
	void Draw(ViewProjection2D& viewProjection);

	void OnCollision(ColliderName name) override;
private:
	PlayerBullet* playerBullet_ = nullptr;

	InputManager* inputManager = InputManager::GetInstance();
	WorldTransform2D worldTransform_;
	int gh_ = 0;

	int hp_ = 5;
	bool isDead_ = false;

	int mouseX{}, mouseY{};
	Vector2 mouse{};

	bool IsShield_ = false;
	//
	void Move();
	void Attack();
public:
	bool isDead() const { return isDead_; }
	bool isShield() const { return IsShield_; }
	Vector2 GetWorldPosition();
	void SetPlayerBullet(PlayerBullet* playerBullet) { playerBullet_ = playerBullet; }
	int GetHP() { return hp_; }
};

