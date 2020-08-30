
#include <DxLib.h>
#include "ScnMng.h"
#include "Common.h"
#include "Title.h"
#include "Game.h"
#include "GameOver.h"

int ScnMng::Init()
{
	SetWindowText(WINDOW_TEXT);
	// ¼½ÃÑˆ—
	SetGraphMode(windowSizeX, windowSizeY, 16);
	ChangeWindowMode(true);
	if (DxLib_Init() == -1)
	{
		return false;
	}

	SetDrawScreen(DX_SCREEN_BACK);

	// ‰Šú‰»
	if (title == nullptr) title = new Title();
	if (game == nullptr) game = new Game();
	if (gameOver == nullptr) gameOver = new GameOver();

	scnID = SCN_ID::SCN_ID_TITLE;

	fadeIn = true;
	fadeOut = false;

	return 0;
}

int ScnMng::ScnCtl()
{
    while (ProcessMessage() == 0 &&
        CheckHitKey(KEY_INPUT_ESCAPE) == 0)
    {
        ClsDrawScreen();

		GetKeyState();
        ScnDraw();

		++fadeCnt;
        ScreenFlip();
    }

    return 0;
}

int ScnMng::ScnDraw()
{
	switch (scnID)
	{
	case SCN_ID::SCN_ID_TITLE:
		
		if (fadeIn)
		{
			if (!FadeInScreen(5))
			{
				fadeOut = false;
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
		if (title != nullptr)
		{
			title->TitleDraw();
			title->TitleCtl();
			if (title->GetFlag())
			{
				fadeOut = true;
			}
		}
		break;
	case SCN_ID::SCN_ID_GAME:
		
		if (fadeIn)
		{
			if (!FadeInScreen(5))
			{
				fadeOut = false;
			}
		}
		if (fadeOut)
		{
			if (!FadeOutScreen(5))
			{
				fadeIn = true;
				scnID = SCN_ID_GAMEOVER;
			}
		}
		if (game != nullptr)
		{
			game->GameDraw();
			game->GameCtl();
			if (game->GetFlag())
			{
				fadeOut = true;
			}
		}
		break;
	case SCN_ID::SCN_ID_GAMEOVER:

		if (fadeIn)
		{
			if (!FadeInScreen(5))
			{
				fadeOut = false;
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
		if (gameOver != nullptr)
		{
			gameOver->GameOverDraw();
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

void ScnMng::GetKeyState(void)
{
	keyFlagOld = keyFlagSp;						// 1ÌÚ°Ñ‘O
	keyFlagSp = CheckHitKey(KEY_INPUT_SPACE);		// Œ»İ
}

// Ìª°ÄŞ²İŠÖ”
bool ScnMng::FadeInScreen(int fadeStep)
{
	if (fadeCnt <= 255)
	{
		SetDrawBright(fadeCnt, fadeCnt, fadeCnt);
		fadeCnt += fadeStep;
		return true; // –ß‚è’l
	}
	else
	{
		SetDrawBright(255, 255, 255);
		fadeIn = false;
		fadeCnt = 0;
		return false; // –ß‚è’l
	}
}

// Ìª°ÄŞ±³ÄŠÖ”
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

ScnMng::ScnMng():
	windowSizeX(1000),
	windowSizeY(600),
	fadeCnt(0)
{
	keyFlagSp = false;
	keyFlagOld = false;

	fadeIn = false;
	fadeOut = false;

    Init();
}

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
