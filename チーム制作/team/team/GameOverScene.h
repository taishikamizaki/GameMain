#pragma once
#include "BaseScene.h"


class GameOverScene :
    public BaseScene
{
public:
	GameOverScene();
	~GameOverScene();

	ScnBase update(ScnBase scnID) override;
	void GameOverDraw(void);

private:
	
int  GameOverCnt;		// 自動遷移用カウント
bool GameOverFlag;		// 自動遷移用フラグ
};

