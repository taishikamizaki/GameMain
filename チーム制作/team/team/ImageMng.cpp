
#include <DxLib.h>
#include "Vector2/Vector2.h"
#include "ImageMng.h"

void ImageMng::Init()
{

}

void ImageMng::Render()
{
	DrawGraph(pos.x, pos.y, imageID, true);
}

void ImageMng::Update()
{

}

ImageMng::ImageMng(int imgID, Vector2 pos)
{
	this->imageID = imgID;
	this->pos = pos;

	Init();
}

ImageMng::~ImageMng()
{

}
