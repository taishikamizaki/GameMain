
#include <DxLib.h>
#include "GameOver.h"

int GameOver::Init()
{
	gameOver = LoadGraph("image/TestGraph/GameOver.png");

	return 0;
}

int GameOver::GameOverCtl()
{
	if (GetNowCount() - now >= 3000)
	{
		now = GetNowCount();
		goF = true;
	}
	return 0;
}

int GameOver::GameOverDraw()
{
	DrawGraph(0, 0, gameOver, true);

	return 0;
}

GameOver::GameOver()
{
	now = GetNowCount();
	goF = false;
	Init();
}

GameOver::~GameOver()
{

}

