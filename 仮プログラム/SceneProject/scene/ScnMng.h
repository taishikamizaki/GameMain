#pragma once

// 呼び出しマクロ
#define SCN_MNG ScnMng::GetInstance()

// クラス呼び出し
class Title;
class Game;
class GameOver;

// シーンマネージャー
class ScnMng
{
public:
	static ScnMng& GetInstance()
	{
		static ScnMng s_instance;
		return s_instance;
	}

	// ｼｰﾝ種別
	enum SCN_ID
	{
		SCN_ID_TITLE,		// ﾀｲﾄﾙ
		SCN_ID_CHAR_SEL,	// ｷｬﾗ選択
		SCN_ID_GAME,		// ｹﾞｰﾑ中
		SCN_ID_GAMEOVER,	// ｹﾞｰﾑｵｰﾊﾞｰ
		SCN_ID_MAX
	};

	int ScnCtl();		// シーン操作用
	
	bool FadeInScreen(int fadeStep);	// ﾌｪｰﾄﾞｲﾝ処理
	bool FadeOutScreen(int fadeStep);	// ﾌｪｰﾄﾞｱｳﾄ処理

	bool fadeIn;	// ﾌｪｰﾄﾞｲﾝ
	bool fadeOut;	// ﾌｪｰﾄﾞｱｳﾄ

private:
	Title*    title;		// class:Title
	Game*     game;			// class:Game
	GameOver* gameOver;		// class:GameOver

	int Init();		// 初期化
	int ScnDraw();	// 描画

	int windowSizeX;	// 画面横サイズ
	int windowSizeY;	// 画面縦サイズ

	int  fadeCnt;		// ﾌｪｰﾄﾞｶｳﾝﾀ

	SCN_ID scnID;		// シーン種別ID	

	int scnCnt;
	int scnCntOld;

	int charID_1;
	int charID_2;

	int pID_1;
	int pID_2;

	ScnMng();
	~ScnMng();

};

