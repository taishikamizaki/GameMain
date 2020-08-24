#pragma once

#define lpImageMng ImageMng::GetInstance()

class ImageMng
{
public:
	static ImageMng GetInstance()
	{
		static ImageMng s_instance;
		return s_instance;
	}

	ImageMng(int imgID, Vector2 pos);
	~ImageMng();

	void Render();
	void Update();

private:
	void Init();
	
	ImageMng() { Init(); };
	
	int imageID;
	Vector2 pos;

};

