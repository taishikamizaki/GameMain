#include "DxLib.h"
#include "main.h"
#include "Stage.h"

int stageID[STAGE_ID_MAX];
int hamaroomImage[7];
Pos mapSize;
int maphamaguri[MAP_Y][MAP_X] = {
{2,0,0,0 ,1,0,0,1 ,0,0,0,0 ,1,0,0,1 ,0,0,0,3,},
{2,0,0,0 ,1,0,0,1 ,0,0,0,0 ,1,0,0,1 ,0,0,0,3,},
{2,0,0,0 ,1,0,0,1 ,0,0,0,0 ,1,0,0,1 ,0,0,0,3,},
{2,0,0,0 ,1,0,0,1 ,0,0,0,0 ,1,0,0,1 ,0,0,0,3,},

{2,0,0,0 ,1,0,0,1 ,0,0,0,0 ,1,0,0,1 ,0,0,0,3,},
{2,0,0,0 ,1,0,0,1 ,0,0,0,0 ,1,0,0,1 ,0,0,0,3,},
{2,0,0,0 ,1,0,0,1 ,0,0,0,0 ,1,0,0,1 ,0,0,0,3,},
{2,0,0,0 ,1,0,0,1 ,0,0,0,0 ,1,0,0,1 ,0,0,0,3,},

{2,0,0,0 ,1,0,0,1 ,0,0,0,0 ,1,0,0,1 ,0,0,0,3,},
{2,0,0,0 ,1,0,0,1 ,0,0,0,0 ,1,0,0,1 ,0,0,0,3,},
{2,0,0,0 ,1,0,0,1 ,0,0,0,0 ,1,0,0,1 ,0,0,0,3,},
{6,6,6,6 ,6,6,6,6 ,6,6,6,6 ,6,6,6,6 ,6,6,6,6,},
};
bool StageInit(void)
{
	bool rtnFlag = true;
	LoadDivGraph("image/stage/hamaguriroom.png",7,7,1
		,CHIP_SIZE_X,CHIP_SIZE_Y
		,hamaroomImage,false);

	mapSize.x = MAP_X;
	mapSize.y = MAP_Y;
	return rtnFlag;
}

bool StageScene(void)
{
	bool rtnFlag = true;



	return rtnFlag;
}

void StageDraw(void)
{
	for (int y = 0; y< mapSize.y;y++)
	{
		for (int x = 0; x < mapSize.x;x++)
		{
			DrawGraph(x*CHIP_SIZE_X, y*CHIP_SIZE_Y, hamaroomImage[maphamaguri[y][x]],true);
		}
	}
	DrawGraph(SCREEN_SIZE_X, SCREEN_SIZE_Y, stageID[STAGE_ID_MAX], true);		// �z��̈���݂����ȓz�ŉ񂵂Ă���
	
}
// �߸�ق̍��W��ϯ�ߔz��̍��W�ɕϊ�����
Pos PosToIndex(Pos pos)
{
	Pos index;
	index.x = pos.x / CHIP_SIZE_X;
	index.y = pos.y / CHIP_SIZE_Y;
	return index;
}
// ϯ�ߔz��̍��W���߸�ق̍��W(����)�ɕϊ�����
Pos IndexToPos(Pos index)
{
	Pos pos;
	pos.x = index.x*CHIP_SIZE_X;
	pos.y = index.y*CHIP_SIZE_Y;
	return pos;
}
// �w�肳�ꂽ���W���ʉ߉\���𔻒f����(true:�ʂ��Ă悢)
bool IsPass(Pos pos)
{
	Pos index;
	index = PosToIndex(pos);
	switch (maphamaguri[index.y][index.x])
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
	}
}