#pragma once
#include "IScene.h"

/// <summary>
/// タイトルシーンのクラス
/// </summary>
class Scene_Title :
	// シーンの基底クラスを継承
	public IScene {
private:
	/// <summary>
	/// このクラスのメンバ変数
	/// </summary>
	InputManager* inputManager = InputManager::GetInstance();

	// タイトル画面のgh
	int titleGh_;

	// BGMのGh
	int titleBgmGh_;
	int titleBgmHandle_;
public:
	/// <summary>
	/// メンバ関数
	/// </summary>

	// コンストラクタ
	Scene_Title() {

		// インスタンスの作成
		Init();
	}

	// デストラクタ
	~Scene_Title() {

		// 開放
		
	}

	void Init()override;
	void Update()override;
	void Draw()override;
};