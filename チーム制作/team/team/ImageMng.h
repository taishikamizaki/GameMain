#pragma once
class ImageMng
{
public:

	void Render();
	void Update();

	ImageMng(int imgID, Vector2 pos);
	~ImageMng();

private:
	void Init();

	int imageID;
	Vector2 pos;

};

