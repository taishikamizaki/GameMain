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
	int now;
	bool	goEnd;
};

