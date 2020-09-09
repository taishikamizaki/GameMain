#pragma once
#include<DxLib.h>
#include<array>
#include "Controller.h"


class GamePad :
	public Controller
{
public:
	void Update(int num)override;
	ContType GetType(void) override;
	bool Setup(int no)override;
private:
	std::array<char, 256>_gamepadData;
	std::map<InputID, int> _inputTbl;
	int inputP_;
};

