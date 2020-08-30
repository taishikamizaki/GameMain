#pragma once
#include <string>
#include <vector>
#include <tuple>
#include <map>
#include "BaseScene.h"
#include "../Key/KeyState.h"

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

	int GetID(const std::string& key,const std::string filename);

	int GetID_D(const std::string& key, const TCHAR fileName, 
			    int AllNum, int xNum, int yNum, int xSize, int ySize, 
			    int* HandleArray);

	int GetID(const std::string& key);
	
	std::shared_ptr<InputState> input;


bool FadeInScreen(int fadeStep);			// ﾌｪｰﾄﾞｲﾝ処理
bool FadeOutScreen(int fadeStep);		// ﾌｪｰﾄﾞｱｳﾄ処理

	bool fadeIn;						// ﾌｪｰﾄﾞｲﾝ
	bool fadeOut;					// ﾌｪｰﾄﾞｱｳﾄ

private:
	SceneMng();
	~SceneMng();
	
	std::vector<drawQue> drawList;		// 画像とか入れるとこ

	void ListDraw(void);				// 描画用

	static SceneMng*sinstance;			// ﾎﾟｲﾝﾀ（動的に作る静的な何か）

	// ユニークベース
	ScnBase nowScn;						// 現在のシーン

	bool ScnInit(void);					// 初期化

	const int screenSizeX;				// 画面サイズX
	const int screenSizeY;				// 画面サイズY

	std::map<std::string, int> imgMng;

	int  fadeCnt;						// ﾌｪｰﾄﾞｶｳﾝﾀ

	int a;

	int kisi[13];
	int majo[13];
	int buto[13];
	int men[13];
};

