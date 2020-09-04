#include <DxLib.h>
#include "SceneMng.h"
#include "SelectScene.h"
#include "TitleScene.h"

// コンストラクタ
TitleScene::TitleScene()
{
	titleLogoImage = NULL;		// タイトルロゴ
	titleMesImage  = NULL;			// タイトルメッセージ
	SCN_MNG.GetID("ti", "image/TestGraph/Title.png");		//鍵　場所
	SCN_MNG.GetID("title", "image/logo/title.png");		//鍵　場所
	titleEnd=false;
	SCN_MNG.fadeIn=true;
}

// デストラクタ
TitleScene::~TitleScene()
{
	
}

ScnBase TitleScene::Update(ScnBase scnID)
{
	/*keyDownTrigger[KEY_ID_SPACE]*/
	if(titleEnd)
	{
		if(!SCN_MNG.fadeOut)
		{
			SCN_MNG.fadeIn=true;
			return std::make_unique<SelectScene>();			// シーンをセレクトに飛ばす
		}
	}
	auto move = [](std::weak_ptr<InputState> KeyID,const KEY_ID id) {
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
		titleEnd=true;
		SCN_MNG.fadeOut=true;
	}

	SCN_MNG.addList(0, 0, "ti");											// xy鍵
	SCN_MNG.addList(200, 0, "title");

	return std::move(scnID);														// 場所の宣言(フラグ)
}
