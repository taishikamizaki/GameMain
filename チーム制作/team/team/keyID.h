#pragma once

enum class KEY_ID	//�L�[�̎��
{
	KEY_ID_SPACE,		// ��߰������p
	KEY_ID_PAUSE,		// �߰�����ݐݒ�p
	KEY_ID_UP,				// ��
	KEY_ID_RIGHT,		// ��
	KEY_ID_DOWN,		// ��
	KEY_ID_LEFT,			// ��
	KEY_ID_SKILL1,		// ���1
	KEY_ID_SKILL2,		// ���2
	KEY_ID_SKILL3,		// ���3
	KEY_ID_SKILL4,		// ���4
	KEY_ID_SHOT,		// �e���˗p
	KEY_ID_JUMP,		// �ެ��ߗp
	KEY_ID_SAVE,			// ���ޗp
	KEY_ID_LOAD,			// ۰�ޗp
	KEY_ID_HOLD,		//�͂ݍU��
	KEY_ID_ATK1,			//��U��
	KEY_ID_ATK2,			//���U��
	KEY_ID_MAX
};

KEY_ID begin(KEY_ID);
KEY_ID end(KEY_ID);
KEY_ID operator*(KEY_ID key);
KEY_ID operator++(KEY_ID&key);

