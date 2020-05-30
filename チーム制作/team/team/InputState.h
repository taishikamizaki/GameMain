#pragma once
#include "keyID.h"
#include <map>


using KeyPir = std::pair<bool, bool>;							//キーNEWとOLD
using KeyMap = std::map<KEY_ID, KeyPir>;		//種類,｛NEW、OLD｝

class InputState
{
public:
	InputState();
	virtual ~InputState();

	virtual void Update(void)=0;
	bool state(KEY_ID id,bool kf);				//キーデータをセット
	void SetOld(void);
	const KeyPir state(KEY_ID id)const;
private:
	KeyMap _state;														//キーデータを入れるやつ。

};

