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
	}
}

// �����`��p�^�X�N
int SceneMng::addList(drawQue dList)
{
	drawList.emplace_back(dList);
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
	for (auto a : drawList)
	{
		int x;
		int y;
		int coller;
		int txt;

		std::tie(x, y, coller, txt) = a;
	}
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
}
