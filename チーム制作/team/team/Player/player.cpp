#include <DxLib.h>
#include "../Scene/SceneMng.h"
#include "../Key/GetKeyState.h"
#include "../Stage/Stage.h"
#include "player.h"

// 初期化
void Player::PlayerSysInit(void)
{
	Vector2 pos;									//キャラクタの位置（中心）
	
	player1.moveDir		 = DIR::DIR_ID_RIGHT;		// 向いている方向
	player1.size		 = { 96,64 };				// キャラクタ画像のサイズ
	player1.hitPosS		 = { 15,16 };				// 当たり判定用の左上
	player1.hitPosE		 = { 15,32 };				// 当たり判定用の右下
	player1.velocity	 = { 0.0f,0 };				// 加速度
	player1.sizeOffset.x = player1.size.x / 2 ;		// キャラクタ中央からの左上位置のX座標
	player1.sizeOffset.y = player1.size.y / 2;		// キャラクタ中央からの左上位置のY座標
	player1.runFlag		 = false;					// キャラクタの状態（走っているか？）
	player1.jumpFlag	 = false;					// キャラクタの状態（ジャンプしているか？）
	player1.shotFlag	 = false;					// キャラクタの状態（弾撃っているか？）
	player1.damageFlag	 = false;					// キャラクタの状態（ダメージ受けているか？）
	player1.surinukeFlag = false;					// 1部ブロックすり抜け用
	player1.moveSpeed	 = 0;						// キャラクタの移動量
	player1.life		 = 4;						// キャラクタの体力
	player1.lifeMax		 = 4;						// キャラクタの体力最大
	player1.animCnt		 = 0;						// キャラクタのアニメーション用カウンタ

	/*LoadDivGraph("./image/char/char_p_hero01.png", 12, 3, 4, 24, 33, kisi);
	LoadDivGraph("./image/char/char_p_hero01.png", 12, 3, 4, 24, 34, majo);
	LoadDivGraph("./image/char/char_p_f04.png", 12, 3, 4, 25, 33, buto);
	LoadDivGraph("./image/char/char_p_hero01.png", 12, 3, 4, 24, 34, men);*/

	int kishi[12];
	for (int i = 0; i < 12; i++)
	{
		kishi[i] = 0;
	}

	SCN_MNG.GetID_D("kishi", *"./image/char/char_p_hero01.png", 12, 3, 4, 24, 33, kishi);
}

// ゲーム中の初期化
void Player::PlayerGameInit(void)
{

}

// ｺﾝﾄﾛｰﾙ
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
	
	//右
	if (keyNew[KEY_ID_RIGHT])
	{
		player1.runFlag = true;
	
		moveFlag = true;
		player1.moveDir = DIR::DIR_ID_RIGHT;
	}
	
	//左
	if (keyNew[KEY_ID_LEFT])
	{
		player1.runFlag = true;
	
		moveFlag = true;
		player1.moveDir = DIR::DIR_ID_LEFT;
	}
	
	//ｼﾞｬﾝﾌﾟ判定
	if (player1.jumpFlag)
	{
		//重力による移動処理
		player1.velocity.fy -= ACC_G * FRAME_TIME;
	
		playerPosBK.y -= player1.velocity.fy * FRAME_TIME;
	
		playerPosHit.y = playerPosBK.y - player1.hitPosS.y;
		playerPosHitLeft = playerPosHit;
		playerPosHitLeft.x -= player1.hitPosS.x;
	
		playerPosHitRight = playerPosHit;
		playerPosHitRight.x += player1.hitPosE.x;
	
		if (!lpStage.IsPass(playerPosHit) || !lpStage.IsPass(playerPosHitRight) || !lpStage.IsPass(playerPosHitLeft))
		{
			//移動キャンセル
			Vector2	blockIndex = lpStage.PosToIndex(playerPosHit);	//ブロックの配列座標
			blockIndex.y = blockIndex.y + 1;
			Vector2	blockPos = lpStage.IndexToPos(blockIndex);		//ブロックの左上のピクセル座標
														
			playerPosBK.y = blockPos.y + player1.hitPosS.y;			//足元の座標からプレイヤーの座標を計算する
			player1.velocity.fy = 0;
		}
	
		//足元の計算
		playerPosHit.y = playerPosBK.y + player1.hitPosE.y;
	
		playerPosHitLeft = playerPosHit;
		playerPosHitLeft.x -= player1.hitPosS.x;
	
		playerPosHitRight = playerPosHit;
		playerPosHitRight.x += player1.hitPosE.x;
	
		//足元チェック
		if (lpStage.IsPass(playerPosHit) && lpStage.IsPass(playerPosHitRight) && lpStage.IsPass(playerPosHitLeft))
		{
			//ブロックない時
			player1.pos.y = playerPosBK.y;
		}
		else
		{
			//ブロックあるなら上に乗る
			Vector2	blockIndex = lpStage.PosToIndex(playerPosHit);		//ブロックの配列座標
			Vector2	blockPos = lpStage.IndexToPos(blockIndex);			//ブロックの左上のピクセル座標
														
			player1.pos.y = blockPos.y - player1.hitPosE.y;				//足元の座標からプレイヤーの座標を計算する
	
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
				playerPosHitDown.y += player1.hitPosE.y - 1;  //1は床の上に足を乗せるよう
	
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
				playerPosHitDown.y += player1.hitPosE.y - 1;//1は床の上に足を乗せるよう
	
	
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

// 描画
void Player::PlayerDraw(void)
{
	// プレイヤー枠
	DrawBox(player1.pos.x - player1.sizeOffset.x , player1.pos.y - player1.sizeOffset.y ,
			player1.pos.x + player1.size.x - player1.sizeOffset.x ,
			player1.pos.y + player1.size.y - player1.sizeOffset.y, 0xFFFFF, false);

	//プレイヤーの当たり判定枠表示
	DrawBox(player1.pos.x - player1.hitPosS.x , player1.pos.y - player1.hitPosS.y,
			player1.pos.x + player1.hitPosE.x , player1.pos.y + player1.hitPosE.y , 0xFFFFF, false);

	DrawGraph(player1.pos.x, player1.pos.y, charID_1, true);

	// プレイヤー座標
	DrawFormatString(0, 32, 0xFFFFF, "player1.Pos(%d,%d)", player1.pos.x, player1.pos.y);
	DrawFormatString(0, 48, 0xFFFFF, "player1.moveSpeed(%d,)", player1.moveSpeed);
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

