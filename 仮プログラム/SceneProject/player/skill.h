#pragma once
#include<memory>
#include"../scene/Game.h"
#include "player.h"
#include"../vector/Vector2.h"

#define lpSkill Skill::GetInstance()

// スキルの種類
enum class SKILL_ID
{
	SKILL_1,
	SKILL_2,
	SKILL_3,
	SKILL_4,
	SKILL_MAX
};
// posのXY
struct XY
{
	int x;
	int y;
};
// スキルのクールダウン
struct SScount
{
	int s1;
	int s2;
	int s3;
	int s4;
};
// スキル関連
struct player
{
	SKILL_ID skill;	// playerのスキル
	XY posp;		// playerのpos
	XY offsetPosp;	// playerのpos(オフセット)
	XY pos;			// playerの初期位置(test)
	XY hitPos;		// playerの当たり判定(攻撃)
	XY hitoffsetPos;// playerの当たり判定(攻撃)のオフセット
	XY AttackRange;	// playerの攻撃範囲
	XY Attackoffset;// playerの攻撃範囲オフセット
	int Scount;		// playerのスキル
	int HP;			// playerHP
	int LP;			// playerの初期ライフポイント
	int dmage;		// playerが与えるダメージ
	int attack;		// playerの攻撃力(付与された数値)
	int defense;	// playerの防御力(付与された数値)
	int speed;		// playerの移動速度
	int count;		// スキルのカウント
	int SSposoffset;// posYの位置保持ようpos
	int SSpos;		// offsetYの位置保持用pos
	int SSX;		// offsetXの位置保持用pos
	int SetPos;		// 保持したpos挿入用(posY)
	int SetoffPos;	// 保持したpos挿入用(offsetY)
	int SetoffX;	// 保持したpos挿入用(offsetX)
	bool SSflag;	// 発動１回用
	bool skillFlag;	// スキルのオンオフ
	bool hitFlag;	// 攻撃の当たり判定フラグ
	bool bufFlag;	// バフぼ発動フラグ
	bool Lflag;		// Dirの左向きフラグ
	bool Rflag;		// Dirの右向きフラグ
	bool posSetFlag;// 保持したposを一回だけ呼ぶフラグ
	bool laserFlag;	// レーザーのフラグ
	SScount kisi;	// 騎士のスキルカウント
	SScount maho;	// 魔導士のスキルカウント
	SScount buto;	// 武闘家のスキルカウント
	SScount nazo;	// 謎の男のスキルカウント
	int dir;		// 左右の向き
};


class Skill
{
public:
	static Skill& GetInstance()
	{
		static Skill s_instance;
		return s_instance;
	}

	bool GetCharF()
	{
		return charF;
	}

	void StageSysInit(void);													// スキルの初期化
	void StageGameInit(void);													// スキルのゲーム設定

	void PlayerInit(Vector2 pos, Vector2 hitposS, Vector2 hitposE, 
		Vector2 offset, Vector2 size, Vector2 pos2, Vector2 hitposS2, 
		Vector2 hitposE2, Vector2 offset2, Vector2 size2);						// プレイヤーのposの受け渡し
	void CharInit(CHAR_ID player1, CHAR_ID player2);							// ４人のキャラの初期ステータス
	void SScountInit(void);														// スキルカウントの初期化

	void SkillDraw(CHAR_ID player1, CHAR_ID player2);							// スキルの描画						


	void SkillCtl(CHAR_ID player1, CHAR_ID player2);							// スキルの発動時演出
	bool CheckHitP2(Vector2 pos, Vector2 posS, Vector2 posE);					// player2の当たり判定
	bool CheckHitP1(Vector2 pos, Vector2 posS, Vector2 posE);					// player1の当たり判定

	bool P1skill(CHAR_ID player1, CHAR_ID player2);								// 騎士のスキル効果
	bool P2skill(CHAR_ID player1, CHAR_ID player2);								// 魔導士のスキル効果
	bool P3skill(CHAR_ID player1, CHAR_ID player2);								// 武闘家のスキル効果
	bool P4skill(CHAR_ID player1, CHAR_ID player2);								// 謎の男のスキル効果

	int HPCtlP1(void);															// player1のHPの値渡し
	int HPCtlP2(void);															// player2のHPの値渡し
	void DmageCtl(Vector2 pos1, Vector2 pos2,
		Vector2 posS, Vector2 posS2, Vector2 posE,Vector2 posE2);				// playerのHP管理

	void Dir(int p1, int p2);													// dirの受け渡し

	Skill();																	// コンストラクタ
	~Skill();																	// デストラクタ
private:

	// 描画用変数
	int healImage[10];															// 回復バフ
	int buffAImage[10];															// 攻撃バフ
	int buffDImage[10];															// 防御バフ
	int buffSImage[10];															// スピードバフ
	int buffUImage[10];															// 特殊バフ
	int laserImage[5];															// レーザー(発射)１
	int laserSetImage[10];														// レーザー(チャージ)１
	int laser2[5];																// レーザー(発射)２
	int laserSet2[10];															// レーザー(チャージ)１
	int charicon[12];															// キャラアイコン
	int upImage[5];																// アッパー１
	int guardImage[20];															// シールド１
	int magic;																	// 魔法１
	int magic2;																	// 魔法２
	int magic3;																	// 魔法３
	int uibuffU;																// uiバフ
	int uiken;																	// ui剣
	int uiheal;																	// ui回復
	int uiles;																	// uiレーザー
	int uihand;																	// ui手
	int uisra;																	// ui斬撃
	int uitate;																	// ui盾
	int uimaho;																	// ui魔法
	int uilej;																	// uiデバフ
	int kensla1;																// 斬撃１
	int kensla2;																// 斬撃２
	int kensla3;																// 斬撃３
	int kensla4;																// 斬撃４
	
	bool charF;																	// キャラ選択の読み込み(一回のみ)
	
	player P1;																	// player1の構造体
	player P2;																	// player2の構造体

};



