#pragma once
#include "BaseScene.h"


class GameOverScene :
	public BaseScene
{
public:
	ScnBase Update(ScnBase scnID) override;
	GameOverScene();
	~GameOverScene();
private:
	int now;
	bool	goEnd;
};

