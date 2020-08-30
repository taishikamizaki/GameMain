
#include <DxLib.h>
#include "ScnMng.h"
#include "Game.h"

int Game::Init()
{
	select = LoadGraph("image/TestGraph/Select.png");
	game = LoadGraph("image/TestGraph/Game.png");

	return 0;
}

int Game::GameCtl()
{
	if (SCN_MNG.keyFlagSp && !SCN_MNG.keyFlagOld)
	{
		gameF = true;
	}
	return 0;
}

int Game::GameDraw()
{
	DrawGraph(0, 0, select, true);
	if (gameF)
	{
		DrawGraph(0, 0, game, true);
		if (SCN_MNG.keyFlagSp && !SCN_MNG.keyFlagOld)
		{
			_gameF = true;
		}
	}

	return 0;
}

Game::Game()
{
	gameF = false;
	_gameF = false;
	Init();
}

Game::~Game()
{

}
