#include <algorithm>
#include <DxLib.h>
#include "KeyState.h"
#include "InputID.h"

KeyState::KeyState()
{
	//初期化
	for (int i = 0; i < sizeof(_buf); i++)
	{
		_buf[0]={ 0 };
	}
	_confId = KEY_ID::KEY_ID_SPACE;

	// キーインプット
	_keyConDef.reserve(static_cast<size_t>(end(KEY_ID())));
	_keyConDef.emplace_back(KEY_INPUT_SPACE);		// シーン遷移用
	_keyConDef.emplace_back(KEY_INPUT_P);					// ポーズ
	_keyConDef.emplace_back(KEY_INPUT_UP);				// ↑
	_keyConDef.emplace_back(KEY_INPUT_RIGHT);		// →
	_keyConDef.emplace_back(KEY_INPUT_DOWN);		// ↓
	_keyConDef.emplace_back(KEY_INPUT_LEFT);			// ←
	_keyConDef.emplace_back(KEY_INPUT_1);					// スキル１
	_keyConDef.emplace_back(KEY_INPUT_2);					// スキル2
	_keyConDef.emplace_back(KEY_INPUT_3);					// スキル３
	_keyConDef.emplace_back(KEY_INPUT_4);					// スキル4（必殺）
	_keyConDef.emplace_back(KEY_INPUT_E);					// 気弾（魔法使い用）
	_keyConDef.emplace_back(KEY_INPUT_J);					// ジャンプ
	_keyConDef.emplace_back(KEY_INPUT_S);					// 何かのセーブ
	_keyConDef.emplace_back(KEY_INPUT_L);					// 何かのロード
	_keyConDef.emplace_back(KEY_INPUT_A);					// 掴み
	_keyConDef.emplace_back(KEY_INPUT_Q);				// 弱
	_keyConDef.emplace_back(KEY_INPUT_W);				// 強

	FILE *fileptr =0;

	fopen_s(&fileptr, "data/key.dat","rb");

	//キー設定
	if (fileptr == NULL)
	{
		_keyCon = _keyConDef;

		fopen_s(&fileptr, "data/key.dat", "wb");

		if (fileptr != NULL)
		{
			fwrite(_keyCon.data(), sizeof(_keyCon[0]), _keyCon.size(), fileptr);
			fclose(fileptr);
		}
	}
	else
	{	
		_keyCon.resize(static_cast<int>(end(KEY_ID())));
		fread(_keyCon.data(), sizeof(_keyCon[0]), _keyCon.size(), fileptr);
		fclose(fileptr);
	}

	func = &KeyState::RefKeyData;

	modekeyOld = true;
}

KeyState::~KeyState()
{
	
}

void KeyState::Update(void)
{
	SetOld();
	modekeyOld = _buf[KEY_INPUT_F1];
	GetHitKeyStateAll(_buf);
	if (func != nullptr)
	{
		(this->*func)();
	}
}

void KeyState::RefKeyData(void)
{
	for (auto id : KEY_ID())
	{
		
	}

	if (_buf[KEY_INPUT_F1]&&!modekeyOld)
	{
		func = &KeyState::SetKeyConfig;
		for (auto id : KEY_ID())
		{
			InputState::state(id, 0);
		}
	}
}

void KeyState::SetKeyConfig(void)
{
	if (_buf[KEY_INPUT_F1] && !modekeyOld)
	{
		func = &KeyState::RefKeyData;
		FILE* fileptr = 0;
		fopen_s(&fileptr, "data/key.dat", "r");
		if (fileptr != NULL)
		{
			fread(_keyCon.data(), sizeof(_keyCon[0]), _keyCon.size(), fileptr);
			fclose(fileptr);
		}
		return;
	}

	auto checkkey = [&](int id)
	{
		for (auto cid = KEY_ID::KEY_ID_SPACE; cid < _confId; ++cid)
		{
			if (_keyCon[static_cast<int>(cid)] == id)
			{
				return false;
			}
		}
		return true;
	};

	for (int id = 0; id < sizeof(_buf); id++)
	{
		if (!checkkey(id))
		{
			continue;
		}
		if (_buf[id] &&( !_buf[KEY_INPUT_F1]))
		{
			_keyCon[static_cast<int>(_confId)] = id;
			++_confId;
			
			if (_confId==end(_confId))
			{
				FILE* fileptr;

				fopen_s(&fileptr, "data/key.dat", "wb");

				if (fileptr != NULL)
				{
					fwrite(_keyCon.data(), sizeof(_keyCon[0]), _keyCon.size(), fileptr);
					fclose(fileptr);
				}

				func = &KeyState::RefKeyData;
			
				break;
			}
		}
	}
	return;
}
