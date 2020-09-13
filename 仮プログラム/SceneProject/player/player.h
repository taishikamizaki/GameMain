#pragma once
#include <map>
#include <string>
#include "skill.h"
#include"../scene/Game.h"
#include "../vector/Vector2.h"
#include "../vector/Vector2f.h"


//�萔�̒�`
#define	P_DSP	        4		//�v���C���[�̊�{�X�s�[�h
#define INIT_VELOCITY	50.0f	//�����x
#define ACC_G		    10		//�d�͉����x
#define	FRAME_TIME	    0.3f	//IsPass�p

#define	lpPlayer Player::GetInstance()

//Run�摜�؂�ւ��p
constexpr auto DIR_RIGHT=0;
constexpr auto DIR_LEFT =1;


using MapInt = std::map<int, int>;
using PairChar = std::pair<CHAR_ID, CHAR_ID>;
//��
enum class DIR
{
	DIR_ID_RIGHT,
	DIR_ID_LEFT,
	DIR_MAX
};

//�\����
struct CHARACTER 
{
	DIR moveDir;			//�����Ă������
	Vector2 pos;			//�L�����N�^�̈ʒu�i���S�j
	Vector2 size;			//�L�����N�^�摜�̃T�C�Y
	Vector2 sizeOffset;		//�L�����N�^��������̍���ʒu
	Vector2 hitPosS;		//�����蔻��p�̍���
	Vector2 hitPosE;		//�����蔻��p�̉E��
	Vector2f velocity;
	bool atFlag;
	bool runFlag;			//�L�����N�^�̏�ԁi�����Ă��邩�H�j
	bool jumpFlag;			//�L�����N�^�̏�ԁi�W�����v���Ă��邩�H�j
	bool shotFlag;			//�L�����N�^�̏�ԁi�e�����Ă��邩�H�j
	bool damageFlag;		//�L�����N�^�̏�ԁi�_���[�W�󂯂Ă��邩�H�j
	bool surinukeFlag;		//1���u���b�N���蔲���p
	bool nonFlag;
	bool winFlag;
	int moveSpeed;			//�L�����N�^�̈ړ���
	int animCnt;			//�L�����N�^�̃A�j���[�V�����p�J�E���^
	int Hp;
	int dirS;
	CHAR_ID charID;
};

class Skill;
class Player
{
public:

	int kisiImage[12];		//�R�m�̉摜
	int mahoImage[12];		//���@�g���̉摜
	int butoImage[12];		//�����Ƃ̉摜
	int nazoImage[12];		//��̒j�̉摜

	int kisiRunImage[2][4];	// �R�m�̑����Ԃ̉摜
	int mahoRunImage[2][4];	// ���@�g���̑����Ԃ̉摜
	int butoRunImage[2][4];	// �����Ƃ̑����Ԃ̉摜
	int nazoRunImage[2][4];	// ��̒j�̑����Ԃ̉摜

	static Player& GetInstance()
	{
		static Player s_Instance;
		return s_Instance;
	}

	//�����o�֐�
	void PlayerSysInit(void);
	void PlayerGameInit(void);
	void PlayerCtl(STAGE_ID id);
	void PlayerDraw(void);

	void SetPlayerID(Vector2 pos1, Vector2 pos2);
	void charCtl(CHAR_ID p1, CHAR_ID p2);

	bool HPmng(void);
	bool playerWin(void);
	bool win(void);

	Player();
	~Player();

private:
	std::map<std::string, int> images;
	int playerPosX;
	int playerPosY;
	int hp;
	int iconp1;
	int iconp2;
	int p1win;
	int p2win;
	int draw;
	bool DrawFlag;
	bool GameOverFlag;
	bool charSelFlag;

	Vector2f HPsize;

	CHARACTER player1;	//1P
	CHARACTER player2;	//2P

	const Vector2 screen_size;
	DIR dir;

	MapInt charcter;
	PairChar charID_;

	Skill* skill;

};