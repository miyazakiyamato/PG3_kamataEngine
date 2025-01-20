#include <Novice.h>
#include "SceneManager.h"

const char kWindowTitle[] = "LE2B_21_ミヤザキ_ヤマト";

#pragma warning(push)
// C28251の警告(WinMain)を見なかったことにする
#pragma warning(disable:28251)
// Windowsアプリでのエントリーポイント(main関数)
int WINAPI WinMain(HINSTANCE, HINSTANCE, LPSTR, int) {
#pragma warning(pop)

	// ライブラリの初期化
	Novice::Initialize(kWindowTitle, 1280, 720);

	// シーン管理クラスのインスタンスの作成
	SceneManager* sceneManger_ = new SceneManager();

	// ウィンドウの×ボタンが押されるまでループ
	sceneManger_->Run();

	// ライブラリの終了
	Novice::Finalize();

	// 開放
	delete sceneManger_;

	return 0;
}