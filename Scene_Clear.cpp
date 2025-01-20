#include "Scene_Clear.h"

void Scene_Clear::Init()
{
}

void Scene_Clear::Update()
{

	if (inputManager->GetKeys()[DIK_SPACE] && !inputManager->GetPreKeys()[DIK_SPACE]) {
		sceneNo_ = TITLE;
	}
}

void Scene_Clear::Draw()
{
	Novice::DrawBox(0, 0, 1280, 720, 0.0f, 0xffff88ff, kFillModeSolid);

	/*　　　　　　　　　デバッグ表示					*/
#ifdef _DEBUG

	Novice::ScreenPrintf(24, 24, "scene:game");
	Novice::ScreenPrintf(24, 48, "count = %d", count_);

#endif

}
