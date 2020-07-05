#include <DxLib.h>
#include "SceneMng.h"
#include "GameScene.h"
#include "Stage.h"
#include "player.h"
#include "SelectScene.h"


SelectScene::SelectScene()
{
	SelectScene::SelectInit();
}

SelectScene::~SelectScene()
{
}

ScnBase SelectScene::update(ScnBase scnID)
{	auto move = [](std::weak_ptr<InputState> KeyID,const KEY_ID id) {
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
		selEnd=true;
		SCN_MNG.fadeOut=true;
	}
	if(selEnd)
	{
		if(!SCN_MNG.fadeOut)
		{
			SCN_MNG.fadeIn=true;
			return std::make_unique<GameScene>();		// シーンをゲームオーバーに差し替え
		}
	}

	SelectScene::SelectDraw();
	return std::move(scnID);
}

// 初期化
void SelectScene::SelectInit(void)
{
	SCN_MNG.GetId("sli", "image/TestGraph/Select.png");		//鍵　場所
	selEnd = false;
}

// 描画 
void SelectScene::SelectDraw(void)
{
	SCN_MNG.addList(0, 0, "sli");
}