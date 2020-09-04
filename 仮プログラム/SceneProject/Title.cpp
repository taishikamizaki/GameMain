
#include <DxLib.h>
#include "ScnMng.h"
#include "Title.h"

// ����������
int Title::Init()
{
	title = LoadGraph("image/TestGraph/Title.png");
	space = LoadGraph("image/TestGraph/space.png");

	return 0;
}

// ���쏈��
int Title::TitleCtl()
{
	if (SCN_MNG.keyFlagSp && !SCN_MNG.keyFlagOld)
	{
		titleF = true;
	}
	return 0;
}

// �`�揈��
int Title::Draw()
{
	DrawGraph(200, 120, title, true);
	DrawGraph(250, 540, space, true);

	return 0;
}

Title::Title()
{
	titleF = false;
	Init();
}

Title::~Title()
{

}

