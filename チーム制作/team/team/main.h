#pragma once
//�A�T�[�g�̒�`
#ifdef _DEBUG
#define AST() {\
	CHAR ast_msg[256];\
	wsprintf(ast_msg, "%s %d�s��\0", __FILE__, __LINE__);\
	MessageBox(0, ast_msg, "�A�T�[�g�\��", MB_OK);\
	}
#else
#define AST()
#endif

// ���ID
enum SCN_ID
{
	SCN_ID_INIT,		// �Ư�
	SCN_ID_TITLE,		// ����
	SCN_ID_SELECT,		// �ڸ�
	SCN_ID_GAME,		// �ް�
	SCN_ID_PAUSE,		// �߰��
	SCN_ID_RESULT,		// ػ���
	SCN_ID_GAMEOVER,	// �ްѵ��ް
	SCN_ID_MAX
};

// ����
enum DIR
{
	DIR_UP,			// ��
	DIR_RIGHT,		// �E
	DIR_DOWN,		// ��
	DIR_LEFT,		// ��
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
