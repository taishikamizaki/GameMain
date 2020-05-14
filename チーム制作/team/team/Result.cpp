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
	bool rtnFlag = true;
	scnID = SCN_ID_RESULT;
	if (keyDownTrigger[KEY_ID_SPACE])
	{
		fadeOut = true;
		
	}
	return rtnFlag;
}

void ResultDraw(void)
{
	DrawFormatString(0, 0, 0xFFFFFF, "ResultScene");
}