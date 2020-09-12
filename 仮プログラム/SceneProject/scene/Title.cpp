
#include <DxLib.h>
#include "ScnMng.h"
#include "../key/GetKeyState.h"
#include "Title.h"

// ‰Šú‰»ˆ—
int Title::Init()
{
	title = LoadGraph("image/logo/titleB.png");
	titleL = LoadGraph("image/logo/Title.png");
	space = LoadGraph("image/logo/space.png");

	SetVolumeMusic(10);
	return 0;
}

// ‘€ìˆ—
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

// •`‰æˆ—
int Title::Draw()
{
	DrawGraph(0, 0, title, true);
	DrawGraph(200, 120, titleL, true);
	DrawGraph(250, 540, space, true);

	PlaySoundFile("sound/bgm/title/title.mp3", DX_PLAYTYPE_LOOP);

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

