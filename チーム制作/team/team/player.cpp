#include "DxLib.h"
#include "main.h"
#include "GetKeyState.h"
#include "player.h"

//変数の定義
CHARACTER	player1;

void	PlayerSysInit(void)
{
	player1.moveDir = DIR_RIGHT;						//向いている方向
	player1.pos = {96,SCREEN_SIZE_Y-100};								//キャラクタの位置（中心）
	player1.size = {96,100};								//キャラクタ画像のサイズ
	player1.sizeOffset.x =  player1.size.x / 2 ;		//キャラクタ中央からの左上位置のX座標
	player1.sizeOffset.y = player1.size.y / 2;			//キャラクタ中央からの左上位置のY座標
	player1.runFlag = false;							//キャラクタの状態（走っているか？）
	player1.jumpFlag = false;							//キャラクタの状態（ジャンプしているか？）
	player1.shotFlag = false;							//キャラクタの状態（弾撃っているか？）
	player1.damageFlag = false;							//キャラクタの状態（ダメージ受けているか？）
	player1.moveSpeed=4;								//キャラクタの移動量
	player1.life=4;										//キャラクタの体力
	player1.lifeMax=4;									//キャラクタの体力最大
	player1.animCnt=0;									//キャラクタのアニメーション用カウンタ
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