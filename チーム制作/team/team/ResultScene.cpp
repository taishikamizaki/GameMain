#include <DxLib.h>
#include "GameOverScene.h"
#include "ResultScene.h"

ScnBase ResultScene::update(ScnBase scnID)
{
	if (CheckHitKeyAll())
	{
		return std::make_unique<GameOverScene>();		// �V�[�����Q�[���I�[�o�[�ɍ����ւ�
	}
	
	DrawFormatString(0, 0, 0xFFFFFF, "ResultScene");
	return std::move(scnID);
	//return ScnBase();
}

ResultScene::ResultScene()
{
}

ResultScene::~ResultScene()
{
}
