
#include <DxLib.h>
#include "ScnMng.h"
#include "Title.h"

// ‰Šú‰»ˆ—
int Title::Init()
{
	title = LoadGraph("image/TestGraph/Title.png");
	space = LoadGraph("image/TestGraph/space.png");

	return 0;
}

// ‘€ìˆ—
int Title::TitleCtl()
{
	if (SCN_MNG.keyFlagSp && !SCN_MNG.keyFlagOld)
	{
		titleF = true;
	}
	return 0;
}

// •`‰æˆ—
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

