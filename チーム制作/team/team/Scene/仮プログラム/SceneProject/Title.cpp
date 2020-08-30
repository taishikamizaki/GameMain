
#include <DxLib.h>
#include "ScnMng.h"
#include "Title.h"

int Title::Init()
{
	title = LoadGraph("image/TestGraph/Title.png");

	return 0;
}

int Title::TitleCtl()
{
	if (SCN_MNG.keyFlagSp && !SCN_MNG.keyFlagOld)
	{
		titleF = true;
	}
	return 0;
}

int Title::TitleDraw()
{
	DrawGraph(0, 0, title, true);
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

