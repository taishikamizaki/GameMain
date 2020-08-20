#pragma once
#include<string>
#include "BaseScene.h"
#include "../Player/player.h"
#include "../Stage/Stage.h"

// セレクトクラス
class SelectScene :
	public BaseScene
{
public:
	SelectScene();			// コンストラクタ
	~SelectScene();			// デストラクタ

	ScnBase update(ScnBase scnID) override;

	void SelectInit(void);
	void SelectDraw(void);
private:

	bool selEnd;
};

