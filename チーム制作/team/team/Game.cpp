#include "DxLib.h"
#include "main.h"
#include "GetKeyState.h"
#include "Stage.h"
#include "player.h"
#include "Effect.h"
#include "Game.h"

Pos playerPos[4];

bool InitScene(void)
{
	bool rtnFlag = true;

	return rtnFlag;
}

// ������
bool GameInit(void)
{
	bool rtnFlag = true;

	return rtnFlag;
}

// ���
bool GameScene(void)
{
	bool rtnFlag = true;

	playerPos[4] = { , };

	GameDraw();
	StageDraw();
	PlayerDraw();
	EffectDraw();
	return rtnFlag;
}

// �`��
void GameDraw(void)
{

}

