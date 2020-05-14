#pragma once

//定数の定義

//列挙型

enum DIR 
{
	DIR_UP,
	DIR_RIGHT,
	DIR_DOWN,
	DIR_LEFT,
	DIR_MAX
};

enum CHAR_ID
{
	CHAR_ID_KISI
	,CHAR_ID_MDOU
	,CHAR_ID_BTOU
	,CHAR_ID_4
	,CHAR_ID_MAX

};

//構造体

<<<<<<< HEAD
struct CHARACTER 
{
=======

struct CHARACTER 
{
	DIR moveDir;		//向いている方向
	Pos pos;			//キャラクタの位置（中心）
	Pos size;			//キャラクタ画像のサイズ
	Pos sizeOffset;		//キャラクタ中央からの左上位置
>>>>>>> cdc52835e72d010a7654657e2869079f04b2fd7a
	bool runFlag;		//キャラクタの状態（走っているか？）
	bool jumpFlag;		//キャラクタの状態（ジャンプしているか？）
	bool shotFlag;		//キャラクタの状態（弾撃っているか？）
	bool damageFlag;	//キャラクタの状態（ダメージ受けているか？）
	int moveSpeed;		//キャラクタの移動量
	int life;			//キャラクタの体力
	int lifeMax;		//キャラクタの体力最大
	int animCnt;		//キャラクタのアニメーション用カウンタ
<<<<<<< HEAD
	int imgLockCnt;		//キャラクタのイメージ固定用カウンタ
	int type;			//何らかの属性を格納できる。
};

//プロトタイプ宣言
void PlayerSysInit(void);
void PlayerGameInit(void);
void PlayerCtl(void);
void PlayerDraw(void);
=======

};

//プロトタイプ宣言
void	PlayerSystemInit(void);
void	PlayerGameInit(void);
void	PlayerControl(void);
void	PlayerGameDraw(void);
>>>>>>> cdc52835e72d010a7654657e2869079f04b2fd7a
