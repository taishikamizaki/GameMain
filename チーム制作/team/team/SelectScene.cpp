#include <DxLib.h>
#include "SceneMng.h"
#include "GameScene.h"
#include "SelectScene.h"



// シーン
//ScnBase SelectScene::update(ScnBase scnID)
//{
//	if (CheckHitKey(KEY_INPUT_SPACE))
//	{
//		return std::make_unique<GameScene>();
//	}
	
//	SCN_MNG.addList(0, 0, 0xffffff, "SelectScene");

//	return std::move(scnID);
//}

SelectScene::SelectScene()
{
	SCN_MNG.GetId("sli", "image/TestGraph/Select.png");		//鍵　場所
}

SelectScene::~SelectScene()
{
}

ScnBase SelectScene::update(ScnBase scnID)
{
	if (CheckHitKey(KEY_INPUT_SPACE))
	{
		return std::make_unique<GameScene>();		// シーンをゲームオーバーに差し替え
	}
	SCN_MNG.addList(0, 0, "sli");
	return std::move(scnID);
}
