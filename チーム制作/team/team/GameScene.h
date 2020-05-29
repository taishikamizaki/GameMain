#pragma once
#include "BaseScene.h"

// ゲームシーンクラス
class GameScene :
	public BaseScene		// 親クラス
{
public:
	bool InitScene(void);
	bool GameInit(void);			// 初期化
	bool Game(void);				// 元ｼｰﾝ
	void GameDraw(void);			// 描画

private:


};

