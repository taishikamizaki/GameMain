#pragma once
#include<string>
#include "BaseScene.h"
#include "../Player/player.h"
#include "../Stage/Stage.h"

// �Z���N�g�N���X
class SelectScene :
	public BaseScene
{
public:
	SelectScene();			// �R���X�g���N�^
	~SelectScene();			// �f�X�g���N�^

	ScnBase update(ScnBase scnID) override;

	void SelectInit(void);
	void SelectDraw(void);
private:
	std::map<std::string, int> images;

	bool selEnd;
};

