
#include <DxLib.h>
#include "ScnMng.h"
#include "Game.h"

int Game::Init()
{
	select = LoadGraph("image/TestGraph/Select.png");
	game = LoadGraph("image/TestGraph/Game.png");
	space = LoadGraph("image/TestGraph/please_space.png");

	return 0;
}

int Game::SelectCtl()
{
	if (SCN_MNG.keyFlagSp && !SCN_MNG.keyFlagOld)
	{
		selectF = false;
		gameF = true;
	}
	return 0;
}

int Game::GameCtl()
{
	
	return 0;
}

int Game::GameDraw()
{
	if (selectF && !gameF)
	{
		DrawGraph(0, 0, select, true);
	}
	else if(!selectF && gameF)
	{
		DrawGraph(0, 0, game, true);
		if (SCN_MNG.keyFlagSp && !SCN_MNG.keyFlagOld)
		{
			gameF = false;
			_gameF = true;
		}
	}

	return 0;
}

Game::Game()
{
	selectF = true;
	gameF = false;
	_gameF = false;
	Init();
}

Game::~Game()
{

}
