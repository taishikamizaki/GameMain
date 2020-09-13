#pragma once

// タイトルクラス
class Title
{
public:

	// フラグゲッター
	int GetFlag()
	{
		return titleF;
	}

	int TitleCtl();		// 操作処理
	int Draw();	// 描画処理

	Title();	// コンストラクタ
	~Title();	// デストラクタ

private:
	int Init();		// 初期化

	int title;		// 仮置き画像用
	int titleL;
	int space;

	int titleBgm;
	bool titleF;	// 遷移フラグ

};

