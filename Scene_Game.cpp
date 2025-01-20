#include "Scene_Game.h"
#include "fstream"
#include <cassert>

/// <summary>
/// デストラクタ
/// </summary>
Scene_Game::~Scene_Game(){
	delete player_;
	delete playerBullet_;
	for (Enemy* enemy : enemy_) {
		delete enemy;
	}
	for (EnemyBullet* bullet : enemyBullets_) {
		delete bullet;
	}
}

/// <summary>
/// 初期化
/// </summary>
void Scene_Game::Init() {
	collisionManager_ = new CollisionManager();

	worldTransform_.Initialize(0);
	viewProjection_.Initialize();

	player_ = new Player();
	player_->Initialize(Novice::LoadTexture("./NoviceResources/maru.png"), { 0,0 });

	playerBullet_ = new PlayerBullet();
	playerBullet_->Initialize(Novice::LoadTexture("./NoviceResources/maru.png"), { 0,0 });
	playerBullet_->SetPlayer(player_);

	player_->SetPlayerBullet(playerBullet_);

	enemyCount_ = 0;
	enemyPopTimer_ = 0;
	IsEnemyPop_ = false;

	hpGh_ = Novice::LoadTexture("./NoviceResources/hart.png");

	LoadEnemyPopData();
}

/// <summary>
/// 更新処理
/// </summary>
void Scene_Game::Update() {

	player_->Update();
	playerBullet_->Update();
	UpdateEnemyPopCommands();
	for (Enemy* enemy : enemy_) {
		enemy->Update();
		if (enemy->isDead()) {
			enemyCount_++;
			if (enemyCount_ >= 24) {
				sceneNo_ = CLEAR;
			}
		}
	}
	enemy_.remove_if([](Enemy* enemy) {
		if (enemy->isDead()) {
			delete enemy;
			return true;
		}
		return false;
		});
	for (EnemyBullet* bullet : enemyBullets_) {
		bullet->Update(player_->GetWorldPosition());
	}
	enemyBullets_.remove_if([](EnemyBullet* bullet) {
		if (bullet->isDead()) {
			delete bullet;
			return true;
		}
		return false;
		});

	collisionManager_->ColliderClear();
	SetAllCollisions();
	collisionManager_->CheckAllCollisions();

	viewProjection_.ViewProjectionUpdate();

	/*if (inputManager->GetKeys()[DIK_SPACE] && !inputManager->GetPreKeys()[DIK_SPACE]) {
		sceneNo_ = CLEAR;
	}*/
	if (player_->isDead()) {
		sceneNo_ = TITLE;
	}
}

/// <summary>
/// 描画処理
/// </summary>
void Scene_Game::Draw() {

	Novice::DrawBox(0, 0, 1280, 720, 0.0f, 0x888888ff, kFillModeSolid);

	player_->Draw(viewProjection_);
	playerBullet_->Draw(viewProjection_);
	for (Enemy* enemy : enemy_) {
		enemy->Draw(viewProjection_);
	}
	for (EnemyBullet* bullet : enemyBullets_) {
		bullet->Draw(viewProjection_);
	}
	for (int i = 0; i < player_->GetHP(); i++) {
		Novice::DrawSprite(40 * i + 20, 20, hpGh_, 0.5f, 0.5f, 0.0f, 0xffffffff);
	}
	/*====================================================
		デバッグ表示										*/
#ifdef _DEBUG

#endif
	
}


void Scene_Game::AddEnemy(const Vector2& position)
{
	Enemy* newEnemy = new Enemy();
	newEnemy->SetPlayer(player_);
	newEnemy->SetGameScene(this);
	newEnemy->Initialize(Novice::LoadTexture("./NoviceResources/maru.png"), position);
	enemy_.push_back(newEnemy);
}

void Scene_Game::AddEnemyBullet(EnemyBullet* enemyBullet)
{
	enemyBullets_.push_back(enemyBullet);
}

void Scene_Game::SetAllCollisions()
{
	collisionManager_->SetColliders(player_);
	collisionManager_->SetColliders(playerBullet_);
	for (Enemy* enemy : enemy_) {
		collisionManager_->SetColliders(enemy);
	}
	for (EnemyBullet* bullet : enemyBullets_) {
		collisionManager_->SetColliders(bullet);
	}
}
void Scene_Game::LoadEnemyPopData() {
	std::ifstream file{};
	file.open("./enemyPop.csv");
	assert(file.is_open());
	//
	enemyPopCommands << file.rdbuf();
	//
	file.close();
}

void Scene_Game::UpdateEnemyPopCommands() {
	//待機処理
	if (IsEnemyPop_) {
		enemyPopTimer_--;
		if (enemyPopTimer_ <= 0) {
			//
			IsEnemyPop_ = false;
		}
		return;
	}
	//
	std::string line;
	while (getline(enemyPopCommands, line)) {
		std::stringstream line_stream(line);

		std::string word;
		//
		getline(line_stream, word, ',');
		if (word.find("//") == 0) {
			continue;
		}
		//POP
		if (word.find("POP") == 0) {
			//x
			getline(line_stream, word, ',');
			float x = (float)std::atof(word.c_str());
			//y
			getline(line_stream, word, ',');
			float y = (float)std::atof(word.c_str());
			//
			AddEnemy(Vector2(x, y));
		}
		//WAIT
		else if (word.find("WAIT") == 0) {
			getline(line_stream, word, ',');
			//
			int32_t waitTime = atoi(word.c_str());
			//待機開始
			IsEnemyPop_ = true;
			enemyPopTimer_ = waitTime;
			//
			break;
		}
	}

}
