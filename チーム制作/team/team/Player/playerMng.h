#pragma once
class playerMng
{
public:

	playerMng(int charID_1,int ID_1,int charID_2,int ID_2);
	~playerMng();

private:
	int charID_1;
	int charID_2;
	
	int pID_1;
	int pID_2;

	int Init();

};

