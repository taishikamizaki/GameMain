#include "DxLib.h"
#include "main.h"
#include "Stage.h"

int stageID[STAGE_ID_MAX];

bool StageInit(void)
{
	bool rtnFlag = true;

	return rtnFlag;
}

bool StageScene(void)
{
	bool rtnFlag = true;



	return rtnFlag;
}

void StageDraw(void)
{
	DrawGraph(SCREEN_SIZE_X, SCREEN_SIZE_Y, stageID[STAGE_ID_MAX], true);		// ”z—ñ‚ÌˆŸŽí‚Ý‚½‚¢‚È“z‚Å‰ñ‚µ‚Ä‚­‚ê
}