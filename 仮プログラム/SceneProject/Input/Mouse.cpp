#include "Mouse.h"

void Mouse::Update(int num)
{
	inputM_ = GetMouseInput();
	//Vector2 mpos = { 0,0 };
	auto VolM = GetMouseWheelRotVol();

	//GetMousePoint(&mpos.x, &mpos.y);
	if (inputM_ == _inputTbl[InputID::Down])
	{
		_mouseData[_inputTbl[InputID::Down]] = 1;
	}
	else
	{
		_mouseData[_inputTbl[InputID::Down]] = 0;
	}
	if (VolM >= 1)
	{
		_mouseData[_inputTbl[InputID::Btn1]] = 1;
	}
	if (VolM < 0)
	{
		_mouseData[_inputTbl[InputID::Btn2]] = 1;
	}
	if (inputM_ == _inputTbl[InputID::Left])
	{
		_mouseData[_inputTbl[InputID::Left]] = 1;
	}
	else
	{
		_mouseData[_inputTbl[InputID::Left]] = 0;
	}

	if (inputM_ == _inputTbl[InputID::Right])
	{
		_mouseData[_inputTbl[InputID::Right]] = 1;
	}
	else
	{
		_mouseData[_inputTbl[InputID::Right]] = 0;
	}
	

	for (auto id : InputID())
	{
		_data[id][static_cast<int>(Trg::Old)] = _data[id][static_cast<int>(Trg::Now)];
		_data[id][static_cast<int>(Trg::Now)] = _mouseData[_inputTbl[id]];
	}
		_mouseData[_inputTbl[InputID::Btn1]] = 0;
		_mouseData[_inputTbl[InputID::Btn2]] = 0;
}

bool Mouse::Setup(int no)
{
	if (no == 1)
	{
		_inputTbl = {
		{InputID::Up,KEY_INPUT_W},
		{InputID::Down,MOUSE_INPUT_MIDDLE},
		{InputID::Right,MOUSE_INPUT_RIGHT},
		{InputID::Left,MOUSE_INPUT_LEFT},
		{InputID::Btn1,KEY_INPUT_NUMPAD1},
		{InputID::Btn2,KEY_INPUT_NUMPAD2},
		};
	}
	else
	{
		_inputTbl = {
		{InputID::Up,KEY_INPUT_W},
		{InputID::Down,MOUSE_INPUT_MIDDLE},
		{InputID::Right,MOUSE_INPUT_RIGHT},
		{InputID::Left,MOUSE_INPUT_LEFT},
		{InputID::Btn1,KEY_INPUT_NUMPAD1},
		{InputID::Btn2,KEY_INPUT_NUMPAD2},
		};
	}

	return true;
}


ContType Mouse::GetType(void)
{
	return ContType::Mouse;
}
