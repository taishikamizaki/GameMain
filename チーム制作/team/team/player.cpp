#include "DxLib.h"
#include "main.h"
#include "GetKeyState.h"
#include "player.h"
#include"Stage.h"

//�ϐ��̒�`
CHARACTER	player1;

void	PlayerSysInit(void)
{
	player1.moveDir = DIR_RIGHT;						//�����Ă������
	player1.pos = {96,SCREEN_SIZE_Y-100};								//�L�����N�^�̈ʒu�i���S�j
	player1.size = {96,100};								//�L�����N�^�摜�̃T�C�Y
	player1.hitPosS = { 15,16 };		//�����蔻��p�̍���
	player1.hitPosE = { 15,32 };		//�����蔻��p�̉E��
	player1.velocity = { 0.0f,0 };
	player1.sizeOffset.x =  player1.size.x / 2 ;		//�L�����N�^��������̍���ʒu��X���W
	player1.sizeOffset.y = player1.size.y / 2;			//�L�����N�^��������̍���ʒu��Y���W
	player1.runFlag = false;							//�L�����N�^�̏�ԁi�����Ă��邩�H�j
	player1.jumpFlag = false;							//�L�����N�^�̏�ԁi�W�����v���Ă��邩�H�j
	player1.shotFlag = false;							//�L�����N�^�̏�ԁi�e�����Ă��邩�H�j
	player1.damageFlag = false;							//�L�����N�^�̏�ԁi�_���[�W�󂯂Ă��邩�H�j
	player1.surinukeFlag=false;							//1���u���b�N���蔲���p
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

	Pos	playerPosBK = player1.pos;
	Pos	playerPosHit = player1.pos;
	Pos	playerPosHitLeft = player1.pos;
	Pos	playerPosHitRight = player1.pos;
	Pos	playerPosHitUp = player1.pos;
	Pos	playerPosHitDown = player1.pos;

	player1.runFlag = false;
	player1.shotFlag = false;
	player1.jumpFlag = true;


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

	if (player1.jumpFlag)
	{
		//�d�͂ɂ��ړ�����
		player1.velocity.y -= ACC_G * FRAME_TIME;

		playerPosBK.y -= player1.velocity.y*FRAME_TIME;


		playerPosHit.y = playerPosBK.y - player1.hitPosS.y;
		playerPosHitLeft = playerPosHit;
		playerPosHitLeft.x -= player1.hitPosS.x;

		playerPosHitRight = playerPosHit;
		playerPosHitRight.x += player1.hitPosE.x;

		if (!IsPass(playerPosHit) || !IsPass(playerPosHitRight) || !IsPass(playerPosHitLeft))
		{
			//�ړ��L�����Z��
			Pos	blockIndex = PosToIndex(playerPosHit);		//�u���b�N�̔z����W
			blockIndex.y = blockIndex.y + 1;
			Pos	blockPos = IndexToPos(blockIndex);		//�u���b�N�̍���̃s�N�Z�����W
														//�����̍��W����v���C���[�̍��W���v�Z����
			playerPosBK.y = blockPos.y + player1.hitPosS.y;
			player1.velocity.y = 0;

		}

		//�����̌v�Z
		playerPosHit.y = playerPosBK.y + player1.hitPosE.y;

		playerPosHitLeft = playerPosHit;
		playerPosHitLeft.x -= player1.hitPosS.x;

		playerPosHitRight = playerPosHit;
		playerPosHitRight.x += player1.hitPosE.x;

		//�����`�F�b�N
		if (IsPass(playerPosHit) && IsPass(playerPosHitRight) && IsPass(playerPosHitLeft))
		{
			//�u���b�N�Ȃ���
			player1.pos.y = playerPosBK.y;
		}
		else
		{
			//�u���b�N����Ȃ��ɏ��

			//�W�����v�I���͑����̍��W����ʒu������o��
			//�����̍��W��playerPosHit
			//PosIndex(playerPosHit)������Ǝ��������u���b�N���킩��
			//���̃u���b�N�̏�̖ʂ�Y���W���v���C���[�̑����̍��W
			//�u���b�N�̏�̖ʂ�Y���W�́H
			Pos	blockIndex = PosToIndex(playerPosHit);		//�u���b�N�̔z����W
			Pos	blockPos = IndexToPos(blockIndex);		//�u���b�N�̍���̃s�N�Z�����W
														//�����̍��W����v���C���[�̍��W���v�Z����
			player1.pos.y = blockPos.y - player1.hitPosE.y;

			player1.jumpFlag = false;
			player1.velocity.y = 0;

			if (player1.jumpFlag == false)
			{
				if (keyNew[KEY_ID_UP])
				{
					player1.jumpFlag = true;
					player1.velocity.y = INIT_VELOCITY;
					//player1.pos.y -= player1.moveSpeed;

				}
			}
		}




		if (moveFlag)
		{
			if (player1.moveDir == DIR_RIGHT)
			{
				player1.moveSpeed = 4;
			}
			else if (player1.moveDir == DIR_LEFT)
			{
				player1.moveSpeed = -4;
			}
		}

		//�E�ɐi��ł���Ƃ�
		if (player1.moveSpeed == 4)
		{
			playerPosBK.x += player1.moveSpeed;
			playerPosHit.x = playerPosBK.x + player1.hitPosE.x;

			playerPosHitUp = playerPosHit;
			playerPosHitUp.y -= player1.hitPosS.y;

			playerPosHitDown = playerPosHit;
			playerPosHitDown.y += player1.hitPosE.y - 1;//1�͏��̏�ɑ����悹��悤

			if (IsPass(playerPosHit) && IsPass(playerPosHitUp) && IsPass(playerPosHitDown))
			{
				player1.pos.x = playerPosBK.x;
			}
			else
			{
				player1.moveSpeed = 0;
			}
		}


		//���ɐi��ł���Ƃ�
		if (player1.moveSpeed == -4)
		{
			playerPosBK.x += player1.moveSpeed;
			playerPosHit.x = playerPosBK.x - player1.hitPosS.x;

			playerPosHitUp = playerPosHit;
			playerPosHitUp.y -= player1.hitPosS.y;

			playerPosHitDown = playerPosHit;
			playerPosHitDown.y += player1.hitPosE.y - 1;//1�͏��̏�ɑ����悹��悤


			//if (player1.velocity.x < -6) { player1.velocity.x = -6; }


			if (IsPass(playerPosHit) && IsPass(playerPosHitUp) && IsPass(playerPosHitDown))
			{
				player1.pos.x = playerPosBK.x;
			}
			else
			{
				player1.moveSpeed = 0;
			}

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

	DrawFormatString(0, 32, 0xFFFFF, "player1.Pos(%d,%d)", player1.pos.x, player1.pos.y);

}