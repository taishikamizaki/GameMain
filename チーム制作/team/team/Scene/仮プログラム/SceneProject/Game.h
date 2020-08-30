#pragma once
class Game
{
public:
	int GetFlag()
	{
		return _gameF;
	}


	int GameCtl();
	int GameDraw();

	Game();
	~Game();

private:

	int Init();

	int select;
	int game;

	bool gameF;		// 切り替え用
	bool _gameF;	// シーン遷移用

};

