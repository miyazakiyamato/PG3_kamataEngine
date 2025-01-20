#include "Scene_Title.h"

/// <summary>
/// 初期化
/// </summary>
void Scene_Title::Init() {

	stageNum_ = 0;
	// シーン遷移に使う変数の初期化

	timer_ = 0.0f;

	// ここで0で初期化
	isModeSelect = false;

}

/// <summary>
/// 更新処理
/// </summary>
void Scene_Title::Update() {
	stageNum_ = 0;
	if (inputManager->GetKeys()[DIK_SPACE] && !inputManager->GetPreKeys()[DIK_SPACE]) {
		sceneNo_ = GAME;
	}
}

/// <summary>
/// 描画処理
/// </summary>
void Scene_Title::Draw() {

	Novice::DrawBox(0, 0, 1280, 720, 0.0f, 0x212121ff, kFillModeSolid);
	Novice::DrawSprite(0, 0, Novice::LoadTexture("./NoviceResources/Title.png"), 1, 1, 0.0f, 0xffffffff);
	/*====================================================
		デバッグ表示										*/
#ifdef _DEBUG

		/*Novice::ScreenPrintf(580, 360, "Press space to select");

		Novice::ScreenPrintf(24, 24, "scene:title");*/

#endif
		/*===================================================*/

	// シーン遷移の描画
}