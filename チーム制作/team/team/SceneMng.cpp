#include <iostream>
#include <string>
#include <DxLib.h>
#include "SceneMng.h"
#include "TitleScene.h"

// �ÓI�œ��I�ȉ���
SceneMng* SceneMng::sinstance = nullptr;

// ��ݺ��۰�
void SceneMng::ScnCtl(void)
{
	SceneMng::ScnInit();
	nowScn = std::make_unique<TitleScene>();		// �V�[�����^�C�g���ɍ����ւ�

	while (ProcessMessage() == 0 &&
		CheckHitKey(KEY_INPUT_ESCAPE) == 0)
	{
		drawList.clear();		// ���X�g�̏�����
		(*input).Update();
		/*KeyCheck();*/
		nowScn = (*nowScn).update(std::move(nowScn));// �V�[���ڍs

		SceneMng::ListDraw();
	}
}

// �����`��p�^�X�N
int SceneMng::addList(int x, int y, std::string id)
{
	drawList.emplace_back(x, y, id);

	return 0;
}

// �R���X�g���N�^
SceneMng::SceneMng():screenSizeX(1000),screenSizeY(600)
{
	
}

// �f�X�g���N�^
SceneMng::~SceneMng()
{

}

// �`��p
void SceneMng::ListDraw(void)
{
	ClsDrawScreen();
	int x, y;
	std::string id;
	for(auto dl:drawList)
	{
		std::tie(x, y, id) = dl;
		
		DrawGraph(x,y,GetId(id),true);
	}

	ScreenFlip();
}

// ������
bool SceneMng::ScnInit(void)
{
	SetWindowText("HAMAGURI");
	// ���я���
	SetGraphMode(screenSizeX, screenSizeY, 16);
	ChangeWindowMode(true);
	if (DxLib_Init() == -1)
	{
		/*AST();*/
		return false;
	}

	SetDrawScreen(DX_SCREEN_BACK);

	// ������
	//EffectInit();

	/*TitleInit();*/

	//scnID = SCN_ID_INIT;
	//scnIDOld = SCN_ID_MAX;
	input = std::make_shared<KeyState>();
	return 0;
}

int SceneMng::GetId(const std::string& key,const std::string filename)
{
	if (imgMng.find(key) == imgMng.end())
	{
		imgMng[key] = LoadGraph(filename.c_str());
	}
	return imgMng[key];
}

int SceneMng::GetId(const std::string& key)
{
	GetId(key, key);
	return imgMng[key];
}