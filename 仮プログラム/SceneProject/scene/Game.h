#pragma once
#include "../stage/Stage.h"

enum class CHAR_ID
{
	CHAR_ID_KISI,
	CHAR_ID_MDOU,
	CHAR_ID_BTOU,
	CHAR_ID_4,
	CHAR_ID_MAX
};

// �Q�[���N���X
class Select;
class Player;
class Stage;
class Game
{
public:
	// �t���O�Q�b�^�[
	int GetFlag()
	{
		return _gameF;
	}

	int SelectCtl();			// �Z���N�g����n
	int GameCtl();				// �Q�[������n
	int Draw();		// �`��

	int GetPlayerInit();

	Game();		// �R���X�g���N�^
	~Game();	// �f�X�g���N�^

private:

	int charCnt;

	int selectB;		// ���u���摜�p
	int game;		// ���u���摜�p
	int space;

	bool selectF;	// �؂�ւ��p
	bool gameF;		// �؂�ւ��p
	bool _gameF;	// �V�[���J�ڗp

	bool resetF;

	CHAR_ID player1;
	CHAR_ID player2;

	STAGE_ID stageID;

	Select* select;
	Player* player;
	Stage* stage;

	friend class Select;
	friend class Player;
	friend class Stage;

	int Init();

};

