#pragma once
#include <map>

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

enum class DIR
{
	DIR_ID_RIGHT,
	DIR_ID_LEFT,
	DIR_MAX
};

#define lpPos Pos::GetInstance()

// XY
class Pos
{
public:
	static Pos& GetInstance()
	{
		static Pos s_instance;
		return s_instance;
	}


	int ix;
	int iy;

	float fx;
	float fy;

private:
	Pos();
	~Pos();
};

// ����ݐ錾
//extern SCN_ID scnID;		// ��ݎ��ʗp
//extern SCN_ID scnIDOld;		// ��ݎ��ʁi�ڰёO�j
