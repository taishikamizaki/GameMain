#pragma once
#include "BaseScene.h"

// ゲームシーンクラス
class GameScene :
	public BaseScene		// 親クラス
{
public:
	ScnBase update(ScnBase scnID) override;
	GameScene();
	~GameScene();

private:

};

