#pragma once
#include <map>
#include"Vector2.h"
#include"Vector2f.h"


//�萔�̒�`
#define	P_DSP	4				//�v���C���[�̊�{�X�s�[�h
#define INIT_VELOCITY	50.0f	//�����x
#define ACC_G		10			//�d�͉����x
#define	FRAME_TIME	0.3f

#define	lpPlayer Player::GetInstance()

using MapInt = std::map<int, int>;

//�񋓌^
enum CHAR_ID
{
	CHAR_ID_KISI,
	CHAR_ID_MDOU,
	CHAR_ID_BTOU,
	CHAR_ID_4,
	CHAR_ID_MAX
};

//�\����
struct CHARACTER 
{
	DIR moveDir;		//�����Ă������
	Vector2 pos;			//�L�����N�^�̈ʒu�i���S�j
	Vector2 size;			//�L�����N�^�摜�̃T�C�Y
	Vector2 sizeOffset;		//�L�����N�^��������̍���ʒu
	Vector2 hitPosS;		//�����蔻��p�̍���
	Vector2 hitPosE;		//�����蔻��p�̉E��
	Vector2f velocity;
	bool runFlag;		//�L�����N�^�̏�ԁi�����Ă��邩�H�j
	bool jumpFlag;		//�L�����N�^�̏�ԁi�W�����v���Ă��邩�H�j
	bool shotFlag;		//�L�����N�^�̏�ԁi�e�����Ă��邩�H�j
	bool damageFlag;	//�L�����N�^�̏�ԁi�_���[�W�󂯂Ă��邩�H�j
	bool surinukeFlag;	//1���u���b�N���蔲���p
	int moveSpeed;		//�L�����N�^�̈ړ���
	int life;			//�L�����N�^�̗̑�
	int lifeMax;		//�L�����N�^�̗͍̑ő�
	int animCnt;		//�L�����N�^�̃A�j���[�V�����p�J�E���^
	int imgLockCnt;		//�L�����N�^�̃C���[�W�Œ�p�J�E���^
	int type;			//���炩�̑������i�[�ł���B
};

//�v���g�^�C�v�錾
//void	PlayerSysInit(void);
//void	PlayerGameInit(void);
//void	PlayerCtl(void);
//void	PlayerDraw(void);

class Player
{
public:
	static Player& GetInstance()
	{
		static Player s_Instance;
		return s_Instance;
	}

	//�����o�֐�
	void PlayerSysInit(void);
	void PlayerGameInit(void);
	void PlayerCtl(void);
	void PlayerDraw(void);

private:

	
	//Vector2 velocity;

	int playerPosX;
	int playerPosY;

	MapInt charcter;
	CHARACTER player1;
	bool runFlag;		//�L�����N�^�̏�ԁi�����Ă��邩�H�j
	bool jumpFlag;		//�L�����N�^�̏�ԁi�W�����v���Ă��邩�H�j
	bool shotFlag;		//�L�����N�^�̏�ԁi�e�����Ă��邩�H�j
	bool damageFlag;	//�L�����N�^�̏�ԁi�_���[�W�󂯂Ă��邩�H�j
	bool surinukeFlag;	//1���u���b�N���蔲���p
	int moveSpeed;		//�L�����N�^�̈ړ���
	int life;			//�L�����N�^�̗̑�
	int lifeMax;		//�L�����N�^�̗͍̑ő�
	int animCnt;		//�L�����N�^�̃A�j���[�V�����p�J�E���^
	int imgLockCnt;		//�L�����N�^�̃C���[�W�Œ�p�J�E���^
	int type;			//���炩�̑������i�[�ł���B

	Player();
	~Player();
};