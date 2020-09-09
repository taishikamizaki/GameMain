#pragma once
#include <DxLib.h>
#include <array>
#include "Controller.h"



struct Keyboard :
	public Controller
{
	// 各コントローラーで操作する際に必要な共通の３つ
	ContType GetType(void) override;	// 純粋仮想
	bool Setup(int no) override;		// 純粋仮想
	void Update(int num) override;

private:
	std::array<char, 256> _keyData;
	std::map<InputID, int> _inputTbl;

};

