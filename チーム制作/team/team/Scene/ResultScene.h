#pragma once
#include "BaseScene.h"
class ResultScene :
    public BaseScene
{
	public:
	ScnBase Update(ScnBase scnID) override;
	ResultScene();
	~ResultScene();

private:
	bool resEnd;
};
