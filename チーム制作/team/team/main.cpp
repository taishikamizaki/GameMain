#include "DxLib.h"
#include "SceneMng.h"

// WinMain関数
int WINAPI WinMain(HINSTANCE,HINSTANCE,LPSTR,int)
{
	SceneMng::ScnGeter().ScnCreate();		// マネージャーを直接クリエイト
	SCN_MNG.ScnCtl();						// シーンマネージャー召喚
	DxLib_End();
	return 0;
}
