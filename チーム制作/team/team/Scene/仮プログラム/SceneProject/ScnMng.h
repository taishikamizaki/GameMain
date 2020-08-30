#pragma once


#define SCN_MNG ScnMng::GetInstance()

// ¼°İí•Ê
enum SCN_ID
{
	SCN_ID_TITLE,				// À²ÄÙ
	SCN_ID_CHAR_SEL,		// ·¬×‘I‘ğ
	SCN_ID_GAME,				// ¹Ş°Ñ’†
	SCN_ID_GAMEOVER,	// ¹Ş°Ñµ°ÊŞ°
	SCN_ID_MAX
};

class Title;
class Game;
class GameOver;

class ScnMng
{
public:
	static ScnMng& GetInstance()
	{
		static ScnMng s_instance;
		return s_instance;
	}

	int ScnCtl();
	
	bool FadeInScreen(int fadeStep);			// Ìª°ÄŞ²İˆ—
	bool FadeOutScreen(int fadeStep);		// Ìª°ÄŞ±³Äˆ—

	bool fadeIn;			// Ìª°ÄŞ²İ
	bool fadeOut;		// Ìª°ÄŞ±³Ä

	bool keyFlagSp;
	bool keyFlagOld;

private:
	Title* title;
	Game* game;
	GameOver* gameOver;

	int Init();
	int ScnDraw();

	void GetKeyState(void);

	int windowSizeX;
	int windowSizeY;

	int  fadeCnt;						// Ìª°ÄŞ¶³İÀ

	SCN_ID scnID;

	ScnMng();
	~ScnMng();

};

