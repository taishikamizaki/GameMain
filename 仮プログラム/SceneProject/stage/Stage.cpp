#include "DxLib.h"
#include "Stage.h"

// ������
bool Stage::StageInit(void)
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

	map =  STAGE_ID::STAGE_ID_YAMA;

	mapSize.x = MAP_X;
	mapSize.y = MAP_Y;

	return rtnFlag;
}

// �ð�޼��
bool Stage::StageCtl(void)
{
	bool rtnFlag = true;

	switch (map)
	{
	case STAGE_ID::STAGE_ID_YAMA:
		for (int y = 0; y < mapSize.y; y++)
		{
			for (int x = 0; x < mapSize.x; x++)
			{
				yamaImage[mapyama[y][x]];
			}
		}
		break;
	case STAGE_ID::STAGE_ID_MACHI:
		for (int y = 0; y < mapSize.y; y++)
		{
			for (int x = 0; x < mapSize.x; x++)
			{
				matiImage[mapmati[y][x]];
			}
		}
		break;
	case STAGE_ID::STAGE_ID_COLOSSEUM:
		for (int y = 0; y < mapSize.y; y++)
		{
			for (int x = 0; x < mapSize.x; x++)
			{
				tougiImage[maptougi[y][x]];
			}
		}
		break;
	case STAGE_ID::STAGE_ID_HAMAGURI:
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

// �`��
void Stage::StageDraw(void)
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

// �߸�ق̍��W��ϯ�ߔz��̍��W�ɕϊ�����
Vector2 Stage::PosToIndex(Vector2 pos)
{
	Vector2 index;
	index.x = pos.x / CHIP_SIZE_X;
	index.y = pos.y / CHIP_SIZE_Y;
	return index;
}

// ϯ�ߔz��̍��W���߸�ق̍��W(����)�ɕϊ�����
Vector2 Stage::IndexToPos(Vector2 index)
{
	Vector2 pos;
	pos.x = index.x*CHIP_SIZE_X;
	pos.y = index.y*CHIP_SIZE_Y;
	return pos;
}

// �w�肳�ꂽ���W���ʉ߉\���𔻒f����(true:�ʂ��Ă悢)
bool Stage::IsPass(Vector2 pos)
{
	Vector2 index;
	index = PosToIndex(pos);

	// �n�}�O��
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

	// �R
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

	//// �X
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

	//// ���Z��
	//switch (maptougi[index.y][index.x])
	//{
	//case 7:
	//	return false;
	//	break;
	//default:
	//	break;
	//}
	

	return true;
}

Stage::Stage()
{
	StageInit();
}
Stage::~Stage()
{

}