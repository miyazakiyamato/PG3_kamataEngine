#pragma once
#include <memory>
#include "IScene.h"
#include "InputManager.h"
/// <summary>
/// シーンを管理するクラス
/// </summary>
class SceneManager {
private:
	/// <summary>
	/// メンバ変数
	/// </summary>
	std::unique_ptr<IScene> sceneArr_;

	InputManager* inputManager = InputManager::GetInstance();
	int stageNum{};
	SceneNo currentSceneNo_{};
	SceneNo prevSceneNo_{};

	// フルスクリーンモードか判断するフラグ
	bool isFullScreen_ = false;
public:
	/// <summary>
	/// メンバ関数
	/// </summary>

	// コンストラクタ
	SceneManager();

	// デストラクタ
	~SceneManager() {}

	void Run();
};