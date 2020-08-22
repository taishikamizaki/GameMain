
#include <DxLib.h>
#include "Vector2/Vector2.h"
#include "ImageMng.h"

void ImageMng::Init()
{

}

void ImageMng::Render()
{

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
