#pragma once

// ﾌﾟﾛﾄﾀｲﾌﾟ宣言
void EffectInit(void);					// ｴﾌｪｸﾄ初期化用
bool FadeInScreen(int fadeStep);		// ﾌｪｰﾄﾞｲﾝ処理
bool FadeOutScreen(int fadeStep);		// ﾌｪｰﾄﾞｱｳﾄ処理

// ｴｸｽﾀﾝ宣言
extern int gameCounter;
extern int testCounter;

extern bool fadeIn;
extern bool fadeOut;
