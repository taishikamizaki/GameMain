#include <DxLib.h>
#include "SceneMng.h"
#include "GameOverScene.h"
#include "ResultScene.h"

ScnBase ResultScene::update(ScnBase scnID)
{
	if (CheckHitKey(KEY_INPUT_B))
	{
		return std::make_unique<GameOverScene>();		// シーンをゲームオーバーに差し替え
	}
	
	SCN_MNG.addList(0, 0, "rsi");
	return std::move(scnID);
	//return ScnBase();
}

ResultScene::ResultScene()
{
	SCN_MNG.GetId("rsi", "image/TestGraph/Result.png");		//鍵　場所
}

ResultScene::~ResultScene()
{
}
