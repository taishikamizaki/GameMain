#include <DxLib.h>
#include "SelectScene.h"
#include "TitleScene.h"


// �R���X�g���N�^
TitleScene::TitleScene()
{
	titleLogoImage = NULL;		// �^�C�g�����S
	titleMesImage  = NULL;		// �^�C�g�����b�Z�[�W
}

// �f�X�g���N�^
TitleScene::~TitleScene()
{
	
}

ScnBase TitleScene::update(ScnBase scnID)
{
	/*keyDownTrigger[KEY_ID_SPACE]*/

	// �L�[�`�F�b�N
	if (CheckHitKeyAll())
	{
		/*fadeOut = true;*/
		//return std::make_unique<SelectScene>();			// �V�[�����Z���N�g�ɔ�΂�
	}
	return std::move(scnID);	// �ꏊ�̐錾(�t���O)
}
