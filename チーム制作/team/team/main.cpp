#include "DxLib.h"
#include "main.h"


// WinMain�֐�
int main(void)
{
	/*if (!SysInit())
	{
		return 0;
	}*/

	// �������֐��Ăяo��
	/*SysInit();*/

	// �ް�ٰ��
	while (ProcessMessage() == 0 &&
		CheckHitKey(KEY_INPUT_ESCAPE) == 0)
	{
		/*KeyCheck();
		gameCounter++;*/

		// ��ݑJ�ڗp������
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