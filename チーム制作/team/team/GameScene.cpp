#include <string>
#include <DxLib.h>
#include "SceneMng.h"
#include "ResultScene.h"
#include "GameScene.h"


// �V�[��
ScnBase GameScene::update(ScnBase scnID)
{
	auto move = [](std::weak_ptr<InputState> KeyID, const KEY_ID id) {
		if (!KeyID.expired())
		{
			if ((*KeyID.lock()).state(id).first == true && (*KeyID.lock()).state(id).second == false)
			{
				return true;
			}
		}
		return false;
	};


	if(move(SCN_MNG.input, KEY_ID::KEY_ID_SPACE))
	{
		gamEnd=true;
		SCN_MNG.fadeOut=true;
	}
	if(gamEnd)
	{
		if(!SCN_MNG.fadeOut)
		{
			SCN_MNG.fadeIn=true;
			return std::make_unique<ResultScene>();		// �V�[�����Q�[���I�[�o�[�ɍ����ւ�
		}
		}
	SCN_MNG.addList(0, 0, "gsi");
	return std::move(scnID);
}

GameScene::GameScene()
{
	SCN_MNG.GetId("gsi", "image/TestGraph/Game.png");		//���@�ꏊ
	gamEnd=false;
}

GameScene::~GameScene()
{
}
