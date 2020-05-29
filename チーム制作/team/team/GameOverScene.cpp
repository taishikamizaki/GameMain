#include <DxLib.h>
#include "SceneMng.h"
#include "TitleScene.h"
#include "GameOverScene.h"

ScnBase GameOverScene::update(ScnBase scnID)
{
	now = GetNowHiPerformanceCount();
	//�t���b�V�����[�g��60�̎��A1000000��1�b
	if (GetNowHiPerformanceCount() - now >= 6000000)
	{
		return std::make_unique<TitleScene>();		// �V�[�����^�C�g���ɍ����ւ�
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
