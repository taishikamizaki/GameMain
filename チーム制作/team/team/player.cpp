#include <DxLib.h>
#include "main.h"
#include "GetKeyState.h"
#include "Stage.h"
#include "player.h"

// 初期化
void Player::PlayerSysInit(void)
{
	lpPos;
	//player.moveDir = DIR_RIGHT;						//向いている方向
	Pos* pos;												//キャラクタの位置（中心）
	size = {96,64};										//キャラクタ画像のサイズ
	//player1.hitPosS = { 15,16 };						//当たり判定用の左上
	//player1.hitPosE = { 15,32 };						//当たり判定用の右下
	//player1.velocity = { 0.0f,0 };
	//player1.sizeOffset.x =  player1.size.x / 2 ;		//キャラクタ中央からの左上位置のX座標
	//player1.sizeOffset.y = player1.size.y / 2;			//キャラクタ中央からの左上位置のY座標
	runFlag = false;							//キャラクタの状態（走っているか？）
	jumpFlag = false;							//キャラクタの状態（ジャンプしているか？）
	shotFlag = false;							//キャラクタの状態（弾撃っているか？）
	damageFlag = false;							//キャラクタの状態（ダメージ受けているか？）
	surinukeFlag=false;							//1部ブロックすり抜け用
	moveSpeed=0;								//キャラクタの移動量
	life=4;										//キャラクタの体力
	lifeMax=4;									//キャラクタの体力最大
	animCnt=0;									//キャラクタのアニメーション用カウンタ
}

// ゲーム中の初期化
void Player::PlayerGameInit(void)
{
	
}

// ｺﾝﾄﾛｰﾙ
void Player::PlayerCtl(void)
{
	//	bool	moveFlag = false;
	//
	//	Pos	playerPosBK = player1.pos;
	//	Pos	playerPosHit = player1.pos;
	//	Pos	playerPosHitLeft = player1.pos;
	//	Pos	playerPosHitRight = player1.pos;
	//	Pos	playerPosHitUp = player1.pos;
	//	Pos	playerPosHitDown = player1.pos;
	//
	//	player1.moveSpeed = 0;
	//	player1.runFlag = false;
	//	player1.shotFlag = false;
	//	player1.jumpFlag = true;
	//
	//	// 右
	//	if (keyNew[KEY_ID_RIGHT])
	//	{
	//		player1.runFlag = true;
	//
	//		moveFlag = true;
	//		player1.moveDir = DIR_RIGHT;
	//	}
	//
	//	// 左
	//	if (keyNew[KEY_ID_LEFT])
	//	{
	//		player1.runFlag = true;
	//
	//		moveFlag = true;
	//		player1.moveDir = DIR_LEFT;
	//	}
	//
	//	// ｼﾞｬﾝﾌﾟ判定
	//	if (player1.jumpFlag)
	//	{
	//		//重力による移動処理
	//		player1.velocity.y -= ACC_G * FRAME_TIME;
	//
	//		playerPosBK.y -= player1.velocity.y*FRAME_TIME;
	//
	//
	//		playerPosHit.y = playerPosBK.y - player1.hitPosS.y;
	//		playerPosHitLeft = playerPosHit;
	//		playerPosHitLeft.x -= player1.hitPosS.x;
	//
	//		playerPosHitRight = playerPosHit;
	//		playerPosHitRight.x += player1.hitPosE.x;
	//
	//		if (!IsPass(playerPosHit) || !IsPass(playerPosHitRight) || !IsPass(playerPosHitLeft))
	//		{
	//			//移動キャンセル
	//			Pos	blockIndex = PosToIndex(playerPosHit);		//ブロックの配列座標
	//			blockIndex.y = blockIndex.y + 1;
	//			Pos	blockPos = IndexToPos(blockIndex);		//ブロックの左上のピクセル座標
	//														//足元の座標からプレイヤーの座標を計算する
	//			playerPosBK.y = blockPos.y + player1.hitPosS.y;
	//			player1.velocity.y = 0;
	//
	//		}
	//
	//		//足元の計算
	//		playerPosHit.y = playerPosBK.y + player1.hitPosE.y;
	//
	//		playerPosHitLeft = playerPosHit;
	//		playerPosHitLeft.x -= player1.hitPosS.x;
	//
	//		playerPosHitRight = playerPosHit;
	//		playerPosHitRight.x += player1.hitPosE.x;
	//
	//		//足元チェック
	//		if (IsPass(playerPosHit) && IsPass(playerPosHitRight) && IsPass(playerPosHitLeft))
	//		{
	//			//ブロックない時
	//			player1.pos.y = playerPosBK.y;
	//		}
	//		else
	//		{
	//			//ブロックあるなら上に乗る
	//
	//			//ジャンプ終了は足元の座標から位置を割り出す
	//			//足元の座標はplayerPosHit
	//			//PosIndex(playerPosHit)をすると自分が乗るブロックがわかる
	//			//そのブロックの上の面のY座標がプレイヤーの足元の座標
	//			//ブロックの上の面のY座標は？
	//			Pos	blockIndex = PosToIndex(playerPosHit);		//ブロックの配列座標
	//			Pos	blockPos = IndexToPos(blockIndex);		//ブロックの左上のピクセル座標
	//														//足元の座標からプレイヤーの座標を計算する
	//			player1.pos.y = blockPos.y - player1.hitPosE.y;
	//
	//			player1.jumpFlag = false;
	//			player1.velocity.y = 0;
	//
	//			if (player1.jumpFlag == false)
	//			{
	//				if (keyNew[KEY_ID_UP])
	//				{
	//					player1.jumpFlag = true;
	//					player1.velocity.y = INIT_VELOCITY;
	//					//player1.pos.y -= player1.moveSpeed;
	//
	//				}
	//			}
	//		}
	//
	//
	//		playerPosBK = player1.pos;
	//		playerPosHit = player1.pos;
	//
	//		if (moveFlag)
	//		{
	//			if (player1.moveDir == DIR_RIGHT)
	//			{
	//				player1.moveSpeed = P_DSP;
	//
	//				playerPosBK.x += player1.moveSpeed;
	//				playerPosHit.x = playerPosBK.x + player1.hitPosE.x;
	//
	//				playerPosHitUp = playerPosHit;
	//				playerPosHitUp.y -= player1.hitPosS.y;
	//
	//				playerPosHitDown = playerPosHit;
	//				playerPosHitDown.y += player1.hitPosE.y - 1;//1は床の上に足を乗せるよう
	//
	//				if (IsPass(playerPosHit) && IsPass(playerPosHitUp) && IsPass(playerPosHitDown))
	//				{
	//					player1.pos.x = playerPosBK.x;
	//				}
	//				else
	//				{
	//					player1.moveSpeed = 0;
	//				}
	//			}
	//			else if (player1.moveDir == DIR_LEFT)
	//			{
	//				player1.moveSpeed = P_DSP;
	//
	//				playerPosBK.x -= player1.moveSpeed;
	//				playerPosHit.x = playerPosBK.x - player1.hitPosS.x;
	//
	//				playerPosHitUp = playerPosHit;
	//				playerPosHitUp.y -= player1.hitPosS.y;
	//
	//				playerPosHitDown = playerPosHit;
	//				playerPosHitDown.y += player1.hitPosE.y - 1;//1は床の上に足を乗せるよう
	//
	//
	//				//if (player1.velocity.x < -6) { player1.velocity.x = -6; }
	//
	//
	//				if (IsPass(playerPosHit) && IsPass(playerPosHitUp) && IsPass(playerPosHitDown))
	//				{
	//					player1.pos.x = playerPosBK.x;
	//				}
	//				else
	//				{
	//					player1.moveSpeed = 0;
	//				}
	//			}
	//		}
	//
	//	
	//	}
}

// 描画
void Player::PlayerDraw(void)
{
	//// プレイヤー枠
	//DrawBox(player1.pos.x - player1.sizeOffset.x 
	//	, player1.pos.y - player1.sizeOffset.y 
	//	, player1.pos.x + player1.size.x - player1.sizeOffset.x 
	//	, player1.pos.y + player1.size.y - player1.sizeOffset.y
	//	, 0xFFFFF
	//	, false);

	////プレイヤーの当たり判定枠表示
	//DrawBox(player1.pos.x - player1.hitPosS.x 
	//	, player1.pos.y - player1.hitPosS.y
	//	, player1.pos.x + player1.hitPosE.x 
	//	, player1.pos.y + player1.hitPosE.y 
	//	, 0xFFFFF
	//	, false);

	//// プレイヤー座標
	//DrawFormatString(0, 32, 0xFFFFF, "player1.Pos(%d,%d)", player1.pos.x, player1.pos.y);
	//DrawFormatString(0, 48, 0xFFFFF, "player1.moveSpeed(%d,)", player1.moveSpeed);

}

Player::Player()
{

}

Player::~Player()
{

}