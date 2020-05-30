#include <DxLib.h>
#include "SceneMng.h"
#include "GameScene.h"
#include "SelectScene.h"



// �V�[��
//ScnBase SelectScene::update(ScnBase scnID)
//{
//	if (CheckHitKey(KEY_INPUT_SPACE))
//	{
//		return std::make_unique<GameScene>();
//	}
	
//	SCN_MNG.addList(0, 0, 0xffffff, "SelectScene");

//	return std::move(scnID);
//}

SelectScene::SelectScene()
{
	SCN_MNG.GetId("sli", "image/TestGraph/Select.png");		//���@�ꏊ
}

SelectScene::~SelectScene()
{
}

ScnBase SelectScene::update(ScnBase scnID)
{	auto move = [](std::weak_ptr<InputState> KeyID,const KEY_ID id) {
		if (!KeyID.expired())
		{
			if (!(*KeyID.lock()).state(id).first)
			{
				return true;
			}
		}
		return false;
	};

	
		if(move(SCN_MNG.input, KEY_ID::KEY_ID_SPACE))
		{
			return std::make_unique<GameScene>();		// �V�[�����Q�[���I�[�o�[�ɍ����ւ�
		}

	SCN_MNG.addList(0, 0, "sli");
	return std::move(scnID);
}
