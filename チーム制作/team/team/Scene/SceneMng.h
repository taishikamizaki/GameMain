#pragma once
#include <string>
#include <vector>
#include <tuple>
#include <map>
#include "BaseScene.h"
#include "../Key/KeyState.h"

#define SCN_MNG SceneMng::ScnGeter()								// �}�N��

using drawQue = std::tuple<int, int, std::string>;

// �V�[���}�l�[�W���[
class SceneMng
{
public:
	// �Q�b�^�[
	static SceneMng & ScnGeter(void)
	{
		ScnCreate();
		return *sinstance;
	}
	// �N���G�C�^�[
	static void ScnCreate(void)
	{
		if (sinstance != nullptr)
		{
			//�������Ȃ�
		}
		else
		{
			sinstance = new SceneMng();
		}
	}
	// �J�X�^���f���[�^�[
	static void ScnDestroy(void)
	{
		if (sinstance != nullptr)
		{
			delete sinstance;
		}
		sinstance = nullptr;
	}

	// ��ݺ��۰�
	void ScnCtl(void);

	int addList(int x, int y, std::string id);

	int GetID(const std::string& key,const std::string filename);

	int GetID_D(const std::string& key, const TCHAR fileName, 
			    int AllNum, int xNum, int yNum, int xSize, int ySize, 
			    int* HandleArray);

	int GetID(const std::string& key);
	
	std::shared_ptr<InputState> input;


bool FadeInScreen(int fadeStep);			// ̪��޲ݏ���
bool FadeOutScreen(int fadeStep);		// ̪��ޱ�ď���

	bool fadeIn;						// ̪��޲�
	bool fadeOut;					// ̪��ޱ��

private:
	SceneMng();
	~SceneMng();
	
	std::vector<drawQue> drawList;		// �摜�Ƃ������Ƃ�

	void ListDraw(void);				// �`��p

	static SceneMng*sinstance;			// �߲���i���I�ɍ��ÓI�ȉ����j

	// ���j�[�N�x�[�X
	ScnBase nowScn;						// ���݂̃V�[��

	bool ScnInit(void);					// ������

	const int screenSizeX;				// ��ʃT�C�YX
	const int screenSizeY;				// ��ʃT�C�YY

	std::map<std::string, int> imgMng;

	int  fadeCnt;						// ̪��޶���

	int a;

	int kisi[13];
	int majo[13];
	int buto[13];
	int men[13];
};

