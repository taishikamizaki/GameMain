#include <DxLib.h>
#include "SceneMng.h"
#include "GameScene.h"
#include "../Stage/Stage.h"
#include "../Player/player.h"
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

	images.try_emplace("kisi", LoadGraph("image/char/charsel icon/騎士選択(無し).png"));
	images.try_emplace("kisi_1p", LoadGraph("image/char/charsel icon/騎士選択(1p).png"));
	images.try_emplace("kisi_2p", LoadGraph("image/char/charsel icon/騎士選択(2p).png"));

	images.try_emplace("majo", LoadGraph("image/char/charsel icon/魔法使い選択(無し).png"));
	images.try_emplace("majo_1p", LoadGraph("image/char/charsel icon/魔法使い選択(1p).png"));
	images.try_emplace("majo_2p", LoadGraph("image/char/charsel icon/魔法使い選択(2p).png"));

	images.try_emplace("buto", LoadGraph("image/char/charsel icon/武闘家選択(無し).png"));
	images.try_emplace("buto_1p", LoadGraph("image/char/charsel icon/武闘家選択(1p).png"));
	images.try_emplace("buto_2p", LoadGraph("image/char/charsel icon/武闘家選択(2p).png"));

	images.try_emplace("men", LoadGraph("image/char/charsel icon/謎の男選択(無し).png"));
	images.try_emplace("men_1p", LoadGraph("image/char/charsel icon/謎の男選択(1p).png"));
	images.try_emplace("men_2p", LoadGraph("image/char/charsel icon/謎の男選択(2p).png"));
}

// 描画 
void SelectScene::SelectDraw(void)
{
	SCN_MNG.addList(0, 0, "sli");
}

