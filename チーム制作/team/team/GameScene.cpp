#include <string>
#include <DxLib.h>
#include "SceneMng.h"
#include "ResultScene.h"
#include "GameScene.h"


// シーン
ScnBase GameScene::update(ScnBase scnID)
{
	if (CheckHitKey(KEY_INPUT_A))
	{
		return std::make_unique<ResultScene>();		// シーンをゲームオーバーに差し替え
	}

	SCN_MNG.addList(0, 0, "gsi");
	return std::move(scnID);
}

GameScene::GameScene()
{
	SCN_MNG.GetId("gsi", "image/TestGraph/Game.png");		//鍵　場所
}

GameScene::~GameScene()
{
}
