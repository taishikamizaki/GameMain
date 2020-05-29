#include "DxLib.h"
#include "GameOver.h"
#include "main.h"
#include "GetKeyState.h"
#include "Effect.h"

int  GameOverCnt;		// 自動遷移用カウント
bool GameOverFlag;		// 自動遷移用フラグ

// 初期化
bool GameOverInit(void)
{
	bool rtnFlag = true;
	GameOverCnt = 0;
	GameOverFlag = false;
	GameOverScene();
	return rtnFlag;
}

bool GameOverScene(void)
{
	if (keyDownTrigger[KEY_ID_SPACE] || GameOverFlag == true)
	{
		fadeOut = true;
	}
	GameOverDraw();
	return 0;
}

void GameOverDraw(void)
{
	GameOverCnt++;

	if (GameOverCnt == 100)
	{
		GameOverFlag = true;
	}

	DrawFormatString(0, 0, 0xFFFFFF, "GameOverScene");
}


