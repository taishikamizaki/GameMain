#pragma once
#include"../scene/Game.h"
#include "player.h"
#include"../vector/Vector2.h"


#define lpSkill Skill::GetInstance()

//enum class PlayChar
//{
//	P_KISI,
//	P_MAHO,
//	P_BUTO,
//	P_NAZO,
//	P_MAX
//};


//enum class MAP_ID
//{
//	MAP_ID_YAMA,
//	MAP_ID_MATI,
//	MAP_ID_TOUGI,
//	MAP_ID_MAX
//};

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

//#define SCREEN_SIZE_X 1000		//��ʂ̉�����
//#define SCREEN_SIZE_Y 600		//��ʂ̏c����
//
//#define MAP_X 20
//#define MAP_Y 12
//#define CHIP_SIZE_X 50
//#define CHIP_SIZE_Y 50
//
//#define HAMA_SIZE_X 50
//#define HAMA_SIZE_Y 50
//
//#define TIME_SIZE_X 43
//#define TIME_SIZE_Y 100
//
//#define HAMA_CNT_1 5000
//#define HAMA_CNT_2 (HAMA_CNT_1 + 20000)

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
	SKILL_ID skill;	// player�̃X�L��
	XY posp;		//
	XY offsetPosp;	//
	XY pos;			// player�̏����ʒu(test)
	XY hitPos;		// player�̓����蔻��(�U��)
	XY hitoffsetPos;// player�̓����蔻��(�U��)�̃I�t�Z�b�g
	XY AttackRange;	// player�̍U���͈�
	XY Attackoffset;// player�̍U���͈̓I�t�Z�b�g
	int Scount;		//
	int HP;			// playerHP
	int LP;			// player�̏������C�t�|�C���g
	int dmage;		// player���^����_���[�W
	int attack;		// player�̍U����(�t�^���ꂽ���l)
	int defense;	// player�̖h���(�t�^���ꂽ���l)
	int speed;		// player�̈ړ����x
	int count;
	bool SSflag;	//�����P��p
	bool skillFlag;
	bool hitFlag;
	bool bufFlag;
	bool atFlag;
	SScount kisi;
	SScount maho;
	SScount buto;
	SScount nazo;
};


//bool SysInit();

//void SoundSysInit(void);
//void StageGameInit(void);
//void SoundGameInit(void);

class Skill
{
public:
	static Skill& GetInstance()
	{
		static Skill s_instance;
		return s_instance;
	}

	void StageSysInit(void);
	void StageGameInit(void);

	void PlayerInit(Vector2 pos, Vector2 hitposS, Vector2 hitposE, Vector2 offset, Vector2 size, Vector2 pos2, Vector2 hitposS2, Vector2 hitposE2, Vector2 offset2, Vector2 size2);
	void CharInit(CHAR_ID player1, CHAR_ID player2);
	void SScountInit(void);

	void StageDraw(CHAR_ID player1, CHAR_ID player2);
	void SkillDraw(void);
	void HamaTime(void);

	void SkillCtl(CHAR_ID player1, CHAR_ID player2);
	void CheckHit();

	bool P1skill(CHAR_ID player1, CHAR_ID player2);
	bool P2skill(CHAR_ID player1, CHAR_ID player2);
	bool P3skill(CHAR_ID player1, CHAR_ID player2);
	bool P4skill(CHAR_ID player1, CHAR_ID player2);

	Skill();
private:
	/*int chipImage[7];
	int matiImage[43];
	int tougiImage[12];
	int yamaImage[23];*/
	/*int hamaImage;
	int timeImage[10];*/
	int healImage[10];
	int buffAImage[10];
	int buffDImage[10];
	int buffSImage[10];
	int buffUImage[10];
	int slashImage[16];
	int slash2Image[16];
	int slash3Image[12];
	int laserImage[5];

	int swordImage;

	//bool hamaFlag;
	//int yamabgm;
	//int matibgm;
	//int tougibgm;
	//int hamaCnt;
	//XY mapSize;
	//XY hamaPos;
	
	//enum MAP_ID mapID;
	//SKILL_ID skill;
	player P1;
	player P2;

	/*SScount kisi;
	SScount maho;
	SScount buto;
	SScount nazo;*/
	
	~Skill();

};



