#pragma once

// ボタンの種類
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
//underlying_type：既定の型を調べるためのもの
// enum class ：既定の型を自由に変えることができる
// イテレーターを持っているやつがいれば上のoperator++はいらない
// この４つがあれば範囲for文を回すことができる


// static：アドレスを複数作らないようにしたいときに使用

