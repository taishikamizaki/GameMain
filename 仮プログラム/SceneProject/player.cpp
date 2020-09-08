#include <DxLib.h>
#include "GetKeyState.h"
#include "skill.h"
#include "Stage.h"
#include "Vector2.h"
#include "player.h"

// 初期化
void Player::PlayerSysInit(void)
{
	Vector2 pos;									//キャラクタの位置（中心）
	
	player1.moveDir		 = DIR::DIR_ID_RIGHT;		// 向いている方向
	player1.size		 = { 96,64 };				// キャラクタ画像のサイズ
	player1.pos          = { 200,100 };
	player1.hitPosS		 = { 15,16 };				// 当たり判定用の左上
	player1.hitPosE		 = { 15,32 };				// 当たり判定用の右下
	player1.velocity	 = { 0.0f,0 };				// 加速度
	player1.sizeOffset.x = player1.size.x / 2;		// キャラクタ中央からの左上位置のX座標
	player1.sizeOffset.y = player1.size.y / 2;		// キャラクタ中央からの左上位置のY座標
	player1.runFlag		 = false;					// キャラクタの状態（走っているか？）
	player1.jumpFlag	 = false;					// キャラクタの状態（ジャンプしているか？）
	player1.shotFlag	 = false;					// キャラクタの状態（弾撃っているか？）
	player1.damageFlag	 = false;					// キャラクタの状態（ダメージ受けているか？）
	player1.surinukeFlag = false;					// 1部ブロックすり抜け用
	player1.moveSpeed	 = 0;						// キャラクタの移動量
	player1.animCnt		 = 0;						// キャラクタのアニメーション用カウンタ

	player2.moveDir		 = DIR::DIR_ID_LEFT;		// 向いている方向
	player2.size		 = { 96,64 };				// キャラクタ画像のサイズ
	player2.hitPosS		 = { 15,16 };				// 当たり判定用の左上
	player2.hitPosE		 = { 15,32 };				// 当たり判定用の右下
	player2.velocity	 = { 0.0f,0 };				// 加速度
	player2.sizeOffset.x = player1.size.x / 2;		// キャラクタ中央からの左上位置のX座標
	player2.sizeOffset.y = player1.size.y / 2;		// キャラクタ中央からの左上位置のY座標
	player2.runFlag      = false;					// キャラクタの状態（走っているか？）
	player2.jumpFlag     = false;					// キャラクタの状態（ジャンプしているか？）
	player2.shotFlag     = false;					// キャラクタの状態（弾撃っているか？）
	player2.damageFlag   = false;					// キャラクタの状態（ダメージ受けているか？）
	player2.surinukeFlag = false;				    // 1部ブロックすり抜け用
	player2.moveSpeed    = 0;						// キャラクタの移動量
	player2.animCnt      = 0;						// キャラクタのアニメーション用カウンタ

	LoadDivGraph("image/TestGraph/KISHI.png,", 12, 3, 4, 25, 33, kisiImage);
	LoadDivGraph("image/TestGraph/MAHO.png,", 12, 3, 4, 25, 33, mahoImage);
	LoadDivGraph("image/TestGraph/BUTOU.png,", 12, 3, 4, 25, 33, butoImage);
	LoadDivGraph("image/TestGraph/NAZO.png,", 12, 3, 4, 25, 33, nazoImage);

}

// ゲーム中の初期化
void Player::PlayerGameInit(void)
{
	
}

// ｺﾝﾄﾛｰﾙ
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

	//右
	if (keyNew[KEY_ID_RIGHT])
	{
		player1.runFlag = true;
	
		moveFlag1 = true;
		player1.moveDir = DIR::DIR_ID_RIGHT;
	}
	
	//左
	if (keyNew[KEY_ID_LEFT])
	{
		player1.runFlag = true;
	
		moveFlag1 = true;
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

	// 2P

	//右
	if (keyNew[KEY_ID_RIGHT])
	{
		player2.runFlag = true;

		moveFlag2 = true;
		player2.moveDir = DIR::DIR_ID_RIGHT;
	}

	//左
	if (keyNew[KEY_ID_LEFT])
	{
		player2.runFlag = true;

		moveFlag2 = true;
		player2.moveDir = DIR::DIR_ID_LEFT;
	}

	//ｼﾞｬﾝﾌﾟ判定
	if (player2.jumpFlag)
	{
		//重力による移動処理
		player2.velocity.fy -= ACC_G * FRAME_TIME;

		playerPosBK2.y -= player2.velocity.fy * FRAME_TIME;

		playerPosHit2.y = playerPosBK2.y - player2.hitPosS.y;
		playerPosHitLeft2 = playerPosHit2;
		playerPosHitLeft2.x -= player2.hitPosS.x;

		playerPosHitRight2 = playerPosHit2;
		playerPosHitRight2.x += player2.hitPosE.x;

		if (!lpStage.IsPass(playerPosHit2) || !lpStage.IsPass(playerPosHitRight2) || !lpStage.IsPass(playerPosHitLeft2))
		{
			//移動キャンセル
			Vector2	blockIndex2 = lpStage.PosToIndex(playerPosHit2);	//ブロックの配列座標
			blockIndex2.y = blockIndex2.y + 1;
			Vector2	blockPos2 = lpStage.IndexToPos(blockIndex2);		//ブロックの左上のピクセル座標

			playerPosBK2.y = blockPos2.y + player2.hitPosS.y;			//足元の座標からプレイヤーの座標を計算する
			player2.velocity.fy = 0;
		}

		//足元の計算
		playerPosHit2.y = playerPosBK2.y + player2.hitPosE.y;

		playerPosHitLeft2 = playerPosHit2;
		playerPosHitLeft2.x -= player2.hitPosS.x;

		playerPosHitRight2 = playerPosHit2;
		playerPosHitRight2.x += player2.hitPosE.x;

		//足元チェック
		if (lpStage.IsPass(playerPosHit2) && lpStage.IsPass(playerPosHitRight2) && lpStage.IsPass(playerPosHitLeft2))
		{
			//ブロックない時
			player2.pos.y = playerPosBK2.y;
		}
		else
		{
			//ブロックあるなら上に乗る
			Vector2	blockIndex2 = lpStage.PosToIndex(playerPosHit2);		//ブロックの配列座標
			Vector2	blockPos2 = lpStage.IndexToPos(blockIndex2);			//ブロックの左上のピクセル座標

			player2.pos.y = blockPos2.y - player2.hitPosE.y;				//足元の座標からプレイヤーの座標を計算する

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
				playerPosHitDown2.y += player2.hitPosE.y - 1;  //1は床の上に足を乗せるよう

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
				playerPosHitDown2.y += player2.hitPosE.y - 1;//1は床の上に足を乗せるよう


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

// 描画
void Player::PlayerDraw(void)
{

	// 1P
	// プレイヤー枠
	DrawBox(player1.pos.x - player1.sizeOffset.x , player1.pos.y - player1.sizeOffset.y ,
			player1.pos.x + player1.size.x - player1.sizeOffset.x ,
			player1.pos.y + player1.size.y - player1.sizeOffset.y, 0xFFFFF, false);

	//プレイヤーの当たり判定枠表示
	DrawBox(player1.pos.x - player1.hitPosS.x , player1.pos.y - player1.hitPosS.y,
			player1.pos.x + player1.hitPosE.x , player1.pos.y + player1.hitPosE.y , 0xFFF000, false);

 		DrawGraph(player1.pos.x, player1.pos.y, kisiImage[5], true);

	// プレイヤー座標
	DrawFormatString(0, 32, 0xFFFFF, "player1.Pos(%d,%d)", player1.pos.x, player1.pos.y);
	DrawFormatString(0, 48, 0xFFFFF, "player1.moveSpeed(%d,)", player1.moveSpeed);

	// 2P
	// プレイヤー枠
	DrawBox(player2.pos.x - player2.sizeOffset.x, player2.pos.y - player2.sizeOffset.y,
		player2.pos.x + player2.size.x - player2.sizeOffset.x,
		player2.pos.y + player2.size.y - player2.sizeOffset.y, 0xFFFFF, false);

	//プレイヤーの当たり判定枠表示
	DrawBox(player2.pos.x - player2.hitPosS.x, player2.pos.y - player2.hitPosS.y,
		player2.pos.x + player2.hitPosE.x, player2.pos.y + player2.hitPosE.y, 0xFFFFF, false);

	DrawGraph(player2.pos.x, player2.pos.y, mahoImage[10], true);

	// プレイヤー座標
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

