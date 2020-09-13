#pragma once
#include<memory>
#include"../scene/Game.h"
#include "player.h"
#include"../vector/Vector2.h"

#define lpSkill Skill::GetInstance()

// �X�L���̎��
enum class SKILL_ID
{
	SKILL_1,
	SKILL_2,
	SKILL_3,
	SKILL_4,
	SKILL_MAX
};
// pos��XY
struct XY
{
	int x;
	int y;
};
// �X�L���̃N�[���_�E��
struct SScount
{
	int s1;
	int s2;
	int s3;
	int s4;
};
// �X�L���֘A
struct player
{
	SKILL_ID skill;	// player�̃X�L��
	XY posp;		// player��pos
	XY offsetPosp;	// player��pos(�I�t�Z�b�g)
	XY pos;			// player�̏����ʒu(test)
	XY hitPos;		// player�̓����蔻��(�U��)
	XY hitoffsetPos;// player�̓����蔻��(�U��)�̃I�t�Z�b�g
	XY AttackRange;	// player�̍U���͈�
	XY Attackoffset;// player�̍U���͈̓I�t�Z�b�g
	int Scount;		// player�̃X�L��
	int HP;			// playerHP
	int LP;			// player�̏������C�t�|�C���g
	int dmage;		// player���^����_���[�W
	int attack;		// player�̍U����(�t�^���ꂽ���l)
	int defense;	// player�̖h���(�t�^���ꂽ���l)
	int speed;		// player�̈ړ����x
	int count;		// �X�L���̃J�E���g
	int SSposoffset;// posY�̈ʒu�ێ��悤pos
	int SSpos;		// offsetY�̈ʒu�ێ��ppos
	int SSX;		// offsetX�̈ʒu�ێ��ppos
	int SetPos;		// �ێ�����pos�}���p(posY)
	int SetoffPos;	// �ێ�����pos�}���p(offsetY)
	int SetoffX;	// �ێ�����pos�}���p(offsetX)
	bool SSflag;	// �����P��p
	bool skillFlag;	// �X�L���̃I���I�t
	bool hitFlag;	// �U���̓����蔻��t���O
	bool bufFlag;	// �o�t�ڔ����t���O
	bool Lflag;		// Dir�̍������t���O
	bool Rflag;		// Dir�̉E�����t���O
	bool posSetFlag;// �ێ�����pos����񂾂��Ăԃt���O
	bool laserFlag;	// ���[�U�[�̃t���O
	SScount kisi;	// �R�m�̃X�L���J�E���g
	SScount maho;	// �����m�̃X�L���J�E���g
	SScount buto;	// �����Ƃ̃X�L���J�E���g
	SScount nazo;	// ��̒j�̃X�L���J�E���g
	int dir;		// ���E�̌���
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

	void StageSysInit(void);													// �X�L���̏�����
	void StageGameInit(void);													// �X�L���̃Q�[���ݒ�

	void PlayerInit(Vector2 pos, Vector2 hitposS, Vector2 hitposE, 
		Vector2 offset, Vector2 size, Vector2 pos2, Vector2 hitposS2, 
		Vector2 hitposE2, Vector2 offset2, Vector2 size2);						// �v���C���[��pos�̎󂯓n��
	void CharInit(CHAR_ID player1, CHAR_ID player2);							// �S�l�̃L�����̏����X�e�[�^�X
	void SScountInit(void);														// �X�L���J�E���g�̏�����

	void SkillDraw(CHAR_ID player1, CHAR_ID player2);							// �X�L���̕`��						


	void SkillCtl(CHAR_ID player1, CHAR_ID player2);							// �X�L���̔��������o
	bool CheckHitP2(Vector2 pos, Vector2 posS, Vector2 posE);					// player2�̓����蔻��
	bool CheckHitP1(Vector2 pos, Vector2 posS, Vector2 posE);					// player1�̓����蔻��

	bool P1skill(CHAR_ID player1, CHAR_ID player2);								// �R�m�̃X�L������
	bool P2skill(CHAR_ID player1, CHAR_ID player2);								// �����m�̃X�L������
	bool P3skill(CHAR_ID player1, CHAR_ID player2);								// �����Ƃ̃X�L������
	bool P4skill(CHAR_ID player1, CHAR_ID player2);								// ��̒j�̃X�L������

	int HPCtlP1(void);															// player1��HP�̒l�n��
	int HPCtlP2(void);															// player2��HP�̒l�n��
	void DmageCtl(Vector2 pos1, Vector2 pos2,
		Vector2 posS, Vector2 posS2, Vector2 posE,Vector2 posE2);				// player��HP�Ǘ�

	void Dir(int p1, int p2);													// dir�̎󂯓n��

	Skill();																	// �R���X�g���N�^
	~Skill();																	// �f�X�g���N�^
private:

	// �`��p�ϐ�
	int healImage[10];															// �񕜃o�t
	int buffAImage[10];															// �U���o�t
	int buffDImage[10];															// �h��o�t
	int buffSImage[10];															// �X�s�[�h�o�t
	int buffUImage[10];															// ����o�t
	int laserImage[5];															// ���[�U�[(����)�P
	int laserSetImage[10];														// ���[�U�[(�`���[�W)�P
	int laser2[5];																// ���[�U�[(����)�Q
	int laserSet2[10];															// ���[�U�[(�`���[�W)�P
	int charicon[12];															// �L�����A�C�R��
	int upImage[5];																// �A�b�p�[�P
	int guardImage[20];															// �V�[���h�P
	int magic;																	// ���@�P
	int magic2;																	// ���@�Q
	int magic3;																	// ���@�R
	int uibuffU;																// ui�o�t
	int uiken;																	// ui��
	int uiheal;																	// ui��
	int uiles;																	// ui���[�U�[
	int uihand;																	// ui��
	int uisra;																	// ui�a��
	int uitate;																	// ui��
	int uimaho;																	// ui���@
	int uilej;																	// ui�f�o�t
	int kensla1;																// �a���P
	int kensla2;																// �a���Q
	int kensla3;																// �a���R
	int kensla4;																// �a���S
	
	bool charF;																	// �L�����I���̓ǂݍ���(���̂�)
	
	player P1;																	// player1�̍\����
	player P2;																	// player2�̍\����

};



