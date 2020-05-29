#pragma once
#include "BaseScene.h"

#define SCN_MNG SceneMng::ScnGeter()

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

private:
	SceneMng();
	~SceneMng();

	static SceneMng*sinstance;		// �߲���i���I�ɍ��ÓI�ȉ����j

	// ���j�[�N�x�[�X
	ScnBase nowScn;					// ���݂̃V�[��
};

