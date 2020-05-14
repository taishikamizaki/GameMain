#include "DxLib.h"
#include "Title.h"
#include "main.h"
#include "Init.h"
#include "GetKeyState.h"
#include "Effect.h"


bool TitleInit(void)
{
	bool rtnFlag = true;
	

	return rtnFlag;
}

bool TitleScene(void)
{
	bool rtnFlag = true;
	scnID = SCN_ID_TITLE;
	if (keyDownTrigger[KEY_ID_SPACE])
		{
			fadeOut = true;
			SysInit();
		}
	TitleDraw();
	return rtnFlag;
}

void TitleDraw(void)
{
	DrawFormatString(0, 0, 0xFFFFFF, "TitleScene");
}