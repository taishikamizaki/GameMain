
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

	LoadDivGraph("image/select/charSele.png", 12, 4, 3, 138, 140, pList);

	LoadDivGraph("image/select/yama.png", 2, 1, 2, 100, 60, yamaImage);
	LoadDivGraph("image/select/mati.png", 2, 1, 2, 100, 60, matiImage);
	LoadDivGraph("image/select/tougi.png", 2, 1, 2, 100, 60, tougiImage);

	stage_waku = LoadGraph("image/select/waku.png", true);
	
	stageL[0].pos = { 100,500 };
	stageL[1].pos = { 250,500 };
	stageL[2].pos = { 400,500 };

	stageL[0].waku_pos = {90, 490};
	stageL[1].waku_pos =  {240, 490};
	stageL[2].waku_pos =  {390, 490};

	waku = 0;

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

	stageID = STAGE_ID::STAGE_ID_MAX;

	player1 = CHAR_ID::CHAR_ID_MAX;
	player2 = CHAR_ID::CHAR_ID_MAX;

	return 0;
}

int Select::SelectCtl()
{
	// �v���C���[�I�𔻒�
	if (!selectF && !stageF)
	{
		// 1p��
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
		// 1p��
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
		// 2p��
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
		// 2p��
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
		// 1p����
		if (keyNew[KEY_ID_1SKILL1])
		{
			// ID��������
			if (p1 != p2)
			{
				p1IF = true;
			}
		}
		// 1p�L�����Z��
		if (keyNew[KEY_ID_1SKILL2])
		{
			p1IF = true;
		}
		// 2p����
		if (keyNew[KEY_ID_2SKILL1])
		{
			// ID��������
			if (p2 != p1)
			{
				p2IF = true;
			}
		}
		// 2p�L�����Z��
		if (keyNew[KEY_ID_2SKILL2])
		{
			p2IF = false;
		}
	}
	// �X�e�[�W�I�𔻒�
	else if (!selectF && stageF)
	{
		if (p1Flag && p2Flag)
		{
			// �g��
			if (keyNew[KEY_ID_RIGHT1])
			{
				waku++;
				if (waku > 3)
				{
					waku = 0;
				}
			}
			// �g��
			if (keyNew[KEY_ID_LEFT1])
			{
				waku--;
				if (waku < 0)
				{
					waku = 3;
				}
			}
			// ����i�摜�؂�ւ��j
			if (keyNew[KEY_ID_1SKILL1])
			{
				stageIF = true;
				if (waku == 0)
				{
					yamaF = true;
					matiF = false;
					tougiF = false;
				}
				else if (waku == 1)
				{
					yamaF = false;
					matiF = true;
					tougiF = false;
				}
				else if (waku == 3)
				{
					yamaF = false;
					matiF = false;
					tougiF = true;
				}
			}
			// �L�����Z���i�؂�ւ��j
			if (keyNew[KEY_ID_1SKILL2])
			{
				stageIF = false;
				yamaF = false;
				matiF = false;
				tougiF = false;
			}
			// �ŏI�m�F
			if (p1Flag && p2Flag && stageIF)
			{
				stageF = true;
			}
			else
			{
				stageF = false;
			}
		}
	}
	// �ŏI�m�F����
	if (p1Flag && p2Flag && stageF)
	{
		selectF = true;
	}
	else
	{
		selectF = false;
	}

	// �v���C���[�P��ID���
	if (p1IF)
	{
		if (p1 == 0)
		{
			player1 = CHAR_ID::CHAR_ID_KISI;
		}
		if (p1 == 1)
		{
			player1 = CHAR_ID::CHAR_ID_MDOU;
		}
		if (p1 == 2)
		{
			player1 = CHAR_ID::CHAR_ID_BTOU;
		}
		if (p1 == 3)
		{
			player1 = CHAR_ID::CHAR_ID_4;
		}
	}
	// �v���C���[�Q��ID���
	if (p2IF)
	{
		if (p2 == 0)
		{
			player1 = CHAR_ID::CHAR_ID_KISI;
		}
		if (p2 == 1)
		{
			player1 = CHAR_ID::CHAR_ID_MDOU;
		}
		if (p2 == 2)
		{
			player1 = CHAR_ID::CHAR_ID_BTOU;
		}
		if (p2 == 3)
		{
			player1 = CHAR_ID::CHAR_ID_4;
		}
	}
	// �X�e�[�WID�̑��
	if (stageIF)
	{
		if (waku == 0)
		{
			stageID = STAGE_ID::STAGE_ID_YAMA;
		}
		if (waku == 1)
		{
			stageID = STAGE_ID::STAGE_ID_MACHI;
		}
		if (waku == 2)
		{
			stageID = STAGE_ID::STAGE_ID_COLOSSEUM;
		}
	}

	return 0;
}

void Select::Draw()
{
	// 1p�A�C�R��
	DrawGraph(0, 0, p1Image, true);
	// 2p�A�C�R��
	DrawGraph(878, 0, p2Image, true);

	// �v���C���[�P�g����
	if (!p1IF)
	{
		DrawGraph(90, 190, p1_waku, true);
	}
	else
	{

	}
	// �v���C���[�Q�g����
	if (!p1IF)
	{
		DrawGraph(690, 190, p2_waku, true);
	}
	else
	{

	}
	// �v���C���[�P�L�����؂�ւ�����
	if (!p1IF)
	{
		DrawGraph(100, 200, pList[p1], true);
	}
	else
	{
		DrawGraph(100, 200, pList[p1 + 4], true);
	}
	// �v���C���[�Q�L�����؂�ւ�����
	if (!p2IF)
	{
		DrawGraph(700, 200, pList[p2], true);
	}
	else
	{
		DrawGraph(700, 200, pList[p2 + 4], true);
	}
	// �X�e�[�W�g
	DrawGraph(stageL[waku].waku_pos.x, stageL[waku].waku_pos.y, stage_waku, true);
	// �X�e�[�W�摜�؂�ւ�����
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

