#pragma once

#include <memory>

// プロトタイプ宣言
class BaseScene;

using ScnBase = std::unique_ptr<BaseScene>;

class BaseScene
{

public:
	BaseScene();				// コンストラクタ
	virtual ~BaseScene();		// デストラクタ

	virtual ScnBase Update(ScnBase scnID) = 0;			// 純粋な仮想関数

private:

};
