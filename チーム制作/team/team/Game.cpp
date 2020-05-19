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

// èâä˙âª
bool GameInit(void)
{
	PlayerSysInit();

	GameScene();

	
	return false;
}

// º∞›
bool GameScene(void)
{
	bool rtnFlag = true;

	playerPos[4] = { 0, 0};

	PlayerCtl();

	if (keyDownTrigger[KEY_ID_SPACE])
	{
		fadeOut = true;

	}
	GameDraw();
	
	//EffectDraw(playerPos[4]);
	return rtnFlag;
}

// ï`âÊ
void GameDraw(void)
{
	DrawFormatString(0, 0, 0xFFFFFF, "GameScene");

	StageDraw();
	PlayerDraw();
}

