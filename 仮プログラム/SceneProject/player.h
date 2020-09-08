#pragma once
#include <map>
#include <string>
#include "Vector2.h"
#include "Vector2f.h"


//定数の定義
#define	P_DSP	        4		//プレイヤーの基本スピード
#define INIT_VELOCITY	50.0f	//初速度
#define ACC_G		    10		//重力加速度
#define	FRAME_TIME	    0.3f

#define	lpPlayer Player::GetInstance()

using MapInt = std::map<int, int>;

//列挙型
enum class CHAR_ID
{
	CHAR_ID_KISI,
	CHAR_ID_MDOU,
	CHAR_ID_BTOU,
	CHAR_ID_4,
	CHAR_ID_MAX
};
enum class DIR
{
	DIR_ID_RIGHT,
	DIR_ID_LEFT,
	DIR_MAX
};

//構造体
struct CHARACTER 
{
	DIR moveDir;			//向いている方向
	Vector2 pos;			//キャラクタの位置（中心）
	Vector2 size;			//キャラクタ画像のサイズ
	Vector2 sizeOffset;		//キャラクタ中央からの左上位置
	Vector2 hitPosS;		//当たり判定用の左上
	Vector2 hitPosE;		//当たり判定用の右下
	Vector2f velocity;
	bool runFlag;		//キャラクタの状態（走っているか？）
	bool jumpFlag;		//キャラクタの状態（ジャンプしているか？）
	bool shotFlag;		//キャラクタの状態（弾撃っているか？）
	bool damageFlag;	//キャラクタの状態（ダメージ受けているか？）
	bool surinukeFlag;	//1部ブロックすり抜け用
	int moveSpeed;		//キャラクタの移動量
	int animCnt;		//キャラクタのアニメーション用カウンタ
};

class Player
{
public:

	int kisiImage[12];
	int mahoImage[12];
	int butoImage[12];
	int nazoImage[12];

	static Player& GetInstance()
	{
		static Player s_Instance;
		return s_Instance;
	}

	//メンバ関数
	void PlayerSysInit(void);
	void PlayerGameInit(void);
	void PlayerCtl(void);
	void PlayerDraw(void);

	void SetPlayerID(Vector2 pos1, Vector2 pos2);

	Player(int charID_1, int ID_1, int charID_2, int ID_2);

	Player();
	~Player();

private:
	std::map<std::string, int> images;
	int playerPosX;
	int playerPosY;

	CHARACTER player1;
	CHARACTER player2;

	int charID_1;
	int charID_2;

	int pID_1;
	int pID_2;

	DIR dir;
	CHAR_ID charID;

	MapInt charcter;

};