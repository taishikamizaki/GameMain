#include "DxLib.h"
#include "main.h"
#include "GetKeyState.h"
#include "Stage.h"
#include "player.h"
#include "Effect.h"
#include "Game.h"

Pos playerPos[CHAR_ID];

// ������
bool GmaeInit(void)
{
	bool rtnFlag = true;

	return rtnFlag;
}

// ���
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

// �`��
void GameDraw(void)
{

}

