
#include <DxLib.h>
#include "ScnMng.h"
#include "../select.h"
#include "../stage/Stage.h"
#include "../player/player.h"
#include "Game.h"

// 初期化処理
int Game::Init()
{
	selectB = LoadGraph("image/TestGraph/Select.png");
	game = LoadGraph("image/TestGraph/Game.png");
	space = LoadGraph("image/logo/space.png");

	player1 = CHAR_ID::CHAR_ID_KISI;
	player2 = CHAR_ID::CHAR_ID_4;

    if (select == nullptr) select = new Select();
	if (player == nullptr) player = new Player();
	if (stage == nullptr) stage = new Stage();

	return 0;
}

// セレクトの操作処理
int Game::SelectCtl()
{
	if (SCN_MNG.keyFlagSp && !SCN_MNG.keyFlagOld)
	{
		if (select != nullptr)
		{
			select->SelectCtl();
		}
		selectF = false;
		gameF = true;
		if (select != nullptr)
		{
			delete select;
			select = nullptr;
		}
	}
	return 0;
}

// ゲームの操作処理
int Game::GameCtl()
{
	lpStage.StageCtl();
	if (player != nullptr) player->charCtl(player1, player2);
	if (player != nullptr) player->PlayerCtl();
	return 0;
}

// 描画処理(セレクトとゲーム切り替え同梱)
int Game::Draw()
{
	if (selectF && !gameF)
	{
		DrawGraph(0, 0, selectB, true);
		DrawGraph(250, 540, space, true);
	}
	else if(!selectF && gameF)
	{
		GameCtl();
		DrawGraph(0, 0, game, true);
		DrawGraph(250, 540, space, true);
		lpStage.StageDraw();
		if (player != nullptr)
		{
			player->PlayerDraw();
		}

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
	if (stage != nullptr)
	{
		delete stage;
		stage = nullptr;
	}
}
