#include <DxLib.h>
#include "GetKeyState.h"
#include "skill.h"
#include "Stage.h"
#include "Vector2.h"
#include "player.h"

// ������
void Player::PlayerSysInit(void)
{
	Vector2 pos;									//�L�����N�^�̈ʒu�i���S�j
	
	player1.moveDir		 = DIR::DIR_ID_RIGHT;		// �����Ă������
	player1.size		 = { 96,64 };				// �L�����N�^�摜�̃T�C�Y
	player1.pos          = { 200,100 };
	player1.hitPosS		 = { 15,16 };				// �����蔻��p�̍���
	player1.hitPosE		 = { 15,32 };				// �����蔻��p�̉E��
	player1.velocity	 = { 0.0f,0 };				// �����x
	player1.sizeOffset.x = player1.size.x / 2;		// �L�����N�^��������̍���ʒu��X���W
	player1.sizeOffset.y = player1.size.y / 2;		// �L�����N�^��������̍���ʒu��Y���W
	player1.runFlag		 = false;					// �L�����N�^�̏�ԁi�����Ă��邩�H�j
	player1.jumpFlag	 = false;					// �L�����N�^�̏�ԁi�W�����v���Ă��邩�H�j
	player1.shotFlag	 = false;					// �L�����N�^�̏�ԁi�e�����Ă��邩�H�j
	player1.damageFlag	 = false;					// �L�����N�^�̏�ԁi�_���[�W�󂯂Ă��邩�H�j
	player1.surinukeFlag = false;					// 1���u���b�N���蔲���p
	player1.moveSpeed	 = 0;						// �L�����N�^�̈ړ���
	player1.animCnt		 = 0;						// �L�����N�^�̃A�j���[�V�����p�J�E���^

	player2.moveDir		 = DIR::DIR_ID_LEFT;		// �����Ă������
	player2.size		 = { 96,64 };				// �L�����N�^�摜�̃T�C�Y
	player2.hitPosS		 = { 15,16 };				// �����蔻��p�̍���
	player2.hitPosE		 = { 15,32 };				// �����蔻��p�̉E��
	player2.velocity	 = { 0.0f,0 };				// �����x
	player2.sizeOffset.x = player1.size.x / 2;		// �L�����N�^��������̍���ʒu��X���W
	player2.sizeOffset.y = player1.size.y / 2;		// �L�����N�^��������̍���ʒu��Y���W
	player2.runFlag      = false;					// �L�����N�^�̏�ԁi�����Ă��邩�H�j
	player2.jumpFlag     = false;					// �L�����N�^�̏�ԁi�W�����v���Ă��邩�H�j
	player2.shotFlag     = false;					// �L�����N�^�̏�ԁi�e�����Ă��邩�H�j
	player2.damageFlag   = false;					// �L�����N�^�̏�ԁi�_���[�W�󂯂Ă��邩�H�j
	player2.surinukeFlag = false;				    // 1���u���b�N���蔲���p
	player2.moveSpeed    = 0;						// �L�����N�^�̈ړ���
	player2.animCnt      = 0;						// �L�����N�^�̃A�j���[�V�����p�J�E���^

	LoadDivGraph("image/TestGraph/KISHI.png,", 12, 3, 4, 25, 33, kisiImage);
	LoadDivGraph("image/TestGraph/MAHO.png,", 12, 3, 4, 25, 33, mahoImage);
	LoadDivGraph("image/TestGraph/BUTOU.png,", 12, 3, 4, 25, 33, butoImage);
	LoadDivGraph("image/TestGraph/NAZO.png,", 12, 3, 4, 25, 33, nazoImage);

}

// �Q�[�����̏�����
void Player::PlayerGameInit(void)
{
	
}

// ���۰�
void Player::PlayerCtl(void)
{
	bool moveFlag1 = false;
	bool moveFlag2 = false;
	
	Vector2	playerPosBK       = player1.pos;
	Vector2	playerPosHit      = player1.pos;
	Vector2	playerPosHitLeft  = player1.pos;
	Vector2	playerPosHitRight = player1.pos;
	Vector2	playerPosHitUp    = player1.pos;
	Vector2	playerPosHitDown  = player1.pos;

	Vector2	playerPosBK2       = player2.pos;
	Vector2	playerPosHit2      = player2.pos;
	Vector2	playerPosHitLeft2  = player2.pos;
	Vector2	playerPosHitRight2 = player2.pos;
	Vector2	playerPosHitUp2    = player2.pos;
	Vector2	playerPosHitDown2  = player2.pos;
	
	player1.moveSpeed = 0;
	player1.runFlag   = false;
	player1.shotFlag  = false;
	player1.jumpFlag  = true;

	player2.moveSpeed = 0;
	player2.runFlag = false;
	player2.shotFlag = false;
	player2.jumpFlag = true;
	
	// 1P

	//�E
	if (keyNew[KEY_ID_RIGHT])
	{
		player1.runFlag = true;
	
		moveFlag1 = true;
		player1.moveDir = DIR::DIR_ID_RIGHT;
	}
	
	//��
	if (keyNew[KEY_ID_LEFT])
	{
		player1.runFlag = true;
	
		moveFlag1 = true;
		player1.moveDir = DIR::DIR_ID_LEFT;
	}
	
	//�ެ��ߔ���
	if (player1.jumpFlag)
	{
		//�d�͂ɂ��ړ�����
		player1.velocity.fy -= ACC_G * FRAME_TIME;
	
		playerPosBK.y -= player1.velocity.fy * FRAME_TIME;
	
		playerPosHit.y = playerPosBK.y - player1.hitPosS.y;
		playerPosHitLeft = playerPosHit;
		playerPosHitLeft.x -= player1.hitPosS.x;
	
		playerPosHitRight = playerPosHit;
		playerPosHitRight.x += player1.hitPosE.x;
	
		if (!lpStage.IsPass(playerPosHit) || !lpStage.IsPass(playerPosHitRight) || !lpStage.IsPass(playerPosHitLeft))
		{
			//�ړ��L�����Z��
			Vector2	blockIndex = lpStage.PosToIndex(playerPosHit);	//�u���b�N�̔z����W
			blockIndex.y = blockIndex.y + 1;
			Vector2	blockPos = lpStage.IndexToPos(blockIndex);		//�u���b�N�̍���̃s�N�Z�����W
														
			playerPosBK.y = blockPos.y + player1.hitPosS.y;			//�����̍��W����v���C���[�̍��W���v�Z����
			player1.velocity.fy = 0;
		}
	
		//�����̌v�Z
		playerPosHit.y = playerPosBK.y + player1.hitPosE.y;
	
		playerPosHitLeft = playerPosHit;
		playerPosHitLeft.x -= player1.hitPosS.x;
	
		playerPosHitRight = playerPosHit;
		playerPosHitRight.x += player1.hitPosE.x;
	
		//�����`�F�b�N
		if (lpStage.IsPass(playerPosHit) && lpStage.IsPass(playerPosHitRight) && lpStage.IsPass(playerPosHitLeft))
		{
			//�u���b�N�Ȃ���
			player1.pos.y = playerPosBK.y;
		}
		else
		{
			//�u���b�N����Ȃ��ɏ��
			Vector2	blockIndex = lpStage.PosToIndex(playerPosHit);		//�u���b�N�̔z����W
			Vector2	blockPos = lpStage.IndexToPos(blockIndex);			//�u���b�N�̍���̃s�N�Z�����W
														
			player1.pos.y = blockPos.y - player1.hitPosE.y;				//�����̍��W����v���C���[�̍��W���v�Z����
	
			player1.jumpFlag = false;
			player1.velocity.fy = 0;
	
			if (player1.jumpFlag == false)
			{
				if (keyNew[KEY_ID_UP])
				{
					player1.jumpFlag = true;
					player1.velocity.fy = INIT_VELOCITY;
					player1.pos.y -= player1.moveSpeed;
				}
			}
		}
	
		playerPosBK  = player1.pos;
		playerPosHit = player1.pos;
	
		if (moveFlag1)
		{
			if (player1.moveDir == DIR::DIR_ID_RIGHT)
			{
				player1.moveSpeed = P_DSP;
	
				playerPosBK.x += player1.moveSpeed;
				playerPosHit.x = playerPosBK.x + player1.hitPosE.x;
	
				playerPosHitUp = playerPosHit;
				playerPosHitUp.y -= player1.hitPosS.y;
	
				playerPosHitDown = playerPosHit;
				playerPosHitDown.y += player1.hitPosE.y - 1;  //1�͏��̏�ɑ����悹��悤
	
				if (lpStage.IsPass(playerPosHit) && lpStage.IsPass(playerPosHitUp) && lpStage.IsPass(playerPosHitDown))
				{
					player1.pos.x = playerPosBK.x;
				}
				else
				{
					player1.moveSpeed = 0;
				}
			}
			else if (player1.moveDir == DIR::DIR_ID_LEFT)
			{
				player1.moveSpeed = P_DSP;
	
				playerPosBK.x -= player1.moveSpeed;
				playerPosHit.x = playerPosBK.x - player1.hitPosS.x;
	
				playerPosHitUp = playerPosHit;
				playerPosHitUp.y -= player1.hitPosS.y;
	
				playerPosHitDown = playerPosHit;
				playerPosHitDown.y += player1.hitPosE.y - 1;//1�͏��̏�ɑ����悹��悤
	
	
				if (player1.velocity.fx < -6) { player1.velocity.fx = -6; }
	
	
				if (lpStage.IsPass(playerPosHit) && lpStage.IsPass(playerPosHitUp) && lpStage.IsPass(playerPosHitDown))
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

	// 2P

	//�E
	if (keyNew[KEY_ID_RIGHT])
	{
		player2.runFlag = true;

		moveFlag2 = true;
		player2.moveDir = DIR::DIR_ID_RIGHT;
	}

	//��
	if (keyNew[KEY_ID_LEFT])
	{
		player2.runFlag = true;

		moveFlag2 = true;
		player2.moveDir = DIR::DIR_ID_LEFT;
	}

	//�ެ��ߔ���
	if (player2.jumpFlag)
	{
		//�d�͂ɂ��ړ�����
		player2.velocity.fy -= ACC_G * FRAME_TIME;

		playerPosBK2.y -= player2.velocity.fy * FRAME_TIME;

		playerPosHit2.y = playerPosBK2.y - player2.hitPosS.y;
		playerPosHitLeft2 = playerPosHit2;
		playerPosHitLeft2.x -= player2.hitPosS.x;

		playerPosHitRight2 = playerPosHit2;
		playerPosHitRight2.x += player2.hitPosE.x;

		if (!lpStage.IsPass(playerPosHit2) || !lpStage.IsPass(playerPosHitRight2) || !lpStage.IsPass(playerPosHitLeft2))
		{
			//�ړ��L�����Z��
			Vector2	blockIndex2 = lpStage.PosToIndex(playerPosHit2);	//�u���b�N�̔z����W
			blockIndex2.y = blockIndex2.y + 1;
			Vector2	blockPos2 = lpStage.IndexToPos(blockIndex2);		//�u���b�N�̍���̃s�N�Z�����W

			playerPosBK2.y = blockPos2.y + player2.hitPosS.y;			//�����̍��W����v���C���[�̍��W���v�Z����
			player2.velocity.fy = 0;
		}

		//�����̌v�Z
		playerPosHit2.y = playerPosBK2.y + player2.hitPosE.y;

		playerPosHitLeft2 = playerPosHit2;
		playerPosHitLeft2.x -= player2.hitPosS.x;

		playerPosHitRight2 = playerPosHit2;
		playerPosHitRight2.x += player2.hitPosE.x;

		//�����`�F�b�N
		if (lpStage.IsPass(playerPosHit2) && lpStage.IsPass(playerPosHitRight2) && lpStage.IsPass(playerPosHitLeft2))
		{
			//�u���b�N�Ȃ���
			player2.pos.y = playerPosBK2.y;
		}
		else
		{
			//�u���b�N����Ȃ��ɏ��
			Vector2	blockIndex2 = lpStage.PosToIndex(playerPosHit2);		//�u���b�N�̔z����W
			Vector2	blockPos2 = lpStage.IndexToPos(blockIndex2);			//�u���b�N�̍���̃s�N�Z�����W

			player2.pos.y = blockPos2.y - player2.hitPosE.y;				//�����̍��W����v���C���[�̍��W���v�Z����

			player2.jumpFlag = false;
			player2.velocity.fy = 0;

			if (player2.jumpFlag == false)
			{
				if (keyNew[KEY_ID_UP])
				{
					player2.jumpFlag = true;
					player2.velocity.fy = INIT_VELOCITY;
					player2.pos.y -= player2.moveSpeed;
				}
			}
		}

		playerPosBK2 = player2.pos;
		playerPosHit2 = player2.pos;

		if (moveFlag2)
		{
			if (player2.moveDir == DIR::DIR_ID_RIGHT)
			{
				player2.moveSpeed = P_DSP;

				playerPosBK2.x += player2.moveSpeed;
				playerPosHit2.x = playerPosBK2.x + player2.hitPosE.x;

				playerPosHitUp2 = playerPosHit2;
				playerPosHitUp2.y -= player2.hitPosS.y;

				playerPosHitDown2 = playerPosHit2;
				playerPosHitDown2.y += player2.hitPosE.y - 1;  //1�͏��̏�ɑ����悹��悤

				if (lpStage.IsPass(playerPosHit2) && lpStage.IsPass(playerPosHitUp2) && lpStage.IsPass(playerPosHitDown2))
				{
					player2.pos.x = playerPosBK2.x;
				}
				else
				{
					player2.moveSpeed = 0;
				}
			}
			else if (player2.moveDir == DIR::DIR_ID_LEFT)
			{
				player2.moveSpeed = P_DSP;

				playerPosBK2.x -= player2.moveSpeed;
				playerPosHit2.x = playerPosBK2.x - player2.hitPosS.x;

				playerPosHitUp2 = playerPosHit2;
				playerPosHitUp2.y -= player2.hitPosS.y;

				playerPosHitDown2 = playerPosHit2;
				playerPosHitDown2.y += player2.hitPosE.y - 1;//1�͏��̏�ɑ����悹��悤


				if (player2.velocity.fx < -6) { player2.velocity.fx = -6; }


				if (lpStage.IsPass(playerPosHit2) && lpStage.IsPass(playerPosHitUp2) && lpStage.IsPass(playerPosHitDown2))
				{
					player2.pos.x = playerPosBK2.x;
				}
				else
				{
					player2.moveSpeed = 0;
				}
			}
		}
	}
}

// �`��
void Player::PlayerDraw(void)
{

	// 1P
	// �v���C���[�g
	DrawBox(player1.pos.x - player1.sizeOffset.x , player1.pos.y - player1.sizeOffset.y ,
			player1.pos.x + player1.size.x - player1.sizeOffset.x ,
			player1.pos.y + player1.size.y - player1.sizeOffset.y, 0xFFFFF, false);

	//�v���C���[�̓����蔻��g�\��
	DrawBox(player1.pos.x - player1.hitPosS.x , player1.pos.y - player1.hitPosS.y,
			player1.pos.x + player1.hitPosE.x , player1.pos.y + player1.hitPosE.y , 0xFFF000, false);

 		DrawGraph(player1.pos.x, player1.pos.y, kisiImage[5], true);

	// �v���C���[���W
	DrawFormatString(0, 32, 0xFFFFF, "player1.Pos(%d,%d)", player1.pos.x, player1.pos.y);
	DrawFormatString(0, 48, 0xFFFFF, "player1.moveSpeed(%d,)", player1.moveSpeed);

	// 2P
	// �v���C���[�g
	DrawBox(player2.pos.x - player2.sizeOffset.x, player2.pos.y - player2.sizeOffset.y,
		player2.pos.x + player2.size.x - player2.sizeOffset.x,
		player2.pos.y + player2.size.y - player2.sizeOffset.y, 0xFFFFF, false);

	//�v���C���[�̓����蔻��g�\��
	DrawBox(player2.pos.x - player2.hitPosS.x, player2.pos.y - player2.hitPosS.y,
		player2.pos.x + player2.hitPosE.x, player2.pos.y + player2.hitPosE.y, 0xFFFFF, false);

	DrawGraph(player2.pos.x, player2.pos.y, mahoImage[10], true);

	// �v���C���[���W
	DrawFormatString(500, 32, 0xFFFFF, "player2.Pos(%d,%d)", player2.pos.x, player2.pos.y);
	DrawFormatString(500, 48, 0xFFFFF, "player2.moveSpeed(%d,)", player2.moveSpeed);
}

void Player::SetPlayerID(Vector2 pos1,Vector2 pos2)
{
	pos1 = player1.pos;
	pos2 = player2.pos;
}

Player::Player(int charID_1, int ID_1, int charID_2, int ID_2)
{
	this->charID_1 = charID_1;
	this->charID_2 = charID_2;

	this->pID_1 = ID_1;
	this->pID_2 = ID_2;

	PlayerSysInit();
}

Player::Player()
{
	PlayerSysInit();
}

Player::~Player()
{

}

