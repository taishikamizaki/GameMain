#pragma once
#include "BaseScene.h"

// �Z���N�g�N���X
class SelectScene :
	public BaseScene
{
public:
	SelectScene();			// �R���X�g���N�^
	~SelectScene();			// �f�X�g���N�^

	ScnBase update(ScnBase scnID) override;
private:
	
};

