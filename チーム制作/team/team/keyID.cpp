#include <type_traits>
#include "keyID.h"

KEY_ID begin(KEY_ID)
{
	return KEY_ID::KEY_ID_SPACE;
}

KEY_ID end(KEY_ID)
{
	return KEY_ID::KEY_ID_MAX;
}

KEY_ID operator*(KEY_ID key)
{
	return key;
}

KEY_ID operator++(KEY_ID & key)
{
	return key = static_cast<KEY_ID>(std::underlying_type<KEY_ID>::type(key) + 1);
}

