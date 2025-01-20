#include "SceneManager.h"
#include "Scene_Title.h"
#include "Scene_Game.h"
#include "Scene_Clear.h"

SceneManager::SceneManager() {
	// 各シーンのインスタンスの作成
	sceneArr_ = std::make_unique<Scene_Title>();
}

/// <summary>
/// 各シーンの初期化 更新処理 描画処理を行う
/// </summary>
void SceneManager::Run() {
	while (Novice::ProcessMessage() == 0) {
		// フレームの開始
		Novice::BeginFrame();

		memcpy(inputManager->GetPreKeys(), inputManager->GetKeys(), 256);
		Novice::GetHitKeyStateAll(inputManager->GetKeys());

		// フルスクリーンの切り替え
		if (inputManager->GetKeys()[DIK_F11] && !inputManager->GetPreKeys()[DIK_F11]) {
			isFullScreen_ = !isFullScreen_;
			if (isFullScreen_) {
				Novice::SetWindowMode(WindowMode::kFullscreen);
			}
			else {
				Novice::SetWindowMode(WindowMode::kWindowed);
			}
		}

		prevSceneNo_ = currentSceneNo_;
		currentSceneNo_ = sceneArr_->GetSceneNo();

		if (prevSceneNo_ != currentSceneNo_) {
			if (currentSceneNo_ == TITLE) {
				sceneArr_ = std::make_unique<Scene_Title>();
			}
			if (currentSceneNo_ == GAME) {
				sceneArr_ = std::make_unique<Scene_Game>();
			}
			if (currentSceneNo_ == CLEAR) {
				sceneArr_ = std::make_unique<Scene_Clear>();
			}
			sceneArr_->Init();
		}

		sceneArr_->Update();

		sceneArr_->Draw();
		// フレームの終了
		Novice::EndFrame();

		// ESCキーが押されたらループを抜ける
		if (inputManager->GetPreKeys()[DIK_ESCAPE] == 0 && inputManager->GetKeys()[DIK_ESCAPE] != 0) {
			break;
		}
	}
}