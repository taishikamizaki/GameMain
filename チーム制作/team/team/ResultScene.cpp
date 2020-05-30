#include <DxLib.h>
#include "SceneMng.h"
#include "GameOverScene.h"
#include "ResultScene.h"

ScnBase ResultScene::update(ScnBase scnID)
{
	auto move = [](std::weak_ptr<InputState> KeyID, const KEY_ID id) {
		if (!KeyID.expired())
		{
			if ((*KeyID.lock()).state(id).first)
			{
				return true;
			}
		}
		return false;
	};



		if (move(SCN_MNG.input, KEY_ID::KEY_ID_SPACE))
		{
			return std::make_unique<GameOverScene>();		// �V�[�����Q�[���I�[�o�[�ɍ����ւ�
		}

	SCN_MNG.addList(0, 0, "rsi");
	return std::move(scnID);
	//return ScnBase();
}

ResultScene::ResultScene()
{
	SCN_MNG.GetId("rsi", "image/TestGraph/Result.png");		//���@�ꏊ
}

ResultScene::~ResultScene()
{
}
