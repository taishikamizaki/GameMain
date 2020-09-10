
#include <DxLib.h>
#include "key/GetKeyState.h"
#include "player/player.h"
#include "stage/Stage.h"
#include "select.h"

int Select::Init()
{
	p1Image = LoadGraph("image/select/1P.png", true);
	p2Image = LoadGraph("image/select/2P.png", true);

	p1_waku = LoadGraph("image/1p_waku.png", true);
	p2_waku = LoadGraph("image/2p_waku.png", true);

	LoadDivGraph("image/select/charList.png", 12, 4, 3, 138, 140, pList);

	LoadDivGraph("image/select/yama.png", 2, 1, 2, 100, 60, yamaImage);
	LoadDivGraph("image/select/mati.png", 2, 1, 2, 100, 60, matiImage);
	LoadDivGraph("image/select/tougi.png", 2, 1, 2, 100, 60, tougiImage);

	stage_waku = LoadGraph("image/select/waku.png", true);
	
	stageL[0].pos = { 100,500 };
	stageL[1].pos = { 250,500 };
	stageL[2].pos = { 400,500 };

	p1IF = false;
	p2IF = false;

	p1Flag = false;
	p2Flag = false;

	yamaF = false;
	matiF = false;
	tougiF = false;

	stageF = false;

	selectF = false;

	p1 = 0;
	p2 = 0;

	player1 = CHAR_ID::CHAR_ID_MAX;
	player2 = CHAR_ID::CHAR_ID_MAX;

	return 0;
}

int Select::SelectCtl()
{
	if (!selectF && !stageF)
	{
		if (keyNew[KEY_ID_UP1])
		{
			for (int i = 0; i < 4; i++)
			{
				if (i < 4)
				{
					i = 0;
				}
				this->p1 = i;
				break;
			}
		}
		if (keyNew[KEY_ID_DOWN1])
		{
			for (int i = 4; i > 0; i--)
			{
				if (i > 0)
				{
					i = 4;
				}
				this->p1 = i;
				break;
			}
		}
		if (keyNew[KEY_ID_UP2])
		{
			for (int i = 0; i < 4; i++)
			{
				if (i < 4)
				{
					i = 0;
				}
				this->p2 = i;
				break;
			}
		}
		if (keyNew[KEY_ID_DOWN2])
		{
			for (int i = 4; i > 0; i--)
			{
				if (i > 0)
				{
					i = 4;
				}
				this->p2 = i;
				break;
			}
		}
		if (keyNew[KEY_ID_1SKILL1])
		{
			p1IF = true;
		}
		if (keyNew[KEY_ID_2SKILL1])
		{
			p2IF = true;
		}
		if (keyNew[KEY_ID_1SKILL2])
		{
			p1IF = false;
		}
		if (keyNew[KEY_ID_2SKILL2])
		{
			p2IF = false;
		}
	}
	else if (!select && stageF)
	{
		if (p1Flag && p2Flag)
		{
			if (keyNew[KEY_ID_RIGHT1])
			{

			}
			if (keyNew[KEY_ID_LEFT1])
			{

			}
			if (keyNew[KEY_ID_1SKILL1])
			{

			}
			if (keyNew[KEY_ID_1SKILL2])
			{

			}

		}
	}

	if (p1Flag && p2Flag && stageF)
	{
		selectF = true;
	}
	else
	{
		selectF = false;
	}

	return 0;
}

void Select::Draw()
{
	DrawGraph(0, 0, p1Image, true);
	DrawGraph(878, 0, p2Image, true);

	if (!p1IF)
	{
		DrawGraph(90, 190, p1_waku, true);
	}
	else
	{

	}
	if (!p1IF)
	{
		DrawGraph(690, 190, p2_waku, true);
	}
	else
	{

	}
	if (!p1IF)
	{
		DrawGraph(100, 200, pList[p1], true);
	}
	else
	{
		DrawGraph(100, 200, pList[p1 + 4], true);
	}
	if (!p2IF)
	{
		DrawGraph(700, 200, pList[p2], true);
	}
	else
	{
		DrawGraph(700, 200, pList[p2 + 4], true);
	}
	
	if (p1IF && p2IF && !stageF)
	{
		DrawGraph(stageL[0].pos.x, stageL[0].pos.y, yamaImage[0], true);
		DrawGraph(stageL[1].pos.x, stageL[1].pos.y, matiImage[0], true);
		DrawGraph(stageL[2].pos.x, stageL[2].pos.y, tougiImage[0], true);
	}
	else
	{
		if (yamaF)
		{
			DrawGraph(stageL[0].pos.x, stageL[0].pos.y, yamaImage[1], true);
		}
		if (matiF)
		{
			DrawGraph(stageL[1].pos.x, stageL[1].pos.y, matiImage[1], true);
		}
		if (tougiF)
		{
			DrawGraph(stageL[2].pos.x, stageL[2].pos.y, tougiImage[1], true);
		}
	}

}

Select::Select()
{
	Init();
}

Select::~Select()
{

}

