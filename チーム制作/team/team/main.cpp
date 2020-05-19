#include "DxLib.h"
#include "Init.h"
#include "GetKeyState.h"
#include "Title.h"
#include "Select.h"
#include "Game.h"
#include "Pause.h"
#include "Result.h"
#include "GameOver.h"
#include "Effect.h"
#include "main.h"

SCN_ID scnID;
SCN_ID scnIDOld;

// WinMain�֐�
int main(void)
{
	if (!SysInit())
	{
		return 0;
	}

	// �������֐��Ăяo��
	/*SysInit();*/

	// �ް�ٰ��
	while (ProcessMessage() == 0 &&
		CheckHitKey(KEY_INPUT_ESCAPE) == 0)
	{
		ClsDrawScreen();
		KeyCheck();
		/*gamecounter++;*/

		// ��݈ڍs�Ŷ����ؾ��
		if (scnID != scnIDOld)
		{
			scnIDOld = scnID;
			/*sceneCnt = 0;
			gameCounter = 0;*/
		}

		// ��ݑJ�ڗp������
		switch (scnID)
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
		case SCN_ID_PAUSE:
			PauseInit();
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
					//if (selectFlag)
					//{
					//	// �L�����Z���ֈڍs
					//	scnID = SCN_ID_SELECT;
					//}
					//if (gameOverFlag)
					//{
					scnID = SCN_ID_GAMEOVER;
					//}
				}
			}
			ResultScene();
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
					scnID = SCN_ID_INIT;
				}
			}
			GameOverScene();
			break;
		}
			ScreenFlip();//����ʂ�\��ʂɏu�ԃR�s�[

	}

	DxLib_End();
	return 0;
}

