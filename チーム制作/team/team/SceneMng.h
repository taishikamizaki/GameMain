#pragma once
#include "BaseScene.h"

#define SCN_MNG SceneMng::ScnGeter()

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

private:
	SceneMng();
	~SceneMng();

	static SceneMng*sinstance;		// ﾎﾟｲﾝﾀ（動的に作る静的な何か）

	// ユニークベース
	ScnBase nowScn;					// 現在のシーン
};

