#pragma once
#include "Collider.h"
class Player;

class PlayerBullet:public Collider
{
public:
	PlayerBullet() {};

	~PlayerBullet();
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
	Player* player_ = nullptr;

	WorldTransform2D worldTransform_;
	float length_ = 0;
	Vector2 velocity_{};
	int gh_ = 0;
	int aliveCount = 0;
public:
	void SetPlayer(Player* player) { player_ = player; }
	Vector2 GetWorldPosition();
	void SetWorldPosition(const Vector2& position) { worldTransform_.translation_ = position; }
	float GetLength() { return length_; }
	void SetLength(const float& length) { length_ = length; }
	Vector2 GetVelocity() { return velocity_; }
	void SetVelocity(const Vector2& velocity) { velocity_ = velocity; }
};

