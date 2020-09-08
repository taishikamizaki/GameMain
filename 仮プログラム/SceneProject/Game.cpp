
#include <DxLib.h>
#include "ScnMng.h"
#include "player.h"
#include "Game.h"

// ����������
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

// �Z���N�g�̑��쏈��
int Game::SelectCtl()
{
	if (SCN_MNG.keyFlagSp && !SCN_MNG.keyFlagOld)
	{
		selectF = false;
		gameF = true;
	}
	return 0;
}

// �Q�[���̑��쏈��
int Game::GameCtl()
{

	if (player != nullptr) player->PlayerCtl();
	return 0;
}

// �`�揈��(�Z���N�g�ƃQ�[���؂�ւ�����)
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

// �R���X�g���N�^
Game::Game()
{
	selectF = true;
	gameF = false;
	_gameF = false;

	

	Init();
}

// �f�X�g���N�^
Game::~Game()
{
	if (player != nullptr)
	{
		delete player;
		player = nullptr;
	}
}
