#pragma once
enum STAGE_ID
{
	STAGE_ID_YAMA,
	STAGE_ID_MACHI,
	STAGE_ID_COLOSSEUM,
	STAGE_ID_MAX,
};

bool StageInit(void);
bool StageScene(void);
void StageDraw(void);
