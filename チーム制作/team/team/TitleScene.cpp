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

	// キーチェック
	if (CheckHitKeyAll())
	{
		/*fadeOut = true;*/
		return std::make_unique<SelectScene>();			// シーンをセレクトに飛ばす
	}

	SCN_MNG.addList(0, 0, "ti");											// xy鍵

	return std::move(scnID);														// 場所の宣言(フラグ)
}
