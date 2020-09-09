#pragma once

// �{�^���̎��
enum class InputID
{
	Up,
	Right,
	Left,
	Btn1,
	Btn2,
	Btn3,
	Btn4,
	R,
	L,
	ZR,
	ZL,
	Max
};


static InputID begin(InputID) { return InputID::Up; };
static InputID end(InputID) { return InputID::Max; };
static InputID operator++(InputID& state) { return (state = InputID(std::underlying_type<InputID>::type(state)+1)); };
static InputID operator*(InputID state) { return state; };
//underlying_type�F����̌^�𒲂ׂ邽�߂̂���
// enum class �F����̌^�����R�ɕς��邱�Ƃ��ł���
// �C�e���[�^�[�������Ă���������Ώ��operator++�͂���Ȃ�
// ���̂S������Δ͈�for�����񂷂��Ƃ��ł���


// static�F�A�h���X�𕡐����Ȃ��悤�ɂ������Ƃ��Ɏg�p

