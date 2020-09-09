#pragma once
#include <DxLib.h>
#include <array>
#include "Controller.h"



struct Keyboard :
	public Controller
{
	// �e�R���g���[���[�ő��삷��ۂɕK�v�ȋ��ʂ̂R��
	ContType GetType(void) override;	// �������z
	bool Setup(int no) override;		// �������z
	void Update(int num) override;

private:
	std::array<char, 256> _keyData;
	std::map<InputID, int> _inputTbl;

};

