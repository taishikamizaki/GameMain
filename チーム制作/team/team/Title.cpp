#include "DxLib.h"
#include "Title.h"
#include "main.h"
#include "Init.h"
#include "GetKeyState.h"
#include "Effect.h"


bool TitleInit(void)
{
	TitleScene();
	return 0;
}

bool TitleScene(void)
{
	
	TitleDraw();
	return false;
}

void TitleDraw(void)
{
	DrawFormatString(0, 0, 0xFFFFFF, "TitleScene");
}