#include <DxLib.h>
#include "SceneMng.h"
#include "TitleScene.h"

// 静的で動的な何か
SceneMng* SceneMng::sinstance = nullptr;

// ｼｰﾝｺﾝﾄﾛｰﾙ
void SceneMng::ScnCtl(void)
{
	SceneMng::ScnInit();
	nowScn = std::make_unique<TitleScene>();		// シーンをタイトルに差し替え

	while (ProcessMessage() == 0 &&
		CheckHitKey(KEY_INPUT_ESCAPE) == 0)
	{
		drawList.clear();		// リストの初期化

		/*KeyCheck();*/
		nowScn = (*nowScn).update(std::move(nowScn));// シーン移行
	}
}

// 文字描画用タスク
int SceneMng::addList(drawQue dList)
{
	drawList.emplace_back(dList);
	return 0;
}

// コンストラクタ
SceneMng::SceneMng():screenSizeX(1000),screenSizeY(600)
{
	
}

// デストラクタ
SceneMng::~SceneMng()
{

}

// 描画用
void SceneMng::ListDraw(void)
{
	for (auto a : drawList)
	{
		int x;
		int y;
		int coller;
		int txt;

		std::tie(x, y, coller, txt) = a;
	}
}

// 初期化
bool SceneMng::ScnInit(void)
{
	SetWindowText("HAMAGURI");
	// ｼｽﾃﾑ処理
	SetGraphMode(screenSizeX, screenSizeY, 16);
	ChangeWindowMode(true);
	if (DxLib_Init() == -1)
	{
		/*AST();*/
		return false;
	}

	SetDrawScreen(DX_SCREEN_BACK);

	// 初期化
	//EffectInit();

	/*TitleInit();*/

	//scnID = SCN_ID_INIT;
	//scnIDOld = SCN_ID_MAX;
}
