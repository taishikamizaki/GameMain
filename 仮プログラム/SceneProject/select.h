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
	int GetP1()
	{
		return;
	}
	int SelectCtl();
	void Draw();

	Select();
	~Select();
private:
	int Init();

	StageL stageL[3];

	CHAR_ID player1;
	CHAR_ID player2;

	int p1Image;
	int p2Image;

	int p1;
	int p2;

	int p1_waku;
	int p2_waku;

	int pList[12];

	int yamaImage[2];
	int matiImage[2];
	int tougiImage[2];

	int stage_waku;

	bool p1IF;		// キャラ枠用
	bool p2IF;		// キャラ枠用

	bool p1Flag;	// キャラ選択用
	bool p2Flag;	// キャラ選択用

	bool yamaF;		// ステ選択用
	bool matiF;		// ステ選択用
	bool tougiF;	// ステ選択用

	bool stageF;	// ステ決定用
	bool stageIF;	// ステ枠用

	bool selectF;	// 全体の決定用

};

