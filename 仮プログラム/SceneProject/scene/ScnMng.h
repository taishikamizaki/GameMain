#pragma once

// �Ăяo���}�N��
#define SCN_MNG ScnMng::GetInstance()

// �N���X�Ăяo��
class Title;
class Game;
class GameOver;

// �V�[���}�l�[�W���[
class ScnMng
{
public:
	static ScnMng& GetInstance()
	{
		static ScnMng s_instance;
		return s_instance;
	}

	// ��ݎ��
	enum SCN_ID
	{
		SCN_ID_TITLE,		// ����
		SCN_ID_CHAR_SEL,	// ��בI��
		SCN_ID_GAME,		// �ްђ�
		SCN_ID_GAMEOVER,	// �ްѵ��ް
		SCN_ID_MAX
	};

	int ScnCtl();		// �V�[������p
	
	bool FadeInScreen(int fadeStep);	// ̪��޲ݏ���
	bool FadeOutScreen(int fadeStep);	// ̪��ޱ�ď���

	bool fadeIn;	// ̪��޲�
	bool fadeOut;	// ̪��ޱ��

private:
	Title*    title;		// class:Title
	Game*     game;			// class:Game
	GameOver* gameOver;		// class:GameOver

	int Init();		// ������
	int ScnDraw();	// �`��

	int windowSizeX;	// ��ʉ��T�C�Y
	int windowSizeY;	// ��ʏc�T�C�Y

	int  fadeCnt;		// ̪��޶���

	SCN_ID scnID;		// �V�[�����ID	

	int scnCnt;
	int scnCntOld;

	int charID_1;
	int charID_2;

	int pID_1;
	int pID_2;

	ScnMng();
	~ScnMng();

};

