#pragma once
#include <map>
#include <string>
#include "skill.h"
#include"../scene/Game.h"
#include "../vector/Vector2.h"
#include "../vector/Vector2f.h"


//定数の定義
#define	P_DSP	        4		//プレイヤーの基本スピード
#define INIT_VELOCITY	50.0f	//初速度
#define ACC_G		    10		//重力加速度
#define	FRAME_TIME	    0.3f	//IsPass用

#define	lpPlayer Player::GetInstance()

//Run画像切り替え用
constexpr auto DIR_RIGHT=0;
constexpr auto DIR_LEFT =1;


using MapInt = std::map<int, int>;
using PairChar = std::pair<CHAR_ID, CHAR_ID>;
//列挙
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
	bool atFlag;
	bool runFlag;			//キャラクタの状態（走っているか？）
	bool jumpFlag;			//キャラクタの状態（ジャンプしているか？）
	bool shotFlag;			//キャラクタの状態（弾撃っているか？）
	bool damageFlag;		//キャラクタの状態（ダメージ受けているか？）
	bool surinukeFlag;		//1部ブロックすり抜け用
	bool nonFlag;
	bool winFlag;
	int moveSpeed;			//キャラクタの移動量
	int animCnt;			//キャラクタのアニメーション用カウンタ
	int Hp;
	int dirS;
	CHAR_ID charID;
};

class Skill;
class Player
{
public:

	int kisiImage[12];		//騎士の画像
	int mahoImage[12];		//魔法使いの画像
	int butoImage[12];		//武闘家の画像
	int nazoImage[12];		//謎の男の画像

	int kisiRunImage[2][4];	// 騎士の走り状態の画像
	int mahoRunImage[2][4];	// 魔法使いの走り状態の画像
	int butoRunImage[2][4];	// 武闘家の走り状態の画像
	int nazoRunImage[2][4];	// 謎の男の走り状態の画像

	static Player& GetInstance()
	{
		static Player s_Instance;
		return s_Instance;
	}

	//メンバ関数
	void PlayerSysInit(void);
	void PlayerGameInit(void);
	void PlayerCtl(STAGE_ID id);
	void PlayerDraw(void);

	void SetPlayerID(Vector2 pos1, Vector2 pos2);
	void charCtl(CHAR_ID p1, CHAR_ID p2);

	bool HPmng(void);
	bool playerWin(void);
	bool win(void);

	Player();
	~Player();

private:
	std::map<std::string, int> images;
	int playerPosX;
	int playerPosY;
	int hp;
	int iconp1;
	int iconp2;
	int p1win;
	int p2win;
	int draw;
	bool DrawFlag;
	bool GameOverFlag;
	bool charSelFlag;

	Vector2f HPsize;

	CHARACTER player1;	//1P
	CHARACTER player2;	//2P

	const Vector2 screen_size;
	DIR dir;

	MapInt charcter;
	PairChar charID_;

	Skill* skill;

};