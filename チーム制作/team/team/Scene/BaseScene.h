#pragma once

#include <memory>

// �v���g�^�C�v�錾
class BaseScene;

using ScnBase = std::unique_ptr<BaseScene>;

class BaseScene
{

public:
	BaseScene();				// �R���X�g���N�^
	virtual ~BaseScene();		// �f�X�g���N�^

	virtual ScnBase Update(ScnBase scnID) = 0;			// �����ȉ��z�֐�

private:

};
