#pragma once
#include "BaseScene.h"


class GameOverScene :
	public BaseScene
{
public:
	ScnBase update(ScnBase scnID) override;
	GameOverScene();
	~GameOverScene();
private:
	//int  GameOverCnt;		// 自動遷移用カウント
	//bool GameOverFlag;		// 自動遷移用フラグ
};

