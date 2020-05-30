#pragma once
#include <vector>
#include <tuple>
#include <map>
#include "BaseScene.h"
#include "KeyState.h"

#define SCN_MNG SceneMng::ScnGeter()								// マクロ

using drawQue = std::tuple<int, int, std::string>;

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

	int addList(int x, int y, std::string id);

	int GetId(const std::string& key,const std::string filename);

	int GetId(const std::string& key);
	
	std::shared_ptr<InputState> input;
private:
	SceneMng();
	~SceneMng();
	
	std::vector<drawQue> drawList;		// 画像とか入れるとこ

	void ListDraw(void);									// 描画用

	static SceneMng*sinstance;					// ﾎﾟｲﾝﾀ（動的に作る静的な何か）

	// ユニークベース
	ScnBase nowScn;						// 現在のシーン

	bool ScnInit(void);					// 初期化

	const int screenSizeX;			// 画面サイズX
	const int screenSizeY;			// 画面サイズY

	std::map<std::string, int> imgMng;
};

