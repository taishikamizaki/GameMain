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
	
int  GameOverCnt;		// �����J�ڗp�J�E���g
bool GameOverFlag;		// �����J�ڗp�t���O
};

