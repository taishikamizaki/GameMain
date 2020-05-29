#include <DxLib.h>
//#include "SceneMng.h"
#include "SelectScene.h"



// ÉVÅ[Éì
//ScnBase SelectScene::update(ScnBase scnID)
//{
//	if (CheckHitKey(KEY_INPUT_SPACE))
//	{
//		return std::make_unique<GameScene>();
//	}
	
//	SCN_MNG.addList(0, 0, 0xffffff, "SelectScene");

//	return std::move(scnID);
//}

ScnBase SelectScene::update(ScnBase scnID)
{
	if (CheckHitKey(KEY_INPUT_SPACE))
	{
		return std::make_unique<GameScene>();
	}
	return std::move(scnID);
}
