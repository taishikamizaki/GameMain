#include "DxLib.h"
#include "GameOver.h"
#include "main.h"
#include "GetKeyState.h"
#include "Effect.h"

bool GameOverInit(void)
{
	bool rtnFlag = true;

	return rtnFlag;
}

bool GameOverScene(void)
{
	bool rtnFlag = true;
	scnID = SCN_ID_GAMEOVER;
	if (keyDownTrigger[KEY_ID_SPACE])
	{
		fadeOut = true;
		
	}
	return rtnFlag;
}

void GameOverDraw(void)
{
	DrawFormatString(0, 0, 0xFFFFFF, "GameOverScene");
}


