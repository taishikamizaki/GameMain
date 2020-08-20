#pragma once

class Player;
class playerMng
{
public:

	playerMng(int charID_1,int ID_1,int charID_2,int ID_2);
	~playerMng();

private:
	Player* player = nullptr;

	int charID_1;
	int charID_2;
	
	int pID_1;
	int pID_2;

	int Init();

};

