#include <DxLib.h>
#include "SceneMng.h"
#include "GameScene.h"
#include "../Stage/Stage.h"
#include "../Player/player.h"
#include "SelectScene.h"

SelectScene::SelectScene()
{
	SelectScene::SelectInit();
}

SelectScene::~SelectScene()
{
}

ScnBase SelectScene::update(ScnBase scnID)
{	auto move = [](std::weak_ptr<InputState> KeyID,const KEY_ID id) {
		if (!KeyID.expired())
		{
			if ((*KeyID.lock()).state(id).first == true && (*KeyID.lock()).state(id).second == false)
			{
				return true;
			}
		}
		return false;
	};

	if(move(SCN_MNG.input, KEY_ID::KEY_ID_SPACE))
	{
		selEnd=true;
		SCN_MNG.fadeOut=true;
	}
	if(selEnd)
	{
		if(!SCN_MNG.fadeOut)
		{
			SCN_MNG.fadeIn=true;
			return std::make_unique<GameScene>();		// �V�[�����Q�[���I�[�o�[�ɍ����ւ�
		}
	}

	SelectScene::SelectDraw();
	return std::move(scnID);
}

// ������
void SelectScene::SelectInit(void)
{
	SCN_MNG.GetId("sli", "image/TestGraph/Select.png");		//���@�ꏊ
	selEnd = false;

	images.try_emplace("kisi", LoadGraph("image/char/charsel icon/�R�m�I��(����).png"));
	images.try_emplace("kisi_1p", LoadGraph("image/char/charsel icon/�R�m�I��(1p).png"));
	images.try_emplace("kisi_2p", LoadGraph("image/char/charsel icon/�R�m�I��(2p).png"));

	images.try_emplace("majo", LoadGraph("image/char/charsel icon/���@�g���I��(����).png"));
	images.try_emplace("majo_1p", LoadGraph("image/char/charsel icon/���@�g���I��(1p).png"));
	images.try_emplace("majo_2p", LoadGraph("image/char/charsel icon/���@�g���I��(2p).png"));

	images.try_emplace("buto", LoadGraph("image/char/charsel icon/�����ƑI��(����).png"));
	images.try_emplace("buto_1p", LoadGraph("image/char/charsel icon/�����ƑI��(1p).png"));
	images.try_emplace("buto_2p", LoadGraph("image/char/charsel icon/�����ƑI��(2p).png"));

	images.try_emplace("men", LoadGraph("image/char/charsel icon/��̒j�I��(����).png"));
	images.try_emplace("men_1p", LoadGraph("image/char/charsel icon/��̒j�I��(1p).png"));
	images.try_emplace("men_2p", LoadGraph("image/char/charsel icon/��̒j�I��(2p).png"));
}

// �`�� 
void SelectScene::SelectDraw(void)
{
	SCN_MNG.addList(0, 0, "sli");
}

