#pragma once

class Player;
class PlayerMng
{
public:

	void Render();
	void Update();

	PlayerMng(int charID_1,int ID_1,int charID_2,int ID_2);
	~PlayerMng();
	Player* player;

private:
	int charID_1;
	int charID_2;
	
	int pID_1;
	int pID_2;

	int Init();

};

