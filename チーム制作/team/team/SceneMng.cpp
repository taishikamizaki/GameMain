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

		/*KeyCheck();*/
		nowScn = (*nowScn).update(std::move(nowScn));// �V�[���ڍs

		SceneMng::ListDraw();
	}
}

// �����`��p�^�X�N
int SceneMng::addList(int x, int y, unsigned int coller, std::string txt)
{
	drawList.emplace_back(x, y, coller, txt);
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
	for (auto a : drawList)
	{
		int x;
		int y;
		int coller;
		std::string txt;
		
		std::tie(x, y, coller,txt) = a;

		DrawFormatString(x, y, coller,"%d",txt);	// �����`�揈��
		std::cout << "" << std::endl;
		std::cout << "\n txt==%d"<<txt << std::endl;
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
	return 0;
}
