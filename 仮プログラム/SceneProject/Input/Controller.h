#pragma once
#include<array>
#include<map>
#include"InputID.h"



// ���͑��u
enum class ContType
{
	Key,
	Pad,
	Max
};


// �L�[�̓��͏��
enum class Trg
{
	Now,
	Old,
	Max
};

// array�F�Œ�l�̔z��錾
using TrgBool = std:: array<bool, static_cast<size_t>(Trg::Max)>;// Trg
using CntData = std::map<InputID, TrgBool>;
// �{�^��������Old��New�̏������o����

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
	virtual ContType GetType(void)=0;	// �������z
	virtual bool Setup(int no) = 0;		// �������z
private:
	virtual void Update(int num) = 0;

	// 
protected:
	CntData _data;

};
// �R���X�g���N�^�ƃf�X�g���N�^�͕K�����Ȃ��Ă͂����Ȃ��킯�ł͂Ȃ�
// C++ �X�e�[�g�p�^�[��