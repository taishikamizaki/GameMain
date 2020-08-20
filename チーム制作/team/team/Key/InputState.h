#pragma once
#include "keyID.h"
#include <map>


using KeyPir = std::pair<bool, bool>;							//�L�[NEW��OLD
using KeyMap = std::map<KEY_ID, KeyPir>;		//���,�oNEW�AOLD�p

class InputState
{
public:
	InputState();
	virtual ~InputState();

	virtual void Update(void)=0;
	bool state(KEY_ID id,bool kf);				//�L�[�f�[�^���Z�b�g
	void SetOld(void);
	const KeyPir state(KEY_ID id)const;
private:
	KeyMap _state;														//�L�[�f�[�^�������B

};

