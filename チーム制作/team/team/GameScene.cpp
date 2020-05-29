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

	SCN_MNG.addList(0,0,0xffff00, static_cast<std::string>("GAMESCENE"));
	return std::move(scnID);
}

GameScene::GameScene()
{
}

GameScene::~GameScene()
{
}
