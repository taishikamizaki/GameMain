#include "DxLib.h"
#include "Scene/SceneMng.h"

// WinMain関数
int WINAPI WinMain(_In_ HINSTANCE,_In_opt_ HINSTANCE,_In_ LPSTR,_In_ int)
{
	SceneMng::ScnGeter().ScnCreate();		// マネージャーを直接クリエイト
	SCN_MNG.ScnCtl();						// シーンマネージャー召喚
	DxLib_End();
	return 0;
}
