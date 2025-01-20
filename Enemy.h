#pragma once
#include "EnemyBullet.h"
#include "list"
#include "TimedCall.h"
#include "Collider.h"

class Scene_Game;
class Player;

class Enemy:public Collider {
public:
	Enemy(){};
	~Enemy();
	/// <summary>
	/// 初期化
	/// </summary>
	void Initialize(int texture,const Vector2& position);

	/// <summary>
	/// 毎フレーム処理
	/// </summary>
	void Update();

	/// <summary>
	/// 描画
	/// </summary>
	void Draw(ViewProjection2D& viewProjection);

	//発射間隔
	static const int kFireInterval = 60;
	//
	void Fire();
	void FireTimed();
	void FireCancel();
	//
	void OnCollision(ColliderName name) override;

private:
	Scene_Game* sceneGame_ = nullptr;
	//
	Player* player_ = nullptr;
	// ワールド変換データ
	WorldTransform2D worldTransform_{};
	// テクスチャハンドル
	int textureHandle_ = 0;
	//時限発射のリスト
	std::list<TimedCall*> timedCalls_;
	//
	bool isDead_ = false;

public:
	bool isDead() const { return isDead_; }
	Vector2 GetWorldTransformTranslation() const{ return worldTransform_.translation_; }
	void SetWorldTransformTranslation(const Vector2& translation);
	void SetPlayer(Player* player) { player_ = player; }
	Vector2 GetWorldPosition() override;
	void SetGameScene(Scene_Game* sceneGame) { sceneGame_ = sceneGame; }
};
