#include <string>
#include <DxLib.h>
#include "SceneMng.h"
#include "ResultScene.h"
#include "GameScene.h"


// �V�[��
ScnBase GameScene::update(ScnBase scnID)
{
	if (CheckHitKey(KEY_INPUT_A))
	{
		return std::make_unique<ResultScene>();		// �V�[�����Q�[���I�[�o�[�ɍ����ւ�
	}

	SCN_MNG.addList(0, 0, "gsi");
	return std::move(scnID);
}

GameScene::GameScene()
{
	SCN_MNG.GetId("gsi", "image/TestGraph/Game.png");		//���@�ꏊ
}

GameScene::~GameScene()
{
}
