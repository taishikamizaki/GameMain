#pragma once

// �^�C�g���N���X
class Title
{
public:

	// �t���O�Q�b�^�[
	int GetFlag()
	{
		return titleF;
	}

	int TitleCtl();		// ���쏈��
	int TitleDraw();	// �`�揈��

	Title();	// �R���X�g���N�^
	~Title();	// �f�X�g���N�^

private:
	int Init();		// ������

	int title;		// ���u���摜�p
	int space;

	bool titleF;	// �J�ڃt���O

};

