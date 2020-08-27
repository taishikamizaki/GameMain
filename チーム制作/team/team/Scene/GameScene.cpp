#include <string>
#include <DxLib.h>
#include "SceneMng.h"
#include "ResultScene.h"
#include "Pause.h"
#include "SelectScene.h"
#include "GameOverScene.h"
#include "../Player/playerMng.h"
#include "../Stage/Stage.h"
#include "../ImageMng.h"
#include "GameScene.h"

// シーン
ScnBase GameScene::Update(ScnBase scnID)
{
	auto move = [](std::weak_ptr<InputState> KeyID, const KEY_ID id) {
		if (!KeyID.expired())
		{
			if ((*KeyID.lock()).state(id).first == true && 
				(*KeyID.lock()).state(id).second == false)
			{
				return true;
			}
		}
		return false;
	};

	if(move(SCN_MNG.input, KEY_ID::KEY_ID_SPACE))
	{
		gamEnd=true;
		SCN_MNG.fadeOut=true;
	}
	if(gamEnd)
	{
		if(!SCN_MNG.fadeOut)
		{
			SCN_MNG.fadeIn=true;
			return std::make_unique<ResultScene>();		// シーンをゲームオーバーに差し替え
		}
	}
	
	lpPlayer.PlayerCtl();

	GameScene::GameDraw();
	return std::move(scnID);
}

// 初期化とか
void GameScene::GameInit(void)
{
	/*SCN_MNG.GetID("gsi", "image/TestGraph/Game.png");*/		//鍵　場所

	if (player == nullptr) player = new PlayerMng(charID_1, ID_1, charID_2, ID_2);

	gamEnd = false;
}

// 描画
void GameScene::GameDraw(void)
{	
	/*lpImageMng.Render();
	SCN_MNG.addList(0, 0, "gsi");
	SCN_MNG.addList(0, 0, "player");
	lpStage.StageDraw();
	lpPlayer.PlayerDraw();*/

	SCN_MNG.addList(0, 0, "kishi");

	if (player != nullptr)
	{
		player->Render();
		player->Update();
	}
}

GameScene::GameScene()
{
	GameScene::GameInit();
}

GameScene::GameScene(int charID_1, int ID_1, int charID_2, int ID_2)
{
	this->charID_1 = charID_1;
	this->charID_2 = charID_2;

	this->ID_1 = ID_1;
	this->ID_2 = ID_2;

	GameInit();
}

GameScene::~GameScene()
{
	if (player != nullptr)
	{
		delete player;
		player = nullptr;
	}
}
