#include <DxLib.h>
#include "GetKeyState.h"
#include "Stage.h"
#include "player.h"

// ������
void Player::PlayerSysInit(void)
{
	Vector2 pos;									//�L�����N�^�̈ʒu�i���S�j
	
	player1.moveDir		 = DIR::DIR_ID_RIGHT;		// �����Ă������
	player1.size		 = { 96,64 };				// �L�����N�^�摜�̃T�C�Y
	player1.hitPosS		 = { 15,16 };				// �����蔻��p�̍���
	player1.hitPosE		 = { 15,32 };				// �����蔻��p�̉E��
	player1.velocity	 = { 0.0f,0 };				// �����x
	player1.sizeOffset.x = player1.size.x / 2 ;		// �L�����N�^��������̍���ʒu��X���W
	player1.sizeOffset.y = player1.size.y / 2;		// �L�����N�^��������̍���ʒu��Y���W
	player1.runFlag		 = false;					// �L�����N�^�̏�ԁi�����Ă��邩�H�j
	player1.jumpFlag	 = false;					// �L�����N�^�̏�ԁi�W�����v���Ă��邩�H�j
	player1.shotFlag	 = false;					// �L�����N�^�̏�ԁi�e�����Ă��邩�H�j
	player1.damageFlag	 = false;					// �L�����N�^�̏�ԁi�_���[�W�󂯂Ă��邩�H�j
	player1.surinukeFlag = false;					// 1���u���b�N���蔲���p
	player1.moveSpeed	 = 0;						// �L�����N�^�̈ړ���
	player1.life		 = 4;						// �L�����N�^�̗̑�
	player1.lifeMax		 = 4;						// �L�����N�^�̗͍̑ő�
	player1.animCnt		 = 0;						// �L�����N�^�̃A�j���[�V�����p�J�E���^
}

// �Q�[�����̏�����
void Player::PlayerGameInit(void)
{
	images.try_emplace("kisi",	  LoadGraph("image/char/charsel icon/�R�m�I��(����).png"));
	images.try_emplace("kisi_1p", LoadGraph("image/char/charsel icon/�R�m�I��(1p).png"));
	images.try_emplace("kisi_2p", LoadGraph("image/char/charsel icon/�R�m�I��(2p).png"));

	images.try_emplace("majo",	  LoadGraph("image/char/charsel icon/���@�g���I��(����).png"));
	images.try_emplace("majo_1p", LoadGraph("image/char/charsel icon/���@�g���I��(1p).png"));
	images.try_emplace("majo_2p", LoadGraph("image/char/charsel icon/���@�g���I��(2p).png"));

	images.try_emplace("buto",	  LoadGraph("image/char/charsel icon/�����ƑI��(����).png"));
	images.try_emplace("buto_1p", LoadGraph("image/char/charsel icon/�����ƑI��(1p).png"));
	images.try_emplace("buto_2p", LoadGraph("image/char/charsel icon/�����ƑI��(2p).png"));

	images.try_emplace("men",	 LoadGraph("image/char/charsel icon/��̒j�I��(����).png"));
	images.try_emplace("men_1p", LoadGraph("image/char/charsel icon/��̒j�I��(1p).png"));
	images.try_emplace("men_2p", LoadGraph("image/char/charsel icon/��̒j�I��(2p).png"));
}

// ���۰�
void Player::PlayerCtl(void)
{
	bool moveFlag = false;
	
	Vector2	playerPosBK       = player1.pos;
	Vector2	playerPosHit      = player1.pos;
	Vector2	playerPosHitLeft  = player1.pos;
	Vector2	playerPosHitRight = player1.pos;
	Vector2	playerPosHitUp    = player1.pos;
	Vector2	playerPosHitDown  = player1.pos;
	
	player1.moveSpeed = 0;
	player1.runFlag   = false;
	player1.shotFlag  = false;
	player1.jumpFlag  = true;
	
	//�E
	if (keyNew[KEY_ID_RIGHT])
	{
		player1.runFlag = true;
	
		moveFlag = true;
		player1.moveDir = DIR::DIR_ID_RIGHT;
	}
	
	//��
	if (keyNew[KEY_ID_LEFT])
	{
		player1.runFlag = true;
	
		moveFlag = true;
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
	
		if (moveFlag)
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
}

// �`��
void Player::PlayerDraw(void)
{
	// �v���C���[�g
	DrawBox(player1.pos.x - player1.sizeOffset.x , player1.pos.y - player1.sizeOffset.y ,
			player1.pos.x + player1.size.x - player1.sizeOffset.x ,
			player1.pos.y + player1.size.y - player1.sizeOffset.y, 0xFFFFF, false);

	//�v���C���[�̓����蔻��g�\��
	DrawBox(player1.pos.x - player1.hitPosS.x , player1.pos.y - player1.hitPosS.y,
			player1.pos.x + player1.hitPosE.x , player1.pos.y + player1.hitPosE.y , 0xFFFFF, false);

	// �v���C���[���W
	DrawFormatString(0, 32, 0xFFFFF, "player1.Pos(%d,%d)", player1.pos.x, player1.pos.y);
	DrawFormatString(0, 48, 0xFFFFF, "player1.moveSpeed(%d,)", player1.moveSpeed);
}

void Player::SetPlayerID(CHARACTER p1, CHARACTER p2)
{
	p1 = player1;
	p2 = player2;
}

Player::Player()
{
	PlayerSysInit();
}

Player::~Player()
{

}

