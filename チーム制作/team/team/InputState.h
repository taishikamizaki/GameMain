#pragma once
#include "keyID.h"
#include <map>


using KeyPir = std::pair<int, int>;							//�L�[NEW��OLD
using KeyMap = std::map<KEY_ID, KeyPir>;		//���,�oNEW�AOLD�p

class InputState
{
public:
	InputState();
	virtual ~InputState();

	virtual void Update(void)=0;

	const KeyMap& state(void)const;				//�L�[�}�b�v���ۂ��ƕԂ��B
	const KeyPir& state(KEY_ID id)const;		//ID�ɑΉ�������̂�Ԃ�
	bool state(KEY_ID id,int kf);							//�L�[�f�[�^���Z�b�g
	void SetOld(void);

private:
	KeyMap _state;														//�L�[�f�[�^�������B

};

