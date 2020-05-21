#pragma once
enum STAGE_ID
{
	STAGE_ID_YAMA,
	STAGE_ID_MACHI,
	STAGE_ID_COLOSSEUM,
	STAGE_ID_MAX,
};

#define MAP_X 20
#define MAP_Y 12
#define CHIP_SIZE_X 50
#define CHIP_SIZE_Y 50

bool StageInit(void);
bool StageScene(void);
void StageDraw(void);
Pos PosToIndex(Pos pos);
Pos IndexToPos(Pos index);
bool IsPass(Pos pos);
