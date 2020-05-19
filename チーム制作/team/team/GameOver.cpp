#include "DxLib.h"
#include "GameOver.h"
#include "main.h"
#include "GetKeyState.h"
#include "Effect.h"

bool GameOverInit(void)
{
	bool rtnFlag = true;
	GameOverScene();
	return rtnFlag;
}

bool GameOverScene(void)
{
	if (keyDownTrigger[KEY_ID_SPACE])
	{
		fadeOut = true;
	}
	GameOverDraw();
	return false;
}

void GameOverDraw(void)
{
	DrawFormatString(0, 0, 0xFFFFFF, "GameOverScene");
}


