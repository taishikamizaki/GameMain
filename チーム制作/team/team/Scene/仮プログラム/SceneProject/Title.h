#pragma once

class Title
{
public:

	int GetFlag()
	{
		return titleF;
	}

	int TitleCtl();
	int TitleDraw();

	Title();
	~Title();

private:
	int Init();

	int title;

	bool titleF;

};

