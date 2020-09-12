#include "DxLib.h"
#include "GetKeyState.h"

// ｷｰ操作関連

// 変数定義
bool keyNew[KEY_ID_MAX];						// ｷｰ判定ﾌﾗｸﾞ
bool keyOld[KEY_ID_MAX];							// ｷｰ後判定ﾌﾗｸﾞ
bool keyDownTrigger[KEY_ID_MAX];	// ｷｰ押下判定ﾌﾗｸﾞ
bool keyUpTrigger[KEY_ID_MAX];			// ｷｰを離した瞬間の判定ﾌﾗｸﾞ
XINPUT_STATE input1;
XINPUT_STATE input2;
KEY_ID_ keyID_;

// ｷｰ情報処理
void KeyInit(void)
{
	// ﾌﾗｸﾞ初期化
	for (int keyID = 0; keyID < keyID_; keyID++)
	{
		keyNew[keyID]         = false;
		keyOld[keyID]         = false;
		keyDownTrigger[keyID] = false;
		keyUpTrigger[keyID]   = false;
	}
}

// ｷｰ情報取得
void KeyCheck(void)
{
	GetJoypadXInputState(DX_INPUT_PAD1, &input1);
	GetJoypadXInputState(DX_INPUT_PAD2, &input2);
	//1ﾌﾚｰﾑ前の情報を取得
	for (int keyID = 0; keyID < KEY_ID_MAX; keyID++)
	{
		keyOld[keyID]    = keyNew[keyID];
	}

	// ﾄﾘｶﾞｰ情報を取得する
	keyNew[KEY_ID_SPACE] = CheckHitKey(KEY_INPUT_SPACE);		// ｽﾍﾟｰｽｷｰでｼｰﾝ移行(default)

	// 追加ｷｰ設定
	keyNew[KEY_ID_PAUSE] = CheckHitKey(KEY_INPUT_P);			// Pｷｰでﾎﾟｰｽﾞ起動

	// 1P
	// 選択用
		keyNew[KEY_ID_UP1]= (input1.ThumbLY >= 20000) &&
			(input1.ThumbLX <= 4000) &&
			(input1.ThumbLX >= -4000);
	
	keyNew[KEY_ID_DOWN1] = (input1.ThumbLY <= -20000) &&
		(input1.ThumbLX <= 4000) &&
		(input1.ThumbLX >= -4000);

	// ジャンプ
	keyNew[KEY_ID_JUMP1] = (input1.ThumbLY >= 20000);

	// ﾌﾟﾚｲﾔｰ操作時のｷｰ情報
	keyNew[KEY_ID_RIGHT1] = (input1.ThumbLX >= 30000);
	keyNew[KEY_ID_LEFT1] = (input1.ThumbLX <= -30000);

	// 弾発射用ｷｰ
	keyNew[KEY_ID_SHOT1]  = CheckHitKey(KEY_INPUT_LCONTROL);

	keyNew[KEY_ID_1SKILL1] = (input1.Buttons[9]);
	keyNew[KEY_ID_1SKILL2] = (input1.Buttons[8]);
	keyNew[KEY_ID_1SKILL3] = (input1.LeftTrigger>=100);
	keyNew[KEY_ID_1SKILL4] = (input1.RightTrigger >= 100);
	keyNew[KEY_ID_1A] = (input1.Buttons[12]);
	keyNew[KEY_ID_1B] = (input1.Buttons[13]);
	keyNew[KEY_ID_1X] = (input1.Buttons[14]);
	keyNew[KEY_ID_1Y] = (input1.Buttons[15]);
	keyNew[KEY_ID_1START] = input1.Buttons[4];

	// 2P
	// 選択用
	keyNew[KEY_ID_UP2] = (input2.ThumbLY >= 30000) &&
		(input2.ThumbLX <= 4000) &&
		(input2.ThumbLX >= -4000);
	keyNew[KEY_ID_DOWN2] = (input2.ThumbLY <= -30000) &&
		(input2.ThumbLX <= 4000) &&
		(input2.ThumbLX >= -4000);

	// ジャンプ
	keyNew[KEY_ID_JUMP2] = (input2.ThumbLY >= 30000);

	// ﾌﾟﾚｲﾔｰ操作時のｷｰ情報
	keyNew[KEY_ID_RIGHT2] = (input2.ThumbLX >= 30000);
	keyNew[KEY_ID_LEFT2] = (input2.ThumbLX <= -30000);

	// 弾発射用ｷｰ
	keyNew[KEY_ID_SHOT2] = CheckHitKey(KEY_INPUT_RCONTROL);

	keyNew[KEY_ID_2SKILL1] = (input2.Buttons[9]);
	keyNew[KEY_ID_2SKILL2] = (input2.Buttons[8]);
	keyNew[KEY_ID_2SKILL3] = (input2.LeftTrigger >= 100);
	keyNew[KEY_ID_2SKILL4] = (input2.RightTrigger >= 100);
	keyNew[KEY_ID_2A] = (input2.Buttons[12]);
	keyNew[KEY_ID_2B] = (input2.Buttons[13]);
	keyNew[KEY_ID_2X] = (input2.Buttons[14]);
	keyNew[KEY_ID_2Y] = (input2.Buttons[15]);
	keyNew[KEY_ID_2START] = input1.Buttons[4];

	// デバッグ用キーコンフィグ
	// 1P
	keyNew[UP1] = CheckHitKey(KEY_INPUT_W);
	keyNew[DOWN1] = CheckHitKey(KEY_INPUT_S);
	keyNew[RIGHT1] = CheckHitKey(KEY_INPUT_D);
	keyNew[LEFT1] = CheckHitKey(KEY_INPUT_A);
	keyNew[CONFIRM1] = CheckHitKey(KEY_INPUT_1);
	keyNew[CANCEL1] = CheckHitKey(KEY_INPUT_2);
	keyNew[P1A1] = CheckHitKey(KEY_INPUT_R);
	keyNew[P1A2] = CheckHitKey(KEY_INPUT_F);
	keyNew[P1S1] = CheckHitKey(KEY_INPUT_1);
	keyNew[P1S2] = CheckHitKey(KEY_INPUT_2);
	keyNew[P1S3] = CheckHitKey(KEY_INPUT_3);
	keyNew[P1S4] = CheckHitKey(KEY_INPUT_4);

	// 2P
	keyNew[UP2] = CheckHitKey(KEY_INPUT_UP);
	keyNew[DOWN2] = CheckHitKey(KEY_INPUT_DOWN);
	keyNew[RIGHT2] = CheckHitKey(KEY_INPUT_RIGHT);
	keyNew[LEFT2] = CheckHitKey(KEY_INPUT_LEFT);
	keyNew[CONFIRM2] = CheckHitKey(KEY_INPUT_NUMPAD1);
	keyNew[CANCEL2] = CheckHitKey(KEY_INPUT_NUMPAD2);
	keyNew[P2A1] = CheckHitKey(KEY_INPUT_NUMPAD5);
	keyNew[P2A2] = CheckHitKey(KEY_INPUT_NUMPAD6);
	keyNew[P2S1] = CheckHitKey(KEY_INPUT_NUMPAD1);
	keyNew[P2S2] = CheckHitKey(KEY_INPUT_NUMPAD2);
	keyNew[P2S3] = CheckHitKey(KEY_INPUT_NUMPAD3);
	keyNew[P2S4] = CheckHitKey(KEY_INPUT_NUMPAD4);

	// ｾｰﾌﾞ&ﾛｰﾄﾞ用ｷｰ
	keyNew[KEY_ID_SAVE]  = CheckHitKey(KEY_INPUT_S);		// ｾｰﾌﾞ
	keyNew[KEY_ID_LOAD]  = CheckHitKey(KEY_INPUT_L);		// ﾛｰﾄﾞ

	// ﾄﾘｶﾞｰ
	for (int keyID = 0; keyID < KEY_ID_MAX; keyID++)
	{
		// ﾄﾘｶﾞｰ初期化
		keyDownTrigger[keyID] = false;
		keyUpTrigger[keyID]   = false;
		
		// ﾄﾘｶﾞｰﾌﾚｰﾑ判定
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

