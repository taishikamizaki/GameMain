#include <DxLib.h>
#include "SceneMng.h"
#include "GameOverScene.h"
#include "ResultScene.h"

ScnBase ResultScene::update(ScnBase scnID)
{
	auto move = [](std::weak_ptr<InputState> KeyID, const KEY_ID id) {
		if (!KeyID.expired())
		{
			if ((*KeyID.lock()).state(id).first == true && (*KeyID.lock()).state(id).second == false)
			{
				return true;
			}
		}
		return false;
	};
		if(move(SCN_MNG.input, KEY_ID::KEY_ID_SPACE))
	{
		resEnd=true;
		SCN_MNG.fadeOut=true;
	}
	if(resEnd)
	{
		if(!SCN_MNG.fadeOut)
		{
			SCN_MNG.fadeIn=true;
			return std::make_unique<GameOverScene>();		// シーンをゲームオーバーに差し替え
		}
		}

	SCN_MNG.addList(0, 0, "rsi");
	return std::move(scnID);
	//return ScnBase();
}

ResultScene::ResultScene()
{
	SCN_MNG.GetId("rsi", "image/TestGraph/Result.png");		//鍵　場所
	resEnd=false;
}

ResultScene::~ResultScene()
{

}
