#include "DxLib.h"
#include "Result.h"
#include "main.h"
#include "GetKeyState.h"
#include "Effect.h"

bool ResultInit(void)
{
	bool rtnFlag = true;

	return rtnFlag;
}

bool ResultScene(void)
{
	if (keyDownTrigger[KEY_ID_SPACE])
	{
		fadeOut = true;
	}
	return false;
}

void ResultDraw(void)
{
	DrawFormatString(0, 0, 0xFFFFFF, "ResultScene");
}