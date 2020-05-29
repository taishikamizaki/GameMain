#include <DxLib.h>
#include "SceneMng.h"
#include "TitleScene.h"
#include "GameOverScene.h"

ScnBase GameOverScene::update(ScnBase scnID)
{
	now = GetNowCount();
	
	if (GetNowCount() - now < 3000)
	{
		return std::make_unique<TitleScene>();		// シーンをタイトルに差し替え
	}
	SCN_MNG.addList(0, 0, 0xffffff, "GameOverScene");

	return std::move(scnID);
}

GameOverScene::GameOverScene()
{
}

GameOverScene::~GameOverScene()
{
}
