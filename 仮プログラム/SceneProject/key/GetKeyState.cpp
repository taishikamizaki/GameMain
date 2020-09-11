#include "DxLib.h"
#include "GetKeyState.h"

// ������֘A

// �ϐ���`
bool keyNew[KEY_ID_MAX];						// �������׸�
bool keyOld[KEY_ID_MAX];							// ���㔻���׸�
bool keyDownTrigger[KEY_ID_MAX];	// �����������׸�
bool keyUpTrigger[KEY_ID_MAX];			// ���𗣂����u�Ԃ̔����׸�
XINPUT_STATE input1;
XINPUT_STATE input2;
KEY_ID_ keyID_;

// ����񏈗�
void KeyInit(void)
{
	// �׸ޏ�����
	for (int keyID = 0; keyID < keyID_; keyID++)
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
	GetJoypadXInputState(DX_INPUT_PAD1, &input1);
	GetJoypadXInputState(DX_INPUT_PAD2, &input2);
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

		keyNew[KEY_ID_UP1]= (input1.ThumbLY >= 20000) &&
			(input1.ThumbLX <= 4000) &&
			(input1.ThumbLX >= -4000);
	
	
	keyNew[KEY_ID_DOWN1] = (input1.ThumbLY <= -20000) &&
		(input1.ThumbLX <= 4000) &&
		(input1.ThumbLX >= -4000);

	// �W�����v
	keyNew[KEY_ID_JUMP1] = (input1.ThumbLY >= 20000);
		/*&&
		(input1.ThumbLX <= 7000) &&
		(input1.ThumbLX >= -7000)*/

	// ��ڲ԰���쎞�̷����
	keyNew[KEY_ID_RIGHT1] = (input1.ThumbLX >= 20000);
		/*&&
		(input1.ThumbLY <= 4000) &&
		(input1.ThumbLY >= -4000);*/
	keyNew[KEY_ID_LEFT1] = (input1.ThumbLX <= -20000);
		/*&&
		(input1.ThumbLY <= 4000) &&
		(input1.ThumbLY >= -4000);*/

	// �e���˗p��
	keyNew[KEY_ID_SHOT1]  = CheckHitKey(KEY_INPUT_LCONTROL);

	keyNew[KEY_ID_1SKILL1] = (input1.Buttons[9]);
	keyNew[KEY_ID_1SKILL2] = (input1.Buttons[8]);
	keyNew[KEY_ID_1SKILL3] = (input1.LeftTrigger>=100);
	keyNew[KEY_ID_1SKILL4] = (input1.RightTrigger >= 100);
	keyNew[KEY_ID_1A] = (input1.Buttons[12]);
	keyNew[KEY_ID_1B] = (input1.Buttons[13]);
	keyNew[KEY_ID_1X] = (input1.Buttons[14]);
	keyNew[KEY_ID_1Y] = (input1.Buttons[15]);

	// 2P
	// �I��p
	keyNew[KEY_ID_UP2] = (input2.ThumbLY >= 20000) &&
		(input2.ThumbLX <= 4000) &&
		(input2.ThumbLX >= -4000);
	keyNew[KEY_ID_DOWN2] = (input2.ThumbLY <= -20000) &&
		(input2.ThumbLX <= 4000) &&
		(input2.ThumbLX >= -4000);

	// �W�����v
	keyNew[KEY_ID_JUMP2] = (input2.ThumbLY >= 20000);

	// ��ڲ԰���쎞�̷����
	keyNew[KEY_ID_RIGHT2] = (input2.ThumbLX >= 20000);
	keyNew[KEY_ID_LEFT2] = (input2.ThumbLX <= -20000);

	// �e���˗p��
	keyNew[KEY_ID_SHOT2] = CheckHitKey(KEY_INPUT_RCONTROL);

	keyNew[KEY_ID_2SKILL1] = (input2.Buttons[9]);
	keyNew[KEY_ID_2SKILL2] = (input2.Buttons[8]);
	keyNew[KEY_ID_2SKILL3] = (input2.LeftTrigger >= 100);
	keyNew[KEY_ID_2SKILL4] = (input2.RightTrigger >= 100);
	keyNew[KEY_ID_2A] = (input2.Buttons[12]);
	keyNew[KEY_ID_2B] = (input2.Buttons[13]);
	keyNew[KEY_ID_2X] = (input2.Buttons[14]);
	keyNew[KEY_ID_2Y] = (input2.Buttons[15]);

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

