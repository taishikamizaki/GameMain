#include "DxLib.h"
#include "main.h"
#include "Stage.h"

int stageID[STAGE_ID_MAX];
int hamaroomImage[7];
int matiImage[43];
int tougiImage[12];
int yamaImage[23];
Pos mapSize;
int map;

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

// 初期化
bool StageInit(void)
{
	bool rtnFlag = true;

	LoadDivGraph("image/stage/hamaguriroom.png",7,7,1
		,CHIP_SIZE_X,CHIP_SIZE_Y
		,hamaroomImage,false);

	LoadDivGraph("image/stage/mati.png", 43, 43, 1
		, CHIP_SIZE_X, CHIP_SIZE_Y
		, matiImage, false);

	LoadDivGraph("image/stage/tougizyou.png", 12, 12, 1
		, CHIP_SIZE_X, CHIP_SIZE_Y
		, tougiImage, false);

	LoadDivGraph("image/stage/yama.png", 23, 23, 1
		, CHIP_SIZE_X, CHIP_SIZE_Y
		, yamaImage, false);

	map =  STAGE_ID_YAMA;

	mapSize.x = MAP_X;
	mapSize.y = MAP_Y;

	return rtnFlag;
}

// ｽﾃｰｼﾞｼｰﾝ
bool StageScene(void)
{
	bool rtnFlag = true;

	switch (map)
	{
	case STAGE_ID_YAMA:
		for (int y = 0; y < mapSize.y; y++)
		{
			for (int x = 0; x < mapSize.x; x++)
			{
				yamaImage[mapyama[y][x]];
			}
		}
		break;
	case STAGE_ID_MACHI:
		for (int y = 0; y < mapSize.y; y++)
		{
			for (int x = 0; x < mapSize.x; x++)
			{
				matiImage[mapmati[y][x]];
			}
		}
		break;
	case STAGE_ID_COLOSSEUM:
		for (int y = 0; y < mapSize.y; y++)
		{
			for (int x = 0; x < mapSize.x; x++)
			{
				tougiImage[maptougi[y][x]];
			}
		}
		break;
	case STAGE_ID_HAMAGURI:
		for (int y = 0; y < mapSize.y; y++)
		{
			for (int x = 0; x < mapSize.x; x++)
			{
				hamaroomImage[maphamaguri[y][x]];
			}
		}
		break;
	default:
		break;
	}

	return rtnFlag;
}

// 描画
void StageDraw(void)
{
	for (int y = 0; y< mapSize.y;y++)
	{
		for (int x = 0; x < mapSize.x;x++)
		{
			DrawGraph(x*CHIP_SIZE_X, y*CHIP_SIZE_Y, yamaImage[mapyama[y][x]],true);
		}
	}
	/*DrawGraph(SCREEN_SIZE_X, SCREEN_SIZE_Y, stageID[STAGE_ID_MAX], true);*/
	
}

// ﾋﾟｸｾﾙの座標をﾏｯﾌﾟ配列の座標に変換する
Pos PosToIndex(Pos pos)
{
	Pos index;
	index.x = pos.x / CHIP_SIZE_X;
	index.y = pos.y / CHIP_SIZE_Y;
	return index;
}

// ﾏｯﾌﾟ配列の座標をﾋﾟｸｾﾙの座標(左上)に変換する
Pos IndexToPos(Pos index)
{
	Pos pos;
	pos.x = index.x*CHIP_SIZE_X;
	pos.y = index.y*CHIP_SIZE_Y;
	return pos;
}

// 指定された座標が通過可能かを判断する(true:通ってよい)
bool IsPass(Pos pos)
{
	Pos index;
	index = PosToIndex(pos);

	// ハマグリ
	/*switch (maphamaguri[index.y][index.x])
	{
	case 0:
		return	true;
		break;
	case 1:
		return	true;
		break;
	case 2:
		return false;
		break;
	case 3:
		return false;
		break;
	case 6:
		return false;
		break;
	default:
		break;
	}*/

	// 山
	switch (mapyama[index.y][index.x])
	{
	case 1:
	case 20:
	case 21:
	case 22:
		return false;
		break;
	default:
		break;
	}

	//// 街
	//switch (mapmati[index.y][index.x])
	//{
	//case 0:
	//case 8:
	//case 22:
	//case 23:
	//	return false;
	//	break;
	//default:
	//	break;
	//}

	//// 闘技場
	//switch (maptougi[index.y][index.x])
	//{
	//case 7:
	//	return false;
	//	break;
	//default:
	//	break;
	//}
	//

	return true;
}