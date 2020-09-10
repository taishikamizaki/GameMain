#include "DxLib.h"
#include "GetKeyState.h"

// ｷｰ操作関連

// 変数定義
bool keyNew[KEY_ID_MAX];						// ｷｰ判定ﾌﾗｸﾞ
bool keyOld[KEY_ID_MAX];							// ｷｰ後判定ﾌﾗｸﾞ
bool keyDownTrigger[KEY_ID_MAX];	// ｷｰ押下判定ﾌﾗｸﾞ
bool keyUpTrigger[KEY_ID_MAX];			// ｷｰを離した瞬間の判定ﾌﾗｸﾞ

// ｷｰ情報処理
void KeyInit(void)
{
	// ﾌﾗｸﾞ初期化
	for (int keyID = 0; keyID < KEY_ID_MAX; keyID++)
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
	keyNew[KEY_ID_UP1] = CheckHitKey(KEY_INPUT_W);
	keyNew[KEY_ID_DOWN1] = CheckHitKey(KEY_INPUT_S);

	// ジャンプ
	keyNew[KEY_ID_JUMP1]  = CheckHitKey(KEY_INPUT_W);

	// ﾌﾟﾚｲﾔｰ操作時のｷｰ情報
	keyNew[KEY_ID_RIGHT1] = CheckHitKey(KEY_INPUT_D);
	keyNew[KEY_ID_LEFT1]  = CheckHitKey(KEY_INPUT_A);

	// 弾発射用ｷｰ
	keyNew[KEY_ID_SHOT1]  = CheckHitKey(KEY_INPUT_LCONTROL);

	keyNew[KEY_ID_1SKILL1] = CheckHitKey(KEY_INPUT_1);
	keyNew[KEY_ID_1SKILL2] = CheckHitKey(KEY_INPUT_2);
	keyNew[KEY_ID_1SKILL3] = CheckHitKey(KEY_INPUT_3);
	keyNew[KEY_ID_1SKILL4] = CheckHitKey(KEY_INPUT_4);

	// 2P
	// 選択用
	keyNew[KEY_ID_UP2] = CheckHitKey(KEY_INPUT_UP);
	keyNew[KEY_ID_DOWN2] = CheckHitKey(KEY_INPUT_DOWN);

	// ジャンプ
	keyNew[KEY_ID_JUMP2] = CheckHitKey(KEY_INPUT_UP);

	// ﾌﾟﾚｲﾔｰ操作時のｷｰ情報
	keyNew[KEY_ID_RIGHT2] = CheckHitKey(KEY_INPUT_RIGHT);
	keyNew[KEY_ID_LEFT2] = CheckHitKey(KEY_INPUT_LEFT);

	// 弾発射用ｷｰ
	keyNew[KEY_ID_SHOT2] = CheckHitKey(KEY_INPUT_RCONTROL);

	keyNew[KEY_ID_2SKILL1] = CheckHitKey(KEY_INPUT_NUMPAD1);
	keyNew[KEY_ID_2SKILL2] = CheckHitKey(KEY_INPUT_NUMPAD2);
	keyNew[KEY_ID_2SKILL3] = CheckHitKey(KEY_INPUT_NUMPAD3);
	keyNew[KEY_ID_2SKILL4] = CheckHitKey(KEY_INPUT_NUMPAD4);


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

