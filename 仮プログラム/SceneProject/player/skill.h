#pragma once
#include<memory>
#include"../scene/Game.h"
#include "player.h"
#include"../vector/Vector2.h"

#define lpSkill Skill::GetInstance()


enum class SKILL_ID
{
	SKILL_1,
	SKILL_2,
	SKILL_3,
	SKILL_4,
	SKILL_MAX
};
enum class SKILL_TYPE
{
	Attack,
	Buff,
	Unipue,
	Special,
	Max
};

struct XY
{
	int x;
	int y;
};
struct SScount
{
	int s1;
	int s2;
	int s3;
	int s4;
};
struct player
{
	SKILL_ID skill;	// playerのスキル
	XY posp;		//
	XY offsetPosp;	//
	XY pos;			// playerの初期位置(test)
	XY hitPos;		// playerの当たり判定(攻撃)
	XY hitoffsetPos;// playerの当たり判定(攻撃)のオフセット
	XY AttackRange;	// playerの攻撃範囲
	XY Attackoffset;// playerの攻撃範囲オフセット
	int Scount;		//
	int HP;			// playerHP
	int LP;			// playerの初期ライフポイント
	int dmage;		// playerが与えるダメージ
	int attack;		// playerの攻撃力(付与された数値)
	int defense;	// playerの防御力(付与された数値)
	int speed;		// playerの移動速度
	int count;
	int SSposoffset;
	int SSpos;
	int SSX;
	int SetPos;
	int SetoffPos;
	int SetoffX;
	bool SSflag;	//発動１回用
	bool skillFlag;
	bool kyouFlag;
	bool zyakuFlag;
	bool hitFlag;
	bool bufFlag;
	bool atFlag;
	bool Lflag;
	bool Rflag;
	bool posSetFlag;
	bool laserFlag;
	SScount kisi;
	SScount maho;
	SScount buto;
	SScount nazo;
	int dir;
};


class Skill
{
public:
	static Skill& GetInstance()
	{
		static Skill s_instance;
		return s_instance;
	}

	bool GetCharF()
	{
		return charF;
	}

	void StageSysInit(void);
	void StageGameInit(void);

	void PlayerInit(Vector2 pos, Vector2 hitposS, Vector2 hitposE, Vector2 offset, Vector2 size, Vector2 pos2, Vector2 hitposS2, Vector2 hitposE2, Vector2 offset2, Vector2 size2);
	void CharInit(CHAR_ID player1, CHAR_ID player2);
	void SScountInit(void);

	void StageDraw(CHAR_ID player1, CHAR_ID player2);


	void SkillCtl(CHAR_ID player1, CHAR_ID player2);
	bool CheckHitP2(Vector2 pos, Vector2 posS, Vector2 posE);
	bool CheckHitP1(Vector2 pos, Vector2 posS, Vector2 posE);

	bool P1skill(CHAR_ID player1, CHAR_ID player2);
	bool P2skill(CHAR_ID player1, CHAR_ID player2);
	bool P3skill(CHAR_ID player1, CHAR_ID player2);
	bool P4skill(CHAR_ID player1, CHAR_ID player2);

	int HPCtlP1(void);
	int HPCtlP2(void);
	void DmageCtl(Vector2 pos1, Vector2 pos2,Vector2 posS, Vector2 posS2, Vector2 posE,Vector2 posE2);
	void SpeedCtl(int p1,int p2);

	void Dir(int p1, int p2);

	Skill();
	~Skill();
private:

	int healImage[10];
	int buffAImage[10];
	int buffDImage[10];
	int buffSImage[10];
	int buffUImage[10];
	int slashImage[16];
	int slash2Image[16];
	int slash3Image[12];
	int laserImage[5];
	int laserSetImage[10];
	int laser2[5];
	int laserSet2[10];
	int charicon[12];
	int upImage[5];
	int guardImage[20];
	int magic;
	int magic2;
	int magic3;
	int uibuffU;
	int uiken;
	int uiheal;
	int uiles;
	int uihand;
	int uisra;
	int uitate;
	int uimaho;
	int uilej;
	int swordImage;
	int punchImage;
	int wandImage;
	int dImage;
	int kensla1;
	int kensla2;
	int kensla3;
	int kensla4;
	
	bool charF;
	
	player P1;
	player P2;

};



