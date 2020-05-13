#include "DxLib.h"
#include "main.h"
#include "GetKeyState.h"
#include "Stage.h"
#include "player.h"
#include "Effect.h"
#include "Game.h"

Pos playerPos[CHAR_ID];

// èâä˙âª
bool GmaeInit(void)
{
	bool rtnFlag = true;

	return rtnFlag;
}

// º∞›
bool GmaeScene(void)
{
	bool rtnFlag = true;

	playerPos[] = { , };

	GameDraw();
	StageDraw();
	PlayerDraw();
	EffectDraw();
	return rtnFlag;
}

// ï`âÊ
void GameDraw(void)
{

}

