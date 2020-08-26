#pragma once
#include "BaseScene.h"

class PlayerMng;

// ゲームシーンクラス
class GameScene :
	public BaseScene		// 親クラス
{
public:
	ScnBase Update(ScnBase scnID) override;
	void GameInit(void);
	void GameDraw(void);
	GameScene();
	GameScene(int charID_1, int ID_1, int charID_2, int ID_2);
	~GameScene();

private:
	PlayerMng* player;

	bool gamEnd;

	int charID_1;
	int ID_1;
	int charID_2;
	int ID_2;
};

