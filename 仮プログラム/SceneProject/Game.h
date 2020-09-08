#pragma once

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

	int charID_1;
	int charID_2;

	int pID_1;
	int pID_2;
};

