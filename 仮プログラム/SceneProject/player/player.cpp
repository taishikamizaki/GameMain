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

	DrawFlag = false;
	GameOverFlag = false;
	LoadDivGraph("image/player/KISHI.png", 12, 3, 4, 25, 33, kisiImage);
	LoadDivGraph("image/player/MAHO.png", 12, 3, 4, 25, 33, mahoImage);
	LoadDivGraph("image/player/BUTOU.png", 12, 3, 4, 25, 33, butoImage);
	LoadDivGraph("image/player/NAZO.png", 12, 3, 4, 25, 33, nazoImage);
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
	if ((skill != nullptr)&&
		(player1.charID != CHAR_ID::CHAR_ID_MAX)&&
		(player2.charID != CHAR_ID::CHAR_ID_MAX))
	{

		skill->CharInit(player1.charID,player2.charID);
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
		skill->HPCtl(player1.Hp,player2.Hp);
		skill->SpeedCtl(player1.moveSpeed,player2.moveSpeed);

		skill->StageGameInit();
	}
}

// ｺﾝﾄﾛｰﾙ
void Player::PlayerCtl(void)
{
	if (!GameOverFlag)
	{
		PlayerGameInit();
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
		if (keyNew[KEY_ID_RIGHT1])
		{
			player1.runFlag = true;

			player1.pos.x += player1.moveSpeed;

			moveFlag1 = true;
			player1.moveDir = DIR::DIR_ID_RIGHT;
		}

		//左
		if (keyNew[KEY_ID_LEFT1])
		{
			player1.runFlag = true;

			player1.pos.x -= player1.moveSpeed;

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
				Vector2	blockPos = lpStage.IndexToPos(blockIndex);				//ブロックの左上のピクセル座標

				playerPosBK.y = blockPos.y + player1.hitPosS.y;						//足元の座標からプレイヤーの座標を計算する
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
					if (keyNew[KEY_ID_JUMP1])
					{
						player1.jumpFlag = true;
						player1.velocity.fy = INIT_VELOCITY;
						player1.pos.y -= player1.moveSpeed;
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
		if (keyNew[KEY_ID_RIGHT2])
		{
			player2.runFlag = true;

			player2.pos.x += player2.moveSpeed;

			moveFlag2 = true;
			player2.moveDir = DIR::DIR_ID_RIGHT;
		}

		//左
		if (keyNew[KEY_ID_LEFT2])
		{
			player2.runFlag = true;

			player2.pos.x -= player2.moveSpeed;

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
				Vector2	blockPos2 = lpStage.IndexToPos(blockIndex2);		   //ブロックの左上のピクセル座標

				playerPosBK2.y = blockPos2.y + player2.hitPosS.y;					   //足元の座標からプレイヤーの座標を計算する
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
					if (keyNew[KEY_ID_JUMP2])
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

					if ((player2.pos.x + player2.hitPosE.x) < screen_size.x - 1)
					{
						playerPosBK2.x += player2.moveSpeed;
					}
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

		skill->SkillCtl(player1.charID, player2.charID);
	}
}

// 描画
void Player::PlayerDraw(void)
{
	if (!GameOverFlag)
	{
		// 1P
		// プレイヤー枠
		DrawBox(player1.pos.x - player1.sizeOffset.x, player1.pos.y - player1.sizeOffset.y,
			player1.pos.x + player1.size.x - player1.sizeOffset.x,
			player1.pos.y + player1.size.y - player1.sizeOffset.y, 0xFFFFF, false);

		//プレイヤーの当たり判定枠表示
		DrawBox(player1.pos.x - player1.hitPosS.x, player1.pos.y - player1.hitPosS.y,
			player1.pos.x + player1.hitPosE.x, player1.pos.y + player1.hitPosE.y, 0xFFF000, false);

		/*DrawGraph(player1.pos.x, player1.pos.y, kisiImage[5], true);*/

		switch (player1.charID)
		{
		case CHAR_ID::CHAR_ID_KISI:
			DrawExtendGraph(player1.pos.x - (player1.size.x / 2), player1.pos.y - (player1.size.y / 2),
				player1.pos.x + (player1.size.x / 2), player1.pos.y + (player1.size.y / 2), kisiImage[5], true);


			break;

		case CHAR_ID::CHAR_ID_MDOU:
			DrawExtendGraph(player1.pos.x - (player1.size.x / 2), player1.pos.y - (player1.size.y / 2),
				player1.pos.x + (player1.size.x / 2), player1.pos.y + (player1.size.y / 2), mahoImage[5], true);
			break;

		case CHAR_ID::CHAR_ID_BTOU:
			DrawExtendGraph(player1.pos.x - (player1.size.x / 2), player1.pos.y - (player1.size.y / 2),
				player1.pos.x + (player1.size.x / 2), player1.pos.y + (player1.size.y / 2), butoImage[5], true);
			break;

		case CHAR_ID::CHAR_ID_4:
			DrawExtendGraph(player1.pos.x - (player1.size.x / 2), player1.pos.y - (player1.size.y / 2),
				player1.pos.x + (player1.size.x / 2), player1.pos.y + (player1.size.y / 2), nazoImage[5], true);
			break;
		default:
			break;
		}

		// プレイヤー座標
		DrawFormatString(10, 32, 0xff0000, "player1.Pos(%d,%d)", player1.pos.x, player1.pos.y);
		DrawFormatString(10, 48, 0xff0000, "player1.moveSpeed(%d,)", player1.moveSpeed);
		DrawFormatString(10, 60, 0xff0000, "player1.id(%d)", player1.charID);

		// 2P
		// プレイヤー枠
		DrawBox(player2.pos.x - player2.sizeOffset.x, player2.pos.y - player2.sizeOffset.y,
			player2.pos.x + player2.size.x - player2.sizeOffset.x,
			player2.pos.y + player2.size.y - player2.sizeOffset.y, 0xFFFFF, false);

		//プレイヤーの当たり判定枠表示
		DrawBox(player2.pos.x - player2.hitPosS.x, player2.pos.y - player2.hitPosS.y,
			player2.pos.x + player2.hitPosE.x, player2.pos.y + player2.hitPosE.y, 0xFFFFF, false);

		/*DrawGraph(player2.pos.x, player2.pos.y, mahoImage[10], true);*/

		switch (player2.charID)
		{
		case CHAR_ID::CHAR_ID_KISI:
			DrawExtendGraph(player2.pos.x - (player2.size.x / 2), player2.pos.y - (player2.size.y / 2),
				player2.pos.x + (player2.size.x / 2), player2.pos.y + (player2.size.y / 2), kisiImage[11], true);
			break;

		case CHAR_ID::CHAR_ID_MDOU:
			DrawExtendGraph(player2.pos.x - (player2.size.x / 2), player2.pos.y - (player2.size.y / 2),
				player2.pos.x + (player2.size.x / 2), player2.pos.y + (player2.size.y / 2), mahoImage[11], true);
			break;

		case CHAR_ID::CHAR_ID_BTOU:
			DrawExtendGraph(player2.pos.x - (player2.size.x / 2), player2.pos.y - (player2.size.y / 2),
				player2.pos.x + (player2.size.x / 2), player2.pos.y + (player2.size.y / 2), butoImage[11], true);
			break;

		case CHAR_ID::CHAR_ID_4:
			DrawExtendGraph(player2.pos.x - (player2.size.x / 2), player2.pos.y - (player2.size.y / 2),
				player2.pos.x + (player2.size.x / 2), player2.pos.y + (player2.size.y / 2), nazoImage[11], true);
			break;
		default:
			break;
		}
		// プレイヤー座標
		DrawFormatString(800, 32, 0xff0000, "player2.Pos(%d,%d)", player2.pos.x, player2.pos.y);
		DrawFormatString(800, 48, 0xff0000, "player2.moveSpeed(%d,)", player2.moveSpeed);
		DrawFormatString(800, 60, 0xff0000, "player2.id(%d)", player2.charID);
	}
	//DrawGraph(0, 0, iconp1, true);
	//DrawGraph(920, 0, iconp2, true);
	DrawBox(0,0,1000,60,0xcc9966,true);
	DrawBox(40, 14, 480, 60, 0x000000, true);
	DrawBox(520, 14, 960, 60, 0x000000, true);
	DrawBox(40, 14, 480, 60, 0x33ff66, true);
	DrawBox(520, 14, 960, 60, 0x33ff66, true);
	DrawGraph(500,0,hp,true);
	DrawTurnGraph(0,0,hp,true);

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
	playerWin();
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

}

