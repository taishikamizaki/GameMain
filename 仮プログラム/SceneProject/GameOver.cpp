
#include <DxLib.h>
#include "ScnMng.h"
#include "GameOver.h"

// 初期化処理
int GameOver::Init()
{
	gameOver = LoadGraph("image/TestGraph/GameOver.png");
	space = LoadGraph("image/TestGraph/space.png");

	return 0;
}

// 操作処理
int GameOver::GameOverCtl()
{
	/*if (GetNowCount() - now >= 6000)
	{
		now = GetNowCount();
		goF = true;
	}*/
	if (SCN_MNG.keyFlagSp && !SCN_MNG.keyFlagOld)
	{
		goF = true;
	}
	return 0;
}

// 描画処理
int GameOver::Draw()
{
	DrawGraph(0, 0, gameOver, true);
	DrawGraph(250, 540, space, true);

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

