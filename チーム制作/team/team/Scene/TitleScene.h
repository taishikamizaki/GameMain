#pragma once
#include "BaseScene.h"
// �^�C�g���N���X
class TitleScene :
	public BaseScene		// �e�N���X
{
public:
	TitleScene();
	~TitleScene();

	ScnBase update(ScnBase scnID) override;

private:

	int titleLogoImage;		// �^�C�g�����S
	int titleMesImage;		// �^�C�g�����b�Z�[�W

	bool titleEnd;

};

