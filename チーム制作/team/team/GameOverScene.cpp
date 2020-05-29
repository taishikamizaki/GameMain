#include <DxLib.h>
//#include "SceneMng.h"
#include "TitleScene.h"
#include "GameOverScene.h"

ScnBase GameOverScene::update(ScnBase scnID)
{
	return std::move(scnID);
	//return ScnBase();
}

GameOverScene::GameOverScene()
{
	//GameOverCnt = 0;
	//GameOverFlag = false;
}

GameOverScene::~GameOverScene()
{
}

//ScnBase GameOverScene::update(ScnBase scnID)
//{
	//{
	/*PlayerCtl();

	if (keyDownTrigger[KEY_ID_SPACE])
	{
		fadeOut = true;

	}*/
	//return std::move(scnID);
//}

	//return ScnBase();


//ScnBase GameOverScene::update(ScnBase scnID)
//{
	//if (/*keyDownTrigger[KEY_ID_SPACE]||*/  GameOverFlag == true)
	//{
		//fadeOut = true;
		//return std::make_unique<TitleScene>();		// シーンをタイトルに差し替え
	//}
	//GameOverCnt++;

	//if (GameOverCnt == 100)
	//
		//GameOverFlag = true;
	//}

	//SCN_MNG.addList(0, 0, 0xffffff, "GameOverScene");
	//return std::move(scnID);
//}