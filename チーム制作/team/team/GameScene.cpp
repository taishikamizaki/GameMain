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

	SCN_MNG.addList(0,0,0xffff00, static_cast<std::string>("GAMESCENE"));
	return std::move(scnID);
}

GameScene::GameScene()
{
}

GameScene::~GameScene()
{
}
