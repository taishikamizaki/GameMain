#pragma once
#include <vector>
#include "InputState.h"

class KeyState :
	public InputState
{
public:
	KeyState();
	~KeyState();

	void Update(void) override;	

private:
	void RefKeyData(void);
	void SetKeyConfig(void);
	void (KeyState::*func)(void);

	char _buf[256];									//全キーデータ格納
	std::vector<int> _keyCon;			//操作用のキーを格納
	std::vector<int> _keyConDef;	//既定の操作キーを格納
	int modekeyOld;								//f11

	KEY_ID _confId;
};

