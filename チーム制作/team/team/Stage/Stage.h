#pragma once
#include"../Vector2/Vector2.h"

#define MAP_X 20
#define MAP_Y 12
#define CHIP_SIZE_X 50
#define CHIP_SIZE_Y 50

#define lpStage Stage::GetInstance()
 enum STAGE_ID
{
	STAGE_ID_YAMA,
	STAGE_ID_MACHI,
	STAGE_ID_COLOSSEUM,
	STAGE_ID_HAMAGURI,
	STAGE_ID_MAX
};

class Stage
{
public:
	static Stage& GetInstance()
	{
		static Stage s_instance;
		return s_instance;
	}
	Vector2 PosToIndex(Vector2 pos);
	Vector2 IndexToPos(Vector2 index);
	bool IsPass(Vector2 pos);
	int map;
	
	bool StageCtl(void);
	void StageDraw(void);

private:
	bool StageInit(void);
	
	int stageID[STAGE_ID_MAX];
	int hamaroomImage[7];
	int matiImage[43];
	int tougiImage[12];
	int yamaImage[23];
	Vector2 mapSize;


	int maphamaguri[MAP_Y][MAP_X] = {
	{6,0,0,0 ,1,0,0,1 ,0,0,0,0 ,1,0,0,1 ,0,0,0,6,},
	{6,0,0,0 ,1,0,0,1 ,0,0,0,0 ,1,0,0,1 ,0,0,0,6,},
	{6,0,0,0 ,1,0,0,1 ,0,0,0,0 ,1,0,0,1 ,0,0,0,6,},
	{6,0,0,0 ,1,0,0,1 ,0,0,0,0 ,1,0,0,1 ,0,0,0,6,},

	{6,0,0,0 ,1,0,0,1 ,0,0,0,0 ,1,0,0,1 ,0,0,0,6,},
	{6,0,0,0 ,1,0,0,1 ,0,0,0,0 ,1,0,0,1 ,0,0,0,6,},
	{6,0,0,0 ,1,0,0,1 ,0,0,0,0 ,1,0,0,1 ,0,0,0,6,},
	{6,0,0,0 ,1,0,0,1 ,0,0,0,0 ,1,0,0,1 ,0,0,0,6,},

	{6,0,0,0 ,1,0,0,1 ,0,0,0,0 ,1,0,0,1 ,0,0,0,6,},
	{6,0,0,0 ,1,0,0,1 ,0,0,0,0 ,1,0,0,1 ,0,0,0,6,},
	{6,0,0,0 ,1,0,0,1 ,0,0,0,0 ,1,0,0,1 ,0,0,0,6,},
	{6,6,6,6 ,6,6,6,6 ,6,6,6,6 ,6,6,6,6 ,6,6,6,6,},
	};

	int mapyama[MAP_Y][MAP_X] = {
	{0,0,0,0 ,0,0,0,0 ,0,0,0,0 ,0,0,0,0 ,0,0,0,0,},
	{13,14,8,8 ,8,8,8,8 ,11,13,14,8 ,8,13,14,8 ,8,8,8,8,},
	{9,10,8,8 ,8,8,8,9 ,17,10,8,8 ,8,8,8,8 ,13,14,8,8,},
	{5,5,3,8 ,19,4,2,5 ,5,5,3,8 ,8,2,3,4 ,8,8,8,8,},

	{5,5,5,3 ,2,5,5,5 ,5,5,5,3 ,2,5,5,5 ,3,4,4,2,},
	{12,12,12,12 ,12,12,12,12 ,12,12,12,12 ,12,12,12,12 ,12,12,12,12,},
	{16,16,16,16 ,16,16,16,16 ,16,16,16,16 ,16,16,16,16 ,16,16,16,16,},
	{16,16,16,16 ,16,16,16,16 ,20,21,21,22 ,16,16,16,16 ,16,16,16,16,},

	{6,6,6,6 ,6,6,6,6 ,6,6,6,6 ,6,6,6,6 ,6,6,6,6,},
	{7,6,6,6 ,20,22,6,6 ,7,7,7,7 ,6,6,20,22 ,7,7,7,7,},
	{15,15,15,15 ,15,15,15,15 ,15,15,15,15 ,15,15,15,15 ,15,15,15,15,},
	{1,1,1,1 ,1,1,1,1 ,1,1,1,1 ,1,1,1,1 ,1,1,1,1,},
	};

	int mapmati[MAP_Y][MAP_X] = {
	{16,16,16,16 ,16,16,16,16 ,16,16,16,16 ,16,16,16,16 ,16,16,16,16,},
	{19,19,19,19 ,19,19,19,19 ,20,21,19,19 ,19,19,19,19 ,19,19,19,19,},
	{19,20,21,19 ,19,19,19,19 ,19,19,19,19 ,19,20,21,19 ,19,19,23,19,},
	{19,19,19,19 ,19,20,21,19 ,19,19,19,40 ,19,19,19,19 ,19,19,19,19,},

	{19,19,19,19 ,19,19,19,19 ,19,19,40,19 ,19,19,19,19 ,20,21,19,19,},
	{40,19,19,19 ,19,39,19,19 ,19,19,19,40 ,19,20,21,19 ,19,19,39,19,},
	{35,35,35,35 ,35,38,35,35 ,35,36,37,35 ,35,35,35,35 ,35,35,38,35,},
	{12,11,11,13 ,4,3,3,5 ,33,41,42,34 ,12,11,11,13 ,4,3,3,5,},

	{9,9,9,9 ,1,1,1,1 ,17,31,32,17 ,9,9,9,9 ,1,1,1,1,},
	{9,10,15,9 ,1,2,7,1 ,27,28,29,30 ,22,10,15,9 ,1,2,7,1,},
	{9,9,8,9 ,1,1,8,8 ,24,25,25,26 ,22,22,14,9 ,1,1,6,8,},
	{0,0,0,0 ,0,0,0,0 ,0,0,0,0 ,0,0,0,0 ,0,0,0,0,},
	};

	int maptougi[MAP_Y][MAP_X] = {
	{10,4,4,10 ,10,4,4,10 ,10,4,4,10 ,10,4,4,10 ,10,4,4,10,},
	{11,11,11,11 ,11,11,11,11 ,11,11,11,11 ,11,11,11,11 ,11,11,11,11,},
	{3,4,4,9 ,9,4,4,3 ,9,4,4,9 ,3,4,4,9 ,9,4,4,3,},
	{2,4,4,10 ,10,4,4,2 ,10,4,4,10 ,2,4,4,10 ,10,4,4,2,},

	{5,6,6,6 ,6,6,6,5 ,6,6,6,6 ,5,6,6,6 ,6,6,6,5,},
	{5,8,8,8 ,8,8,8,5 ,8,8,8,8 ,5,8,8,8 ,8,8,8,5,},
	{5,8,8,8 ,8,8,8,5 ,8,8,8,8 ,5,8,8,8 ,8,8,8,5,},
	{5,8,8,8 ,8,8,8,5 ,8,8,8,8 ,5,8,8,8 ,8,8,8,5,},

	{1,1,1,1 ,1,1,1,1 ,1,1,1,1 ,1,1,1,1 ,1,1,1,1,},
	{0,0,0,0 ,0,0,0,0 ,0,0,0,0 ,0,0,0,0 ,0,0,0,0,},
	{0,0,0,0 ,0,0,0,0 ,0,0,0,0 ,0,0,0,0 ,0,0,0,0,},
	{7,7,7,7 ,7,7,7,7 ,7,7,7,7 ,7,7,7,7 ,7,7,7,7,},
	};

	Stage();
	~Stage();
};


