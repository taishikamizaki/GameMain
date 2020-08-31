#pragma once

// ゲームクラス
class Game
{
public:

	// フラグゲッター
	int GetFlag()
	{
		return _gameF;
	}

	int GameCtl();		// 操作系
	int GameDraw();		// 描画

	Game();		// コンストラクタ
	~Game();	// デストラクタ

private:

	int Init();		// 初期化

	int select;		// 仮置き画像用
	int game;		// 仮置き画像用

	bool gameF;		// 切り替え用
	bool _gameF;	// シーン遷移用

};

