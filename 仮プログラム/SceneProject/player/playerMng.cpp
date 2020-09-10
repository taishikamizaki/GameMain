#include <DxLib.h>
#include "player.h"
#include "playerMng.h"

int PlayerMng::Init()
{
	if (player == nullptr)
	{
		//player = new Player(charID_1, pID_1, charID_2, pID_2);
		if (player != nullptr) player->SetPlayerID({ 10,0 }, { 60,0 });
	}
	return 0;
}

void PlayerMng::Render()
{
	if (player != nullptr) player->PlayerDraw();
}

void PlayerMng::Update()
{
	//if (player != nullptr) player->PlayerCtl();
}

PlayerMng::PlayerMng(int charID_1, int ID_1, int charID_2, int ID_2)
{
	this->charID_1 = charID_1;
	this->charID_2 = charID_2;

	this->pID_1 = ID_1;
	this->pID_2 = ID_2;

	Init();
}

PlayerMng::~PlayerMng()
{
	if (player != nullptr)
	{
		delete player;
		player = nullptr;
	}
}
