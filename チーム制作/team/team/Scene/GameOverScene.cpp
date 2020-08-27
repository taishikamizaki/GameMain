#include <DxLib.h>
#include "SceneMng.h"
#include "TitleScene.h"
#include "GameOverScene.h"

ScnBase GameOverScene::Update(ScnBase scnID)
{
	//フレッシュレートが60の時、1000 で1秒
	if (GetNowCount() - now >= 3000 )
	{
		now = GetNowCount();
		SCN_MNG.fadeOut=true;
		goEnd=true;
	}
	SCN_MNG.addList(0, 0, "goi");

	if(goEnd==true)
	{
		if(!SCN_MNG.fadeOut)
		{
			SCN_MNG.fadeIn=true;
			return std::make_unique<TitleScene>();		// シーンをタイトルに差し替え
		}
	}
	return std::move(scnID);
}

GameOverScene::GameOverScene()
{
	now = GetNowCount();
	SCN_MNG.GetID("goi", "image/TestGraph/GameOver.png");		//鍵　場所
	DrawString(0, 0, "GameOver", 0xffffff, true);
	goEnd=false;
}

GameOverScene::~GameOverScene()
{
}
