#pragma once
#include "BaseScene.h"

// セレクトクラス
class SelectScene :
	public BaseScene
{
public:
	SelectScene();			// コンストラクタ
	~SelectScene();			// デストラクタ

	ScnBase update(ScnBase scnID) override;
private:
	
};

