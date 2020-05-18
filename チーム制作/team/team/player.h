#pragma once

//�萔�̒�`

//�񋓌^


enum CHAR_ID
{
	CHAR_ID_KISI
	,CHAR_ID_MDOU
	,CHAR_ID_BTOU
	,CHAR_ID_4
	,CHAR_ID_MAX

};

//�\����
struct CHARACTER 
{
	DIR moveDir;		//�����Ă������
	Pos pos;			//�L�����N�^�̈ʒu�i���S�j
	Pos size;			//�L�����N�^�摜�̃T�C�Y
	Pos sizeOffset;		//�L�����N�^��������̍���ʒu
	bool runFlag;		//�L�����N�^�̏�ԁi�����Ă��邩�H�j
	bool jumpFlag;		//�L�����N�^�̏�ԁi�W�����v���Ă��邩�H�j
	bool shotFlag;		//�L�����N�^�̏�ԁi�e�����Ă��邩�H�j
	bool damageFlag;	//�L�����N�^�̏�ԁi�_���[�W�󂯂Ă��邩�H�j
	int moveSpeed;		//�L�����N�^�̈ړ���
	int life;			//�L�����N�^�̗̑�
	int lifeMax;		//�L�����N�^�̗͍̑ő�
	int animCnt;		//�L�����N�^�̃A�j���[�V�����p�J�E���^
	int imgLockCnt;		//�L�����N�^�̃C���[�W�Œ�p�J�E���^
	int type;			//���炩�̑������i�[�ł���B
};

//�v���g�^�C�v�錾
void	PlayerSysInit(void);
void	PlayerGameInit(void);
void	PlayerCtl(void);
void	PlayerDraw(void);
