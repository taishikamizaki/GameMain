#include "DxLib.h"
#include "main.h"

int Player;
// WinMain関数
int WINAPI WinMain(HINSTANCE, HINSTANCE, LPSTR, int)
{
	/*if (!SysInit())
	{
		return 0;
	}*/

	// 初期化関数呼び出し
	/*SysInit();*/

	// ｹﾞｰﾑﾙｰﾌﾟ
	while (ProcessMessage() == 0 &&
		CheckHitKey(KEY_INPUT_ESCAPE) == 0)
	{
		/*KeyCheck();
		gameCounter++;*/

		// ｼｰﾝ遷移用ｽｲｯﾁ文
		/*switch (scnID)
		{
		case SCN_ID_INIT:
			InitScene();
			scnID = SCN_ID_TITLE;
			break;
		case SCN_ID_TITLE:
			if (fadeIn)
			{
				if (!FadeInScreen(5))
				{

				}
			}
			if (fadeOut)
			{
				if (!FadeOutScreen(5))
				{
					fadeIn = true;
					scnID = SCN_ID_SELECT;
				}
			}

			TitleInit();
			break;
		case SCN_ID_SELECT:
			if (fadeIn)
			{
				if (!FadeInScreen(5))
				{

				}
			}
			if (fadeOut)
			{
				if (!FadeOutScreen(5))
				{
					fadeIn = true;
					scnID = SCN_ID_GAME;
				}
			}
			SelectInit();
			break;
		case SCN_ID_GAME:
			if (fadeIn)
			{
				if (!FadeInScreen(5))
				{

				}
			}
			if (fadeOut)
			{
				if (!FadeOutScreen(5))
				{
					fadeIn = true;
					scnID = SCN_ID_RESULT;
				}
			}
			GameInit();
			break;
		case SCN_ID_RESULT:
			if (fadeIn)
			{
				if (!FadeInScreen(5))
				{

				}
			}
			if (fadeOut)
			{
				if (!FadeOutScreen(5))
				{
					fadeIn = true;
					if (titleFlag)
					{
						scnID = SCN_ID_TITLE;
					}
					if (selectFlag)
					{
						scnID = SCN_ID_SELECT;
					}
					if (gameOverFlag)
					{
						scnID = SCN_ID_GAMEOVER;
					}
				}
			}
			ResultInit();
			break;
		case SCN_ID_GAMEOVER:
			if (fadeIn)
			{
				if (!FadeInScreen(5))
				{

				}
			}
			if (fadeOut)
			{
				if (!FadeOutScreen(5))
				{
					fadeIn = true;
					scnID = SCN_ID_TITLE;
				}
			}
			GameOverInit();
			break;
		}*/

	}

	DxLib_End();
	return 0;
}