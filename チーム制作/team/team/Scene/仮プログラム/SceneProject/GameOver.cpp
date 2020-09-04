
#include <DxLib.h>
#include "ScnMng.h"
#include "GameOver.h"

// ����������
int GameOver::Init()
{
	gameOver = LoadGraph("image/TestGraph/GameOver.png");
	space = LoadGraph("image/TestGraph/space.png");

	return 0;
}

// ���쏈��
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

// �`�揈��
int GameOver::Draw()
{
	DrawGraph(0, 0, gameOver, true);
	DrawGraph(250, 540, space, true);

	return 0;
}

// �R���X�g���N�^
GameOver::GameOver()
{
	now = GetNowCount();
	goF = false;
	Init();
}

// �f�X�g���N�^
GameOver::~GameOver()
{

}

