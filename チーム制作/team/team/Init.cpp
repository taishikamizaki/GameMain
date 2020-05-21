#include "DxLib.h"
#include "main.h"
#include "Effect.h"
#include "Init.h"

// ‰Šú‰»
bool SysInit(void)
{
	bool rtnFlag = true;

	SetWindowText("HAMAGURI");
	// ¼½ÃÑˆ—
	SetGraphMode(SCREEN_SIZE_X, SCREEN_SIZE_Y, 16);
	ChangeWindowMode(true);
	if (DxLib_Init() == -1)
	{
		AST();
		return false;
	}

	SetDrawScreen(DX_SCREEN_BACK);

	// ‰Šú‰»
	EffectInit();
	
	/*TitleInit();*/

	scnID = SCN_ID_INIT;
	scnIDOld = SCN_ID_MAX;

	return rtnFlag;
}