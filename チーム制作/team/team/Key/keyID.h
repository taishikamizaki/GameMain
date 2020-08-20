#pragma once

enum class KEY_ID	//キーの種類
{
	KEY_ID_SPACE,		// ｽﾍﾟｰｽ押下用
	KEY_ID_PAUSE,		// ﾎﾟｰｽﾞﾎﾞﾀﾝ設定用
	KEY_ID_UP,				// ↑
	KEY_ID_RIGHT,		// →
	KEY_ID_DOWN,		// ↓
	KEY_ID_LEFT,			// ←
	KEY_ID_SKILL1,		// ｽｷﾙ1
	KEY_ID_SKILL2,		// ｽｷﾙ2
	KEY_ID_SKILL3,		// ｽｷﾙ3
	KEY_ID_SKILL4,		// ｽｷﾙ4
	KEY_ID_SHOT,		// 弾発射用
	KEY_ID_JUMP,		// ｼﾞｬﾝﾌﾟ用
	KEY_ID_SAVE,			// ｾｰﾌﾞ用
	KEY_ID_LOAD,			// ﾛｰﾄﾞ用
	KEY_ID_HOLD,		//掴み攻撃
	KEY_ID_ATK1,			//弱攻撃
	KEY_ID_ATK2,			//強攻撃
	KEY_ID_MAX
};

KEY_ID begin(KEY_ID);
KEY_ID end(KEY_ID);
KEY_ID operator*(KEY_ID key);
KEY_ID operator++(KEY_ID&key);

