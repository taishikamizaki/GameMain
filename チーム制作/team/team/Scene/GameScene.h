#pragma once
#include "BaseScene.h"

// �Q�[���V�[���N���X
class GameScene :
	public BaseScene		// �e�N���X
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

