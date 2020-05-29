#include <DxLib.h>
#include "SceneMng.h"
#include "TitleScene.h"
#include "GameOverScene.h"

ScnBase GameOverScene::update(ScnBase scnID)
{
	//�t���b�V�����[�g��60�̎��A1000 ��1�b
	if (GetNowHiPerformanceCount() - now >= 6000 )
	{
		return std::make_unique<TitleScene>();		// �V�[�����^�C�g���ɍ����ւ�
	}
	SCN_MNG.addList(0, 0, 0xffa0cf, "GameOverScene");

	return std::move(scnID);
}

GameOverScene::GameOverScene()
{
	now = GetNowCount();
}

GameOverScene::~GameOverScene()
{
}
