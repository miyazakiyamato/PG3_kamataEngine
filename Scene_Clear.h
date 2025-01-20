#pragma once
#include "IScene.h"
class Scene_Clear:public IScene
{
public:
	/// <summary>
	/// メンバ関数
	/// </summary>
	// コンストラクタ
	Scene_Clear() {}
	// デストラクタ
	~Scene_Clear() {}
	//関数
	void Init()override;
	void Update()override;
	void Draw()override;
};

