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

	bool gameF;		// �؂�ւ��p
	bool _gameF;	// �V�[���J�ڗp

};

