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
	//int  GameOverCnt;		// �����J�ڗp�J�E���g
	//bool GameOverFlag;		// �����J�ڗp�t���O
};

