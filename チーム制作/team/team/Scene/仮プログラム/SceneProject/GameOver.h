#pragma once
class GameOver
{
public:

	int GetFlag()
	{
		return goF;
	}

	int GameOverCtl();
	int GameOverDraw();

	GameOver();
	~GameOver();

private:

	int Init();

	int gameOver;

	int now;
	bool goF;

};

