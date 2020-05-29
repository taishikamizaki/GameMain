#include <DxLib.h>
#include "SceneMng.h"
#include "SelectScene.h"
#include "TitleScene.h"


// �R���X�g���N�^
TitleScene::TitleScene()
{
	titleLogoImage = NULL;		// �^�C�g�����S
	titleMesImage  = NULL;			// �^�C�g�����b�Z�[�W
	SCN_MNG.GetId("ti", "image/TestGraph/Title.png");		//���@�ꏊ
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
		return std::make_unique<SelectScene>();			// �V�[�����Z���N�g�ɔ�΂�
	}

	SCN_MNG.addList(0, 0, "ti");											// xy��

	return std::move(scnID);														// �ꏊ�̐錾(�t���O)
}
