#include "DxLib.h"
#include "Effect.h"

// �̪�Ċ֘A

// �ϐ��錾
int gameCounter;			// �ްѼ�ݶ����
int testCounter;			// �ްѼ�݂��߰�ފm�F�p����

bool fadeIn;				// ̪��޲�
bool fadeOut;				// ̪��ޱ��
int  fadeCnt;				// ̪��޶���

// �̪�ď������p
void EffectInit(void)
{
	// �̪�ď���������
	fadeIn = true;
	fadeOut = false;
	fadeCnt = 0;
}

// ̪��޲݊֐�
bool FadeInScreen(int fadeStep)
{
	if (fadeCnt <= 255)
	{
		SetDrawBright(fadeCnt, fadeCnt, fadeCnt);
		fadeCnt += fadeStep;
		return true; // �߂�l
	}
	else
	{
		SetDrawBright(255, 255, 255);
		fadeIn = false;
		fadeCnt = 0;
		return false; // �߂�l
	}
}

// ̪��ޱ�Ċ֐�
bool FadeOutScreen(int fadeStep)
{
	if (fadeCnt <= 255)
	{
		SetDrawBright(255 - fadeCnt, 255 - fadeCnt, 255 - fadeCnt);
		fadeCnt += fadeStep;
		return true;
	}
	else
	{
		SetDrawBright(0, 0, 0);
		fadeOut = false;
		fadeCnt = 0;
		return false;
	}
}

