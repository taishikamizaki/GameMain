#pragma once
#include <vector>
#include <tuple>
#include "BaseScene.h"

#define SCN_MNG SceneMng::ScnGeter()								// マクロ

/*using drawQue = std::tuple<int, int, int>();*/						// 文字特化
using drawQue = std::tuple<int, int, int, std::string>;

/*using drawGraph = std::tuple<int, int, int>();*/					// 画像特化(DrawGraph)

// シーンマネージャー
class SceneMng
{
public:
	// ゲッター
	static SceneMng & ScnGeter(void)
	{
		ScnCreate();
		return *sinstance;
	}
	// クリエイター
	static void ScnCreate(void)
	{
		if (sinstance != nullptr)
		{
			//何もしない
		}
		else
		{
			sinstance = new SceneMng();
		}
	}
	// カスタムデリーター
	static void ScnDestroy(void)
	{
		if (sinstance != nullptr)
		{
			delete sinstance;
		}
		sinstance = nullptr;
	}

	// ｼｰﾝｺﾝﾄﾛｰﾙ
	void ScnCtl(void);

	int addList(int x, int y, unsigned int coller, std::string txt);

private:
	SceneMng();
	~SceneMng();
	
	/*std::vector<drawQue> drawList;*/	
	std::vector<drawQue> drawList;	// 画像とか文字とか入れるとこ （文字特化）
	/*std::vector<drawQue> List;*/
	void ListDraw(void);			// 描画用

	static SceneMng*sinstance;		// ﾎﾟｲﾝﾀ（動的に作る静的な何か）

	// ユニークベース
	ScnBase nowScn;					// 現在のシーン

	bool ScnInit(void);				// 初期化

	const int screenSizeX;			// 画面サイズX
	const int screenSizeY;			// 画面サイズY

};

