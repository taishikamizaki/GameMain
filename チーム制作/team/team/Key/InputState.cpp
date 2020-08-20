#include "KeyID.h"
#include "InputState.h"


InputState::InputState()
{
	for (auto key : KEY_ID())
	{
		_state.try_emplace(key, KeyPir{0,1});
	}
}

InputState::~InputState()
{

}



bool InputState::state(KEY_ID id, bool kf)
{
	if (_state.find(id) != _state.end())
	{
		_state[id].first = kf;
		return true;
	}
	return false;
}

void InputState::SetOld(void)
{
	for (auto key : KEY_ID::KEY_ID_MAX)
	{
		try
		{
			_state[key].second = _state[key].first;
		}
		catch (const std::exception&)
		{
			_state.emplace(key, KeyPir{ 0,1 });
		}
	}
}

const KeyPir InputState::state(KEY_ID id) const
{
	{
		static KeyPir defDate = { 0,0 };

		try
		{
			return	_state.at(id);
		}
		catch (...)
		{
			return defDate;
		}
	}
}

