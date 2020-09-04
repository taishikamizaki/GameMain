
#include <DxLib.h>
#include "ScnMng.h"
#include "Game.h"

// ����������
int Game::Init()
{
	select = LoadGraph("image/TestGraph/Select.png");
	game = LoadGraph("image/TestGraph/Game.png");
	space = LoadGraph("image/TestGraph/space.png");

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

}
