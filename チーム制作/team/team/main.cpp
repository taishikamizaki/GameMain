#include "DxLib.h"
#include "Scene/SceneMng.h"

// WinMain�֐�
int WINAPI WinMain(_In_ HINSTANCE,_In_opt_ HINSTANCE,_In_ LPSTR,_In_ int)
{
	SceneMng::ScnGeter().ScnCreate();		// �}�l�[�W���[�𒼐ڃN���G�C�g
	SCN_MNG.ScnCtl();						// �V�[���}�l�[�W���[����
	DxLib_End();
	return 0;
}
