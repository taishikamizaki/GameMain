#pragma once

// �Q�[���I�[�o�[�N���X
class GameOver
{
public:

	// �t���O�Q�b�^�[
	int GetFlag()
	{
		return goF;
	}

	int GameOverCtl();		// ����n
	int GameOverDraw();		// �`��n

	GameOver();		// �R���X�g���N�^
	~GameOver();	// �f�X�g���N�^

private:

	int Init();		// ������

	int gameOver;	// ���u���摜�p
	int space;

	int now;		// �����J�ڗp�ϐ�
	bool goF;		// �J�ڃt���O

};

