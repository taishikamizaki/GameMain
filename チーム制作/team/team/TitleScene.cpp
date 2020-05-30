#include <DxLib.h>
#include "SceneMng.h"
#include "SelectScene.h"
#include "TitleScene.h"


// コンストラクタ
TitleScene::TitleScene()
{
	titleLogoImage = NULL;		// タイトルロゴ
	titleMesImage  = NULL;			// タイトルメッセージ
	SCN_MNG.GetId("ti", "image/TestGraph/Title.png");		//鍵　場所
}

// デストラクタ
TitleScene::~TitleScene()
{
	
}

ScnBase TitleScene::update(ScnBase scnID)
{
	/*keyDownTrigger[KEY_ID_SPACE]*/

	auto move = [](std::weak_ptr<InputState> KeyID,const KEY_ID id) {
		if (!KeyID.expired())
		{
			if (!(*KeyID.lock()).state(id).first)
			{
				return true;
			}
		}
		return false;
	};

	if(move(SCN_MNG.input, KEY_ID::KEY_ID_SPACE))
	{
		return std::make_unique<SelectScene>();			// シーンをセレクトに飛ばす
	}
	SCN_MNG.addList(0, 0, "ti");											// xy鍵

	return std::move(scnID);														// 場所の宣言(フラグ)
}
