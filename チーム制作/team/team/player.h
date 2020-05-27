#pragma once

//定数の定義

#define	P_DSP	4				//プレイヤーの基本スピード

#define INIT_VELOCITY	50.0f	//初速度

#define ACC_G		10			//重力加速度
#define	FRAME_TIME	0.3f

//列挙型


enum CHAR_ID
{
	CHAR_ID_KISI
	,CHAR_ID_MDOU
	,CHAR_ID_BTOU
	,CHAR_ID_4
	,CHAR_ID_MAX

};

//構造体
struct CHARACTER 
{
	DIR moveDir;		//向いている方向
	Pos pos;			//キャラクタの位置（中心）
	Pos size;			//キャラクタ画像のサイズ
	Pos sizeOffset;		//キャラクタ中央からの左上位置
	Pos hitPosS;		//当たり判定用の左上
	Pos hitPosE;		//当たり判定用の右下
	Pos_F	velocity;
	bool runFlag;		//キャラクタの状態（走っているか？）
	bool jumpFlag;		//キャラクタの状態（ジャンプしているか？）
	bool shotFlag;		//キャラクタの状態（弾撃っているか？）
	bool damageFlag;	//キャラクタの状態（ダメージ受けているか？）
	bool surinukeFlag;	//1部ブロックすり抜け用
	int moveSpeed;		//キャラクタの移動量
	int life;			//キャラクタの体力
	int lifeMax;		//キャラクタの体力最大
	int animCnt;		//キャラクタのアニメーション用カウンタ
	int imgLockCnt;		//キャラクタのイメージ固定用カウンタ
	int type;			//何らかの属性を格納できる。
};

//プロトタイプ宣言
void	PlayerSysInit(void);
void	PlayerGameInit(void);
void	PlayerCtl(void);
void	PlayerDraw(void);
