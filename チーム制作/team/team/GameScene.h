#pragma once
#include "BaseScene.h"

// ゲームシーンクラス
class GameScene :
	public BaseScene		// 親クラス
{
public:
	ScnBase update(ScnBase scnID) override;
	void GameInit(void);
	void GameDraw(void);
	GameScene();
	~GameScene();

private:
	bool gamEnd;
};

