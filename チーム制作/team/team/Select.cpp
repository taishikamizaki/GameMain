#include "DxLib.h"
#include "Select.h"
#include "main.h"
#include "GetKeyState.h"
#include "Effect.h"

bool SelectInit(void)
{
	bool rtnFlag = true;
	SelectScene();
	return rtnFlag;
}

bool SelectScene(void)
{
	if (keyDownTrigger[KEY_ID_SPACE])
	{
		fadeOut = true;
	}
	SelectDraw();
	return false;
}

void SelectDraw(void)
{
	DrawFormatString(0, 0, 0xFFFFFF, "SelectScene");
}

