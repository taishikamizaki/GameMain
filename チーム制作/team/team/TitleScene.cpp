#include <DxLib.h>
#include "SelectScene.h"
#include "TitleScene.h"


// コンストラクタ
TitleScene::TitleScene()
{
	titleLogoImage = NULL;		// タイトルロゴ
	titleMesImage  = NULL;		// タイトルメッセージ
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
		//return std::make_unique<SelectScene>();			// シーンをセレクトに飛ばす
	}
	return std::move(scnID);	// 場所の宣言(フラグ)
}
