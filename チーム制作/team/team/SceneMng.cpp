#include "SceneMng.h"

// �ÓI�œ��I�ȉ���
SceneMng* SceneMng::sinstance = nullptr;

// ��ݺ��۰�
void SceneMng::ScnCtl(void)
{
	nowScn = std::make_unique<>();
}
