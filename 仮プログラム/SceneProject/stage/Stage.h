#pragma once

#include"../vector/Vector2.h"

#define MAP_X 20						// マップのマス数(X)
#define MAP_Y 12						// マップのマス数(Y)
#define CHIP_SIZE_X 50					// マップの１マスのサイズ(X)
#define CHIP_SIZE_Y 50					// マップの１マスのサイズ(Y)

#define lpStage Stage::GetInstance()

// ステージ種別
 enum class STAGE_ID
{
	STAGE_ID_YAMA,
	STAGE_ID_MACHI,
	STAGE_ID_COLOSSEUM,
	STAGE_ID_HAMAGURI,
	STAGE_ID_MAX
};

 // ステージクラス
class Stage
{
public:
	static Stage& GetInstance()
	{
		static Stage s_instance;
		return s_instance;
	}
	Vector2 PosToIndex(Vector2 pos);			// posの受け渡し
	Vector2 IndexToPos(Vector2 index);			// posの受け渡し
	bool IsPassY(Vector2 pos);					// ステージの当たり判定(山)
	bool IsPassM(Vector2 pos);					// ステージの当たり判定(街)
	bool IsPassT(Vector2 pos);					// ステージの当たり判定(闘技場)
	STAGE_ID mapID;								// ステージID

	bool StageCtl(STAGE_ID stage);				// ステージの設定
	void StageDraw(STAGE_ID id);				// ステージの描画
	void SoundGameInit(void);					// ステージのゲーム設定
	Stage();									// コンストラクタ
	~Stage();									// デストラクタ
private:
	bool StageInit(void);						// ステージの初期化
	
	int matiImage[43];							// 街ステージの描画
	int tougiImage[12];							// 闘技場ステージの描画
	int yamaImage[23];							// 山ステージの描画
	Vector2 mapSize;							// マップのサイズ

	int map[MAP_Y][MAP_X];						// マップの配置
	// 山
	int mapyama[MAP_Y][MAP_X] = {
	{0,0,0,0 ,0,0,0,0 ,0,0,0,0 ,0,0,0,0 ,0,0,0,0,},
	{13,14,8,8 ,8,8,8,8 ,11,13,14,8 ,8,13,14,8 ,8,8,8,8,},
	{9,10,8,8 ,8,8,8,9 ,17,10,8,8 ,8,8,8,8 ,13,14,8,8,},
	{5,5,3,8 ,19,4,2,5 ,5,5,3,8 ,8,2,3,4 ,8,8,8,8,},

	{5,5,5,3 ,2,5,5,5 ,5,5,5,3 ,2,5,5,5 ,3,4,4,2,},
	{12,12,12,12 ,12,12,12,12 ,12,12,12,12 ,12,12,12,12 ,12,12,12,12,},
	{16,16,16,16 ,16,16,16,16 ,16,16,16,16 ,16,16,16,16 ,16,16,16,16,},
	{16,16,16,16 ,16,16,16,16 ,20,21,21,22 ,16,16,16,16 ,16,16,16,16,},

	{6,6,6,6 ,6,6,6,6 ,6,6,6,6 ,6,6,6,6 ,6,6,6,6,},
	{7,6,6,6 ,20,22,6,6 ,7,7,7,7 ,6,6,20,22 ,7,7,7,7,},
	{15,15,15,15 ,15,15,15,15 ,15,15,15,15 ,15,15,15,15 ,15,15,15,15,},
	{1,1,1,1 ,1,1,1,1 ,1,1,1,1 ,1,1,1,1 ,1,1,1,1,},
	};
	// 街
	int mapmati[MAP_Y][MAP_X] = {
	{16,16,16,16 ,16,16,16,16 ,16,16,16,16 ,16,16,16,16 ,16,16,16,16,},
	{19,19,19,19 ,19,19,19,19 ,20,21,19,19 ,19,19,19,19 ,19,19,19,19,},
	{19,20,21,19 ,19,19,19,19 ,19,19,19,19 ,19,20,21,19 ,19,19,23,19,},
	{19,19,19,19 ,19,20,21,19 ,19,19,19,40 ,19,19,19,19 ,19,19,19,19,},

	{19,19,19,19 ,19,19,19,19 ,19,19,40,19 ,19,19,19,19 ,20,21,19,19,},
	{40,19,19,19 ,19,39,19,19 ,19,19,19,40 ,19,20,21,19 ,19,19,39,19,},
	{35,35,35,35 ,35,38,35,35 ,35,36,37,35 ,35,35,35,35 ,35,35,38,35,},
	{12,11,11,13 ,4,3,3,5 ,33,41,42,34 ,12,11,11,13 ,4,3,3,5,},

	{9,9,9,9 ,1,1,1,1 ,17,31,32,17 ,9,9,9,9 ,1,1,1,1,},
	{9,10,15,9 ,1,2,7,1 ,27,28,29,30 ,22,10,15,9 ,1,2,7,1,},
	{9,9,8,9 ,1,1,8,8 ,24,25,25,26 ,22,22,14,9 ,1,1,6,8,},
	{0,0,0,0 ,0,0,0,0 ,0,0,0,0 ,0,0,0,0 ,0,0,0,0,},
	};
	// 闘技場
	int maptougi[MAP_Y][MAP_X] = {
	{10,4,4,10 ,10,4,4,10 ,10,4,4,10 ,10,4,4,10 ,10,4,4,10,},
	{11,11,11,11 ,11,11,11,11 ,11,11,11,11 ,11,11,11,11 ,11,11,11,11,},
	{3,4,4,9 ,9,4,4,3 ,9,4,4,9 ,3,4,4,9 ,9,4,4,3,},
	{2,4,4,10 ,10,4,4,2 ,10,4,4,10 ,2,4,4,10 ,10,4,4,2,},

	{5,6,6,6 ,6,6,6,5 ,6,6,6,6 ,5,6,6,6 ,6,6,6,5,},
	{5,8,8,8 ,8,8,8,5 ,8,8,8,8 ,5,8,8,8 ,8,8,8,5,},
	{5,8,8,8 ,8,8,8,5 ,8,8,8,8 ,5,8,8,8 ,8,8,8,5,},
	{5,8,8,8 ,8,8,8,5 ,8,8,8,8 ,5,8,8,8 ,8,8,8,5,},

	{1,1,1,1 ,1,1,1,1 ,1,1,1,1 ,1,1,1,1 ,1,1,1,1,},
	{0,0,0,0 ,0,0,0,0 ,0,0,0,0 ,0,0,0,0 ,0,0,0,0,},
	{0,0,0,0 ,0,0,0,0 ,0,0,0,0 ,0,0,0,0 ,0,0,0,0,},
	{7,7,7,7 ,7,7,7,7 ,7,7,7,7 ,7,7,7,7 ,7,7,7,7,},
	};

	bool yamaF;													// 山ステージフラグ
	bool matiF;													// 街ステージフラグ
	bool tougiF;												// 闘技場ステージフラグ

};


