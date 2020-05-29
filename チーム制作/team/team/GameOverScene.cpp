#include <DxLib.h>
#include "SceneMng.h"
#include "TitleScene.h"
#include "GameOverScene.h"

ScnBase GameOverScene::update(ScnBase scnID)
{
	now = GetNowHiPerformanceCount();
	//フレッシュレートが60の時、1000000で1秒
	if (GetNowHiPerformanceCount() - now >= 6000000)
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
