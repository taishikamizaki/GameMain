#include "GamePad.h"

void GamePad::Update(int num)
{
	inputP_ = GetJoypadInputState(DX_INPUT_KEY_PAD1);

	if(num ==0)
	{
		inputP_ = GetJoypadInputState(DX_INPUT_KEY_PAD1);
	}
	else
	{
		inputP_ = GetJoypadInputState(DX_INPUT_PAD2);
	}


	if (inputP_ & PAD_INPUT_UP)
	{
		_gamepadData[_inputTbl[InputID::Up]] = 1;
	}
	else
	{
		_gamepadData[_inputTbl[InputID::Up]] = 0;
	}

	if (inputP_ & PAD_INPUT_RIGHT)
	{
		_gamepadData[_inputTbl[InputID::Right]] = 1;
	}
	else
	{
		_gamepadData[_inputTbl[InputID::Right]] = 0;
	}

	if (inputP_ & PAD_INPUT_LEFT)
	{
		_gamepadData[_inputTbl[InputID::Left]] = 1;
	}
	else
	{
		_gamepadData[_inputTbl[InputID::Left]] = 0;
	}

	if (inputP_ & PAD_INPUT_A)
	{
		_gamepadData[_inputTbl[InputID::Btn1]] = 1;
	}
	else
	{
		_gamepadData[_inputTbl[InputID::Btn1]] = 0;
	}

	if (inputP_ & PAD_INPUT_B)
	{
		_gamepadData[_inputTbl[InputID::Btn2]] = 1;
	}
	else
	{
		_gamepadData[_inputTbl[InputID::Btn2]] = 0;
	}
	if (inputP_ & PAD_INPUT_B)
	{
		_gamepadData[_inputTbl[InputID::Btn3]] = 1;
	}
	else
	{
		_gamepadData[_inputTbl[InputID::Btn3]] = 0;
	}
	if (inputP_ & PAD_INPUT_B)
	{
		_gamepadData[_inputTbl[InputID::Btn4]] = 1;
	}
	else
	{
		_gamepadData[_inputTbl[InputID::Btn4]] = 0;
	}
	if (inputP_ & PAD_INPUT_B)
	{
		_gamepadData[_inputTbl[InputID::R]] = 1;
	}
	else
	{
		_gamepadData[_inputTbl[InputID::R]] = 0;
	}
	if (inputP_ & PAD_INPUT_B)
	{
		_gamepadData[_inputTbl[InputID::L]] = 1;
	}
	else
	{
		_gamepadData[_inputTbl[InputID::L]] = 0;
	}
	if (inputP_ & PAD_INPUT_B)
	{
		_gamepadData[_inputTbl[InputID::ZR]] = 1;
	}
	else
	{
		_gamepadData[_inputTbl[InputID::ZR]] = 0;
	}
	if (inputP_ & PAD_INPUT_B)
	{
		_gamepadData[_inputTbl[InputID::ZL]] = 1;
	}
	else
	{
		_gamepadData[_inputTbl[InputID::ZL]] = 0;
	}
	for (auto id : InputID())
	{
		_data[id][static_cast<int>(Trg::Old)] = _data[id][static_cast<int>(Trg::Now)];
		_data[id][static_cast<int>(Trg::Now)] = _gamepadData[_inputTbl[id]];
	}

}

ContType GamePad::GetType(void)
{
	return ContType::Pad;
}

bool GamePad::Setup(int no)
{
	if (no == 1)
	{
		_inputTbl = {
		{InputID::Up,PAD_INPUT_UP},
		{InputID::Right,PAD_INPUT_RIGHT},
		{InputID::Left,PAD_INPUT_LEFT},
		{InputID::Btn1,PAD_INPUT_X},
		{InputID::Btn2,PAD_INPUT_Y},
		{InputID::Btn3,PAD_INPUT_A},
		{InputID::Btn4,PAD_INPUT_B},
		{InputID::R,PAD_INPUT_R},
		{InputID::L,PAD_INPUT_L},
		{InputID::ZL,PAD_INPUT_LL},
		{InputID::ZR,PAD_INPUT_RR},
		};
	}
	else
	{
		_inputTbl = {
		{InputID::Up,PAD_INPUT_UP},
		{InputID::Right,PAD_INPUT_RIGHT},
		{InputID::Left,PAD_INPUT_LEFT},
		{InputID::Btn1,PAD_INPUT_X},
		{InputID::Btn2,PAD_INPUT_Y},
		{InputID::Btn3,PAD_INPUT_A},
		{InputID::Btn4,PAD_INPUT_B},
		{InputID::R,PAD_INPUT_R},
		{InputID::L,PAD_INPUT_L},
		{InputID::ZL,PAD_INPUT_LL},
		{InputID::ZR,PAD_INPUT_RR},
		};
	}
	return true;
}
