#include "Keyboard.h"

ContType Keyboard::GetType(void)
{
	return ContType::Key;
}
bool Keyboard::Setup(int no)
{
	//_inputTbl.try_emplace(InputID::Up, KEY_INPUT_UP);
	if (no == 0)
	{
		_inputTbl = {
		{InputID::Up,KEY_INPUT_UP},
		{InputID::Right,KEY_INPUT_RIGHT},
		{InputID::Left,KEY_INPUT_LEFT},
		{InputID::Btn1,KEY_INPUT_RSHIFT},
		{InputID::Btn2,KEY_INPUT_NUMPAD1},
		{InputID::Btn3,KEY_INPUT_NUMPAD4},
		{InputID::Btn4,KEY_INPUT_RCONTROL},
		{InputID::R,KEY_INPUT_NUMPAD8},
		{InputID::L,KEY_INPUT_NUMPAD9},
		{InputID::ZR,KEY_INPUT_NUMPAD6},
		{InputID::ZL,KEY_INPUT_NUMPAD5},
		};
	}
	else
	{
		_inputTbl = {
		{InputID::Up,KEY_INPUT_W},
		{InputID::Right,KEY_INPUT_D},
		{InputID::Left,KEY_INPUT_A},
		{InputID::Btn1,KEY_INPUT_Q},
		{InputID::Btn2,KEY_INPUT_E},
		{InputID::Btn3,KEY_INPUT_SPACE},
		{InputID::Btn4,KEY_INPUT_LCONTROL},
		{InputID::R,KEY_INPUT_U},
		{InputID::L,KEY_INPUT_I},
		{InputID::ZR,KEY_INPUT_K},
		{InputID::ZL,KEY_INPUT_J},
		};
	}

	
	return true;
}
void Keyboard::Update(int num)
{
	GetHitKeyStateAll(_keyData.data());
	for (auto id : InputID())
	{
		_data[id][static_cast<int>(Trg::Old)] = _data[id][static_cast<int>(Trg::Now)];
		_data[id][static_cast<int>(Trg::Now)] = _keyData[_inputTbl[id]];
	}
}