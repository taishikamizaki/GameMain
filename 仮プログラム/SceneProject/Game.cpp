
#include <DxLib.h>
#include "ScnMng.h"
#include "player.h"
#include "Game.h"

// 初期化処理
int Game::Init()
{
	select = LoadGraph("image/TestGraph/Select.png");
	game = LoadGraph("image/TestGraph/Game.png");
	space = LoadGraph("image/TestGraph/space.png");

	if (player == nullptr)
	{
		player = new Player(charID_1, pID_1, charID_2, pID_2);
		if (player != nullptr) player->SetPlayerID({ 10,0 }, { 60,0 });
	}

	return 0;
}

// セレクトの操作処理
int Game::SelectCtl()
{
	if (SCN_MNG.keyFlagSp && !SCN_MNG.keyFlagOld)
	{
		selectF = false;
		gameF = true;
	}
	return 0;
}

// ゲームの操作処理
int Game::GameCtl()
{

	if (player != nullptr) player->PlayerCtl();
	return 0;
}

// 描画処理(セレクトとゲーム切り替え同梱)
int Game::Draw()
{
	if (selectF && !gameF)
	{
		DrawGraph(0, 0, select, true);
		DrawGraph(250, 540, space, true);
	}
	else if(!selectF && gameF)
	{
		DrawGraph(0, 0, game, true);
		DrawGraph(250, 540, space, true);
	    if (player != nullptr) player->PlayerDraw();
		if (SCN_MNG.keyFlagSp && !SCN_MNG.keyFlagOld)
		{
			gameF = false;
			_gameF = true;
		}
	}
	return 0;
}

// コンストラクタ
Game::Game()
{
	selectF = true;
	gameF = false;
	_gameF = false;

	

	Init();
}

// デストラクタ
Game::~Game()
{
	if (player != nullptr)
	{
		delete player;
		player = nullptr;
	}
}
