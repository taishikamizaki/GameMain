
#include <DxLib.h>
#include "../key/GetKeyState.h"
#include "../select.h"
#include "Game.h"

// ����������
int Game::Init()
{
	selectB = LoadGraph("image/TestGraph/seleB.png");
	game = LoadGraph("image/TestGraph/Game.png");
	space = LoadGraph("image/logo/space.png");

	player1 = CHAR_ID::CHAR_ID_MAX;
	player2 = CHAR_ID::CHAR_ID_MAX;

    if (select == nullptr) select = new Select();
	if (player == nullptr) player = new Player();
	if (stage == nullptr) stage = new Stage();

	if (select != nullptr) select->Select::Select();
	return 0;
}

// �Z���N�g�̑��쏈��
int Game::SelectCtl()
{
	if (select != nullptr)
	{
		select->SelectCtl();

		if (select->GetSelectFlag())
		{
			selectF = false;
			gameF = true;
		}
	}
	return 0;
}

// �Q�[���̑��쏈��
int Game::GameCtl()
{
	if (select != nullptr)
	{
		player1 = select->GetP1();
		player2 = select->GetP2();
		stageID = select->GetStage();

		if (stage != nullptr) stage->StageCtl(stageID);
		if (player != nullptr) player->charCtl(player1, player2);
	}
	if (player != nullptr) player->PlayerCtl(stageID);
	return 0;
}

// �`�揈��(�Z���N�g�ƃQ�[���؂�ւ�����)
int Game::Draw()
{
	if (selectF && !gameF)
	{
		DrawGraph(0, 0, selectB, true);
		if (select != nullptr) select->Draw();
	}
	else if(!selectF && gameF)
	{
		GameCtl();
		DrawGraph(0, 0, game, true);
		DrawGraph(250, 540, space, true);
		if(stage != nullptr) stage->StageDraw(stageID);
		if (player != nullptr)
		{
			player->PlayerDraw();
		}

		if (keyDownTrigger[KEY_ID_1START] ||
			keyDownTrigger[KEY_ID_2START] ||
			keyDownTrigger[CONFIRM1] ||
			keyDownTrigger[CONFIRM2])
		{
			gameF = false;
			_gameF = true;
		}
	}
	return 0;
}

// �R���X�g���N�^
Game::Game():charCnt(0)
{
	selectF = true;
	gameF = false;
	_gameF = false;

	Init();
}

// �f�X�g���N�^
Game::~Game()
{
	if (select != nullptr)
	{
		delete select;
		select = nullptr;
	}
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
