#pragma once
#include <DxLib.h>
#include<array>
#include "Controller.h"



class Mouse :
	public Controller
{
	void Update(int num) override;
	bool Setup(int no) override;
	ContType GetType(void) override;


private:
	std::array<char,256 > _mouseData;
	std::map<InputID, int> _inputTbl;
	int inputM_;

};

