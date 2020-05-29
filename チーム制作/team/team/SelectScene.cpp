#include "SelectScene.h"

// コンストラクタ
SelectScene::SelectScene()
{

}

// デストラクタ
SelectScene::~SelectScene()
{

}

// シーン
ScnBase SelectScene::update(ScnBase scnID)
{
	/*if (keyDownTrigger[KEY_ID_SPACE])
	{
		fadeOut = true;
	}*/
	return std::move(scnID);
}

