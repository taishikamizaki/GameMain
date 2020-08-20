#include <DxLib.h>
#include "SceneMng.h"
#include "TitleScene.h"
#include "GameOverScene.h"

ScnBase GameOverScene::update(ScnBase scnID)
{
	//�t���b�V�����[�g��60�̎��A1000 ��1�b
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
		return std::make_unique<TitleScene>();		// �V�[�����^�C�g���ɍ����ւ�
		}

		}
	return std::move(scnID);
}

GameOverScene::GameOverScene()
{
	now = GetNowCount();
	SCN_MNG.GetId("goi", "image/TestGraph/GameOver.png");		//���@�ꏊ
	goEnd=false;
}

GameOverScene::~GameOverScene()
{
}
