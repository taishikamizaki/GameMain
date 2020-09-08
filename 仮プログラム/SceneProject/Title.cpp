
#include <DxLib.h>
#include "ScnMng.h"
#include "Title.h"

// 初期化処理
int Title::Init()
{
	title = LoadGraph("image/TestGraph/titleB.png");
	titleL = LoadGraph("image/TestGraph/Title.png");
	space = LoadGraph("image/TestGraph/space.png");

	return 0;
}

// 操作処理
int Title::TitleCtl()
{
	if (SCN_MNG.keyFlagSp && !SCN_MNG.keyFlagOld)
	{
		titleF = true;
	}
	return 0;
}

// 描画処理
int Title::Draw()
{
	DrawGraph(0, 0, title, true);
	DrawGraph(200, 120, titleL, true);
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

