#pragma once
#include "BaseScene.h"

// �Q�[���V�[���N���X
class GameScene :
	public BaseScene		// �e�N���X
{
public:
	bool InitScene(void);
	bool GameInit(void);			// ������
	bool Game(void);				// �����
	void GameDraw(void);			// �`��

private:


};

