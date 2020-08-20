#pragma once

// ｷｰ押下判定用
enum KEY_ID_
{
	KEY_ID_SPACE,		// ｽﾍﾟｰｽ押下用
	KEY_ID_PAUSE,		// ﾎﾟｰｽﾞﾎﾞﾀﾝ設定用
	KEY_ID_UP,				// ↑
	KEY_ID_RIGHT,		// →
	KEY_ID_DOWN,		// ↓
	KEY_ID_LEFT,			// ←
	KEY_ID_SHOT,		// 弾発射用
	KEY_ID_JUMP,		// ｼﾞｬﾝﾌﾟ用
	KEY_ID_SKILL1,		// ｽｷﾙ1
	KEY_ID_SKILL2,		// ｽｷﾙ2
	KEY_ID_SKILL3,		// ｽｷﾙ3
	KEY_ID_SKILL4,		// ｽｷﾙ4
	KEY_ID_SAVE,			// ｾｰﾌﾞ用
	KEY_ID_LOAD,			// ﾛｰﾄﾞ用
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
