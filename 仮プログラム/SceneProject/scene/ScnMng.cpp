
#include <DxLib.h>
#include "ScnMng.h"
#include "../Common.h"
#include "../key/GetKeyState.h"
#include "Title.h"
#include "Game.h"
#include "GameOver.h"

// ����������
int ScnMng::Init()
{
	SetWindowText(WINDOW_TEXT);
	// ���я���
	SetGraphMode(windowSizeX, windowSizeY, 16);
	ChangeWindowMode(true);
	if (DxLib_Init() == -1)
	{
		return false;
	}

	SetDrawScreen(DX_SCREEN_BACK);
	SetCreateSoundDataType(DX_SOUNDDATATYPE_FILE);

	KeyInit();
	// ������
	if (title == nullptr) title = new Title();
	if (game == nullptr) game = new Game();
	if (gameOver == nullptr) gameOver = new GameOver();

	scnID = SCN_ID::SCN_ID_TITLE;		// �����V�[�����^�C�g����

	SetVolumeMusic(10);
	/*SetVolumeMusic(5);
	PlaySoundMem(seleBgm, DX_PLAYTYPE_LOOP);
	StopMusicMem(seleBgm);*/
	fadeIn = true;
	fadeOut = false;

	return 0;
}

// ���쏈��
int ScnMng::ScnCtl()
{
    while (ProcessMessage() == 0 &&
        CheckHitKey(KEY_INPUT_ESCAPE) == 0)
    {
        ClsDrawScreen();

		KeyCheck();
        ScnDraw();

		++fadeCnt;
        ScreenFlip();
    }

    return 0;
}

// �`�揈��
int ScnMng::ScnDraw()
{
	switch (scnID)
	{
		// �^�C�g��
	case SCN_ID::SCN_ID_TITLE:
		fadeOut = false;
		if (title != nullptr)
		{
			if (title->GetFlag())
			{
				fadeOut = true;
			}
		}
		if (fadeIn)
		{
			if (!FadeInScreen(5))
			{
				fadeOut = false;

			}
		}
		if (fadeOut && !fadeIn)
		{
			if (!FadeOutScreen(5))
			{
				//StopMusic();
				fadeIn = true;

				scnID = SCN_ID_GAME;
				if (gameOver != nullptr)
				{
					gameOver->GameOver::GameOver();
				}
			}
		}
		if (title != nullptr)
		{
			title->Draw();
			title->TitleCtl();
			if (title->GetFlag())
			{
				fadeOut = true;
			}
		}
		break;
		// �Z���N�g���Q�[��
	case SCN_ID::SCN_ID_GAME:
		fadeOut = false;
	
		if (game != nullptr)
		{

			scnCntOld = scnCnt;
			if (scnCntOld == 0)
			{
				game->Game::Game();
				scnCnt++;
			}
			if (game->GetFlag())
			{
				scnID = SCN_ID_GAMEOVER;
				scnCnt = 0;
			}
		}
		if (fadeIn && !fadeOut)
		{
			if (!FadeInScreen(5))
			{
				fadeOut = false;
			}
		}
		if (game != nullptr)
		{
			game->Draw();
			game->SelectCtl();
			if (game->GetFlag())
			{
				scnID = SCN_ID_GAMEOVER;
			}
		}
		break;
		// �Q�[���I�[�o�[
	case SCN_ID::SCN_ID_GAMEOVER:
		fadeOut = false;
		if (gameOver != nullptr)
		{
			if (gameOver->GetFlag())
			{
				fadeOut = true;
				scnCnt = 0;
			}
		}
		if (fadeIn)
		{
			if (!FadeInScreen(5))
			{
				fadeOut = false;
			}
		}
		if (fadeOut && !fadeIn)
		{
			if (!FadeOutScreen(5))
			{
				fadeIn = true;
				scnID = SCN_ID_TITLE;
				if (title != nullptr)
				{
					title->Title::Title();
				}
			}
		}
		if (gameOver != nullptr)
		{
			gameOver->Draw();
			gameOver->GameOverCtl();
			if (gameOver->GetFlag())
			{
				fadeOut = true;
			}
		}
		break;
	case SCN_ID::SCN_ID_MAX:

		break;
	default:
		break;
	}

    return 0;
}

// ̪��޲݊֐�
bool ScnMng::FadeInScreen(int fadeStep)
{
	if (fadeCnt <= 255)
	{
		SetDrawBright(fadeCnt, fadeCnt, fadeCnt);
		fadeCnt += fadeStep;
		return true; // �߂�l
	}
	else
	{
		SetDrawBright(255, 255, 255);
		fadeIn = false;
		fadeCnt = 0;
		return false; // �߂�l
	}
}

// ̪��ޱ�Ċ֐�
bool ScnMng::FadeOutScreen(int fadeStep)
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

// �R���X�g���N�^
ScnMng::ScnMng():
	windowSizeX(1000),
	windowSizeY(600),
	fadeCnt(0),
	scnCnt(0),
	scnCntOld(0)
{
	fadeIn = false;
	fadeOut = false;

    Init();
}

// �f�X�g���N�^
ScnMng::~ScnMng()
{
	if (title != nullptr)
	{
		delete title;
		title = nullptr;
	}
	if (game != nullptr)
	{
		delete game;
		game = nullptr;
	}
	if (gameOver != nullptr)
	{
		delete gameOver;
		gameOver = nullptr;
	}
}
