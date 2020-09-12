
#include <DxLib.h>
#include "../key/GetKeyState.h"
#include "GameOver.h"

// ����������
int GameOver::Init()
{
	gameOver = LoadGraph("image/TestGraph/GameOver.png");
	thank = LoadGraph("image/logo/Thank.png");
	space = LoadGraph("image/logo/space.png");

	return 0;
}

// ���쏈��
int GameOver::GameOverCtl()
{
	if (keyDownTrigger[KEY_ID_1START] ||
		keyDownTrigger[KEY_ID_2START] ||
		keyDownTrigger[CONFIRM1] ||
		keyDownTrigger[CONFIRM2])
	{
		goF = true;
	}
	return 0;
}

// �`�揈��
int GameOver::Draw()
{
	DrawGraph(0, 0, gameOver, true);
	DrawGraph(74, 0, thank, true);
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

