#pragma once

// ����������p
enum KEY_ID_
{
	KEY_ID_SPACE,		// ��߰������p
	KEY_ID_PAUSE,		// �߰�����ݐݒ�p
	KEY_ID_UP,				// ��
	KEY_ID_RIGHT,		// ��
	KEY_ID_DOWN,		// ��
	KEY_ID_LEFT,			// ��
	KEY_ID_SHOT,		// �e���˗p
	KEY_ID_JUMP,		// �ެ��ߗp
	KEY_ID_SKILL1,		// ���1
	KEY_ID_SKILL2,		// ���2
	KEY_ID_SKILL3,		// ���3
	KEY_ID_SKILL4,		// ���4
	KEY_ID_SAVE,			// ���ޗp
	KEY_ID_LOAD,			// ۰�ޗp
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
