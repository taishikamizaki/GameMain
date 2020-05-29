#include <DxLib.h>
#include "SceneMng.h"
#include "GameOverScene.h"
#include "ResultScene.h"

ScnBase ResultScene::update(ScnBase scnID)
{
	if (CheckHitKey(KEY_INPUT_B))
	{
		return std::make_unique<GameOverScene>();		// �V�[�����Q�[���I�[�o�[�ɍ����ւ�
	}
	
	SCN_MNG.addList(0, 0, 0xff00ff, "ResultScene");
	return std::move(scnID);
	//return ScnBase();
}

ResultScene::ResultScene()
{
}

ResultScene::~ResultScene()
{
}
