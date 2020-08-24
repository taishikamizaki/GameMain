#include <string>
#include <DxLib.h>
#include "SceneMng.h"
#include "ResultScene.h"
#include "Pause.h"
#include "SelectScene.h"
#include "GameOverScene.h"
#include "../Player/player.h"
#include "../Stage/Stage.h"
#include "../ImageMng.h"
#include "GameScene.h"

// シーン
ScnBase GameScene::update(ScnBase scnID)
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
	SCN_MNG.GetId("gsi", "image/TestGraph/Game.png");		//鍵　場所
	SCN_MNG.GetId("player", "image/char/char_p_f04.png");
	gamEnd = false;
}

// 描画
void GameScene::GameDraw(void)
{	
	lpImageMng.Render();
	SCN_MNG.addList(0, 0, "gsi");
	SCN_MNG.addList(0, 0, "player");
	lpStage.StageDraw();
	lpPlayer.PlayerDraw();


}

GameScene::GameScene()
{
	GameScene::GameInit();
}

GameScene::~GameScene()
{

}
