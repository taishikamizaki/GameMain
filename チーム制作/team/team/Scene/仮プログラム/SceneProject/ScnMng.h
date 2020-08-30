#pragma once


#define SCN_MNG ScnMng::GetInstance()

// ��ݎ��
enum SCN_ID
{
	SCN_ID_TITLE,				// ����
	SCN_ID_CHAR_SEL,		// ��בI��
	SCN_ID_GAME,				// �ްђ�
	SCN_ID_GAMEOVER,	// �ްѵ��ް
	SCN_ID_MAX
};

class Title;
class Game;
class GameOver;

class ScnMng
{
public:
	static ScnMng& GetInstance()
	{
		static ScnMng s_instance;
		return s_instance;
	}

	int ScnCtl();
	
	bool FadeInScreen(int fadeStep);			// ̪��޲ݏ���
	bool FadeOutScreen(int fadeStep);		// ̪��ޱ�ď���

	bool fadeIn;			// ̪��޲�
	bool fadeOut;		// ̪��ޱ��

	bool keyFlagSp;
	bool keyFlagOld;

private:
	Title* title;
	Game* game;
	GameOver* gameOver;

	int Init();
	int ScnDraw();

	void GetKeyState(void);

	int windowSizeX;
	int windowSizeY;

	int  fadeCnt;						// ̪��޶���

	SCN_ID scnID;

	ScnMng();
	~ScnMng();

};

