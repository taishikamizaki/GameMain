#include <string>
#include <DxLib.h>
#include "SceneMng.h"
#include "ResultScene.h"
#include "GameScene.h"


// シーン
ScnBase GameScene::update(ScnBase scnID)
{
	auto move = [](std::weak_ptr<InputState> KeyID, const KEY_ID id) {
		if (!KeyID.expired())
		{
			if (!(*KeyID.lock()).state(id).first)
			{
				return true;
			}
		}
		return false;
	};



		if (move(SCN_MNG.input, KEY_ID::KEY_ID_SPACE))
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
