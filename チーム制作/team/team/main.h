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

#define SCREEN_SIZE_X 1000
#define SCREEN_SIZE_Y 600

