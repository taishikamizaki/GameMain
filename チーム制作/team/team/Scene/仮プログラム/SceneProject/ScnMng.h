#pragma once


#define SCN_MNG ScnMng::GetInstance()

// ｼｰﾝ種別
enum SCN_ID
{
	SCN_ID_TITLE,				// ﾀｲﾄﾙ
	SCN_ID_CHAR_SEL,		// ｷｬﾗ選択
	SCN_ID_GAME,				// ｹﾞｰﾑ中
	SCN_ID_GAMEOVER,	// ｹﾞｰﾑｵｰﾊﾞｰ
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
	
	bool FadeInScreen(int fadeStep);			// ﾌｪｰﾄﾞｲﾝ処理
	bool FadeOutScreen(int fadeStep);		// ﾌｪｰﾄﾞｱｳﾄ処理

	bool fadeIn;			// ﾌｪｰﾄﾞｲﾝ
	bool fadeOut;		// ﾌｪｰﾄﾞｱｳﾄ

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

	int  fadeCnt;						// ﾌｪｰﾄﾞｶｳﾝﾀ

	SCN_ID scnID;

	ScnMng();
	~ScnMng();

};

