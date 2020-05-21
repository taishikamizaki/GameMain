#include "DxLib.h"
#include "main.h"
#include "GetKeyState.h"
#include "player.h"

//�ϐ��̒�`
CHARACTER	player1;

void	PlayerSysInit(void)
{
	player1.moveDir = DIR_RIGHT;						//�����Ă������
	player1.pos = {96,SCREEN_SIZE_Y-100};								//�L�����N�^�̈ʒu�i���S�j
	player1.size = {96,100};								//�L�����N�^�摜�̃T�C�Y
	player1.sizeOffset.x =  player1.size.x / 2 ;		//�L�����N�^��������̍���ʒu��X���W
	player1.sizeOffset.y = player1.size.y / 2;			//�L�����N�^��������̍���ʒu��Y���W
	player1.runFlag = false;							//�L�����N�^�̏�ԁi�����Ă��邩�H�j
	player1.jumpFlag = false;							//�L�����N�^�̏�ԁi�W�����v���Ă��邩�H�j
	player1.shotFlag = false;							//�L�����N�^�̏�ԁi�e�����Ă��邩�H�j
	player1.damageFlag = false;							//�L�����N�^�̏�ԁi�_���[�W�󂯂Ă��邩�H�j
	player1.moveSpeed=4;								//�L�����N�^�̈ړ���
	player1.life=4;										//�L�����N�^�̗̑�
	player1.lifeMax=4;									//�L�����N�^�̗͍̑ő�
	player1.animCnt=0;									//�L�����N�^�̃A�j���[�V�����p�J�E���^
}

void	PlayerGameInit(void)
{
	
}

void	PlayerCtl(void)
{
	bool	moveFlag = false;

	player1.runFlag = false;

	if (keyNew[KEY_ID_RIGHT])
	{
		player1.runFlag = true;

		moveFlag = true;
		player1.moveDir = DIR_RIGHT;
	}

	if (keyNew[KEY_ID_LEFT])
	{
		player1.runFlag = true;

		moveFlag = true;
		player1.moveDir = DIR_LEFT;
	}


	if (moveFlag)
	{
		if (player1.moveDir == DIR_RIGHT)
		{
			player1.pos.x += player1.moveSpeed;
		}
		else if (player1.moveDir == DIR_LEFT)
		{
			player1.pos.x -= player1.moveSpeed;
		}
	}
}

void	PlayerDraw(void)
{
	DrawBox(player1.pos.x - player1.sizeOffset.x 
		, player1.pos.y - player1.sizeOffset.y 
		, player1.pos.x + player1.size.x - player1.sizeOffset.x 
		, player1.pos.y + player1.size.y - player1.sizeOffset.y
		, 0xFFFFF
		, false);

	DrawFormatString(0, 32, 0xFFFFFF, "player1.Pos(%d,%d)", player1.pos.x, player1.pos.y);

}