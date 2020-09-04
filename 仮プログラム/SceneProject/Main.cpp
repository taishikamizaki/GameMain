
#include  <DxLib.h>
#include "ScnMng.h"

// メイン関数
int WINAPI WinMain (_In_ HINSTANCE, _In_opt_ HINSTANCE, _In_ LPSTR, _In_ int)
{
	SCN_MNG.ScnCtl();	// マネージャー呼び出し
	DxLib_End();
	return 0;
}