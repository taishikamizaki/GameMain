#pragma once

// ����������p
enum KEY_ID_
{
	KEY_ID_SPACE,		// ��߰������p
	KEY_ID_PAUSE,		// �߰�����ݐݒ�p

	KEY_ID_UP1,			// ��
	KEY_ID_RIGHT1,		// ��
	KEY_ID_DOWN1,		// ��
	KEY_ID_LEFT1,		// ��
	KEY_ID_SHOT1,		// �e���˗p
	KEY_ID_JUMP1,		// �ެ��ߗp
	KEY_ID_1SKILL1,		// ���1
	KEY_ID_1SKILL2,		// ���2
	KEY_ID_1SKILL3,		// ���3
	KEY_ID_1SKILL4,		// ���4
	KEY_ID_1A,
	KEY_ID_1B,
	KEY_ID_1X,
	KEY_ID_1Y,
	KEY_ID_1START,

	KEY_ID_UP2,			// ��
	KEY_ID_RIGHT2,		// ��
	KEY_ID_DOWN2,		// ��
	KEY_ID_LEFT2,		// ��
	KEY_ID_SHOT2,		// �e���˗p
	KEY_ID_JUMP2,		// �ެ��ߗp
	KEY_ID_2SKILL1,		// ���1
	KEY_ID_2SKILL2,		// ���2
	KEY_ID_2SKILL3,		// ���3
	KEY_ID_2SKILL4,		// ���4
	KEY_ID_2A,
	KEY_ID_2B,
	KEY_ID_2X,
	KEY_ID_2Y,
	KEY_ID_2START,

	// �f�o�b�O�p�L�[�R���t�B�O
	UP1,
	DOWN1,
	RIGHT1,
	LEFT1,
	CONFIRM1,
	CANCEL1,
	P1A1,
	P1A2,
	P1S1,
	P1S2,
	P1S3,
	P1S4,

	UP2,
	DOWN2,
	RIGHT2,
	LEFT2,
	CONFIRM2,
	CANCEL2,
	P2A1,
	P2A2,
	P2S1,
	P2S2,
	P2S3,
	P2S4,

	KEY_ID_SAVE,		// ���ޗp
	KEY_ID_LOAD,		// ۰�ޗp
	KEY_ID_MAX
};

// �������ߐ錾
void KeyInit(void);								// ������
void KeyCheck(void);							// ������

// ����ݐ錾
extern bool keyNew[KEY_ID_MAX];							// ����������i���݁j
extern bool keyOld[KEY_ID_MAX];								// ����������i�ڰёO�j
extern bool keyDownTrigger[KEY_ID_MAX];		// ������������
extern bool keyUpTrigger[KEY_ID_MAX];				// ���𗣂������̔���
