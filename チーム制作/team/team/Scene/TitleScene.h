#pragma once
#include "BaseScene.h"
// タイトルクラス
class TitleScene :
	public BaseScene		// 親クラス
{
public:
	TitleScene();
	~TitleScene();

	ScnBase update(ScnBase scnID) override;

private:

	int titleLogoImage;		// タイトルロゴ
	int titleMesImage;		// タイトルメッセージ

	bool titleEnd;

};

