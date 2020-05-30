#include <algorithm>
#include <DxLib.h>
#include "KeyState.h"
#include "InputID.h"

KeyState::KeyState()
{
	//������
	for (int i = 0; i < sizeof(_buf); i++)
	{
		_buf[0]={ 0 };
	}
	_confId = KEY_ID::KEY_ID_SPACE;

	// �L�[�C���v�b�g
	_keyConDef.reserve(static_cast<size_t>(end(KEY_ID())));
	_keyConDef.emplace_back(KEY_INPUT_SPACE);		// �V�[���J�ڗp
	_keyConDef.emplace_back(KEY_INPUT_P);					// �|�[�Y
	_keyConDef.emplace_back(KEY_INPUT_UP);				// ��
	_keyConDef.emplace_back(KEY_INPUT_RIGHT);		// ��
	_keyConDef.emplace_back(KEY_INPUT_DOWN);		// ��
	_keyConDef.emplace_back(KEY_INPUT_LEFT);			// ��
	_keyConDef.emplace_back(KEY_INPUT_1);					// �X�L���P
	_keyConDef.emplace_back(KEY_INPUT_2);					// �X�L��2
	_keyConDef.emplace_back(KEY_INPUT_3);					// �X�L���R
	_keyConDef.emplace_back(KEY_INPUT_4);					// �X�L��4�i�K�E�j
	_keyConDef.emplace_back(KEY_INPUT_E);					// �C�e�i���@�g���p�j
	_keyConDef.emplace_back(KEY_INPUT_J);					// �W�����v
	_keyConDef.emplace_back(KEY_INPUT_S);					// �����̃Z�[�u
	_keyConDef.emplace_back(KEY_INPUT_L);					// �����̃��[�h
	_keyConDef.emplace_back(KEY_INPUT_A);					// �͂�
	_keyConDef.emplace_back(KEY_INPUT_Q);				// ��
	_keyConDef.emplace_back(KEY_INPUT_W);				// ��

	FILE *fileptr =0;

	fopen_s(&fileptr, "data/key.dat","rb");

	//�L�[�ݒ�
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
