#include "DxLib.h"
#include "SceneMng.h"
#include "main.h"

// WinMain�֐�
int WINAPI WinMain(HINSTANCE,HINSTANCE,LPSTR,int)
{
	SCN_MNG.ScnCtl();		// �V�[���}�l�[�W���[�l
	DxLib_End();
	return 0;
}


