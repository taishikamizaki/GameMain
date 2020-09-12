#include <DxLib.h>
#include "../key/GetKeyState.h"
#include "../scene/Game.h"
#include "skill.h"
#include "../stage/Stage.h"
#include "../vector/Vector2.h"
#include "player.h"

// 初期化
void Player::PlayerSysInit(void)
{
	Vector2 pos;									//キャラクタの位置（中心）
	
	player1.moveDir		 = DIR::DIR_ID_RIGHT;		// 向いている方向
	player1.size		 = { 75,99 };				// キャラクタ画像のサイズ
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
	player1.nonFlag		 = false;
	player1.winFlag		 = false;
	player1.moveSpeed	 = 0;						// キャラクタの移動量
	player1.animCnt		 = 0;						// キャラクタのアニメーション用カウンタ
	player1.Hp			 = 0;						// キャラクターのHP
	player1.charID = CHAR_ID::CHAR_ID_MAX;

	player2.moveDir		 = DIR::DIR_ID_LEFT;		// 向いている方向
	player2.size		 = { 75,99 };				// キャラクタ画像のサイズ
	player2.pos          = { 500,100 };
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
	player2.nonFlag		 = false;
	player2.winFlag		 = false;
	player2.moveSpeed    = 0;						// キャラクタの移動量
	player2.animCnt      = 0;						// キャラクタのアニメーション用カウンタ
	player2.Hp			 = 0;						// キャラクターのHP
	player2.charID = CHAR_ID::CHAR_ID_MAX;

	HPsize = {4.4f,0};
	DrawFlag = false;
	GameOverFlag = false;
	charSelFlag = false;
	LoadDivGraph("image/player/KISHI.png", 12, 3, 4, 25, 33, kisiImage);
	LoadDivGraph("image/player/MAHO.png", 12, 3, 4, 25, 33, mahoImage);
	LoadDivGraph("image/player/BUTOU.png", 12, 3, 4, 25, 33, butoImage);
	LoadDivGraph("image/player/NAZO.png", 12, 3, 4, 25, 33, nazoImage);

	LoadDivGraph("image/player/KISHI_run1.png"
		, 4
		, 4, 1
		, 25, 33
		, kisiRunImage[DIR_RIGHT]
	);

	LoadDivGraph("image/player/KISHI_run2.png"
		, 4
		, 4, 1
		, 25, 33
		, kisiRunImage[DIR_LEFT]
	);

	LoadDivGraph("image/player/MAHO_run1.png"
		, 4
		, 4, 1
		, 25, 33
		, mahoRunImage[DIR_RIGHT]
	);

	LoadDivGraph("image/player/MAHO_run2.png"
		, 4
		, 4, 1
		, 25, 33
		, mahoRunImage[DIR_LEFT]
	);

	LoadDivGraph("image/player/BUTOU_run1.png"
		, 4
		, 4, 1
		, 25, 33
		, butoRunImage[DIR_RIGHT]
	);

	LoadDivGraph("image/player/BUTOU_run2.png"
		, 4
		, 4, 1
		, 25, 33
		, butoRunImage[DIR_LEFT]
	);

	LoadDivGraph("image/player/KISHI_run1.png"
		, 4
		, 4, 1
		, 25, 33
		, nazoRunImage[DIR_RIGHT]
	);

	LoadDivGraph("image/player/KISHI_run2.png"
		, 4
		, 4, 1
		, 25, 33
		, nazoRunImage[DIR_LEFT]
	);

	hp = LoadGraph("image/hp/bar.png");
	iconp1 = LoadGraph("image/serect/1P.png");
	iconp2 = LoadGraph("image/serect/2P.png");
	p1win = LoadGraph("image/logo/1p_win.png");
	p2win = LoadGraph("image/logo/2p_win.png");
	draw = LoadGraph("image/logo/Draw.png");

	if (skill == nullptr) skill = new Skill();

}
void Player::charCtl(CHAR_ID p1, CHAR_ID p2)
{
	player1.charID = p1;
	player2.charID = p2;
	if (skill != nullptr)
	{
		if ((player1.charID != CHAR_ID::CHAR_ID_MAX) &&
			  (player2.charID != CHAR_ID::CHAR_ID_MAX))
		{
			if (!charSelFlag)
			{
				skill->CharInit(player1.charID, player2.charID);
				charSelFlag = true;
			}
		}
	}
}
// ゲーム中の初期化
void Player::PlayerGameInit(void)
{
	if (skill != nullptr)
	{
		skill->PlayerInit(player1.pos, player1.hitPosS,
						 player1.hitPosE, player1.sizeOffset, player1.size, 
						 player2.pos, player2.hitPosS, 
						 player2.hitPosE, player2.sizeOffset, player2.size);

		skill->SpeedCtl(player1.moveSpeed,player2.moveSpeed);
		player1.Hp = skill->HPCtlP1();
		player2.Hp = skill->HPCtlP2();
		skill->Dir(player1.dirS, player2.dirS);
		skill->StageGameInit();
	}
}

// ｺﾝﾄﾛｰﾙ
void Player::PlayerCtl(STAGE_ID id)
{
	if (!GameOverFlag)
	{
		PlayerGameInit();
		HPmng();
		playerWin();
		bool moveFlag1 = false;
		bool moveFlag2 = false;

		Vector2	playerPosBK = player1.pos;
		Vector2	playerPosHit = player1.pos;
		Vector2	playerPosHitLeft = player1.pos;
		Vector2	playerPosHitRight = player1.pos;
		Vector2	playerPosHitUp = player1.pos;
		Vector2	playerPosHitDown = player1.pos;

		Vector2	playerPosBK2 = player2.pos;
		Vector2	playerPosHit2 = player2.pos;
		Vector2	playerPosHitLeft2 = player2.pos;
		Vector2	playerPosHitRight2 = player2.pos;
		Vector2	playerPosHitUp2 = player2.pos;
		Vector2	playerPosHitDown2 = player2.pos;

		player1.moveSpeed = 1;
		player1.runFlag = false;
		player1.shotFlag = false;
		player1.jumpFlag = true;

		player2.moveSpeed = 1;
		player2.runFlag = false;
		player2.shotFlag = false;
		player2.jumpFlag = true;

		// 1P

		//右
		if (keyNew[KEY_ID_RIGHT1] || keyNew[RIGHT1])
		{
			player1.runFlag = true;

			player1.pos.x += player1.moveSpeed;

			moveFlag1 = true;
			player1.moveDir = DIR::DIR_ID_RIGHT;
			if (player1.moveDir == DIR::DIR_ID_RIGHT)
			{
				player1.dirS = 0;
			}
		}

		//左
		if (keyNew[KEY_ID_LEFT1] || keyNew[LEFT1])
		{
			player1.runFlag = true;

			player1.pos.x -= player1.moveSpeed;

			moveFlag1 = true;
			player1.moveDir = DIR::DIR_ID_LEFT;
			if (player1.moveDir == DIR::DIR_ID_LEFT)
			{
				player1.dirS = 1;
			}
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

			
			if (id == STAGE_ID::STAGE_ID_YAMA)
			{
				if (!lpStage.IsPassY(playerPosHit) || !lpStage.IsPassY(playerPosHitRight) || !lpStage.IsPassY(playerPosHitLeft))
				{
					//移動キャンセル
					Vector2	blockIndex = lpStage.PosToIndex(playerPosHit);	//ブロックの配列座標
					blockIndex.y = blockIndex.y + 1;
					Vector2	blockPos = lpStage.IndexToPos(blockIndex);				//ブロックの左上のピクセル座標

					playerPosBK.y = blockPos.y + player1.hitPosS.y;						//足元の座標からプレイヤーの座標を計算する
					player1.velocity.fy = 0;
				}
			}
			if (id == STAGE_ID::STAGE_ID_MACHI)
			{
				if (!lpStage.IsPassM(playerPosHit) || !lpStage.IsPassM(playerPosHitRight) || !lpStage.IsPassM(playerPosHitLeft))
				{
					//移動キャンセル
					Vector2	blockIndex = lpStage.PosToIndex(playerPosHit);	//ブロックの配列座標
					blockIndex.y = blockIndex.y + 1;
					Vector2	blockPos = lpStage.IndexToPos(blockIndex);				//ブロックの左上のピクセル座標

					playerPosBK.y = blockPos.y + player1.hitPosS.y;						//足元の座標からプレイヤーの座標を計算する
					player1.velocity.fy = 0;
				}

			}
			if (id == STAGE_ID::STAGE_ID_COLOSSEUM)
			{
				if (!lpStage.IsPassT(playerPosHit) || !lpStage.IsPassT(playerPosHitRight) || !lpStage.IsPassT(playerPosHitLeft))
				{
					//移動キャンセル
					Vector2	blockIndex = lpStage.PosToIndex(playerPosHit);	//ブロックの配列座標
					blockIndex.y = blockIndex.y + 1;
					Vector2	blockPos = lpStage.IndexToPos(blockIndex);				//ブロックの左上のピクセル座標

					playerPosBK.y = blockPos.y + player1.hitPosS.y;						//足元の座標からプレイヤーの座標を計算する
					player1.velocity.fy = 0;
				}
			}



			//足元の計算
			playerPosHit.y = playerPosBK.y + player1.hitPosE.y;

			playerPosHitLeft = playerPosHit;
			playerPosHitLeft.x -= player1.hitPosS.x;

			playerPosHitRight = playerPosHit;
			playerPosHitRight.x += player1.hitPosE.x;

			if (id == STAGE_ID::STAGE_ID_YAMA)
			{
				//足元チェック
				if (lpStage.IsPassY(playerPosHit) && lpStage.IsPassY(playerPosHitRight) && lpStage.IsPassY(playerPosHitLeft))
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
						if (keyNew[KEY_ID_JUMP1] || keyNew[JUMP1])
						{
							player1.jumpFlag = true;
							player1.velocity.fy = INIT_VELOCITY;
							player1.pos.y -= player1.moveSpeed;
						}
					}
				}
			}
			if (id == STAGE_ID::STAGE_ID_MACHI)
			{
				if (lpStage.IsPassM(playerPosHit) && lpStage.IsPassM(playerPosHitRight) && lpStage.IsPassM(playerPosHitLeft))
				{
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
						if (keyNew[KEY_ID_JUMP1] || keyNew[JUMP1])
						{
							player1.jumpFlag = true;
							player1.velocity.fy = INIT_VELOCITY;
							player1.pos.y -= player1.moveSpeed;
						}
					}
				}
			}
			if (id == STAGE_ID::STAGE_ID_COLOSSEUM)
			{
				if (lpStage.IsPassT(playerPosHit) && lpStage.IsPassT(playerPosHitRight) && lpStage.IsPassT(playerPosHitLeft))
				{
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
						if (keyNew[KEY_ID_JUMP1] || keyNew[JUMP1])
						{
							player1.jumpFlag = true;
							player1.velocity.fy = INIT_VELOCITY;
							player1.pos.y -= player1.moveSpeed;
						}
					}
				}
			}
			playerPosBK = player1.pos;
			playerPosHit = player1.pos;

			if (moveFlag1)
			{
				if (player1.moveDir == DIR::DIR_ID_RIGHT)
				{
					player1.moveSpeed = P_DSP;

					if ((player1.pos.x + player1.hitPosE.x) < screen_size.x - 1)
					{
						playerPosBK.x += player1.moveSpeed;
					}
					
					playerPosHit.x = playerPosBK.x + player1.hitPosE.x;

					playerPosHitUp = playerPosHit;
					playerPosHitUp.y -= player1.hitPosS.y;

					playerPosHitDown = playerPosHit;
					playerPosHitDown.y += player1.hitPosE.y - 1;  //1は床の上に足を乗せるよう

					if (id == STAGE_ID::STAGE_ID_YAMA)
					{
						if (lpStage.IsPassY(playerPosHit) && lpStage.IsPassY(playerPosHitUp) && lpStage.IsPassY(playerPosHitDown))
						{
							player1.pos.x = playerPosBK.x;
						}
						else
						{
							player1.moveSpeed = 0;
						}
					}
					if (id == STAGE_ID::STAGE_ID_MACHI)
					{
						if (lpStage.IsPassM(playerPosHit) && lpStage.IsPassM(playerPosHitUp) && lpStage.IsPassM(playerPosHitDown))
						{
							player1.pos.x = playerPosBK.x;
						}
						else
						{
							player1.moveSpeed = 0;
						}
					}
					if (id == STAGE_ID::STAGE_ID_COLOSSEUM)
					{
						if (lpStage.IsPassT(playerPosHit) && lpStage.IsPassT(playerPosHitUp) && lpStage.IsPassT(playerPosHitDown))
						{
							player1.pos.x = playerPosBK.x;
						}
						else
						{
							player1.moveSpeed = 0;
						}
					}
				}
				else if (player1.moveDir == DIR::DIR_ID_LEFT)
				{
					player1.moveSpeed = P_DSP;

					if ((player1.pos.x - player1.hitPosS.x) > 1)
					{
						playerPosBK.x -= player1.moveSpeed;
					}
					playerPosHit.x = playerPosBK.x - player1.hitPosS.x;

					playerPosHitUp = playerPosHit;
					playerPosHitUp.y -= player1.hitPosS.y;

					playerPosHitDown = playerPosHit;
					playerPosHitDown.y += player1.hitPosE.y - 1;//1は床の上に足を乗せるよう


					if (player1.velocity.fx < -6) { player1.velocity.fx = -6; }


					if (id == STAGE_ID::STAGE_ID_YAMA)
					{
						if (lpStage.IsPassY(playerPosHit) && lpStage.IsPassY(playerPosHitUp) && lpStage.IsPassY(playerPosHitDown))
						{
							player1.pos.x = playerPosBK.x;
						}
						else
						{
							player1.moveSpeed = 0;
						}
					}
					if (id == STAGE_ID::STAGE_ID_MACHI)
					{
						if (lpStage.IsPassM(playerPosHit) && lpStage.IsPassM(playerPosHitUp) && lpStage.IsPassM(playerPosHitDown))
						{
							player1.pos.x = playerPosBK.x;
						}
						else
						{
							player1.moveSpeed = 0;
						}
					}
					if (id == STAGE_ID::STAGE_ID_COLOSSEUM)
					{
						if (lpStage.IsPassT(playerPosHit) && lpStage.IsPassT(playerPosHitUp) && lpStage.IsPassT(playerPosHitDown))
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

		// 2P

		//右
		if (keyNew[KEY_ID_RIGHT2] || keyNew[RIGHT2])
		{
			player2.runFlag = true;

			player2.pos.x += player2.moveSpeed;

			moveFlag2 = true;
			player2.moveDir = DIR::DIR_ID_RIGHT;
			if (player2.moveDir == DIR::DIR_ID_RIGHT)
			{
				player2.dirS = 0;
			}
		}

		//左
		if (keyNew[KEY_ID_LEFT2] || keyNew[LEFT2])
		{
			player2.runFlag = true;

			player2.pos.x -= player2.moveSpeed;

			moveFlag2 = true;
			player2.moveDir = DIR::DIR_ID_LEFT;
			if (player2.moveDir == DIR::DIR_ID_LEFT)
			{
				player2.dirS = 1;
			}
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

			if (id == STAGE_ID::STAGE_ID_YAMA)
			{
				if (!lpStage.IsPassY(playerPosHit2) || !lpStage.IsPassY(playerPosHitRight2) || !lpStage.IsPassY(playerPosHitLeft2))
				{
					//移動キャンセル
					Vector2	blockIndex2 = lpStage.PosToIndex(playerPosHit2);	//ブロックの配列座標
					blockIndex2.y = blockIndex2.y + 1;
					Vector2	blockPos2 = lpStage.IndexToPos(blockIndex2);		   //ブロックの左上のピクセル座標

					playerPosBK2.y = blockPos2.y + player2.hitPosS.y;					   //足元の座標からプレイヤーの座標を計算する
					player2.velocity.fy = 0;
				}
			}
			if (id == STAGE_ID::STAGE_ID_MACHI)
			{
				if (!lpStage.IsPassM(playerPosHit2) || !lpStage.IsPassM(playerPosHitRight2) || !lpStage.IsPassM(playerPosHitLeft2))
				{
					// 移動キャンセル
					Vector2	blockIndex2 = lpStage.PosToIndex(playerPosHit2);	//ブロックの配列座標
					blockIndex2.y = blockIndex2.y + 1;
					Vector2	blockPos2 = lpStage.IndexToPos(blockIndex2);		   //ブロックの左上のピクセル座標

					playerPosBK2.y = blockPos2.y + player2.hitPosS.y;					   //足元の座標からプレイヤーの座標を計算する
					player2.velocity.fy = 0;
				}
			}
			if (id == STAGE_ID::STAGE_ID_COLOSSEUM)
			{
				if (!lpStage.IsPassT(playerPosHit2) || !lpStage.IsPassT(playerPosHitRight2) || !lpStage.IsPassT(playerPosHitLeft2))
				{
					// 移動キャンセル
					Vector2	blockIndex2 = lpStage.PosToIndex(playerPosHit2);	//ブロックの配列座標
					blockIndex2.y = blockIndex2.y + 1;
					Vector2	blockPos2 = lpStage.IndexToPos(blockIndex2);		   //ブロックの左上のピクセル座標

					playerPosBK2.y = blockPos2.y + player2.hitPosS.y;					   //足元の座標からプレイヤーの座標を計算する
					player2.velocity.fy = 0;
				}
			}
			//足元の計算
			playerPosHit2.y = playerPosBK2.y + player2.hitPosE.y;

			playerPosHitLeft2 = playerPosHit2;
			playerPosHitLeft2.x -= player2.hitPosS.x;

			playerPosHitRight2 = playerPosHit2;
			playerPosHitRight2.x += player2.hitPosE.x;

			if (id == STAGE_ID::STAGE_ID_YAMA)
			{
				//足元チェック
				if (lpStage.IsPassY(playerPosHit2) && lpStage.IsPassY(playerPosHitRight2) && lpStage.IsPassY(playerPosHitLeft2))
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
						if (keyNew[KEY_ID_JUMP2] || keyNew[JUMP2])
						{
							player2.jumpFlag = true;
							player2.velocity.fy = INIT_VELOCITY;
							player2.pos.y -= player2.moveSpeed;
						}
					}
				}
			}
			if (id == STAGE_ID::STAGE_ID_MACHI)
			{
				if (lpStage.IsPassM(playerPosHit2) && lpStage.IsPassM(playerPosHitRight2) && lpStage.IsPassM(playerPosHitLeft2))
				{
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
						if (keyNew[KEY_ID_JUMP2] || keyNew[JUMP2])
						{
							player2.jumpFlag = true;
							player2.velocity.fy = INIT_VELOCITY;
							player2.pos.y -= player2.moveSpeed;
						}
					}
				}
			}
			if (id == STAGE_ID::STAGE_ID_COLOSSEUM)
			{
				if (lpStage.IsPassT(playerPosHit2) && lpStage.IsPassT(playerPosHitRight2) && lpStage.IsPassT(playerPosHitLeft2))
				{
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
						if (keyNew[KEY_ID_JUMP2] || keyNew[JUMP2])
						{
							player2.jumpFlag = true;
							player2.velocity.fy = INIT_VELOCITY;
							player2.pos.y -= player2.moveSpeed;
						}
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

					if ((player2.pos.x + player2.hitPosE.x) < screen_size.x - 1)
					{
						playerPosBK2.x += player2.moveSpeed;
					}
					playerPosHit2.x = playerPosBK2.x + player2.hitPosE.x;

					playerPosHitUp2 = playerPosHit2;
					playerPosHitUp2.y -= player2.hitPosS.y;

					playerPosHitDown2 = playerPosHit2;
					playerPosHitDown2.y += player2.hitPosE.y - 1;  //1は床の上に足を乗せるよう

					if (id == STAGE_ID::STAGE_ID_YAMA)
					{
						if (lpStage.IsPassY(playerPosHit2) && lpStage.IsPassY(playerPosHitUp2) && lpStage.IsPassY(playerPosHitDown2))
						{
							player2.pos.x = playerPosBK2.x;
						}
						else
						{
							player2.moveSpeed = 0;
						}
					}
					if (id == STAGE_ID::STAGE_ID_MACHI)
					{
						if (lpStage.IsPassM(playerPosHit2) && lpStage.IsPassM(playerPosHitUp2) && lpStage.IsPassM(playerPosHitDown2))
						{
							player2.pos.x = playerPosBK2.x;
						}
						else
						{
							player2.moveSpeed = 0;
						}
					}
					if (id == STAGE_ID::STAGE_ID_COLOSSEUM)
					{
						if (lpStage.IsPassT(playerPosHit2) && lpStage.IsPassT(playerPosHitUp2) && lpStage.IsPassT(playerPosHitDown2))
						{
							player2.pos.x = playerPosBK2.x;
						}
						else
						{
							player2.moveSpeed = 0;
						}
					}
					
				}
				else if (player2.moveDir == DIR::DIR_ID_LEFT)
				{
					player2.moveSpeed = P_DSP;
					if ((player2.pos.x - player2.hitPosS.x) > 1)
					{
						playerPosBK2.x -= player2.moveSpeed;
					}
					playerPosHit2.x = playerPosBK2.x - player2.hitPosS.x;

					playerPosHitUp2 = playerPosHit2;
					playerPosHitUp2.y -= player2.hitPosS.y;

					playerPosHitDown2 = playerPosHit2;
					playerPosHitDown2.y += player2.hitPosE.y - 1;//1は床の上に足を乗せるよう


					if (player2.velocity.fx < -6) { player2.velocity.fx = -6; }

					if (id == STAGE_ID::STAGE_ID_YAMA)
					{
						if (lpStage.IsPassY(playerPosHit2) && lpStage.IsPassY(playerPosHitUp2) && lpStage.IsPassY(playerPosHitDown2))
						{
							player2.pos.x = playerPosBK2.x;
						}
						else
						{
							player2.moveSpeed = 0;
						}
					}
					if (id == STAGE_ID::STAGE_ID_MACHI)
					{
						if (lpStage.IsPassM(playerPosHit2) && lpStage.IsPassM(playerPosHitUp2) && lpStage.IsPassM(playerPosHitDown2))
						{
							player2.pos.x = playerPosBK2.x;
						}
						else
						{
							player2.moveSpeed = 0;
						}
					}
					if (id == STAGE_ID::STAGE_ID_COLOSSEUM)
					{
						if (lpStage.IsPassT(playerPosHit2) && lpStage.IsPassT(playerPosHitUp2) && lpStage.IsPassT(playerPosHitDown2))
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

		player1.animCnt++;
		player2.animCnt++;

		skill->SkillCtl(player1.charID, player2.charID);
		skill->DmageCtl(player1.pos,player2.pos);
		skill->SpeedCtl(player1.moveSpeed, player2.moveSpeed);
	}
}
// 描画
void Player::PlayerDraw(void)
{
	if (!GameOverFlag)
	{
		// 1P
		// プレイヤー枠
		DxLib::DrawBox(player1.pos.x - player1.sizeOffset.x, player1.pos.y - player1.sizeOffset.y,
			player1.pos.x + player1.size.x - player1.sizeOffset.x,
			player1.pos.y + player1.size.y - player1.sizeOffset.y, 0xFFFFF, false);

		//プレイヤーの当たり判定枠表示
		DxLib::DrawBox(player1.pos.x - player1.hitPosS.x, player1.pos.y - player1.hitPosS.y,
			player1.pos.x + player1.hitPosE.x, player1.pos.y + player1.hitPosE.y, 0xFFF000, false);

		switch (player1.charID)
		{
		case CHAR_ID::CHAR_ID_KISI:
			if (player1.moveDir == DIR::DIR_ID_RIGHT)
			{
				if (player1.runFlag)
				{
					DrawExtendGraph(player1.pos.x - (player1.size.x / 2), player1.pos.y - (player1.size.y / 2),
						player1.pos.x + (player1.size.x / 2), player1.pos.y + (player1.size.y / 2), kisiRunImage[DIR_RIGHT][((player1.animCnt / 20) % 10) / 3], true);
				}
				else
				{
					DrawExtendGraph(player1.pos.x - (player1.size.x / 2), player1.pos.y - (player1.size.y / 2),
						player1.pos.x + (player1.size.x / 2), player1.pos.y + (player1.size.y / 2), kisiImage[5], true);
				}
			}
			else if (player1.moveDir == DIR::DIR_ID_LEFT)
			{
				if (player1.runFlag)
				{
					DrawExtendGraph(player1.pos.x - (player1.size.x / 2), player1.pos.y - (player1.size.y / 2),
						player1.pos.x + (player1.size.x / 2), player1.pos.y + (player1.size.y / 2), kisiRunImage[DIR_LEFT][((player1.animCnt / 20) % 10) / 3], true);
				}
				else
				{
					DrawExtendGraph(player1.pos.x - (player1.size.x / 2), player1.pos.y - (player1.size.y / 2),
						player1.pos.x + (player1.size.x / 2), player1.pos.y + (player1.size.y / 2), kisiImage[11], true);
				}
			}
			break;

		case CHAR_ID::CHAR_ID_MDOU:
			if (player1.moveDir == DIR::DIR_ID_RIGHT)
			{
				if (player1.runFlag)
				{
					DrawExtendGraph(player1.pos.x - (player1.size.x / 2), player1.pos.y - (player1.size.y / 2),
						player1.pos.x + (player1.size.x / 2), player1.pos.y + (player1.size.y / 2), mahoRunImage[DIR_RIGHT][((player1.animCnt / 20) % 10) / 3], true);
				}
				else
				{
					DrawExtendGraph(player1.pos.x - (player1.size.x / 2), player1.pos.y - (player1.size.y / 2),
						player1.pos.x + (player1.size.x / 2), player1.pos.y + (player1.size.y / 2), mahoImage[5], true);
				}
			}
			else if (player1.moveDir == DIR::DIR_ID_LEFT)
			{
				if (player1.runFlag)
				{
					DrawExtendGraph(player1.pos.x - (player1.size.x / 2), player1.pos.y - (player1.size.y / 2),
						player1.pos.x + (player1.size.x / 2), player1.pos.y + (player1.size.y / 2), mahoRunImage[DIR_LEFT][((player1.animCnt / 20) % 10) / 3], true);
				}
				else
				{
					DrawExtendGraph(player1.pos.x - (player1.size.x / 2), player1.pos.y - (player1.size.y / 2),
						player1.pos.x + (player1.size.x / 2), player1.pos.y + (player1.size.y / 2), mahoImage[11], true);
				}
			}
			break;

		case CHAR_ID::CHAR_ID_BTOU:
			if (player1.moveDir == DIR::DIR_ID_RIGHT)
			{
				if (player1.runFlag)
				{
					DrawExtendGraph(player1.pos.x - (player1.size.x / 2), player1.pos.y - (player1.size.y / 2),
						player1.pos.x + (player1.size.x / 2), player1.pos.y + (player1.size.y / 2), butoRunImage[DIR_RIGHT][((player1.animCnt / 20) % 10) / 3], true);
				}
				else
				{
					DrawExtendGraph(player1.pos.x - (player1.size.x / 2), player1.pos.y - (player1.size.y / 2),
						player1.pos.x + (player1.size.x / 2), player1.pos.y + (player1.size.y / 2), butoImage[5], true);
				}
			}
			else if (player1.moveDir == DIR::DIR_ID_LEFT)
			{
				if (player1.runFlag)
				{
					DrawExtendGraph(player1.pos.x - (player1.size.x / 2), player1.pos.y - (player1.size.y / 2),
						player1.pos.x + (player1.size.x / 2), player1.pos.y + (player1.size.y / 2), butoRunImage[DIR_LEFT][((player1.animCnt / 20) % 10) / 3], true);
				}
				else
				{
					DrawExtendGraph(player1.pos.x - (player1.size.x / 2), player1.pos.y - (player1.size.y / 2),
						player1.pos.x + (player1.size.x / 2), player1.pos.y + (player1.size.y / 2), butoImage[11], true);
				}
			}
			break;

		case CHAR_ID::CHAR_ID_4:
			if (player1.moveDir == DIR::DIR_ID_RIGHT)
			{
				DrawExtendGraph(player1.pos.x - (player1.size.x / 2), player1.pos.y - (player1.size.y / 2),
					player1.pos.x + (player1.size.x / 2), player1.pos.y + (player1.size.y / 2), nazoImage[5], true);
			}
			else if (player1.moveDir == DIR::DIR_ID_LEFT)
			{
				DrawExtendGraph(player1.pos.x - (player1.size.x / 2), player1.pos.y - (player1.size.y / 2),
					player1.pos.x + (player1.size.x / 2), player1.pos.y + (player1.size.y / 2), nazoImage[11], true);
			}
			break;
		default:
			break;
		}

		// プレイヤー座標
		DxLib::DrawFormatString(10, 32, 0xff0000, "player1.Pos(%d,%d)", player1.pos.x, player1.pos.y);
		DxLib::DrawFormatString(10, 48, 0xff0000, "player1.moveSpeed(%d,)", player1.moveSpeed);
		DxLib::DrawFormatString(10, 60, 0xff0000, "player1.id(%d)", player1.charID);

		// 2P
		// プレイヤー枠
		DxLib::DrawBox(player2.pos.x - player2.sizeOffset.x, player2.pos.y - player2.sizeOffset.y,
			player2.pos.x + player2.size.x - player2.sizeOffset.x,
			player2.pos.y + player2.size.y - player2.sizeOffset.y, 0xFFFFF, false);

		//プレイヤーの当たり判定枠表示
		DxLib::DrawBox(player2.pos.x - player2.hitPosS.x, player2.pos.y - player2.hitPosS.y,
			player2.pos.x + player2.hitPosE.x, player2.pos.y + player2.hitPosE.y, 0xFFFFF, false);

		switch (player2.charID)
		{
		case CHAR_ID::CHAR_ID_KISI:
			if (player2.moveDir == DIR::DIR_ID_RIGHT)
			{
				if (player2.runFlag)
				{
					DrawExtendGraph(player2.pos.x - (player2.size.x / 2), player2.pos.y - (player2.size.y / 2),
						player2.pos.x + (player2.size.x / 2), player2.pos.y + (player2.size.y / 2), kisiRunImage[DIR_RIGHT][((player2.animCnt / 20) % 10) / 3], true);
				}
				else
				{
					DrawExtendGraph(player2.pos.x - (player2.size.x / 2), player2.pos.y - (player2.size.y / 2),
						player2.pos.x + (player2.size.x / 2), player2.pos.y + (player2.size.y / 2), kisiImage[5], true);
				}
			}
			else if (player2.moveDir == DIR::DIR_ID_LEFT)
			{
				if (player2.runFlag)
				{
					DrawExtendGraph(player2.pos.x - (player2.size.x / 2), player2.pos.y - (player2.size.y / 2),
						player2.pos.x + (player2.size.x / 2), player2.pos.y + (player2.size.y / 2), kisiRunImage[DIR_LEFT][((player2.animCnt / 20) % 10) / 3], true);
				}
				else
				{
					DrawExtendGraph(player2.pos.x - (player2.size.x / 2), player2.pos.y - (player2.size.y / 2),
						player2.pos.x + (player2.size.x / 2), player2.pos.y + (player2.size.y / 2), kisiImage[11], true);
				}
			}
			break;

		case CHAR_ID::CHAR_ID_MDOU:
			if (player2.moveDir == DIR::DIR_ID_RIGHT)
			{
				if (player2.runFlag)
				{
					DrawExtendGraph(player2.pos.x - (player2.size.x / 2), player2.pos.y - (player2.size.y / 2),
						player2.pos.x + (player2.size.x / 2), player2.pos.y + (player2.size.y / 2), mahoRunImage[DIR_RIGHT][((player2.animCnt / 20) % 10) / 3], true);
				}
				else
				{
					DrawExtendGraph(player2.pos.x - (player2.size.x / 2), player2.pos.y - (player2.size.y / 2),
						player2.pos.x + (player2.size.x / 2), player2.pos.y + (player2.size.y / 2), mahoImage[5], true);
				}
			}
			else if (player2.moveDir == DIR::DIR_ID_LEFT)
			{
				if (player2.runFlag)
				{
					DrawExtendGraph(player2.pos.x - (player2.size.x / 2), player2.pos.y - (player2.size.y / 2),
						player2.pos.x + (player2.size.x / 2), player2.pos.y + (player2.size.y / 2), mahoRunImage[DIR_LEFT][((player2.animCnt / 20) % 10) / 3], true);
				}
				else
				{
					DrawExtendGraph(player2.pos.x - (player2.size.x / 2), player2.pos.y - (player2.size.y / 2),
						player2.pos.x + (player2.size.x / 2), player2.pos.y + (player2.size.y / 2), mahoImage[11], true);
				}
			}
			break;

		case CHAR_ID::CHAR_ID_BTOU:
			if (player2.moveDir == DIR::DIR_ID_RIGHT)
			{
				if (player2.runFlag)
				{
					DrawExtendGraph(player2.pos.x - (player2.size.x / 2), player2.pos.y - (player2.size.y / 2),
						player2.pos.x + (player2.size.x / 2), player2.pos.y + (player2.size.y / 2), butoRunImage[DIR_RIGHT][((player2.animCnt / 20) % 10) / 3], true);
				}
				else
				{
					DrawExtendGraph(player2.pos.x - (player2.size.x / 2), player2.pos.y - (player2.size.y / 2),
						player2.pos.x + (player2.size.x / 2), player2.pos.y + (player2.size.y / 2), butoImage[5], true);
				}
			}
			else if (player2.moveDir == DIR::DIR_ID_LEFT)
			{
				if (player2.runFlag)
				{
					DrawExtendGraph(player2.pos.x - (player2.size.x / 2), player2.pos.y - (player2.size.y / 2),
						player2.pos.x + (player2.size.x / 2), player2.pos.y + (player2.size.y / 2), butoRunImage[DIR_LEFT][((player2.animCnt / 20) % 10) / 3], true);
				}
				else
				{
					DrawExtendGraph(player2.pos.x - (player2.size.x / 2), player2.pos.y - (player2.size.y / 2),
						player2.pos.x + (player2.size.x / 2), player2.pos.y + (player2.size.y / 2), butoImage[11], true);
				}
			}
			break;

		case CHAR_ID::CHAR_ID_4:
			if (player2.moveDir == DIR::DIR_ID_RIGHT)
			{
				if (player2.runFlag)
				{
					DrawExtendGraph(player2.pos.x - (player2.size.x / 2), player2.pos.y - (player2.size.y / 2),
						player2.pos.x + (player2.size.x / 2), player2.pos.y + (player2.size.y / 2), nazoRunImage[DIR_RIGHT][((player2.animCnt / 20) % 10) / 3], true);
				}
				else
				{
					DrawExtendGraph(player2.pos.x - (player2.size.x / 2), player2.pos.y - (player2.size.y / 2),
						player2.pos.x + (player2.size.x / 2), player2.pos.y + (player2.size.y / 2), nazoImage[5], true);
				}
			}
			else if (player2.moveDir == DIR::DIR_ID_LEFT)
			{
				if (player2.runFlag)
				{
					DrawExtendGraph(player2.pos.x - (player2.size.x / 2), player2.pos.y - (player2.size.y / 2),
						player2.pos.x + (player2.size.x / 2), player2.pos.y + (player2.size.y / 2), nazoRunImage[DIR_LEFT][((player2.animCnt / 20) % 10) / 3], true);
				}
				else
				{
					DrawExtendGraph(player2.pos.x - (player2.size.x / 2), player2.pos.y - (player2.size.y / 2),
						player2.pos.x + (player2.size.x / 2), player2.pos.y + (player2.size.y / 2), nazoImage[11], true);
				}
			}
			break;
		default:
			break;
		}
		// プレイヤー座標
		DxLib::DrawFormatString(800, 32, 0xff0000, "player2.Pos(%d,%d)", player2.pos.x, player2.pos.y);
		DxLib::DrawFormatString(800, 48, 0xff0000, "player2.moveSpeed(%d,)", player2.moveSpeed);
		DxLib::DrawFormatString(800, 60, 0xff0000, "player2.id(%d)", player2.charID);
	}
	DxLib::DrawBox(0,0,1000,60,0xcc9966,true);
	DxLib::DrawBox(40, 14, 480, 60, 0x000000, true);
	DxLib::DrawBox(520, 14, 960, 60, 0x000000, true);
	for (int x = player1.Hp; x > 0; x--)
	{
		DxLib::DrawBox(35+x*HPsize.fx, 14, 35+(x+1)*HPsize.fx, 60, 0x33ff66, true);
	}
	for (int x = 0; x < player1.Hp; x++)
	{
		DxLib::DrawBox(520+x*HPsize.fx, 14, 520+(x+1)*HPsize.fx, 60, 0x33ff66, true);
	}
	DxLib::DrawGraph(500,0,hp,true);
	DxLib::DrawTurnGraph(0,0,hp,true);

	if (player1.winFlag)
	{
		DrawGraph(200,100,p1win,true);
	}
	if (player2.winFlag)
	{
		DrawGraph(200, 100, p2win, true);
	}
	if (DrawFlag)
	{
		DrawGraph(350,100,draw,true);
	}

	if (skill != nullptr)
	{
		skill->StageDraw(player1.charID,player2.charID);
	}
}

void Player::SetPlayerID(Vector2 pos1,Vector2 pos2)
{
	pos1 = player1.pos;
	pos2 = player2.pos;
}

bool Player::HPmng(void)
{
	if(player1.Hp<=0)
	{
		player1.nonFlag = true;
		return true;
	}
	else
	{
		player1.nonFlag = false;
	}
	if(player2.Hp<=0)
	{
		player2.nonFlag = true;
		return true;
	}
	else
	{
		player2.nonFlag = false;
	}
	if((player1.Hp<=0)&&(player2.Hp<=0))
	{
		DrawFlag = true;
		return true;
	}
	else
	{
		DrawFlag = false;
	}

	return false;
}

bool Player::playerWin(void)
{
	if (player1.nonFlag)
	{
		GameOverFlag = true;
		player2.winFlag = true;
	}
	else
	{

	}
	if (player2.nonFlag)
	{
		GameOverFlag = true;
		player1.winFlag = true;
	}
	else
	{

	}
	if (DrawFlag)
	{
		GameOverFlag = true;
	}
	else
	{

	}
	return false;
}

Player::Player():screen_size(1000,600)
{
	PlayerSysInit();
}

Player::~Player()
{
	if (skill != nullptr)
	{
		delete skill;
		skill = nullptr;
	}
}

