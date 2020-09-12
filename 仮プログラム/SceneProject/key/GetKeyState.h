#pragma once

// ｷｰ押下判定用
enum KEY_ID_
{
	KEY_ID_SPACE,		// ｽﾍﾟｰｽ押下用
	KEY_ID_PAUSE,		// ﾎﾟｰｽﾞﾎﾞﾀﾝ設定用

	KEY_ID_UP1,			// ↑
	KEY_ID_RIGHT1,		// →
	KEY_ID_DOWN1,		// ↓
	KEY_ID_LEFT1,		// ←
	KEY_ID_SHOT1,		// 弾発射用
	KEY_ID_JUMP1,		// ｼﾞｬﾝﾌﾟ用
	KEY_ID_1SKILL1,		// ｽｷﾙ1
	KEY_ID_1SKILL2,		// ｽｷﾙ2
	KEY_ID_1SKILL3,		// ｽｷﾙ3
	KEY_ID_1SKILL4,		// ｽｷﾙ4
	KEY_ID_1A,
	KEY_ID_1B,
	KEY_ID_1X,
	KEY_ID_1Y,
	KEY_ID_1START,

	KEY_ID_UP2,			// ↑
	KEY_ID_RIGHT2,		// →
	KEY_ID_DOWN2,		// ↓
	KEY_ID_LEFT2,		// ←
	KEY_ID_SHOT2,		// 弾発射用
	KEY_ID_JUMP2,		// ｼﾞｬﾝﾌﾟ用
	KEY_ID_2SKILL1,		// ｽｷﾙ1
	KEY_ID_2SKILL2,		// ｽｷﾙ2
	KEY_ID_2SKILL3,		// ｽｷﾙ3
	KEY_ID_2SKILL4,		// ｽｷﾙ4
	KEY_ID_2A,
	KEY_ID_2B,
	KEY_ID_2X,
	KEY_ID_2Y,
	KEY_ID_2START,

	// デバッグ用キーコンフィグ
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

	KEY_ID_SAVE,		// ｾｰﾌﾞ用
	KEY_ID_LOAD,		// ﾛｰﾄﾞ用
	KEY_ID_MAX
};

// ﾌﾟﾛﾄﾀｲﾌﾟ宣言
void KeyInit(void);								// 初期化
void KeyCheck(void);							// ｷｰ判定

// ｴｸｽﾀﾝ宣言
extern bool keyNew[KEY_ID_MAX];							// ｷｰ押下判定（現在）
extern bool keyOld[KEY_ID_MAX];								// ｷｰ押下判定（ﾌﾚｰﾑ前）
extern bool keyDownTrigger[KEY_ID_MAX];		// ｷｰ押下時判定
extern bool keyUpTrigger[KEY_ID_MAX];				// ｷｰを離した時の判定
