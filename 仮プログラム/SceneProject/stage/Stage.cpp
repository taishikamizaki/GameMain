#include "DxLib.h"
#include "Stage.h"

// 初期化
bool Stage::StageInit(void)
{
	bool rtnFlag = true;

	LoadDivGraph("image/stage/mati.png", 43, 43, 1
		, CHIP_SIZE_X, CHIP_SIZE_Y
		, matiImage, false);

	LoadDivGraph("image/stage/tougizyou.png", 12, 12, 1
		, CHIP_SIZE_X, CHIP_SIZE_Y
		, tougiImage, false);

	LoadDivGraph("image/stage/yama.png", 23, 23, 1
		, CHIP_SIZE_X, CHIP_SIZE_Y
		, yamaImage, false);

	mapID =  STAGE_ID::STAGE_ID_MAX;

	mapSize.x = MAP_X;
	mapSize.y = MAP_Y;

	yamaF = false;
	matiF = false;
	tougiF = false;

	SetVolumeMusic(10);
	SoundGameInit();
	return rtnFlag;
}

// ｽﾃｰｼﾞｼｰﾝ
bool Stage::StageCtl(STAGE_ID stage)
{
	bool rtnFlag = true;

	mapID = stage;

	switch (mapID)
	{
	case STAGE_ID::STAGE_ID_YAMA:
		for (int y = 0; y < mapSize.y; y++)
		{
			for (int x = 0; x < mapSize.x; x++)
			{
				yamaImage[mapyama[y][x]];
			}
		}
		yamaF = true;
		break;
	case STAGE_ID::STAGE_ID_MACHI:
		for (int y = 0; y < mapSize.y; y++)
		{
			for (int x = 0; x < mapSize.x; x++)
			{
				
				matiImage[mapmati[y][x]];
			}
		}
		matiF = true;
		break;
	case STAGE_ID::STAGE_ID_COLOSSEUM:
		for (int y = 0; y < mapSize.y; y++)
		{
			for (int x = 0; x < mapSize.x; x++)
			{
				tougiImage[maptougi[y][x]];
			}
		}
		tougiF = true;
		break;
	case STAGE_ID::STAGE_ID_HAMAGURI:
		
		break;
	default:
		break;
	}

	return rtnFlag;
}
void Stage::SoundGameInit(void)
{
	switch (mapID)
	{
	case STAGE_ID::STAGE_ID_YAMA:
		SetVolumeMusic(10);
		PlayMusic("sound/yama.mp3", DX_PLAYTYPE_LOOP);
		break;
	case STAGE_ID::STAGE_ID_MACHI:
		SetVolumeMusic(10);
		PlayMusic("sound/mati.mp3", DX_PLAYTYPE_LOOP);
		break;
	case STAGE_ID::STAGE_ID_COLOSSEUM:

		PlayMusic("sound/tougizyou.mp3", DX_PLAYTYPE_LOOP);
		break;
	default:
		break;
	}
	if (mapID == STAGE_ID::STAGE_ID_YAMA)
	{
		SetVolumeMusic(80);
	}
	if (mapID == STAGE_ID::STAGE_ID_MACHI)
	{
		SetVolumeMusic(100);
	}
	if (mapID == STAGE_ID::STAGE_ID_COLOSSEUM)
	{
		SetVolumeMusic(100);
	}
}

// 描画
void Stage::StageDraw(STAGE_ID id)
{
	if (id == STAGE_ID::STAGE_ID_YAMA)
	{
		for (int y = 0; y < mapSize.y; y++)
		{
			for (int x = 0; x < mapSize.x; x++)
			{
				DrawGraph(x * CHIP_SIZE_X, y * CHIP_SIZE_Y, yamaImage[mapyama[y][x]], true);
			}
		}
	}
	else if (id == STAGE_ID::STAGE_ID_MACHI)
	{
		for (int y = 0; y < mapSize.y; y++)
		{
			for (int x = 0; x < mapSize.x; x++)
			{
				DrawGraph(x * CHIP_SIZE_X, y * CHIP_SIZE_Y, matiImage[mapmati[y][x]], true);
			}
		}
	}
	else if (id == STAGE_ID::STAGE_ID_COLOSSEUM)
	{
		for (int y = 0; y < mapSize.y; y++)
		{
			for (int x = 0; x < mapSize.x; x++)
			{
				DrawGraph(x * CHIP_SIZE_X, y * CHIP_SIZE_Y, tougiImage[maptougi[y][x]], true);
			}
		}
	}
	else if (id == STAGE_ID::STAGE_ID_MAX)
	{

	}
}

// ﾋﾟｸｾﾙの座標をﾏｯﾌﾟ配列の座標に変換する
Vector2 Stage::PosToIndex(Vector2 pos)
{
	Vector2 index;
	index.x = pos.x / CHIP_SIZE_X;
	index.y = pos.y / CHIP_SIZE_Y;
	return index;
}

// ﾏｯﾌﾟ配列の座標をﾋﾟｸｾﾙの座標(左上)に変換する
Vector2 Stage::IndexToPos(Vector2 index)
{
	Vector2 pos;
	pos.x = index.x*CHIP_SIZE_X;
	pos.y = index.y*CHIP_SIZE_Y;
	return pos;
}

bool Stage::IsPassM(Vector2 pos)
{
	Vector2 index;
	index = PosToIndex(pos);
	// 街
	switch (mapmati[index.y][index.x])
	{
	case 0:
	case 8:
	case 22:
	case 23:
		return false;
		break;
	default:
		break;
	}
	return true;
}

bool Stage::IsPassT(Vector2 pos)
{
	Vector2 index;
	index = PosToIndex(pos);
	// 闘技場
	switch (maptougi[index.y][index.x])
	{
	case 7:
		return false;
		break;
	default:
		break;
	}
	return true;
}

// 指定された座標が通過可能かを判断する(true:通ってよい)
bool Stage::IsPassY(Vector2 pos)
{
	Vector2 index;
	index = PosToIndex(pos);
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
	return true;
}

Stage::Stage()
{
	StageInit();
}
Stage::~Stage()
{

}