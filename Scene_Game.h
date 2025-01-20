#pragma once
#include "IScene.h"
#include "WorldTransform2D.h"
#include "ViewProjection2D.h"
#include "Player.h"
#include "PlayerBullet.h"
#include "Enemy.h"
#include "EnemyBullet.h"
#include "CollisionManager.h"
#include <sstream>

/// <summary>
/// ゲームシーンのクラス
/// </summary>
class Scene_Game :public IScene {
public:
	/// <summary>
	/// メンバ関数
	/// </summary>
	// コンストラクタ
	Scene_Game() {}
	// デストラクタ
	~Scene_Game();
	//関数
	void Init()override;
	void Update()override;
	void Draw()override;

	void AddEnemy(const Vector2& position);
	void AddEnemyBullet(EnemyBullet* enemyBullet);

	void LoadEnemyPopData();
	void UpdateEnemyPopCommands();
private:
	/// <summary>
	/// このクラスのメンバ変数
	/// </summary>
	CollisionManager* collisionManager_ = nullptr;

	WorldTransform2D worldTransform_;
	ViewProjection2D viewProjection_;

	//
	Player* player_ = nullptr;
	PlayerBullet* playerBullet_ = nullptr;
	
	std::list <Enemy*> enemy_;
	std::list<EnemyBullet*> enemyBullets_;

	int enemyCount_ = 0;
	int hpGh_ = 0;
	//敵発生コマンド
	std::stringstream enemyPopCommands;
	int32_t enemyPopTimer_ = 0;
	bool IsEnemyPop_ = false;
	//関数
	void SetAllCollisions();
};