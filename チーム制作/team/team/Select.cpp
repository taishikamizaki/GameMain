#include "DxLib.h"
#include "Select.h"
#include "main.h"
#include "GetKeyState.h"
#include "Effect.h"

bool SelectInit(void)
{
	bool rtnFlag = true;

	return rtnFlag;
}

bool SelectScene(void)
{
	bool rtnFlag = true;
	scnID = SCN_ID_SELECT;
	if (keyDownTrigger[KEY_ID_SPACE])
	{
		fadeOut = true;
		
	}
	return rtnFlag;
}

void SelectDraw(void)
{
	DrawFormatString(0, 0, 0xFFFFFF, "SelectScene");
}

