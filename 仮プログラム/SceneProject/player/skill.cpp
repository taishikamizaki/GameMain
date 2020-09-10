#include "DxLib.h"
#include "skill.h"
#include "player.h"

	//// ------∏ﬁ◊Ã®Ø∏ÇÃìoò^------
	//LoadDivGraph("image/hamaguriroom.png", 7, 7, 1, CHIP_SIZE_X, CHIP_SIZE_Y, chipImage, false);
	//LoadDivGraph("image/mati.png", 43, 43, 1, CHIP_SIZE_X, CHIP_SIZE_Y, matiImage, false);
	//LoadDivGraph("image/tougizyou.png", 12, 12, 1, CHIP_SIZE_X, CHIP_SIZE_Y, tougiImage, false);
	//LoadDivGraph("image/yama.png", 23, 23, 1, CHIP_SIZE_X, CHIP_SIZE_Y, yamaImage, false);
	//LoadDivGraph("image/É^ÉCÉÄ.png", 10, 10, 1, TIME_SIZE_X, TIME_SIZE_Y, timeImage, false);

	//// ------ïœêîèâä˙âª------


void Skill::StageSysInit(void)
{
	/*hamaFlag = false;
	hamaPos = { 0,0 };
	hamaCnt = 0;*/
	P1.skillFlag = false;
	P1.SSflag = true;
	P1.bufFlag = false;
	P1.hitFlag = false;
	P1.atFlag = false;
	P2.skillFlag = false;
	P2.SSflag = true;
	P2.bufFlag = false;
	P2.hitFlag = false;
	P1.count = 0;
	P2.count = 0;
	P1.Scount = 0;
	P2.Scount = 0;
	P1.skill = SKILL_ID::SKILL_MAX;
	P2.skill = SKILL_ID::SKILL_MAX;
	LoadDivGraph("image/skill/buff/Heal.png", 10, 10, 1, 120, 120, healImage, false);
	LoadDivGraph("image/skill/buff/buff_a.png", 10, 10, 1, 120, 120, buffAImage, false);
	LoadDivGraph("image/skill/buff/buff_d.png", 10, 10, 1, 120, 120, buffDImage, false);
	LoadDivGraph("image/skill/buff/buff_s.png", 10, 10, 1, 120, 120, buffSImage, false);
	LoadDivGraph("image/skill/buff/buff_u.png", 10, 10, 1, 120, 120, buffUImage, false);
	uibuffU = LoadGraph("image/ui/uibuff.png");
	uiken = LoadGraph("image/ui/uiken.png");
	uisra = LoadGraph("image/ui/uisra.png");
	uimaho = LoadGraph("image/ui/uimaho.png");
	uiles = LoadGraph("image/ui/uile.png");
	uitate = LoadGraph("image/ui/uitate.png");
	uihand = LoadGraph("image/ui/uite.png");
	uilej = LoadGraph("image/ui/uilej.png");
	uiheal = LoadGraph("image/ui/uiheal.png");
	swordImage = LoadGraph("image/player/turugi2.png", true);

	//LoadDivGraph("image/slash1.png", 16, 4, 4, 320, 240, slashImage, false);
	//LoadDivGraph("image/slash2.png", 16, 4, 4, 320, 240, slash2Image, false);
	//LoadDivGraph("image/slash3.png", 12, 5, 3, 192, 192, slash3Image, false);
	//LoadDivGraph("image/laser.png", 5, 1, 5, 320, 120, laserImage, false);
	//mapID = MAP_ID::MAP_ID_MATI;
}

//void SoundSysInit(void)
//{
//	yamabgm = LoadSoundMem("sound/yama.mp3");
//	matibgm = LoadSoundMem("sound/mati.mp3");
//	tougibgm = LoadSoundMem("sound/tougizyou.mp3");
//
//	SoundGameInit();
//}

void Skill::StageGameInit(void)
{
	P1.count++;
	P2.count++;
	P1.Scount++;
	P2.Scount++;
}

//void SoundGameInit(void)
//{
//	int randam;
//	switch (mapID)
//	{
//	case MAP_ID::MAP_ID_YAMA:
//		SetVolumeMusic(10);
//		PlayMusic("sound/yama.mp3", DX_PLAYTYPE_LOOP);
//		break;
//	case MAP_ID::MAP_ID_MATI:
//		SetVolumeMusic(10);
//		PlayMusic("sound/mati.mp3", DX_PLAYTYPE_LOOP);
//		break;
//	case MAP_ID::MAP_ID_TOUGI:
//
//		PlayMusic("sound/tougizyou.mp3", DX_PLAYTYPE_LOOP);
//		break;
//	default:
//		break;
//	}
//	if (mapID == MAP_ID::MAP_ID_YAMA)
//	{
//		SetVolumeMusic(80);
//	}
//	if (mapID == MAP_ID::MAP_ID_MATI)
//	{
//		SetVolumeMusic(100);
//	}
//	if (mapID == MAP_ID::MAP_ID_TOUGI)
//	{
//		SetVolumeMusic(100);
//	}
//
//}

void Skill::PlayerInit(Vector2 pos,Vector2 hitposS, Vector2 hitposE, Vector2 offset,Vector2 size, Vector2 pos2, Vector2 hitposS2, Vector2 hitposE2, Vector2 offset2, Vector2 size2)
{
	P1.posp = { pos.x-hitposS.x,pos.y-hitposS.y };
	P1.offsetPosp = { offset.x+hitposE.x,offset.y+hitposE.y };
	P1.hitPos = { P1.offsetPosp.x + 10,P1.posp.y + 10 };
	P1.hitoffsetPos = { P1.hitPos.x + 50,P1.hitPos.y + 70 };
	P1.AttackRange = { pos.x - offset.x , pos.y - offset.y };
	P1.Attackoffset = { pos.x + size.x - offset.x ,
			pos.y + size.y - offset.y };



	P2.posp = { pos2.x-hitposS2.x,pos2.y-hitposS2.y };
	P2.offsetPosp = { offset2.x+hitposE2.x,offset2.y+hitposE2.y };
	P2.hitPos = { P2.offsetPosp.x + 10,P2.posp.y + 10 };
	P2.hitoffsetPos = { P2.hitPos.x + 50,P2.hitPos.y + 70 };
	P2.AttackRange = { pos2.x - offset2.x , pos2.y - offset2.y };
	P2.Attackoffset = {pos2.x + size2.x - offset2.x ,
			pos2.y + size2.y - offset2.y };
	

}

void Skill::CharInit(CHAR_ID player1,CHAR_ID player2)
{
	if (player1 != CHAR_ID::CHAR_ID_MAX)
	{
		if (player1 == CHAR_ID::CHAR_ID_KISI)
		{
			P1.HP = 0;
			P1.LP = 100;
			P1.dmage = 10;
			P1.attack = 0;
			P1.defense = 0;
			P1.speed = 0;
		}
		if (player1 == CHAR_ID::CHAR_ID_MDOU)
		{
			P1.HP = 0;
			P1.LP = 50;
			P1.dmage = 10;
			P1.attack = 0;
			P1.defense = 0;
			P1.speed = 0;
		}
		if (player1 == CHAR_ID::CHAR_ID_BTOU)
		{
			P1.HP = 0;
			P1.LP = 30;
			P1.dmage = 10;
			P1.attack = 0;
			P1.defense = 0;
			P1.speed = 0;
		}
		if (player1 == CHAR_ID::CHAR_ID_4)
		{
			P1.HP = 0;
			P1.LP = 50;
			P1.dmage = 10;
			P1.attack = 0;
			P1.defense = 0;
			P1.speed = 5;
		}
	}
	if (player2 != CHAR_ID::CHAR_ID_MAX)
	{
		if (player2 == CHAR_ID::CHAR_ID_KISI)
		{
			P2.HP = 0;
			P2.LP = 100;
			P2.dmage = 10;
			P2.attack = 0;
			P2.defense = 0;
			P2.speed = 0;
		}
		if (player2 == CHAR_ID::CHAR_ID_MDOU)
		{
			P2.HP = 0;
			P2.LP = 50;
			P2.dmage = 10;
			P2.attack = 0;
			P2.defense = 0;
			P2.speed = 0;
		}
		if (player2 == CHAR_ID::CHAR_ID_BTOU)
		{
			P2.HP = 0;
			P2.LP = 30;
			P2.dmage = 10;
			P2.attack = 0;
			P2.defense = 0;
			P2.speed = 0;
		}
		if (player2 == CHAR_ID::CHAR_ID_4)
		{
			P2.HP = 0;
			P2.LP = 50;
			P2.dmage = 10;
			P2.attack = 0;
			P2.defense = 0;
			P2.speed = 5;
		}
	}
}

void Skill::SScountInit(void)
{
	P1.kisi.s1 = 0;
	P1.kisi.s2 = 0;
	P1.kisi.s3 = 0;
	P1.kisi.s4 = 0;

	P1.maho.s1 = 0;
	P1.maho.s2 = 0;
	P1.maho.s3 = 0;
	P1.maho.s4 = 0;

	P1.buto.s1 = 0;
	P1.buto.s2 = 0;
	P1.buto.s3 = 0;
	P1.buto.s4 = 0;

	P1.nazo.s1 = 0;
	P1.nazo.s2 = 0;
	P1.nazo.s3 = 0;
	P1.nazo.s4 = 0;

	P2.kisi.s1 = 0;
	P2.kisi.s2 = 0;
	P2.kisi.s3 = 0;
	P2.kisi.s4 = 0;

	P2.maho.s1 = 0;
	P2.maho.s2 = 0;
	P2.maho.s3 = 0;
	P2.maho.s4 = 0;

	P2.buto.s1 = 0;
	P2.buto.s2 = 0;
	P2.buto.s3 = 0;
	P2.buto.s4 = 0;

	P2.nazo.s1 = 0;
	P2.nazo.s2 = 0;
	P2.nazo.s3 = 0;
	P2.nazo.s4 = 0;
}

void Skill::StageDraw(CHAR_ID player1,CHAR_ID player2)
{
	int Anim = (P1.Scount / 6) % 10;
	int AnimS = (P1.Scount / 5) % 16;
	int AnimI = (P1.Scount / 5) % 12;
	int AnimL = (P1.Scount / 5) % 5;
	//for (int y = 0; y < mapSize.y; y++)
	//{
	//	for (int x = 0; x < mapSize.x; x++)
	//	{
	//		DrawGraph(x * CHIP_SIZE_X, y * CHIP_SIZE_Y, tougiImage[map[y][x]], true);
	//	}
	//}
	//DrawGraph(SCREEN_SIZE_X / 2 - TIME_SIZE_X, 0, timeImage[0], true);
	//DrawFormatString(0, 0, 0x000000, "%d", hamaCnt);
	if (player1 != CHAR_ID::CHAR_ID_MAX)
	{
		DrawFormatString(0, 20, 0x000000, "count:%d", P1.count);
		DrawFormatString(0, 40, 0x000000, "Scount:%d", P1.Scount);
		DrawFormatString(0, 60, 0x000000, "p1HP:%d", P1.HP);
		DrawFormatString(0, 80, 0x000000, "p1LP:%d", P1.LP);
		DrawFormatString(0, 100, 0x000000, "p1dmege:%d", P1.dmage);
		DrawFormatString(0, 120, 0x000000, "p1attack:%d", P1.attack);
		DrawFormatString(0, 140, 0x000000, "p1defense:%d", P1.defense);
		DrawFormatString(0, 160, 0x000000, "p1speed:%d", P1.speed);
		if (player1 == CHAR_ID::CHAR_ID_KISI)
		{
			DrawFormatString(0, 180, 0x000000, "ks1:%d", P1.kisi.s1);
			DrawFormatString(0, 200, 0x000000, "ks2:%d", P1.kisi.s2);
			DrawFormatString(0, 220, 0x000000, "ks3:%d", P1.kisi.s3);
			DrawFormatString(0, 240, 0x000000, "ks4:%d", P1.kisi.s4);
		}
		else if (player1 == CHAR_ID::CHAR_ID_MDOU)
		{
			DrawFormatString(0, 180, 0x000000, "ms1:%d", P1.maho.s1);
			DrawFormatString(0, 200, 0x000000, "ms2:%d", P1.maho.s2);
			DrawFormatString(0, 220, 0x000000, "ms3:%d", P1.maho.s3);
			DrawFormatString(0, 240, 0x000000, "ms4:%d", P1.maho.s4);
		}
		else if(player1 == CHAR_ID::CHAR_ID_BTOU)
		{
			DrawFormatString(0, 180, 0x000000, "bs1:%d", P1.buto.s1);
			DrawFormatString(0, 200, 0x000000, "bs2:%d", P1.buto.s2);
			DrawFormatString(0, 220, 0x000000, "bs3:%d", P1.buto.s3);
			DrawFormatString(0, 240, 0x000000, "bs4:%d", P1.buto.s4);
		}
		else if (player1 == CHAR_ID::CHAR_ID_4)
		{
			DrawFormatString(0, 180, 0x000000, "ns1:%d", P1.nazo.s1);
			DrawFormatString(0, 200, 0x000000, "ns2:%d", P1.nazo.s2);
			DrawFormatString(0, 220, 0x000000, "ns3:%d", P1.nazo.s3);
			DrawFormatString(0, 240, 0x000000, "ns4:%d", P1.nazo.s4);
		}
	}

	if (player2 != CHAR_ID::CHAR_ID_MAX)
	{
		DrawFormatString(850, 20, 0x000000, "count:%d", P2.count);
		DrawFormatString(850, 40, 0x000000, "Scount:%d", P2.Scount);
		DrawFormatString(850, 60, 0x000000, "p2HP:%d", P2.HP);
		DrawFormatString(850, 80, 0x000000, "p2LP:%d", P2.LP);
		DrawFormatString(850, 100, 0x000000, "p2dmege:%d", P2.dmage);
		DrawFormatString(850, 120, 0x000000, "p2attack:%d", P2.attack);
		DrawFormatString(850, 140, 0x000000, "p2defense:%d", P2.defense);
		DrawFormatString(850, 160, 0x000000, "p2speed:%d", P2.speed);
		if (player2 == CHAR_ID::CHAR_ID_KISI)
		{
			DrawFormatString(850, 180, 0x000000, "ks1:%d", P2.kisi.s1);
			DrawFormatString(850, 200, 0x000000, "ks2:%d", P2.kisi.s2);
			DrawFormatString(850, 220, 0x000000, "ks3:%d", P2.kisi.s3);
			DrawFormatString(850, 240, 0x000000, "ks4:%d", P2.kisi.s4);
		}
		else if (player2 == CHAR_ID::CHAR_ID_MDOU)
		{
			DrawFormatString(850, 180, 0x000000, "ms1:%d", P2.maho.s1);
			DrawFormatString(850, 200, 0x000000, "ms2:%d", P2.maho.s2);
			DrawFormatString(850, 220, 0x000000, "ms3:%d", P2.maho.s3);
			DrawFormatString(850, 240, 0x000000, "ms4:%d", P2.maho.s4);
		}
		else if (player2 == CHAR_ID::CHAR_ID_BTOU)
		{
			DrawFormatString(850, 180, 0x000000, "bs1:%d", P2.buto.s1);
			DrawFormatString(850, 200, 0x000000, "bs2:%d", P2.buto.s2);
			DrawFormatString(850, 220, 0x000000, "bs3:%d", P2.buto.s3);
			DrawFormatString(850, 240, 0x000000, "bs4:%d", P2.buto.s4);
		}
		else if (player2 == CHAR_ID::CHAR_ID_4)
		{
			DrawFormatString(850, 180, 0x000000, "ns1:%d", P2.nazo.s1);
			DrawFormatString(850, 200, 0x000000, "ns2:%d", P2.nazo.s2);
			DrawFormatString(850, 220, 0x000000, "ns3:%d", P2.nazo.s3);
			DrawFormatString(850, 240, 0x000000, "ns4:%d", P2.nazo.s4);
		}
	}
	/*if (hamaCnt > HAMA_CNT_1)
	{
		DrawGraph(hamaPos.x, hamaPos.y, hamaImage, true);
	}*/
	//P1
	//DrawBox(P1.AttackRange.x, P1.AttackRange.y, P1.Attackoffset.x, P1.Attackoffset.y, 0x000000, false);
	//DrawBox(P1.posp.x, P1.posp.y, P1.offsetPosp.x, P1.offsetPosp.y, 0xff00ff, false);
	//P2
	//DrawBox(P2.AttackRange.x, P2.AttackRange.y, P2.Attackoffset.x, P2.Attackoffset.y, 0x000000, false);
	
	//DrawBox(P2.posp.x, P2.posp.y, P2.offsetPosp.x, P2.offsetPosp.y, 0xff00ff, false);
	if (player1 != CHAR_ID::CHAR_ID_MAX)
	{
		// ÉLÉÉÉâÇP
		if (player1 == CHAR_ID::CHAR_ID_KISI)
		{
			if (CheckHitKey(KEY_INPUT_T) == 1)
			{
				DrawRotaGraph(P1.posp.x +25, P1.posp.y+50, 1.0f, 3.1415926535897932384626433832795f / 2, swordImage, true);
			}
			else
			{
				DrawGraph(P1.posp.x, P1.posp.y, swordImage, true);
				/*DrawRotaGraph2(325, 190, 0, 0, 1.5f, 0, swordImage, true);*/
			}
			if (P1.skill == SKILL_ID::SKILL_1)
			{
				if (P1.skillFlag == true)
				{
					DrawBox(P1.hitPos.x, P1.hitPos.y, P1.hitoffsetPos.x, P1.hitoffsetPos.y, 0xffff88, true);
					//DrawGraph(P1.hitoffsetPos.x+10,posp.y-120,slashImage[AnimS],true);
				}
			}
			if (P1.skill == SKILL_ID::SKILL_2)
			{
				if (P1.bufFlag == true)
				{
					DrawGraph(P1.posp.x - 43, P1.posp.y - 55, healImage[Anim], true);
				}
			}
			if (P1.skill == SKILL_ID::SKILL_3)
			{
				//DrawBox(posp.x, posp.y, offsetPosp.x, offsetPosp.y,  0x88ffff, true);
				

				if (P1.bufFlag == true)
				{
					DrawGraph(P1.posp.x - 43, P1.posp.y - 55, buffUImage[Anim], true);
					//DrawBox(P1.hitPos.x, P1.hitPos.y, P1.hitoffsetPos.x, P1.hitoffsetPos.y, 0x88ffff, true);
				}
			}
			if (P1.skill == SKILL_ID::SKILL_4)
			{
				//DrawBox(posp.x, posp.y, offsetPosp.x, offsetPosp.y, 0xffffff, true);
				//DrawGraph(P1.posp.x - 10, P1.posp.y - 10, healImage[Anim], true);
				if (P1.skillFlag == true)
				{
					
						//DrawGraph(P1.posp.x - 10, P1.posp.y - 10, laserImage[AnimL], true);
						DrawBox(P1.hitPos.x, P1.hitPos.y, P1.hitoffsetPos.x, P1.hitoffsetPos.y, 0xffffff, true);
					
				}
			}
		}
		// ÉLÉÉÉâÇQ
		if (player1 == CHAR_ID::CHAR_ID_MDOU)
		{
			if (P1.skill == SKILL_ID::SKILL_1)
			{
				if (P1.skillFlag == true)
				{
					DrawBox(P1.hitPos.x, P1.hitPos.y, P1.hitoffsetPos.x, P1.hitoffsetPos.y, 0xffff88, true);
					//DrawGraph(P1.hitoffsetPos.x+10,posp.y-120,slashImage[AnimS],true);
				}
			}
			if (P1.skill == SKILL_ID::SKILL_2)
			{
				if (P1.bufFlag == true)
				{
					DrawGraph(P1.posp.x - 43, P1.posp.y - 55, buffSImage[Anim], true);
				}
			}
			if (P1.skill == SKILL_ID::SKILL_3)
			{
				//DrawBox(posp.x, posp.y, offsetPosp.x, offsetPosp.y,  0x88ffff, true);


				if (P1.bufFlag == true)
				{
					DrawGraph(P1.posp.x - 43, P1.posp.y - 55, buffUImage[Anim], true);
					//DrawBox(P1.hitPos.x, P1.hitPos.y, P1.hitoffsetPos.x, P1.hitoffsetPos.y, 0x88ffff, true);
				}
			}
			if (P1.skill == SKILL_ID::SKILL_4)
			{
				//DrawBox(posp.x, posp.y, offsetPosp.x, offsetPosp.y, 0xffffff, true);
				//DrawGraph(P1.posp.x - 10, P1.posp.y - 10, healImage[Anim], true);
				if (P1.skillFlag == true)
				{
					
						DrawGraph(P1.posp.x - 10, P1.posp.y - 10, laserImage[AnimL], true);
						//DrawBox(P1.hitPos.x, P1.hitPos.y, P1.hitoffsetPos.x, P1.hitoffsetPos.y, 0xffffff, true);
					
				}
			}
		}
		// ÉLÉÉÉâÇR
		if (player1 == CHAR_ID::CHAR_ID_BTOU)
		{
			if (P1.skill == SKILL_ID::SKILL_1)
			{
				if (P1.skillFlag == true)
				{
					DrawBox(P1.hitPos.x, P1.hitPos.y, P1.hitoffsetPos.x, P1.hitoffsetPos.y, 0xffff88, true);
					//DrawGraph(P1.hitoffsetPos.x+10,posp.y-120,slashImage[AnimS],true);
				}
			}
			if (P1.skill == SKILL_ID::SKILL_2)
			{
				if (P1.bufFlag == true)
				{
					DrawGraph(P1.posp.x - 43, P1.posp.y - 55, buffDImage[Anim], true);
				}
			}
			if (P1.skill == SKILL_ID::SKILL_3)
			{
				//DrawBox(posp.x, posp.y, offsetPosp.x, offsetPosp.y,  0x88ffff, true);
				if (P1.bufFlag == true)
				{
					DrawGraph(P1.posp.x - 43, P1.posp.y - 55, buffUImage[Anim], true);
				}

				//if (skillFlag == true)
				//{
					//DrawBox(P1.hitPos.x, P1.hitPos.y, P1.hitoffsetPos.x, P1.hitoffsetPos.y, 0x88ffff, true);
				//}
			}
			if (P1.skill == SKILL_ID::SKILL_4)
			{
				//DrawBox(posp.x, posp.y, offsetPosp.x, offsetPosp.y, 0xffffff, true);
				//DrawGraph(P1.posp.x - 10, P1.posp.y - 10, healImage[Anim], true);
				if (P1.bufFlag == true)
				{
					DrawGraph(P1.posp.x - 43, P1.posp.y - 55, healImage[Anim], true);
						//DrawGraph(P1.posp.x - 10, P1.posp.y - 10, laserImage[AnimL], true);
					//DrawBox(P1.hitPos.x, P1.hitPos.y, P1.hitoffsetPos.x, P1.hitoffsetPos.y, 0xffffff, true);
				}
			}
		}
		// ÉLÉÉÉâÇS
		if (player1 == CHAR_ID::CHAR_ID_4)
		{
			if (P1.skill == SKILL_ID::SKILL_1)
			{
				if (P1.skillFlag == true)
				{
					DrawBox(P1.hitPos.x, P1.hitPos.y, P1.hitoffsetPos.x, P1.hitoffsetPos.y, 0xffff88, true);
					//DrawGraph(P1.hitoffsetPos.x+10,posp.y-120,slashImage[AnimS],true);
				}
			}
			if (P1.skill == SKILL_ID::SKILL_2)
			{
				if (P1.bufFlag == true)
				{
					DrawGraph(P1.posp.x - 43, P1.posp.y - 55, buffDImage[Anim], true);
				}
			}
			if (P1.skill == SKILL_ID::SKILL_3)
			{
				//DrawBox(posp.x, posp.y, offsetPosp.x, offsetPosp.y,  0x88ffff, true);
				//DrawGraph(P1.posp.x - 10, P1.posp.y - 10, buffUImage[Anim], true);

				if (P1.skillFlag == true)
				{
					DrawBox(P1.hitPos.x, P1.hitPos.y, P1.hitoffsetPos.x, P1.hitoffsetPos.y, 0x88ffff, true);
				}
			}
			if (P1.skill == SKILL_ID::SKILL_4)
			{
				//DrawBox(posp.x, posp.y, offsetPosp.x, offsetPosp.y, 0xffffff, true);
				//DrawGraph(P1.posp.x - 10, P1.posp.y - 10, healImage[Anim], true);
				if (P1.skillFlag == true)
				{
					
						//DrawGraph(P1.posp.x - 10, P1.posp.y - 10, laserImage[AnimL], true);
						DrawBox(P1.hitPos.x, P1.hitPos.y, P1.hitoffsetPos.x, P1.hitoffsetPos.y, 0xffffff, true);
					
				}
			}
		}
	}
	if (player2 != CHAR_ID::CHAR_ID_MAX)
	{
		// ÉLÉÉÉâÇP
		if (player2 == CHAR_ID::CHAR_ID_KISI)
		{
			if (P2.skill == SKILL_ID::SKILL_1)
			{
				if (P2.skillFlag == true)
				{
					DrawBox(P2.hitPos.x, P2.hitPos.y, P2.hitoffsetPos.x, P2.hitoffsetPos.y, 0xffff88, true);
					//DrawGraph(P1.hitoffsetPos.x+10,posp.y-120,slashImage[AnimS],true);
				}
			}
			if (P2.skill == SKILL_ID::SKILL_2)
			{
				if (P2.bufFlag == true)
				{
					DrawGraph(P2.posp.x - 43, P2.posp.y - 55, healImage[Anim], true);
				}
			}
			if (P2.skill == SKILL_ID::SKILL_3)
			{
				//DrawBox(posp.x, posp.y, offsetPosp.x, offsetPosp.y,  0x88ffff, true);


				if (P2.bufFlag == true)
				{
					DrawGraph(P2.posp.x - 43, P2.posp.y - 55, buffUImage[Anim], true);
					//DrawBox(P1.hitPos.x, P1.hitPos.y, P1.hitoffsetPos.x, P1.hitoffsetPos.y, 0x88ffff, true);
				}
			}
			if (P2.skill == SKILL_ID::SKILL_4)
			{
				//DrawBox(posp.x, posp.y, offsetPosp.x, offsetPosp.y, 0xffffff, true);
				//DrawGraph(P1.posp.x - 10, P1.posp.y - 10, healImage[Anim], true);
				if (P2.skillFlag == true)
				{
					
						//DrawGraph(P1.posp.x - 10, P1.posp.y - 10, laserImage[AnimL], true);
						DrawBox(P2.hitPos.x, P2.hitPos.y, P2.hitoffsetPos.x, P2.hitoffsetPos.y, 0xffffff, true);
					
				}
			}
		}
		// ÉLÉÉÉâÇQ
		if (player2 == CHAR_ID::CHAR_ID_MDOU)
		{
			if (P2.skill == SKILL_ID::SKILL_1)
			{
				if (P2.skillFlag == true)
				{
					DrawBox(P2.hitPos.x, P2.hitPos.y, P2.hitoffsetPos.x, P2.hitoffsetPos.y, 0xffff88, true);
					//DrawGraph(P1.hitoffsetPos.x+10,posp.y-120,slashImage[AnimS],true);
				}
			}
			if (P2.skill == SKILL_ID::SKILL_2)
			{
				if (P2.bufFlag == true)
				{
					DrawGraph(P2.posp.x - 43, P2.posp.y - 55, buffSImage[Anim], true);
				}
			}
			if (P2.skill == SKILL_ID::SKILL_3)
			{
				//DrawBox(posp.x, posp.y, offsetPosp.x, offsetPosp.y,  0x88ffff, true);


				if (P2.bufFlag == true)
				{
					DrawGraph(P2.posp.x - 43, P2.posp.y - 55, buffUImage[Anim], true);
					//DrawBox(P1.hitPos.x, P1.hitPos.y, P1.hitoffsetPos.x, P1.hitoffsetPos.y, 0x88ffff, true);
				}
			}
			if (P2.skill == SKILL_ID::SKILL_4)
			{
				//DrawBox(posp.x, posp.y, offsetPosp.x, offsetPosp.y, 0xffffff, true);
				//DrawGraph(P1.posp.x - 10, P1.posp.y - 10, healImage[Anim], true);
				if (P2.skillFlag == true)
				{
					
					DrawGraph(P2.posp.x - 10, P2.posp.y - 10, laserImage[AnimL], true);
						//DrawBox(P1.hitPos.x, P1.hitPos.y, P1.hitoffsetPos.x, P1.hitoffsetPos.y, 0xffffff, true);
					
				}
			}
		}
		// ÉLÉÉÉâÇR
		if (player2 == CHAR_ID::CHAR_ID_BTOU)
		{
			if (P2.skill == SKILL_ID::SKILL_1)
			{
				if (P2.skillFlag == true)
				{
					DrawBox(P2.hitPos.x, P2.hitPos.y, P2.hitoffsetPos.x, P2.hitoffsetPos.y, 0xffff88, true);
					//DrawGraph(P1.hitoffsetPos.x+10,posp.y-120,slashImage[AnimS],true);
				}
			}
			if (P2.skill == SKILL_ID::SKILL_2)
			{
				if (P2.bufFlag == true)
				{
					DrawGraph(P2.posp.x - 43, P2.posp.y - 55, buffDImage[Anim], true);
				}
			}
			if (P2.skill == SKILL_ID::SKILL_3)
			{
				//DrawBox(posp.x, posp.y, offsetPosp.x, offsetPosp.y,  0x88ffff, true);
				if (P2.bufFlag == true)
				{
					DrawGraph(P2.posp.x - 43, P2.posp.y - 55, buffUImage[Anim], true);
				}

				//if (skillFlag == true)
				//{
					//DrawBox(P1.hitPos.x, P1.hitPos.y, P1.hitoffsetPos.x, P1.hitoffsetPos.y, 0x88ffff, true);
				//}
			}
			if (P2.skill == SKILL_ID::SKILL_4)
			{
				//DrawBox(posp.x, posp.y, offsetPosp.x, offsetPosp.y, 0xffffff, true);
				//DrawGraph(P1.posp.x - 10, P1.posp.y - 10, healImage[Anim], true);
				if (P2.bufFlag == true)
				{
					DrawGraph(P2.posp.x - 43, P2.posp.y - 55, healImage[Anim], true);
					//DrawGraph(P1.posp.x - 10, P1.posp.y - 10, laserImage[AnimL], true);
				//DrawBox(P1.hitPos.x, P1.hitPos.y, P1.hitoffsetPos.x, P1.hitoffsetPos.y, 0xffffff, true);

				}
			}
		}
		// ÉLÉÉÉâÇS
		if (player2 == CHAR_ID::CHAR_ID_4)
		{
			if (P2.skill == SKILL_ID::SKILL_1)
			{
				if (P2.skillFlag == true)
				{
					DrawBox(P2.hitPos.x, P2.hitPos.y, P2.hitoffsetPos.x, P2.hitoffsetPos.y, 0xffff88, true);
					//DrawGraph(P1.hitoffsetPos.x+10,posp.y-120,slashImage[AnimS],true);
				}
			}
			if (P2.skill == SKILL_ID::SKILL_2)
			{
				if (P2.bufFlag == true)
				{
					DrawGraph(P2.posp.x - 43, P2.posp.y - 55, buffDImage[Anim], true);
				}
			}
			if (P2.skill == SKILL_ID::SKILL_3)
			{
				//DrawBox(posp.x, posp.y, offsetPosp.x, offsetPosp.y,  0x88ffff, true);
				//DrawGraph(P1.posp.x - 10, P1.posp.y - 10, buffUImage[Anim], true);

				if (P2.skillFlag == true)
				{
					DrawBox(P2.hitPos.x, P2.hitPos.y, P2.hitoffsetPos.x, P2.hitoffsetPos.y, 0x88ffff, true);
				}
			}
			if (P2.skill == SKILL_ID::SKILL_4)
			{
				//DrawBox(posp.x, posp.y, offsetPosp.x, offsetPosp.y, 0xffffff, true);
				//DrawGraph(P1.posp.x - 10, P1.posp.y - 10, healImage[Anim], true);
				if (P2.skillFlag == true)
				{
					//DrawGraph(P1.posp.x - 10, P1.posp.y - 10, laserImage[AnimL], true);
					DrawBox(P2.hitPos.x, P2.hitPos.y, P2.hitoffsetPos.x, P2.hitoffsetPos.y, 0xffffff, true);
				}
			}
		}
	}


	//ÉXÉLÉãUI
	if (player1 != CHAR_ID::CHAR_ID_MAX)
	{
		if (player1 == CHAR_ID::CHAR_ID_KISI)
		{
			DrawGraph(0,70,uiheal,true);
			DrawGraph(100, 70, uibuffU, true);
			DrawGraph(50,70, uitate, true);
			DrawGraph(150, 70, uisra, true);

		}
		if (player1 == CHAR_ID::CHAR_ID_MDOU)
		{
			DrawGraph(0, 70, uibuffU, true);
			DrawGraph(100, 70, uibuffU, true);
			DrawGraph(50, 70, uimaho, true);
			DrawGraph(150, 70, uiles, true);
		}
		if (player1 == CHAR_ID::CHAR_ID_BTOU)
		{
			DrawGraph(0, 70, uibuffU, true);
			DrawGraph(100, 70, uibuffU, true);
			DrawGraph(50, 70, uihand, true);
			DrawGraph(150, 70, uiheal, true);
		}
		if (player1 == CHAR_ID::CHAR_ID_4)
		{
			DrawGraph(0, 70, uibuffU, true);
			DrawGraph(100, 70, uiken, true);
			DrawGraph(50, 70, uilej, true);
			DrawGraph(150, 70, uisra, true);
		}
	}
	if (player2 != CHAR_ID::CHAR_ID_MAX)
	{
		if (player2 == CHAR_ID::CHAR_ID_KISI)
		{
			DrawGraph(800, 70, uiheal, true);
			DrawGraph(900, 70, uibuffU, true);
			DrawGraph(850, 70, uitate, true);
			DrawGraph(950, 70, uisra, true);
		}
		if (player2 == CHAR_ID::CHAR_ID_MDOU)
		{
			DrawGraph(800, 70, uibuffU, true);
			DrawGraph(900, 70, uibuffU, true);
			DrawGraph(850, 70, uimaho, true);
			DrawGraph(950, 70, uiles, true);
		}
		if (player2 == CHAR_ID::CHAR_ID_BTOU)
		{
			DrawGraph(800, 70, uibuffU, true);
			DrawGraph(900, 70, uibuffU, true);
			DrawGraph(850, 70, uihand, true);
			DrawGraph(950, 70, uiheal, true);
		}
		if (player2 == CHAR_ID::CHAR_ID_4)
		{
			DrawGraph(800, 70, uibuffU, true);
			DrawGraph(900, 70, uiken, true);
			DrawGraph(850, 70, uilej, true);
			DrawGraph(950, 70, uisra, true);
		}
	}


}

void Skill::SkillDraw(void)
{
}

void Skill::HamaTime(void)
{


}

void Skill::SkillCtl(CHAR_ID player1, CHAR_ID player2)
{


	/// player1(ãRém)
	if (player1 == CHAR_ID::CHAR_ID_KISI)
	{
		if (CheckHitKey(KEY_INPUT_U) == 1)
		{

			P1.hitPos.x = P1.offsetPosp.x;
			P1.hitoffsetPos.x = P1.offsetPosp.x + 50;
			P1.skill = SKILL_ID::SKILL_1;
			if (P1.kisi.s1 / 300)//ëÂëÃ5ïb
			{
				P1.skillFlag = true;
				P1.count = 0;
			}
		}
		if (P1.skill == SKILL_ID::SKILL_1)
		{
			if (P1.skillFlag == true)
			{

				if (P1.count / 10)
				{
					if (P1.hitoffsetPos.x < P1.Attackoffset.x - 40)
					{
						P1.hitPos.x += 2;
						P1.hitoffsetPos.x += 2;
					}
					else
					{
						P1.skillFlag = false;
						P1.hitPos = { P1.offsetPosp.x + 10,P1.posp.y + 10 };
						P1.hitoffsetPos = { P1.hitPos.x + 50,P1.hitPos.y + 70 };
					}
					if (P1.offsetPosp.x > P1.hitPos.x)
					{
						P1.skillFlag = false;
						P1.hitPos = { P1.offsetPosp.x + 10,P1.posp.y + 10 };
						P1.hitoffsetPos = { P1.hitPos.x + 50,P1.hitPos.y + 70 };
					}
				}
				P1.kisi.s1 = 0;
			}

		}

		if (CheckHitKey(KEY_INPUT_I) == 1)
		{
			if (P1.kisi.s2 / 4200)
			{
				P1.skill = SKILL_ID::SKILL_2;

				P1.skillFlag = true;
				P1.bufFlag = true;
			}
			else
			{
				P1.skillFlag = false;
			}
		}
		if (CheckHitKey(KEY_INPUT_J) == 1)
		{
			if (P1.kisi.s3 / 360)
			{
				P1.skill = SKILL_ID::SKILL_3;

				P1.skillFlag = true;
				P1.bufFlag = true;
			}
			else
			{
				P1.skillFlag = false;
			}

		}
		if (CheckHitKey(KEY_INPUT_K) == 1)
		{
			if (P1.SSflag == true)
			{
				if (P1.LP <= 10)
				{
					P1.skill = SKILL_ID::SKILL_4;
					P1.skillFlag = true;
					P1.count = 0;
				}
			}
		}
		if (P1.skill == SKILL_ID::SKILL_4)
		{
			if (P1.skillFlag == true)
			{
				if (P1.count / 5)
				{
					if (P1.hitPos.y > 450)
					{
						P1.hitPos.y -= 10;
					}
					if (P1.hitoffsetPos.x < P1.Attackoffset.x + 120)
					{
						P1.hitoffsetPos.x += 10;
					}
					else
					{
						P1.skillFlag = false;
					}
				}
			}
			else if (P1.skillFlag == false)
			{
				P1.SSflag = false;
				P1.hitPos = { P1.offsetPosp.x + 10,P1.posp.y + 10 };
				P1.hitoffsetPos = { P1.hitPos.x + 50,P1.hitPos.y + 70 };
			}
		}
	}
	if (player2 == CHAR_ID::CHAR_ID_KISI)
	{
		if (CheckHitKey(KEY_INPUT_Q) == 1)
		{

			P2.hitPos.x = P2.offsetPosp.x;
			P2.hitoffsetPos.x = P2.offsetPosp.x + 50;
			P2.skill = SKILL_ID::SKILL_1;
			if (P2.kisi.s1 / 300)//ëÂëÃ5ïb
			{
				P2.skillFlag = true;
				P2.count = 0;
			}
		}
		if (P2.skill == SKILL_ID::SKILL_1)
		{
			if (P2.skillFlag == true)
			{

				if (P2.count / 10)
				{
					if (P2.hitoffsetPos.x < P2.Attackoffset.x - 40)
					{
						P2.hitPos.x += 2;
						P2.hitoffsetPos.x += 2;
					}
					else
					{
						P2.skillFlag = false;
						P2.hitPos = { P2.offsetPosp.x + 10,P2.posp.y + 10 };
						P2.hitoffsetPos = { P2.hitPos.x + 50,P2.hitPos.y + 70 };
					}
					if (P2.offsetPosp.x > P2.hitPos.x)
					{
						P2.skillFlag = false;
						P2.hitPos = { P2.offsetPosp.x + 10,P2.posp.y + 10 };
						P2.hitoffsetPos = { P2.hitPos.x + 50,P2.hitPos.y + 70 };
					}
				}
				P2.kisi.s1 = 0;
			}

		}

		if (CheckHitKey(KEY_INPUT_W) == 1)
		{
			if (P2.kisi.s2 / 4200)
			{
				P2.skill = SKILL_ID::SKILL_2;

				P2.skillFlag = true;
				P2.bufFlag = true;
			}
			else
			{
				P2.skillFlag = false;
			}

		}
		if (CheckHitKey(KEY_INPUT_A) == 1)
		{
			if (P2.kisi.s3 / 60)
			{
				P2.skill = SKILL_ID::SKILL_3;

				P2.skillFlag = true;
				P2.bufFlag = true;
			}
			else
			{
				P1.skillFlag = false;
			}

		}
		if (CheckHitKey(KEY_INPUT_S) == 1)
		{
			if (P2.SSflag == true)
			{
				if (P2.LP <= 10)
				{
					P2.skill = SKILL_ID::SKILL_4;
					P2.skillFlag = true;
					P2.count = 0;
				}
			}
		}
		if (P2.skill == SKILL_ID::SKILL_4)
		{
			if (P2.skillFlag == true)
			{
				if (P2.count / 5)
				{
					if (P2.hitPos.y > 450)
					{
						P2.hitPos.y -= 10;
					}
					if (P2.hitoffsetPos.x < P2.Attackoffset.x + 120)
					{
						P2.hitoffsetPos.x += 10;
					}
					else
					{
						P2.skillFlag = false;
					}
				}
			}
			else if (P2.skillFlag == false)
			{
				P2.SSflag = false;
				P1.hitPos = { P2.offsetPosp.x + 10,P2.posp.y + 10 };
				P1.hitoffsetPos = { P2.hitPos.x + 50,P2.hitPos.y + 70 };
			}
		}
	}

	///player2(ñÇñ@égÇ¢)
	if (player1 == CHAR_ID::CHAR_ID_MDOU)
	{
		if (CheckHitKey(KEY_INPUT_U) == 1)
		{

			P1.skill = SKILL_ID::SKILL_1;
			if (P1.maho.s1 / 300)
			{
				P1.skillFlag = true;
			}
		}
		if (P1.skill == SKILL_ID::SKILL_1)
		{
			if (P1.skillFlag == true)
			{
				if (P1.hitoffsetPos.x < P1.Attackoffset.x + 300)
				{
					P1.hitPos.x += 10;
					P1.hitoffsetPos.x += 10;
				}
				else
				{
					P1.skillFlag = false;
					P1.hitPos = { P1.offsetPosp.x + 10,P1.posp.y + 10 };
					P1.hitoffsetPos = { P1.hitPos.x + 50,P1.hitPos.y + 70 };
				}
			}
		}
		if (CheckHitKey(KEY_INPUT_I) == 1)
		{
			P1.skill = SKILL_ID::SKILL_2;
			if (P1.maho.s2 / 1200)
			{
				P1.skillFlag = true;
				P1.bufFlag = true;

			}
		}
		if (CheckHitKey(KEY_INPUT_J) == 1)
		{
			P1.skill = SKILL_ID::SKILL_3;
			if (P1.maho.s3 / 1000)
			{
				P1.skillFlag = true;
				P1.bufFlag = true;
			}
		}
		if (CheckHitKey(KEY_INPUT_K) == 1)
		{
			if (P1.LP <= 50)
			{
				P1.skill = SKILL_ID::SKILL_4;
				if (P1.maho.s4 / 1800)
				{
					P1.count = 0;
					P1.skillFlag = true;
				}
			}
		}
		if (P1.skill == SKILL_ID::SKILL_4)
		{
			if (P1.skillFlag == true)
			{
				if (P1.count / 240)
				{
					if (P1.hitPos.y > 250)
					{
						P1.hitPos.y -= 20;
					}
					if (P1.hitoffsetPos.x < 1000)
					{
						P1.hitoffsetPos.x += 20;
					}
				}
				if (P1.count / 540)
				{
					P1.skillFlag = false;
				}
			}
			else if (P1.skillFlag == false)
			{
				P1.hitPos = { P1.offsetPosp.x + 10,P1.posp.y + 10 };
				P1.hitoffsetPos = { P1.hitPos.x + 50,P1.hitPos.y + 70 };
			}
		}
	}
	if (player2 == CHAR_ID::CHAR_ID_MDOU)
	{
		if (CheckHitKey(KEY_INPUT_Q) == 1)
		{

			P2.skill = SKILL_ID::SKILL_1;
			if (P2.maho.s1 / 300)
			{
				P2.skillFlag = true;
			}
		}
		if (P2.skill == SKILL_ID::SKILL_1)
		{
			if (P2.skillFlag == true)
			{
				if (P2.hitoffsetPos.x < P2.Attackoffset.x + 300)
				{
					P2.hitPos.x += 10;
					P2.hitoffsetPos.x += 10;
				}
				else
				{
					P2.skillFlag = false;
					P2.hitPos = { P2.offsetPosp.x + 10,P2.posp.y + 10 };
					P2.hitoffsetPos = { P2.hitPos.x + 50,P2.hitPos.y + 70 };
				}
			}
		}
		if (CheckHitKey(KEY_INPUT_W) == 1)
		{
			P2.skill = SKILL_ID::SKILL_2;
			if (P2.maho.s2 / 1200)
			{
				P2.skillFlag = true;
				P2.bufFlag = true;
			}
		}
		if (CheckHitKey(KEY_INPUT_A) == 1)
		{
			P2.skill = SKILL_ID::SKILL_3;
			if (P2.maho.s3 / 1000)
			{
				P2.skillFlag = true;
				P2.bufFlag = true;
			}
		}
		if (CheckHitKey(KEY_INPUT_S) == 1)
		{
			if (P2.LP <= 50)
			{
				P2.skill = SKILL_ID::SKILL_4;
				if (P2.maho.s4 / 1800)
				{
					P2.count = 0;
					P2.skillFlag = true;
				}
			}
		}
		if (P2.skill == SKILL_ID::SKILL_4)
		{
			if (P2.skillFlag == true)
			{
				if (P2.count / 240)
				{
					if (P2.hitPos.y > 250)
					{
						P2.hitPos.y -= 20;
					}
					if (P2.hitoffsetPos.x < 1000)
					{
						P2.hitoffsetPos.x += 20;
					}
				}
				if (P2.count / 540)
				{
					P2.skillFlag = false;
				}
			}
			else if (P2.skillFlag == false)
			{
				P2.hitPos = { P2.offsetPosp.x + 10,P2.posp.y + 10 };
				P2.hitoffsetPos = { P2.hitPos.x + 50,P2.hitPos.y + 70 };
			}
		}
	}

	///plaeyr3(ïêì¨â∆)
	if (player1 == CHAR_ID::CHAR_ID_BTOU)
	{
		if (CheckHitKey(KEY_INPUT_U) == 1)
		{

			P1.skill = SKILL_ID::SKILL_1;
			if (P1.buto.s1 / 300)
			{
				P1.skillFlag = true;
			}

		}
		if (P1.skill == SKILL_ID::SKILL_1)
		{
			if (P1.skillFlag == true)
			{
				if (P1.hitPos.y > 400)
				{
					P1.hitPos.y -= 10;
					P1.hitoffsetPos.y -= 10;
				}
				if (P1.hitoffsetPos.x < P1.Attackoffset.x)
				{
					P1.hitPos.x += 10;
					P1.hitoffsetPos.x += 10;
				}
				else
				{
					P1.skillFlag = false;
				}
				P1.buto.s1 = 0;
			}
			else if (P1.skillFlag == false)
			{

				P1.hitPos = { P1.offsetPosp.x + 10,P1.posp.y + 10 };
				P1.hitoffsetPos = { P1.hitPos.x + 50,P1.hitPos.y + 70 };
			}
		}

		if (CheckHitKey(KEY_INPUT_I) == 1)
		{
			if (P1.buto.s2 / 600)
			{
				P1.skill = SKILL_ID::SKILL_2;

				P1.skillFlag = true;
				P1.bufFlag = true;
			}
		}
		if (CheckHitKey(KEY_INPUT_J) == 1)
		{
			if (P1.buto.s3 / 1200)
			{
				P1.skill = SKILL_ID::SKILL_3;
				P1.skillFlag = true;
				P1.bufFlag = true;
			}
		}
		if (CheckHitKey(KEY_INPUT_K) == 1)
		{
			if (P1.buto.s4 / 600)
			{
				if (P1.LP <= 30)
				{
					P1.skill = SKILL_ID::SKILL_4;
					P1.skillFlag = true;
					P1.bufFlag = true;
				}
			}
		}
	}
	if (player2 == CHAR_ID::CHAR_ID_BTOU)
	{
		if (CheckHitKey(KEY_INPUT_Q) == 1)
		{

			P2.skill = SKILL_ID::SKILL_1;
			if (P2.buto.s1 / 300)
			{
				P2.skillFlag = true;
			}

		}
		if (P2.skill == SKILL_ID::SKILL_1)
		{
			if (P2.skillFlag == true)
			{
				if (P2.hitPos.y > 400)
				{
					P2.hitPos.y -= 10;
					P2.hitoffsetPos.y -= 10;
				}
				if (P2.hitoffsetPos.x < P2.Attackoffset.x)
				{
					P2.hitPos.x += 10;
					P2.hitoffsetPos.x += 10;
				}
				else
				{
					P2.skillFlag = false;
				}
				P2.buto.s1 = 0;
			}
			else if (P2.skillFlag == false)
			{

				P2.hitPos = { P2.offsetPosp.x + 10,P2.posp.y + 10 };
				P2.hitoffsetPos = { P2.hitPos.x + 50,P2.hitPos.y + 70 };
			}
		}

		if (CheckHitKey(KEY_INPUT_W) == 1)
		{
			if (P2.buto.s2 / 600)
			{
				P2.skill = SKILL_ID::SKILL_2;

				P2.skillFlag = true;
				P2.bufFlag = true;
			}
		}
		if (CheckHitKey(KEY_INPUT_A) == 1)
		{
			if (P2.buto.s3 / 1200)
			{
				P2.skill = SKILL_ID::SKILL_3;
				P2.skillFlag = true;
				P2.bufFlag = true;
			}
		}
		if (CheckHitKey(KEY_INPUT_S) == 1)
		{
			if (P2.buto.s4 / 600)
			{
				if (P2.LP <= 30)
				{
					P2.skill = SKILL_ID::SKILL_4;
					P2.skillFlag = true;
					P2.bufFlag = true;
				}
			}
		}
	}
	///player4(íj)
	if (player1 == CHAR_ID::CHAR_ID_4)
	{
		if (CheckHitKey(KEY_INPUT_U) == 1)
		{
			if (P1.nazo.s1 / 300)
			{
				P1.skillFlag = true;
				P1.skill = SKILL_ID::SKILL_1;
			}
		}
		if (P1.skill == SKILL_ID::SKILL_1)
		{
			if (P1.skillFlag == true)
			{
				if ((P1.hitoffsetPos.x > P1.Attackoffset.x - 50) && (P1.hitPos.y > 300))
				{
					P1.hitPos.y -= 10;

				}
				if (P1.hitoffsetPos.x < P1.Attackoffset.x + 100)
				{
					P1.hitPos.x += 10;
					P1.hitoffsetPos.x += 10;
				}
				else
				{
					P1.skillFlag = false;
					P1.hitPos = { P1.offsetPosp.x + 10,P1.posp.y + 10 };
					P1.hitoffsetPos = { P1.hitPos.x + 50,P1.hitPos.y + 70 };
				}
				P1.nazo.s1 = 0;
			}
		}

		if (CheckHitKey(KEY_INPUT_I) == 1)
		{
			if (P1.nazo.s2 / 600)
			{
				P1.skill = SKILL_ID::SKILL_2;
				P1.skillFlag = true;
				P1.bufFlag = true;
			}
		}
		if (CheckHitKey(KEY_INPUT_J) == 1)
		{
			if (P1.nazo.s3 / 1000)
			{
				P1.skillFlag = true;
				P1.skill = SKILL_ID::SKILL_3;
				P1.hitPos.x = P1.offsetPosp.x;
				P1.hitoffsetPos.x = P1.offsetPosp.x + 50;
			}
		}
		if (P1.skill == SKILL_ID::SKILL_3)
		{
			if (P1.skillFlag == true)
			{
				P1.nazo.s3 = 0;
				if (P1.hitPos.y > 450)
				{
					P1.hitPos.y -= 1;
					P1.hitoffsetPos.y -= 1;
				}
				if (P1.hitoffsetPos.x < P1.Attackoffset.x - 40)
				{
					P1.hitPos.x += 1;
					P1.hitoffsetPos.x += 1;

				}
				else
				{
					P1.skillFlag = false;
				}
		
			}
			else if (P1.skillFlag == false)
			{
				P1.hitPos = { P1.offsetPosp.x + 10,P1.posp.y + 10 };
				P1.hitoffsetPos = { P1.hitPos.x + 50,P1.hitPos.y + 70 };
			}
		}
		if (CheckHitKey(KEY_INPUT_K) == 1)
		{
			if (P1.LP <= 50)
			{
				if (P1.nazo.s4 / 1800)
				{
					P1.skillFlag = true;
					P1.count = 0;
					P1.skill = SKILL_ID::SKILL_4;
				}

			}

		}
		if (P1.skill == SKILL_ID::SKILL_4)
		{
			if (P1.skillFlag == true)
			{
				if (P1.count / 60)
				{
					if (P1.hitPos.y > 450)
					{
						P1.hitPos.y -= 20;
					}
					if (P1.hitoffsetPos.x < P1.Attackoffset.x + 100)
					{
						P1.hitoffsetPos.x += 20;
					}
				}
				if (P1.count / 120)
				{
					P1.skillFlag = false;
				}
			}
			else if (P1.skillFlag == false)
			{
				P1.hitPos = { P1.offsetPosp.x + 10,P1.posp.y + 10 };
				P1.hitoffsetPos = { P1.hitPos.x + 50,P1.hitPos.y + 70 };
			}
		}
	}
	if (player2 == CHAR_ID::CHAR_ID_4)
	{
		if (CheckHitKey(KEY_INPUT_Q) == 1)
		{
			if (P2.nazo.s1 / 300)
			{
				P2.skillFlag = true;
				P2.skill = SKILL_ID::SKILL_1;
			}
		}
		if (P2.skill == SKILL_ID::SKILL_1)
		{
			if (P2.skillFlag == true)
			{
				if ((P2.hitoffsetPos.x > P2.Attackoffset.x - 50) && (P2.hitPos.y > 300))
				{
					P1.hitPos.y -= 10;

				}
				if (P2.hitoffsetPos.x < P2.Attackoffset.x + 100)
				{
					P2.hitPos.x += 10;
					P2.hitoffsetPos.x += 10;
				}
				else
				{
					P2.skillFlag = false;
					P2.hitPos = { P2.offsetPosp.x + 10,P2.posp.y + 10 };
					P2.hitoffsetPos = { P2.hitPos.x + 50,P2.hitPos.y + 70 };
				}
				P2.nazo.s1 = 0;
			}
		}

		if (CheckHitKey(KEY_INPUT_W) == 1)
		{
			if (P2.nazo.s2 / 600)
			{
				P2.skill = SKILL_ID::SKILL_2;
				P2.skillFlag = true;
				P2.bufFlag = true;
			}
		}
		if (CheckHitKey(KEY_INPUT_A) == 1)
		{
			if (P2.nazo.s3 / 1000)
			{
				P2.skillFlag = true;
				P2.skill = SKILL_ID::SKILL_3;
				P2.hitPos.x = P2.offsetPosp.x;
				P2.hitoffsetPos.x = P2.offsetPosp.x + 50;
			}
		}
		if (P2.skill == SKILL_ID::SKILL_3)
		{
			if (P2.skillFlag == true)
			{
				if (P2.hitPos.y > 450)
				{
					P2.hitPos.y -= 1;
					P2.hitoffsetPos.y -= 1;
				}
				if (P2.hitoffsetPos.x < P2.Attackoffset.x - 40)
				{
					P2.hitPos.x += 1;
					P2.hitoffsetPos.x += 1;

				}
				else
				{
					P2.skillFlag = false;
				}
				P2.nazo.s3 = 0;
			}
			else if (P2.skillFlag == false)
			{
				P2.hitPos = { P2.offsetPosp.x + 10,P2.posp.y + 10 };
				P2.hitoffsetPos = { P2.hitPos.x + 50,P2.hitPos.y + 70 };
			}
		}
		if (CheckHitKey(KEY_INPUT_S) == 1)
		{
			if (P2.LP <= 50)
			{
				if (P2.nazo.s4 / 1800)
				{
					P2.skillFlag = true;
					P2.count = 0;
					P2.skill = SKILL_ID::SKILL_4;
				}

			}

		}
		if (P2.skill == SKILL_ID::SKILL_4)
		{

			if (P2.skillFlag == true)
			{
				if (P2.count / 60)
				{
					if (P2.hitPos.y > 450)
					{
						P2.hitPos.y -= 20;
					}
					if (P2.hitoffsetPos.x < P2.Attackoffset.x + 100)
					{
						P2.hitoffsetPos.x += 20;
					}
				}
				if (P2.count / 120)
				{
					P2.skillFlag = false;
				}
			}
			else if (P2.skillFlag == false)
			{
				P2.hitPos = { P2.offsetPosp.x + 10,P2.posp.y + 10 };
				P2.hitoffsetPos = { P2.hitPos.x + 50,P2.hitPos.y + 70 };
			}
		}
	}

	P1skill(player1,player2);
	P2skill(player1, player2);
	P3skill(player1, player2);
	P4skill(player1, player2);

	P1.kisi.s1++;
	P1.kisi.s2++;
	P1.kisi.s3++;
	P1.kisi.s4++;


	P1.maho.s1++;
	P1.maho.s2++;
	P1.maho.s3++;
	P1.maho.s4++;


	P1.buto.s1++;
	P1.buto.s2++;
	P1.buto.s3++;
	P1.buto.s4++;


	P1.nazo.s1++;
	P1.nazo.s2++;
	P1.nazo.s3++;
	P1.nazo.s4++;
	
	P2.kisi.s1++;
	P2.kisi.s2++;
	P2.kisi.s3++;
	P2.kisi.s4++;
		
		
	P2.maho.s1++;
	P2.maho.s2++;
	P2.maho.s3++;
	P2.maho.s4++;
		
	P2.buto.s1++;
	P2.buto.s2++;
	P2.buto.s3++;
	P2.buto.s4++;
		
	P2.nazo.s1++;
	P2.nazo.s2++;
	P2.nazo.s3++;
	P2.nazo.s4++;
		
	
	StageGameInit();
}

void Skill::CheckHit()
{
	if ((P1.hitoffsetPos.x > P2.posp.x) &&
		(P1.hitPos.x < P2.offsetPosp.x) &&
		(P1.hitoffsetPos.y > P2.posp.y) &&
		(P1.hitPos.y < P2.offsetPosp.y))
	{
		P2.skillFlag = false;
		P2.hitFlag = true;
	}
}

bool Skill::P1skill(CHAR_ID player1,CHAR_ID player2)
{
	int LPhold = 0;
	int Dehold = 0;
	int Athold = 0;
	if (player1 == CHAR_ID::CHAR_ID_KISI)
	{
		switch (P1.skill)
		{
		case SKILL_ID::SKILL_1:
			if (P1.kisi.s1 / 300)
			{
				P1.dmage = 10;
				if (P1.defense < 20)
				{
					Dehold = P1.defense + 5;
					P1.defense = Dehold;
				}
				else if (P1.defense == 20)
				{
					//è„å¿
				}
			}
			break;
		case SKILL_ID::SKILL_2:
			if (P1.skillFlag == true)
			{
				P1.HP = 50;
				if (P1.HP == 50)
				{
					LPhold = P1.LP + P1.HP;
					P1.LP = LPhold;
					if (P1.LP >= 100)
					{
						P1.LP = 100;
					}
				}
				P1.kisi.s2 = 0;
				P1.skillFlag = false;
			}
			else if (P1.skillFlag==false)
			{
				if (P1.kisi.s2 / 120)
				{
					P1.bufFlag = false;
				}
			}
			//P1.Scount = 4200;//ëÂëÃ70ïb
			break;
		case SKILL_ID::SKILL_3:

			if (P1.skillFlag == true)
			{
				if (P1.LP > 10)
				{
					P1.HP = 10;
					LPhold = P1.LP - P1.HP;
					P1.LP = LPhold;
					Athold = P1.attack + 5;
					P1.attack = Athold;
				}
				else if (P1.LP == 10)
				{

				}
				P1.kisi.s3 = 0;
				P1.skillFlag = false;
			}
			else if (P1.skillFlag == false)
			{
				if (P1.kisi.s3 / 120)
				{
					P1.bufFlag = false;
				}
			}

			break;
		case SKILL_ID::SKILL_4:
			if (P1.HP <= 10)
			{
				P1.dmage = 40;
			}
			break;
		case SKILL_ID::SKILL_MAX:
			break;
		default:
			break;
		}
		return true;
	}
	int LPhold2 = 0;
	int Dehold2 = 0;
	int Athold2 = 0;
	if (player2 == CHAR_ID::CHAR_ID_KISI)
	{
		switch (P2.skill)
		{
		case SKILL_ID::SKILL_1:
			if (P2.kisi.s1 / 300)
			{
				P2.dmage = 10;
				if (P2.defense < 20)
				{
					Dehold2 = P2.defense + 5;
					P2.defense = Dehold2;
				}
				else if (P2.defense == 20)
				{
					//è„å¿
				}
			}
			break;
		case SKILL_ID::SKILL_2:
			if (P2.skillFlag == true)
			{
				P2.HP = 50;
				if (P2.HP == 50)
				{
					LPhold2 = P2.LP + P2.HP;
					P2.LP = LPhold2;
					if (P2.LP >= 100)
					{
						P2.LP = 100;
					}
				}
				P2.kisi.s2 = 0;
				P2.skillFlag = false;
			}
			else if (P1.skillFlag == false)
			{
				if (P1.kisi.s2 / 120)
				{
					P1.bufFlag = false;
				}
			}
			//P1.Scount = 4200;//ëÂëÃ70ïb
			break;
		case SKILL_ID::SKILL_3:

			if (P2.skillFlag == true)
			{
				if (P2.LP > 10)
				{
					P2.HP = 10;
					LPhold2 = P2.LP - P2.HP;
					P2.LP = LPhold2;
					Athold2 = P2.attack + 5;
					P2.attack = Athold2;
				}
				else if (P2.LP == 10)
				{

				}
				P2.kisi.s3 = 0;
				P2.skillFlag = false;
			}
			else if (P1.skillFlag == false)
			{
				if (P1.kisi.s3 / 120)
				{
					P1.bufFlag = false;
				}
			}

			break;
		case SKILL_ID::SKILL_4:
			if (P2.HP <= 10)
			{
				P2.dmage = 40;
			}
			break;
		case SKILL_ID::SKILL_MAX:
			break;
		default:
			break;
		}
		return true;
	}
	return false;
}

bool Skill::P2skill(CHAR_ID player1, CHAR_ID player2)
{
	int LPhold = 0;
	int Dehold = 0;
	int Athold = 0;
	int Sphold = 0;
	if (player1 == CHAR_ID::CHAR_ID_MDOU)
	{
		switch (P1.skill)
		{
		case SKILL_ID::SKILL_1:
			if (P1.skillFlag == true)
			{
				P1.dmage = 7;
				P1.maho.s1 = 0;
			}
			break;
		case SKILL_ID::SKILL_2:
			if (P1.skillFlag == true)
			{
				P1.speed = 6;
				P1.maho.s2 = 0;
				P1.skillFlag = false;
			}
			else if (P1.skillFlag == false)
			{

				if (P1.maho.s2 / 300)
				{
					P1.speed = 0;
					P1.bufFlag = false;
				}

			}
			break;
		case SKILL_ID::SKILL_3:
			if (P1.skillFlag == true)
			{

				P1.defense = 30;
				P1.HP = 5;
				if (P1.HP == 5)
				{
					LPhold = P1.LP - P1.HP;
					P1.LP = LPhold;
				}

				P1.maho.s3 = 0;
				P1.skillFlag = false;
			}
			else if (P1.skillFlag == false)
			{

				if (P1.maho.s3 / 300)
				{
					P1.defense = 0;
					P1.bufFlag = false;
				}

			}
			break;
		case SKILL_ID::SKILL_4:
			if (P1.skillFlag == true)
			{
				if (P1.HP <= 50)
				{
					P1.dmage = 40;
				}
				P1.maho.s4 = 0;
			}
			break;
		case SKILL_ID::SKILL_MAX:
			break;
		default:
			break;
		}
		return true;
	}
	int LPhold2 = 0;
	int Dehold2= 0;
	int Athold2 = 0;
	int Sphold2 = 0;
	if (player2 == CHAR_ID::CHAR_ID_MDOU)
	{
		switch (P2.skill)
		{
		case SKILL_ID::SKILL_1:
			if (P2.skillFlag == true)
			{
				P2.dmage = 7;
				P2.maho.s1 = 0;
			}
			break;
		case SKILL_ID::SKILL_2:
			if (P2.skillFlag == true)
			{
				P2.speed = 6;
				P2.maho.s2 = 0;
				P2.skillFlag = false;
			}
			else if (P2.skillFlag == false)
			{

				if (P2.maho.s2 / 300)
				{
					P2.speed = 0;
				}

			}
			break;
		case SKILL_ID::SKILL_3:
			if (P2.skillFlag == true)
			{

				P2.defense = 30;
				P2.HP = 5;
				if (P2.HP == 5)
				{
					LPhold2 = P2.LP - P2.HP;
					P2.LP = LPhold2;
				}

				P2.maho.s3 = 0;
				P2.skillFlag = false;
			}
			else if (P2.skillFlag == false)
			{

				if (P2.maho.s3 / 300)
				{
					P2.defense = 0;
				}

			}
			break;
		case SKILL_ID::SKILL_4:
			if (P2.skillFlag == true)
			{
				if (P2.HP <= 50)
				{
					P2.dmage = 40;
				}
				P2.maho.s4 = 0;
			}
			break;
		case SKILL_ID::SKILL_MAX:
			break;
		default:
			break;
		}
		return true;
	}

	return false;
}

bool Skill::P3skill(CHAR_ID player1, CHAR_ID player2)
{
	int LPhold = 0;
	int Dehold = 0;
	int Athold = 0;
	int Sphold = 0;
	if ( player1== CHAR_ID::CHAR_ID_BTOU)
	{
		switch (P1.skill)
		{
		case SKILL_ID::SKILL_1:
			if (P1.skillFlag == true)
			{
				P1.dmage = 15;

			}

			break;
		case SKILL_ID::SKILL_2:
			if (P1.skillFlag == true)
			{
				P1.defense = 5;
				P1.skillFlag = false;
				P1.buto.s2 = 0;
			}
			else if (P1.skillFlag == false)
			{

				if (P1.buto.s2 / 180)
				{
					P1.defense = 0;
					P1.bufFlag = false;
				}
			}
			break;
		case SKILL_ID::SKILL_3:
			if (P1.skillFlag == true)
			{
				P1.attack = 10;
				P1.buto.s3 = 0;
			}
			else if (P1.skillFlag == false)
			{
				if (P1.buto.s3 / 600)
				{
					P1.attack = 0;
					P1.bufFlag = false;
				}
			}
			break;
		case SKILL_ID::SKILL_4:
			if (P1.skillFlag == true)
			{
				if (P1.LP <= 30)
				{
					P1.HP = 20;
					LPhold = P1.LP + P1.HP;
					P1.LP = LPhold;
					P1.speed = 5;
				}
				P1.skillFlag = false;
				P1.buto.s4 = 0;
			}
			else if (P1.skillFlag == false)
			{
				if (P1.buto.s4 / 300)
				{
					P1.speed = 0;
					P1.bufFlag = false;
				}
			}
			break;
		case SKILL_ID::SKILL_MAX:
			break;
		default:
			break;
		}
		return true;
	}
	int LPhold2 = 0;
	int Dehold2 = 0;
	int Athold2 = 0;
	int Sphold2 = 0;
	if (player2== CHAR_ID::CHAR_ID_BTOU)
	{
		switch (P2.skill)
		{
		case SKILL_ID::SKILL_1:
			if (P2.skillFlag == true)
			{
				P2.dmage = 15;

			}

			break;
		case SKILL_ID::SKILL_2:
			if (P2.skillFlag == true)
			{
				P2.defense = 5;
				P2.skillFlag = false;
				P2.buto.s2 = 0;
			}
			else if (P2.skillFlag == false)
			{

				if (P2.buto.s2 / 180)
				{
					P2.defense = 0;
				}
			}
			break;
		case SKILL_ID::SKILL_3:
			if (P2.skillFlag == true)
			{
				P2.attack = 10;
				P2.buto.s3 = 0;
			}
			else if (P2.skillFlag == false)
			{
				if (P2.buto.s3 / 600)
				{
					P2.attack = 0;
				}
			}
			break;
		case SKILL_ID::SKILL_4:
			if (P2.skillFlag == true)
			{
				if (P2.LP <= 30)
				{
					P2.HP = 20;
					LPhold2 = P2.LP + P2.HP;
					P2.LP = LPhold2;
					P2.speed = 5;
				}
				P2.skillFlag = false;
				P2.buto.s4 = 0;
			}
			else if (P2.skillFlag == false)
			{
				if (P2.buto.s4 / 300)
				{
					P2.speed = 0;
				}
			}
			break;
		case SKILL_ID::SKILL_MAX:
			break;
		default:
			break;
		}
		return true;
	}
	return false;
}

bool Skill::P4skill(CHAR_ID player1, CHAR_ID player2)
{
	int LPhold = 0;
	int Dehold = 0;
	int Athold = 0;
	int Sphold = 0;
	if (player1 == CHAR_ID::CHAR_ID_4)
	{
		switch (P1.skill)
		{
		case SKILL_ID::SKILL_1:
			if (P1.skillFlag == true)
			{
				P1.dmage = 15;

			}
			break;
		case SKILL_ID::SKILL_2:
			if (P1.skillFlag == true)
			{
				P1.defense = 5;
				P1.nazo.s2 = 0;
				P1.skillFlag = false;
			}
			else if (P1.skillFlag == false)
			{
				if (P1.nazo.s2 / 300)
				{
					P1.defense = 0;
					P1.bufFlag = false;
				}
			}
			break;
		case SKILL_ID::SKILL_3:
			if (P1.skillFlag == true)
			{
				P1.dmage = 15;
				if (P1.hitFlag == true)
				{
					P1.HP = 20;
					LPhold = P1.LP + P1.HP;
					P1.LP = LPhold;
				}
			}
			break;
		case SKILL_ID::SKILL_4:
			if (P1.skillFlag == true)
			{
				if (P1.LP <= 50)
				{
					P1.dmage = 60;
				}
			}
			break;
		case SKILL_ID::SKILL_MAX:
			break;
		default:
			break;
		}
		return true;
	}
	int LPhold2 = 0;
	int Dehold2 = 0;
	int Athold2 = 0;
	int Sphold2 = 0;
	if (player2 == CHAR_ID::CHAR_ID_4)
	{
		switch (P2.skill)
		{
		case SKILL_ID::SKILL_1:
			if (P2.skillFlag == true)
			{
				P2.dmage = 15;

			}
			break;
		case SKILL_ID::SKILL_2:
			if (P2.skillFlag == true)
			{
				P2.defense = 5;
				P2.nazo.s2 = 0;
				P2.skillFlag = false;
			}
			else if (P2.skillFlag == false)
			{
				if (P2.nazo.s2 / 300)
				{
					P2.defense = 0;
					P2.bufFlag = false;
				}
			}
			break;
		case SKILL_ID::SKILL_3:
			if (P2.skillFlag == true)
			{
				P2.dmage = 15;
				if (P2.hitFlag == true)
				{
					P2.HP = 20;
					LPhold2 = P2.LP + P2.HP;
					P2.LP = LPhold2;
				}
			}
			break;
		case SKILL_ID::SKILL_4:
			if (P2.skillFlag == true)
			{
				if (P2.LP <= 50)
				{
					P2.dmage = 60;
				}
			}
			break;
		case SKILL_ID::SKILL_MAX:
			break;
		default:
			break;
		}
		return true;
	}
	return false;
}

Skill::Skill()
{
	StageSysInit();

	SScountInit();
}

Skill::~Skill()
{
}
