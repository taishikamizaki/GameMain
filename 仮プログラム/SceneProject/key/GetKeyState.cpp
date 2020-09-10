#include "DxLib.h"
#include "GetKeyState.h"

// ������֘A

// �ϐ���`
bool keyNew[KEY_ID_MAX];						// �������׸�
bool keyOld[KEY_ID_MAX];							// ���㔻���׸�
bool keyDownTrigger[KEY_ID_MAX];	// �����������׸�
bool keyUpTrigger[KEY_ID_MAX];			// ���𗣂����u�Ԃ̔����׸�

// ����񏈗�
void KeyInit(void)
{
	// �׸ޏ�����
	for (int keyID = 0; keyID < KEY_ID_MAX; keyID++)
	{
		keyNew[keyID]         = false;
		keyOld[keyID]         = false;
		keyDownTrigger[keyID] = false;
		keyUpTrigger[keyID]   = false;
	}
}

// �����擾
void KeyCheck(void)
{
	//1�ڰёO�̏����擾
	for (int keyID = 0; keyID < KEY_ID_MAX; keyID++)
	{
		keyOld[keyID]    = keyNew[keyID];
	}

	// �ضް�����擾����
	keyNew[KEY_ID_SPACE] = CheckHitKey(KEY_INPUT_SPACE);		// ��߰����ż�݈ڍs(default)

	// �ǉ����ݒ�
	keyNew[KEY_ID_PAUSE] = CheckHitKey(KEY_INPUT_P);			// P�����߰�ދN��

	// 1P
	// �I��p
	keyNew[KEY_ID_UP1] = CheckHitKey(KEY_INPUT_W);
	keyNew[KEY_ID_DOWN1] = CheckHitKey(KEY_INPUT_S);

	// �W�����v
	keyNew[KEY_ID_JUMP1]  = CheckHitKey(KEY_INPUT_W);

	// ��ڲ԰���쎞�̷����
	keyNew[KEY_ID_RIGHT1] = CheckHitKey(KEY_INPUT_D);
	keyNew[KEY_ID_LEFT1]  = CheckHitKey(KEY_INPUT_A);

	// �e���˗p��
	keyNew[KEY_ID_SHOT1]  = CheckHitKey(KEY_INPUT_LCONTROL);

	keyNew[KEY_ID_1SKILL1] = CheckHitKey(KEY_INPUT_1);
	keyNew[KEY_ID_1SKILL2] = CheckHitKey(KEY_INPUT_2);
	keyNew[KEY_ID_1SKILL3] = CheckHitKey(KEY_INPUT_3);
	keyNew[KEY_ID_1SKILL4] = CheckHitKey(KEY_INPUT_4);

	// 2P
	// �I��p
	keyNew[KEY_ID_UP2] = CheckHitKey(KEY_INPUT_UP);
	keyNew[KEY_ID_DOWN2] = CheckHitKey(KEY_INPUT_DOWN);

	// �W�����v
	keyNew[KEY_ID_JUMP2] = CheckHitKey(KEY_INPUT_UP);

	// ��ڲ԰���쎞�̷����
	keyNew[KEY_ID_RIGHT2] = CheckHitKey(KEY_INPUT_RIGHT);
	keyNew[KEY_ID_LEFT2] = CheckHitKey(KEY_INPUT_LEFT);

	// �e���˗p��
	keyNew[KEY_ID_SHOT2] = CheckHitKey(KEY_INPUT_RCONTROL);

	keyNew[KEY_ID_2SKILL1] = CheckHitKey(KEY_INPUT_NUMPAD1);
	keyNew[KEY_ID_2SKILL2] = CheckHitKey(KEY_INPUT_NUMPAD2);
	keyNew[KEY_ID_2SKILL3] = CheckHitKey(KEY_INPUT_NUMPAD3);
	keyNew[KEY_ID_2SKILL4] = CheckHitKey(KEY_INPUT_NUMPAD4);


	// ����&۰�ޗp��
	keyNew[KEY_ID_SAVE]  = CheckHitKey(KEY_INPUT_S);		// ����
	keyNew[KEY_ID_LOAD]  = CheckHitKey(KEY_INPUT_L);		// ۰��

	// �ضް
	for (int keyID = 0; keyID < KEY_ID_MAX; keyID++)
	{
		// �ضް������
		keyDownTrigger[keyID] = false;
		keyUpTrigger[keyID]   = false;
		
		// �ضް�ڰє���
		if (keyNew[keyID] && !keyOld[keyID])
		{
			keyDownTrigger[keyID] = true;
		}
		if (!keyNew[keyID] && keyOld[keyID])
		{
			keyUpTrigger[keyID]   = true;
		}
	}
}

