
#include <DxLib.h>
#include "ScnMng.h"
#include "../key/GetKeyState.h"
#include "Title.h"

// 初期化処理
int Title::Init()
{
	title = LoadGraph("image/logo/titleB.png");
	titleL = LoadGraph("image/logo/Title.png");
	space = LoadGraph("image/logo/space.png");

	return 0;
}

// 操作処理
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

// 描画処理
int Title::Draw()
{
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

