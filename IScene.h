#pragma once
#include <vector>
#include <Novice.h>
#include "InputManager.h"
// シーンの数
const int SCENE_NUM = 3;

// シーンの種類
enum SceneNo {
	TITLE,
	GAME,
	CLEAR,
};

/// <summary>
/// シーンの基底クラス
/// </summary>
class IScene {
protected:
	/// <summary>
	/// メンバ変数
	/// </summary>
	InputManager* inputManager = InputManager::GetInstance();
	static SceneNo sceneNo_;

	static int count_;
	float timer_ = 0.0f;

	// マウス操作かコントローラー操作か 0がマウス1がコントローラー
	static int operate_;

	//
	static int stageNum_;

	static bool isModeSelect;
public:
	/// <summary>
	/// メンバ関数
	/// </summary>

	// コンストラクタ
	IScene() {

		count_ = 0;
		timer_ = 0.0f;
	}

	// 仮想デストラクタ
	virtual ~IScene() {}

	// 純粋仮想関数
	virtual void Init() = 0;
	virtual void Update() = 0;
	virtual void Draw() = 0;

	/// <summary>
	/// ゲッター
	/// </summary>
	/// <returns></returns>
	SceneNo GetSceneNo() { return sceneNo_; }
};