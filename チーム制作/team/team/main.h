#pragma once
//アサートの定義
#ifdef _DEBUG
#define AST() {\
	CHAR ast_msg[256];\
	wsprintf(ast_msg, "%s %d行目\0", __FILE__, __LINE__);\
	MessageBox(0, ast_msg, "アサート表示", MB_OK);\
	}
#else
#define AST()
#endif

// ｼｰﾝID
enum SCN_ID
{
	SCN_ID_INIT,		// ｲﾆｯﾄ
	SCN_ID_TITLE,		// ﾀｲﾄﾙ
	SCN_ID_SELECT,		// ｾﾚｸﾄ
	SCN_ID_GAME,		// ｹﾞｰﾑ
	SCN_ID_PAUSE,		// ﾎﾟｰｽﾞ
	SCN_ID_RESULT,		// ﾘｻﾞﾙﾄ
	SCN_ID_GAMEOVER,	// ｹﾞｰﾑｵｰﾊﾞｰ
	SCN_ID_MAX
};

// 方向
enum DIR
{
	DIR_UP,			// 上
	DIR_RIGHT,		// 右
	DIR_DOWN,		// 下
	DIR_LEFT,		// 左
	DIR_MAX
};

#define SCREEN_SIZE_X 1000
#define SCREEN_SIZE_Y 600

// XY
struct Pos
{
	int x;
	int y;
};

extern SCN_ID scnID;
