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

	// �ޯ��
	keyNew[KEY_ID_JUMP]  = CheckHitKey(KEY_INPUT_LSHIFT);

	// ��ڲ԰���쎞�̷����
	keyNew[KEY_ID_UP]    = CheckHitKey(KEY_INPUT_UP);
	keyNew[KEY_ID_RIGHT] = CheckHitKey(KEY_INPUT_RIGHT);
	keyNew[KEY_ID_DOWN]  = CheckHitKey(KEY_INPUT_DOWN);
	keyNew[KEY_ID_LEFT]  = CheckHitKey(KEY_INPUT_LEFT);

	// �e���˗p��
	keyNew[KEY_ID_SHOT]  = CheckHitKey(KEY_INPUT_LCONTROL);

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

