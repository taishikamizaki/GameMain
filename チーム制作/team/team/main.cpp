#include "DxLib.h"
#include "SceneMng.h"
#include "main.h"

// WinMain関数
int WINAPI WinMain(HINSTANCE,HINSTANCE,LPSTR,int)
{
	SCN_MNG.ScnCtl();		// シーンマネージャー様
	DxLib_End();
	return 0;
}


