#include "DxLib.h"
#include "SceneMng.h"

// WinMain�֐�
int WINAPI WinMain(HINSTANCE,HINSTANCE,LPSTR,int)
{
	SceneMng::ScnGeter().ScnCreate();		// �}�l�[�W���[�𒼐ڃN���G�C�g
	SCN_MNG.ScnCtl();						// �V�[���}�l�[�W���[����
	DxLib_End();
	return 0;
}
