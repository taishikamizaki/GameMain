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

	// ﾀﾞｯｼｭ
	keyNew[KEY_ID_JUMP]  = CheckHitKey(KEY_INPUT_LSHIFT);

	// ﾌﾟﾚｲﾔｰ操作時のｷｰ情報
	keyNew[KEY_ID_UP]    = CheckHitKey(KEY_INPUT_UP);
	keyNew[KEY_ID_RIGHT] = CheckHitKey(KEY_INPUT_RIGHT);
	keyNew[KEY_ID_DOWN]  = CheckHitKey(KEY_INPUT_DOWN);
	keyNew[KEY_ID_LEFT]  = CheckHitKey(KEY_INPUT_LEFT);

	// 弾発射用ｷｰ
	keyNew[KEY_ID_SHOT]  = CheckHitKey(KEY_INPUT_LCONTROL);

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

