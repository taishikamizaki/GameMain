#include "DxLib.h"
#include "main.h"
#include "Init.h"

// èâä˙âª
bool SysInit(void)
{
	bool rtnFlag = true;

	SetWindowText("HAMAGURI");
	// ºΩ√—èàóù
	SetGraphMode(SCREEN_SIZE_X, SCREEN_SIZE_Y, 16);
	ChangeWindowMode(true);
	if (DxLib_Init() == -1)
	{
		AST();
		return false;
	}

	SetDrawScreen(DX_SCREEN_BACK);
	scnID = SCN_ID_INIT;
	/*TitleInit();*/

	return rtnFlag;
}