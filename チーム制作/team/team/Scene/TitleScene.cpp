#include <DxLib.h>
#include "SceneMng.h"
#include "SelectScene.h"
#include "TitleScene.h"

// �R���X�g���N�^
TitleScene::TitleScene()
{
	titleLogoImage = NULL;		// �^�C�g�����S
	titleMesImage  = NULL;			// �^�C�g�����b�Z�[�W
	SCN_MNG.GetID("ti", "image/TestGraph/Title.png");		//���@�ꏊ
	SCN_MNG.GetID("title", "image/logo/title.png");		//���@�ꏊ
	titleEnd=false;
	SCN_MNG.fadeIn=true;
}

// �f�X�g���N�^
TitleScene::~TitleScene()
{
	
}

ScnBase TitleScene::Update(ScnBase scnID)
{
	/*keyDownTrigger[KEY_ID_SPACE]*/
	if(titleEnd)
	{
		if(!SCN_MNG.fadeOut)
		{
			SCN_MNG.fadeIn=true;
			return std::make_unique<SelectScene>();			// �V�[�����Z���N�g�ɔ�΂�
		}
	}
	auto move = [](std::weak_ptr<InputState> KeyID,const KEY_ID id) {
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
		titleEnd=true;
		SCN_MNG.fadeOut=true;
	}

	SCN_MNG.addList(0, 0, "ti");											// xy��
	SCN_MNG.addList(200, 0, "title");

	return std::move(scnID);														// �ꏊ�̐錾(�t���O)
}
