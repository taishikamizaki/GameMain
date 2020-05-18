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
	scnID = SCN_ID_GAME;

	PlayerSysInit();

	if (keyDownTrigger[KEY_ID_SPACE])
	{
		fadeOut = true;
		
	}
	return rtnFlag;
}

// ���
bool GameScene(void)
{
	bool rtnFlag = true;

	playerPos[4] = { 0, 0};

	PlayerCtl();

	GameDraw();
	
	//EffectDraw(playerPos[4]);
	return rtnFlag;
}

// �`��
void GameDraw(void)
{
	DrawFormatString(0, 0, 0xFFFFFF, "GameScene");

	StageDraw();
	PlayerDraw();
}

