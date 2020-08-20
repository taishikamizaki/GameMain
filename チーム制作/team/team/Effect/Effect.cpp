#include "DxLib.h"
#include "Effect.h"

// ｴﾌｪｸﾄ関連

// 変数宣言
int gameCounter;			// ｹﾞｰﾑｼｰﾝｶｳﾝﾀｰ
int testCounter;			// ｹﾞｰﾑｼｰﾝのﾎﾟｰｽﾞ確認用ｶｳﾝﾀ

bool fadeIn;				// ﾌｪｰﾄﾞｲﾝ
bool fadeOut;				// ﾌｪｰﾄﾞｱｳﾄ
int  fadeCnt;				// ﾌｪｰﾄﾞｶｳﾝﾀ

// ｴﾌｪｸﾄ初期化用
void EffectInit(void)
{
	// ｴﾌｪｸﾄ初期化処理
	fadeIn = true;
	fadeOut = false;
	fadeCnt = 0;
}

// ﾌｪｰﾄﾞｲﾝ関数
bool FadeInScreen(int fadeStep)
{
	if (fadeCnt <= 255)
	{
		SetDrawBright(fadeCnt, fadeCnt, fadeCnt);
		fadeCnt += fadeStep;
		return true; // 戻り値
	}
	else
	{
		SetDrawBright(255, 255, 255);
		fadeIn = false;
		fadeCnt = 0;
		return false; // 戻り値
	}
}

// ﾌｪｰﾄﾞｱｳﾄ関数
bool FadeOutScreen(int fadeStep)
{
	if (fadeCnt <= 255)
	{
		SetDrawBright(255 - fadeCnt, 255 - fadeCnt, 255 - fadeCnt);
		fadeCnt += fadeStep;
		return true;
	}
	else
	{
		SetDrawBright(0, 0, 0);
		fadeOut = false;
		fadeCnt = 0;
		return false;
	}
}

