#include "SceneMng.h"
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

	SCN_MNG.addList(0, 0, 0xffffff, "SelectScene");

	return std::move(scnID);
}

