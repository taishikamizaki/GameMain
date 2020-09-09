#pragma once


enum class CHAR_ID
{
	CHAR_ID_KISI,
	CHAR_ID_MDOU,
	CHAR_ID_BTOU,
	CHAR_ID_4,
	CHAR_ID_MAX
};

// ゲームクラス
class Player;
class Game
{
public:

	// フラグゲッター
	int GetFlag()
	{
		return _gameF;
	}

	int SelectCtl();			// セレクト操作系
	int GameCtl();				// ゲーム操作系
	int Draw();		// 描画

	Game();		// コンストラクタ
	~Game();	// デストラクタ

	Player* player;

private:

	int Init();		// 初期化

	int select;		// 仮置き画像用
	int game;		// 仮置き画像用
	int space;

	bool selectF;	// 切り替え用
	bool gameF;		// 切り替え用
	bool _gameF;	// シーン遷移用

	CHAR_ID player1;
	CHAR_ID player2;

	friend class Player;

};

