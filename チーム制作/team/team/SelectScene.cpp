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
	return std::move(scnID);
}

