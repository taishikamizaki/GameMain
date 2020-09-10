#pragma once
#include "player/player.h"
#include "stage/Stage.h"

struct Pos
{
	int x;
	int y;
};

struct StageL
{
	Pos pos;
	Pos waku_pos;
};

class Stage;
class Player;
class Select
{
public:
	int GetSelectFlag()
	{
		return selectF;
	}
	CHAR_ID GetP1();
	CHAR_ID GetP2();
	STAGE_ID GetStage()
	{
		return stageID;
	}
	int SelectCtl();
	void Draw();

	Select();
	~Select();
private:
	int Init();

	StageL stageL[3];
	STAGE_ID stageID;


	CHAR_ID player1;
	CHAR_ID player2;

	int p1Image;
	int p2Image;

	int p1;
	int p2;

	int p1_waku;	// �g�`��
	int p2_waku;	// �g�`��
	int p_waku1;	// �g����
	int p_waku2;	// �g����

	int pList[12];

	int yamaImage[2];
	int matiImage[2];
	int tougiImage[2];

	int stage_waku;		// �g�`��
	int s_waku;				// �g����

	bool p1IF;		// �L�����g�p
	bool p2IF;		// �L�����g�p

	bool p1Flag;		// �L�����I��p
	bool p2Flag;		// �L�����I��p

	bool yamaF;		// �X�e�I��p
	bool matiF;		// �X�e�I��p
	bool tougiF;		// �X�e�I��p

	bool stageF;		// �X�e����p
	bool stageIF;	// �X�e�g�p

	bool selectF;	// �S�̂̌���p

};

