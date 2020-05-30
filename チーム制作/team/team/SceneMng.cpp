#include <iostream>
#include <string>
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
		(*input).Update();
		/*KeyCheck();*/
		nowScn = (*nowScn).update(std::move(nowScn));// シーン移行

		SceneMng::ListDraw();
	}
}

// 文字描画用タスク
int SceneMng::addList(int x, int y, std::string id)
{
	drawList.emplace_back(x, y, id);

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
	ClsDrawScreen();
	int x, y;
	std::string id;
	for(auto dl:drawList)
	{
		std::tie(x, y, id) = dl;
		
		DrawGraph(x,y,GetId(id),true);
	}

	ScreenFlip();
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
	input = std::make_shared<KeyState>();
	return 0;
}

int SceneMng::GetId(const std::string& key,const std::string filename)
{
	if (imgMng.find(key) == imgMng.end())
	{
		imgMng[key] = LoadGraph(filename.c_str());
	}
	return imgMng[key];
}

int SceneMng::GetId(const std::string& key)
{
	GetId(key, key);
	return imgMng[key];
}