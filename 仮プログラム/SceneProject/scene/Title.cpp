
#include <DxLib.h>
#include "ScnMng.h"
#include "../key/GetKeyState.h"
#include "Title.h"

// ����������
int Title::Init()
{
	title = LoadGraph("image/logo/titleB.png");
	titleL = LoadGraph("image/logo/Title.png");
	space = LoadGraph("image/logo/space.png");
	titleBgm = LoadSoundMem("sound/bgm/title/fi_Knights.mp3");

	return 0;
}

// ���쏈��
int Title::TitleCtl()
{
	if (keyDownTrigger[KEY_ID_1START] || 
		keyDownTrigger[KEY_ID_2START] || 
		keyDownTrigger[CONFIRM1] || 
		keyDownTrigger[CONFIRM2])
	{
		PlaySoundFile("sound/button/confirm.mp3",DX_PLAYTYPE_BACK);

		titleF = true;
	}
	return 0;
}

// �`�揈��
int Title::Draw()
{
	PlayMusic("sound/bgm/select/select.mp3", DX_PLAYTYPE_LOOP);
	DrawGraph(0, 0, title, true);
	DrawGraph(200, 120, titleL, true);
	DrawGraph(250, 540, space, true);

	

	return 0;
}

Title::Title()
{
	titleF = false;
	Init();
}

Title::~Title()
{

}

