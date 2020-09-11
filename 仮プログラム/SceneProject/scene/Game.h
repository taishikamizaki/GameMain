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
class Skill;
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

	Game();		// �R���X�g���N�^
	~Game();	// �f�X�g���N�^

	


private:

	int Init();		// ������

	int charCnt;

	int selectB;		// ���u���摜�p
	int game;		// ���u���摜�p
	int space;

	bool selectF;	// �؂�ւ��p
	bool gameF;		// �؂�ւ��p
	bool _gameF;	// �V�[���J�ڗp

	CHAR_ID player1;
	CHAR_ID player2;

	CHAR_ID P1[5];
	CHAR_ID P2[5];

	STAGE_ID stageID;

	Select* select;
	Player* player;
	Skill* skill;
	Stage* stage;

	friend class Select;
	friend class Player;
	friend class Stage;


};

