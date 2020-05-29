#include "SceneMng.h"

// Ã“I‚Å“®“I‚È‰½‚©
SceneMng* SceneMng::sinstance = nullptr;

// ¼°İºİÄÛ°Ù
void SceneMng::ScnCtl(void)
{
	nowScn = std::make_unique<>();
}
