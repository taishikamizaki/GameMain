
#include <DxLib.h>
#include "../key/GetKeyState.h"
#include "GameOver.h"

// 初期化処理
int GameOver::Init()
{
	gameOver = LoadGraph("image/TestGraph/GameOver.png");
	thank = LoadGraph("image/logo/Thank.png");
	space = LoadGraph("image/logo/space.png");

	SetVolumeMusic(10);
	return 0;
}

// 操作処理
int GameOver::GameOverCtl()
{
	if (keyDownTrigger[KEY_ID_1START] ||
		keyDownTrigger[KEY_ID_2START] ||
		keyDownTrigger[CONFIRM1] ||
		keyDownTrigger[CONFIRM2])
	{
		PlaySoundFile("sound/button/confirm", DX_PLAYTYPE_BACK);
		goF = true;
	}
	return 0;
}

// 描画処理
int GameOver::Draw()
{
	DrawGraph(0, 0, gameOver, true);
	DrawGraph(74, 0, thank, true);
	DrawGraph(250, 540, space, true);

<<<<<<< HEAD

=======
>>>>>>> 139ec4b61e14886e2ab4791274327e02d5b6b7c9
	return 0;
}

// コンストラクタ
GameOver::GameOver()
{
	now = GetNowCount();
	goF = false;
	Init();
}

// デストラクタ
GameOver::~GameOver()
{

}

