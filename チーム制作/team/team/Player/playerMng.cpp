#include <DxLib.h>
#include "playerMng.h"

int playerMng::Init()
{

	return 0;
}

playerMng::playerMng(int charID_1, int ID_1, int charID_2, int ID_2)
{
	this->charID_1 = charID_1;
	this->charID_2 = charID_2;

	this->pID_1 = ID_1;
	this->pID_2 = ID_2;

	Init();
}

playerMng::~playerMng()
{

}
