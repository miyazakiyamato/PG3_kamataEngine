#include "IScene.h"

//タイトルで初期化
SceneNo IScene::sceneNo_ = TITLE;

// シーン遷移を管理する静的メンバ変数
int IScene::count_ = 0;

// 最初はマウスで初期化
int IScene::operate_ = 0;

//
int IScene::stageNum_ = 0;

bool IScene::isModeSelect = false;
