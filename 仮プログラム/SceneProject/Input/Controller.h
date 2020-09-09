#pragma once
#include<array>
#include<map>
#include"InputID.h"



// 入力装置
enum class ContType
{
	Key,
	Pad,
	Max
};


// キーの入力情報
enum class Trg
{
	Now,
	Old,
	Max
};

// array：固定値の配列宣言
using TrgBool = std:: array<bool, static_cast<size_t>(Trg::Max)>;// Trg
using CntData = std::map<InputID, TrgBool>;
// ボタン分だけOldとNewの情報を取り出せる

struct Controller
{
	void operator()(int num)
	{
		Update(num);
	}

	const CntData& GetCntData(void)
	{
		return _data;
	}
	virtual ContType GetType(void)=0;	// 純粋仮想
	virtual bool Setup(int no) = 0;		// 純粋仮想
private:
	virtual void Update(int num) = 0;

	// 
protected:
	CntData _data;

};
// コンストラクタとデストラクタは必ず作らなくてはいけないわけではない
// C++ ステートパターン