#include "SceneMng.h"
#include "SelectScene.h"

// �R���X�g���N�^
SelectScene::SelectScene()
{

}

// �f�X�g���N�^
SelectScene::~SelectScene()
{

}

// �V�[��
ScnBase SelectScene::update(ScnBase scnID)
{
	/*if (keyDownTrigger[KEY_ID_SPACE])
	{
		fadeOut = true;
	}*/

	SCN_MNG.addList(0, 0, 0xffffff, "SelectScene");

	return std::move(scnID);
}

