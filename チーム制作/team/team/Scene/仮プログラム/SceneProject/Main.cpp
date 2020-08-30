
#include  <DxLib.h>
#include "ScnMng.h"

int WINAPI WinMain (_In_ HINSTANCE, _In_opt_ HINSTANCE, _In_ LPSTR, _In_ int)
{
	SCN_MNG.ScnCtl();
	DxLib_End();
	return 0;
}