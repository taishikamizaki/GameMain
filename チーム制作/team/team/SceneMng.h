#pragma once
#include <vector>
#include <tuple>
#include "BaseScene.h"

#define SCN_MNG SceneMng::ScnGeter()								// �}�N��

/*using drawQue = std::tuple<int, int, int>();*/						// ��������
using drawQue = std::tuple<int, int, int, std::string>;

/*using drawGraph = std::tuple<int, int, int>();*/					// �摜����(DrawGraph)

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

	int addList(int x, int y, unsigned int coller, std::string txt);

private:
	SceneMng();
	~SceneMng();
	
	/*std::vector<drawQue> drawList;*/	
	std::vector<drawQue> drawList;	// �摜�Ƃ������Ƃ������Ƃ� �i���������j
	/*std::vector<drawQue> List;*/
	void ListDraw(void);			// �`��p

	static SceneMng*sinstance;		// �߲���i���I�ɍ��ÓI�ȉ����j

	// ���j�[�N�x�[�X
	ScnBase nowScn;					// ���݂̃V�[��

	bool ScnInit(void);				// ������

	const int screenSizeX;			// ��ʃT�C�YX
	const int screenSizeY;			// ��ʃT�C�YY

};

