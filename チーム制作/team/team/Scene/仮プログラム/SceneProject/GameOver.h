#pragma once

// ゲームオーバークラス
class GameOver
{
public:

	// フラグゲッター
	int GetFlag()
	{
		return goF;
	}

	int GameOverCtl();		// 操作系
	int GameOverDraw();		// 描画系

	GameOver();		// コンストラクタ
	~GameOver();	// デストラクタ

private:

	int Init();		// 初期化

	int gameOver;	// 仮置き画像用
	int space;

	int now;		// 自動遷移用変数
	bool goF;		// 遷移フラグ

};

