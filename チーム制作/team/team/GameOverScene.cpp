#include <DxLib.h>
#include "SceneMng.h"
#include "TitleScene.h"
#include "GameOverScene.h"

ScnBase GameOverScene::update(ScnBase scnID)
{
	//�t���b�V�����[�g��60�̎��A1000 ��1�b
	if (GetNowCount() - now >= 6000 )
	{
		return std::make_unique<TitleScene>();		// �V�[�����^�C�g���ɍ����ւ�
	}
	SCN_MNG.addList(0, 0, "goi");

	return std::move(scnID);
}

GameOverScene::GameOverScene()
{
	now = GetNowCount();
	SCN_MNG.GetId("goi", "image/TestGraph/GameOver.png");		//���@�ꏊ
}

GameOverScene::~GameOverScene()
{
}
