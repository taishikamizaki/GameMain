#include <iostream>
#include <string>
#include <DxLib.h>
#include "SceneMng.h"
#include "TitleScene.h"
#include "../Player/playerMng.h"
#include "../Vector2/Vector2.h"
#include "../ImageMng.h"


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
		nowScn = (*nowScn).Update(std::move(nowScn));// シーン移行

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
	fadeIn  = false;
	fadeOut = false;

	fadeCnt = 0;

	ScnInit();
}

// デストラクタ
SceneMng::~SceneMng()
{

}

// 描画用
void SceneMng::ListDraw(void)
{
	ClsDrawScreen();
	if(fadeIn)fadeIn=FadeInScreen(5);
	if(fadeOut)fadeOut=FadeOutScreen(5);

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

	// ｴﾌｪｸﾄ初期化処理
	fadeIn = true;
	fadeOut = false;
	fadeCnt = 0;


	//プレイヤー画像
	a = LoadGraph("./image/char/char_p_hero01.png");
	LoadDivGraph("./image/char/char_p_hero01.png", 12, 3, 4, 24, 33, kisi);
	LoadDivGraph("./image/char/char_p_hero01.png", 12, 3, 4, 24, 34, majo);
	LoadDivGraph("./image/char/char_p_f04.png", 12, 3, 4, 25, 33, buto);
	LoadDivGraph("./image/char/char_p_hero01.png", 12, 3, 4, 24, 34, men);

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

// ﾌｪｰﾄﾞｲﾝ関数
bool SceneMng::FadeInScreen(int fadeStep)
{
	if (fadeCnt <= 255)
	{
		SetDrawBright(fadeCnt, fadeCnt, fadeCnt);
		fadeCnt += fadeStep;
		return true; // 戻り値
	}
	else
	{
		SetDrawBright(255, 255, 255);
		fadeIn = false;
		fadeCnt = 0;
		return false; // 戻り値
	}
}

// ﾌｪｰﾄﾞｱｳﾄ関数
bool SceneMng::FadeOutScreen(int fadeStep)
{
	if (fadeCnt <= 255)
	{
		SetDrawBright(255 - fadeCnt, 255 - fadeCnt, 255 - fadeCnt);
		fadeCnt += fadeStep;
		return true;
	}
	else
	{
		SetDrawBright(0, 0, 0);
		fadeOut = false;
		fadeCnt = 0;
		return false;
	}
}

