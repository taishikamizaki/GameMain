#pragma once



enum class PlayChar
{
	P_KISI,
	P_MAHO,
	P_BUTO,
	P_NAZO,
	P_MAX
};


enum class MAP_ID
{
	MAP_ID_YAMA,
	MAP_ID_MATI,
	MAP_ID_TOUGI,
	MAP_ID_MAX
};

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




#define SCREEN_SIZE_X 1000		//��ʂ̉�����
#define SCREEN_SIZE_Y 600		//��ʂ̏c����

#define MAP_X 20
#define MAP_Y 12
#define CHIP_SIZE_X 50
#define CHIP_SIZE_Y 50

#define HAMA_SIZE_X 50
#define HAMA_SIZE_Y 50

#define TIME_SIZE_X 43
#define TIME_SIZE_Y 100

#define HAMA_CNT_1 5000
#define HAMA_CNT_2 (HAMA_CNT_1 + 20000)

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

};


bool SysInit();

void StageSysInit(void);
void SoundSysInit(void);
void StageGameInit(void);
void SoundGameInit(void);
void PlayerInit(void);
void CharInit(void);
void SScountInit(void);

void StageDraw(void);
void SkillDraw(void);
void HamaTime(void);

void SkillCtl();
void CheckHit();

bool P1skill(void);
bool P2skill(void);
bool P3skill(void);
bool P4skill(void);




XY PosToIndex(XY pos);

XY IndexToPos(XY index);

