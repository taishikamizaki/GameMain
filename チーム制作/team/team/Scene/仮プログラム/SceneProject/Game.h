#pragma once

// �Q�[���N���X
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
	int GameDraw();		// �`��

	Game();		// �R���X�g���N�^
	~Game();	// �f�X�g���N�^

private:

	int Init();		// ������

	int select;		// ���u���摜�p
	int game;		// ���u���摜�p

	bool selectF;	// �؂�ւ��p
	bool gameF;		// �؂�ւ��p
	bool _gameF;	// �V�[���J�ڗp

};

