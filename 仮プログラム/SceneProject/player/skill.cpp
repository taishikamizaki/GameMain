#include "DxLib.h"
#include "skill.h"
#include "player.h"
#include"../key/GetKeyState.h"

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
	P1.Lflag = false;
	P1.Rflag = false;
	P2.skillFlag = false;
	P2.SSflag = true;
	P2.bufFlag = false;
	P2.hitFlag = false;
	P2.Lflag = false;
	P2.Rflag = false;
	P1.count = 0;
	P2.count = 0;
	P1.Scount = 0;
	P2.Scount = 0;
	P1.skill = SKILL_ID::SKILL_MAX;
	P2.skill = SKILL_ID::SKILL_MAX;
	P1.SSpos = 0;
	P1.SSposoffset = 0;
	P1.SSX=0;
	P1.SetPos = 0;
	P1.SetoffPos = 0;
	P1.SetoffX = 0;
	P2.SSpos = 0;
	P2.SSposoffset = 0;
	P2.SSX = 0;
	P2.SetPos = 0;
	P2.SetoffPos = 0;
	P2.SetoffX = 0;
	P1.posSetFlag = false;
	P1.laserFlag = false;
	P2.posSetFlag = false;
	P2.laserFlag = false;
	LoadDivGraph("image/skill/buff/Heal.png", 10, 10, 1, 120, 120, healImage, false);
	LoadDivGraph("image/skill/buff/buff_a.png", 10, 10, 1, 120, 120, buffAImage, false);
	LoadDivGraph("image/skill/buff/buff_d.png", 10, 10, 1, 120, 120, buffDImage, false);
	LoadDivGraph("image/skill/buff/buff_s.png", 10, 10, 1, 120, 120, buffSImage, false);
	LoadDivGraph("image/skill/buff/buff_u.png", 10, 10, 1, 120, 120, buffUImage, false);
	LoadDivGraph("image/serect/charList.png", 12, 4, 3, 138, 140, charicon,false);
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
	punchImage= LoadGraph("image/player/punch.png", true);
	wandImage = LoadGraph("image/player/wand.png", true);
	dImage = LoadGraph("image/player/turugi.png", true);
	magic = LoadGraph("image/skill/effect/magic5.png", true);
	magic2 = LoadGraph("image/skill/magic/magic6.png", true);
	magic3 = LoadGraph("image/skill/magic/magic7.png", true);
	kensla1 = LoadGraph("image/skill/slash/ken.png", true);
	kensla2 = LoadGraph("image/skill/slash/ken1.png", true);
	kensla3 = LoadGraph("image/skill/slash/ken2.png", true);
	kensla4 = LoadGraph("image/skill/slash/ken3.png", true);

	charF = false;

	//LoadDivGraph("image/slash1.png", 16, 4, 4, 320, 240, slashImage, false);
	//LoadDivGraph("image/slash2.png", 16, 4, 4, 320, 240, slash2Image, false);
	//LoadDivGraph("image/slash3.png", 12, 5, 3, 192, 192, slash3Image, false);
	LoadDivGraph("image/skill/cut-in/m/laser2.png", 5, 1, 5, 640, 240, laserImage, false);
	LoadDivGraph("image/skill/cut-in/m/laser1.png", 10, 1, 10, 640, 480, laserSetImage, false);
	LoadDivGraph("image/skill/cut-in/m/laser4.png", 10, 1, 10, 640, 480, laserSet2, false);
	LoadDivGraph("image/skill/cut-in/m/laser5.png", 5, 1, 5, 640, 240, laser2, false);
	LoadDivGraph("image/skill/slash/ken/up.png", 5, 5, 1, 192, 192, upImage, false);
	LoadDivGraph("image/skill/guard/png/gd.png", 5, 5, 1, 100, 100, guardImage, false);
	//mapID = MAP_ID::MAP_ID_MATI;
}

void Skill::StageGameInit(void)
{
	P1.count++;
	P2.count++;
	P1.Scount++;
	P2.Scount++;
}

void Skill::PlayerInit(Vector2 pos,Vector2 hitposS, 
	Vector2 hitposE, Vector2 offset,Vector2 size, 
	Vector2 pos2, Vector2 hitposS2, Vector2 hitposE2, 
	Vector2 offset2, Vector2 size2)
{
	P1.posp = { pos.x-hitposS.x,pos.y-hitposS.y };
	P1.offsetPosp = { offset.x+hitposE.x,offset.y+hitposE.y };
	
	P1.AttackRange = { pos.x - offset.x , pos.y - offset.y };
	P1.Attackoffset = { pos.x + size.x - offset.x ,
			pos.y + size.y - offset.y };



	P2.posp = { pos2.x-hitposS2.x,pos2.y-hitposS2.y };
	P2.offsetPosp = { offset2.x+hitposE2.x,offset2.y+hitposE2.y };
	
	P2.AttackRange = { pos2.x - offset2.x , pos2.y - offset2.y };
	P2.Attackoffset = {pos2.x + size2.x - offset2.x ,
			pos2.y + size2.y - offset2.y };


	//P1.dir==0:right;
	//P1.dir==1:left;
	if (!P1.skillFlag)
	{
		if (P1.dir == 0)
		{
			P1.hitPos = { (pos.x + hitposS.x) + 10,(pos.y - hitposS.y)-20 };
			P1.hitoffsetPos = { P1.hitPos.x + 50,P1.hitPos.y + 60 };
		}
		else if(P1.dir==1)
		{
			P1.hitPos = { (pos.x - hitposS.x) - 10,(pos.y - hitposS.y) -20 };
			P1.hitoffsetPos = { P1.hitPos.x - 50,P1.hitPos.y + 60 };
		}
	}
	if (!P2.skillFlag)
	{
		if (P2.dir == 0)
		{
			P2.hitPos = { (pos2.x + hitposS2.x) + 10,(pos2.y + hitposE2.y) -20 };
			P2.hitoffsetPos = { P2.hitPos.x + 50,P2.hitPos.y + 60 };
		}
		else if (P2.dir == 1)
		{
			P2.hitPos = { (pos.x - hitposE.x) - 10,(pos.y + hitposS.y) -20 };
			P2.hitoffsetPos = { P2.hitPos.x - 50,P2.hitPos.y +60 };
		}
	}

}

void Skill::CharInit(CHAR_ID player1,CHAR_ID player2)
{
	if (player1 != CHAR_ID::CHAR_ID_MAX)
	{
		switch (player1)
		{
		case CHAR_ID::CHAR_ID_KISI:
			P1.HP = 0;
			P1.LP = 100;
			P1.dmage = 10;
			P1.attack = 0;
			P1.defense = 0;
			P1.speed = 0;
			break;
		case CHAR_ID::CHAR_ID_MDOU:
			P1.HP = 0;
			P1.LP = 100;
			P1.dmage = 10;
			P1.attack = 0;
			P1.defense = 0;
			P1.speed = 0;
			
			break;
		case CHAR_ID::CHAR_ID_BTOU:
			P1.HP = 0;
			P1.LP = 100;
			P1.dmage = 10;
			P1.attack = 0;
			P1.defense = 0;
			P1.speed = 0;
			break;
		case CHAR_ID::CHAR_ID_4:
			P1.HP = 0;
			P1.LP = 50;
			P1.dmage = 10;
			P1.attack = 0;
			P1.defense = 0;
			P1.speed = 5;
			break;
		case CHAR_ID::CHAR_ID_MAX:
			break;
		default:
			break;
		}

	}
	if (player2 != CHAR_ID::CHAR_ID_MAX)
	{
		switch (player2)
		{
		case CHAR_ID::CHAR_ID_KISI:
			P2.HP = 0;
			P2.LP = 100;
			P2.dmage = 10;
			P2.attack = 0;
			P2.defense = 0;
			P2.speed = 0;
			break;
		case CHAR_ID::CHAR_ID_MDOU:

			P2.HP = 0;
			P2.LP = 100;
			P2.dmage = 10;
			P2.attack = 0;
			P2.defense = 0;
			P2.speed = 0;
			break;
		case CHAR_ID::CHAR_ID_BTOU:
			P2.HP = 0;
			P2.LP = 100;
			P2.dmage = 10;
			P2.attack = 0;
			P2.defense = 0;
			P2.speed = 0;
			break;
		case CHAR_ID::CHAR_ID_4:
			P2.HP = 0;
			P2.LP = 100;
			P2.dmage = 10;
			P2.attack = 0;
			P2.defense = 0;
			P2.speed = 5;
			break;
		case CHAR_ID::CHAR_ID_MAX:
			break;
		default:
			break;
		}
	}
	charF = true;
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
	int AnimG = (P1.Scount/2)%5;

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
		DrawFormatString(850, 260, 0x000000, "p2HP:%d", P2.HP);
		DrawFormatString(850, 280, 0x000000, "p2LP:%d", P2.LP);
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
	if (player1 != CHAR_ID::CHAR_ID_MAX)
	{
		// ÉLÉÉÉâÇP
		if (player1 == CHAR_ID::CHAR_ID_KISI)
		{
			if (P1.dir == 0)
			{
				if ((keyDownTrigger[KEY_ID_1Y]) || (keyDownTrigger[KEY_ID_1X]) || keyDownTrigger[P1A1] || keyDownTrigger[P1A2])
				{
					DrawRotaGraph(P1.posp.x + 25 + 6, P1.posp.y + 50 + 15, 1.0f, 3.1415926535897932384626433832795f / 2, swordImage, true);
				}
				else
				{
					DrawGraph(P1.posp.x + 6, P1.posp.y + 15, swordImage, true);
				}
			}
			else if (P1.dir == 1)
			{
				if ((keyDownTrigger[KEY_ID_1Y]) || (keyDownTrigger[KEY_ID_1X]) || keyDownTrigger[P1A1] || keyDownTrigger[P1A2])
				{
					DrawRotaGraph(P1.posp.x + 25 - 25, P1.posp.y + 50 + 15, 1.0f, 3.1415926535897932384626433832795f, swordImage, true);
				}
				else
				{
					DrawRotaGraph(P1.posp.x + 25 - 25, P1.posp.y + 25 + 15, 1.0f, -3.1415926535897932384626433832795f / 2, swordImage, true);
				}
			}

			if (P1.skill == SKILL_ID::SKILL_1)
			{
				if (P1.skillFlag == true)
				{
					DrawBox(P1.hitPos.x, P1.hitPos.y, P1.hitoffsetPos.x, P1.hitoffsetPos.y, 0xffff88, true);
					if (P1.Rflag)
					{
						DrawTurnGraph(P1.hitPos.x - 30, P1.hitPos.y - 20, guardImage[AnimG], true);
					}
					if (P1.Lflag)
					{
						DrawGraph(P1.hitoffsetPos.x + 30, P1.hitPos.y + 20, guardImage[AnimG], true);
					}
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
				if (P1.bufFlag == true)
				{
					DrawGraph(P1.posp.x - 43, P1.posp.y - 55, buffUImage[Anim], true);
				}
			}
			if (P1.skill == SKILL_ID::SKILL_4)
			{
				if (P1.skillFlag == true)
				{
					//DrawBox(P1.hitPos.x, P1.hitPos.y, P1.hitoffsetPos.x, P1.hitoffsetPos.y, 0xffffff, true);
					if (P1.Rflag)
					{
						DrawExtendGraph(P1.hitPos.x, P1.hitPos.y, P1.hitoffsetPos.x, P1.hitoffsetPos.y, kensla1, true);
					}
					if (P1.Lflag)
					{
						DrawExtendGraph(P1.hitoffsetPos.x, P1.hitPos.y, P1.hitPos.x, P1.hitoffsetPos.y, kensla2, true);
					}
				}
			}
		}
		// ÉLÉÉÉâÇQ
		if (player1 == CHAR_ID::CHAR_ID_MDOU)
		{
			if (P1.dir == 0)
			{
				if ((keyDownTrigger[KEY_ID_1Y]) || (keyDownTrigger[KEY_ID_1X]) || keyDownTrigger[P1A1] || keyDownTrigger[P1A2])
				{
					DrawRotaGraph(P1.posp.x + 25 + 6, P1.posp.y + 50 - 25 + 15, 1.0f, 3.1415926535897932384626433832795f / 2, wandImage, true);
				}
				else
				{
					DrawGraph(P1.posp.x + 6, P1.posp.y - 25 + 15, wandImage, true);
				}
			}
			else if (P1.dir == 1)
			{
				if ((keyDownTrigger[KEY_ID_1Y]) || (keyDownTrigger[KEY_ID_1X]) || keyDownTrigger[P1A1] || keyDownTrigger[P1A2])
				{
					DrawRotaGraph(P1.posp.x, P1.posp.y - 25 + 50 + 15, 1.0f, -3.1415926535897932384626433832795f / 2, wandImage, true);
				}
				else
				{
					DrawGraph(P1.posp.x - 25, P1.posp.y - 25 + 15, wandImage, true);
				}
			}
			if (P1.skill == SKILL_ID::SKILL_1)
			{
				if (P1.skillFlag == true)
				{
					DrawBox(P1.hitPos.x, P1.hitPos.y, P1.hitoffsetPos.x, P1.hitoffsetPos.y, 0xffff88, true);
					if (P1.Rflag)
					{
						DrawGraph(P1.hitPos.x - 50, P1.hitPos.y - 40, magic, true);
					}

					if (P1.Lflag)
					{
						DrawGraph(P1.hitoffsetPos.x - 50, P1.hitPos.y - 40, magic, true);
					}
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
				if (P1.bufFlag == true)
				{
					DrawGraph(P1.posp.x - 43, P1.posp.y - 55, buffUImage[Anim], true);
				}
			}
			if (P1.skill == SKILL_ID::SKILL_4)
			{
				P1.laserFlag = true;
				if (P1.skillFlag == true)
				{

					DrawBox(P1.hitPos.x, P1.hitPos.y, P1.hitoffsetPos.x, P1.hitoffsetPos.y, 0xffff88, true);

					if (P1.Lflag)
					{

						DrawExtendGraph(P1.hitoffsetPos.x, P1.hitPos.y, P1.hitPos.x, P1.hitoffsetPos.y, laserSetImage[Anim], true);

						if (P1.count / 240)
						{

							DrawExtendGraph(P1.hitoffsetPos.x, P1.hitPos.y, P1.hitPos.x, P1.hitoffsetPos.y, laserImage[AnimL], true);
						}
						else if (P1.count / 540)
						{
							P1.laserFlag = false;
						}
					}
					if (P1.Rflag)
					{

						DrawExtendGraph(P1.hitPos.x, P1.hitPos.y, P1.hitoffsetPos.x, P1.hitoffsetPos.y, laserSetImage[Anim], true);

						if (P1.count / 240)
						{

							DrawExtendGraph(P1.hitPos.x, P1.hitPos.y, P1.hitoffsetPos.x, P1.hitoffsetPos.y, laserImage[AnimL], true);
						}
						else if (P1.count / 540)
						{
							P1.laserFlag = false;
						}
					}
				}
			}
		}
		// ÉLÉÉÉâÇR
		if (player1 == CHAR_ID::CHAR_ID_BTOU)
		{
			if (P1.dir == 0)
			{
				if ((keyDownTrigger[KEY_ID_1Y]) || (keyDownTrigger[KEY_ID_1X]) || keyDownTrigger[P1A1] || keyDownTrigger[P1A2])
				{
					DrawGraph(P1.posp.x + 6 + 5, P1.posp.y + 15, punchImage, true);
				}
				else
				{
					DrawGraph(P1.posp.x + 6, P1.posp.y + 15, punchImage, true);
				}
			}
			else if (P1.dir == 1)
			{
				if ((keyDownTrigger[KEY_ID_1Y]) || (keyDownTrigger[KEY_ID_1X]) || keyDownTrigger[P1A1] || keyDownTrigger[P1A2])
				{
					DrawTurnGraph(P1.posp.x - 30, P1.posp.y + 15, punchImage, true);
				}
				else
				{
					DrawTurnGraph(P1.posp.x - 25, P1.posp.y + 15, punchImage, true);
				}
			}
			if (P1.skill == SKILL_ID::SKILL_1)
			{
				if (P1.skillFlag == true)
				{
					DrawBox(P1.hitPos.x, P1.hitPos.y, P1.hitoffsetPos.x, P1.hitoffsetPos.y, 0xffff88, true);

					if (P1.Rflag)
					{
						DrawExtendGraph(P1.hitPos.x - 20, P1.hitPos.y - 30, P1.hitoffsetPos.x + 20, P1.hitoffsetPos.y + 30, upImage[AnimL], true);
					}
					if (P1.Lflag)
					{
						DrawExtendGraph(P1.hitoffsetPos.x - 20, P1.hitPos.y - 30, P1.hitPos.x + 20, P1.hitoffsetPos.y + 30, upImage[AnimL], true);
					}
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
				if (P1.bufFlag == true)
				{
					DrawGraph(P1.posp.x - 43, P1.posp.y - 55, buffUImage[Anim], true);
				}
			}
			if (P1.skill == SKILL_ID::SKILL_4)
			{
				if (P1.bufFlag == true)
				{
					DrawGraph(P1.posp.x - 43, P1.posp.y - 55, healImage[Anim], true);
				}
			}
		}
		// ÉLÉÉÉâÇS
		if (player1 == CHAR_ID::CHAR_ID_4)
		{
			if (P1.dir == 0)
			{
				if ((keyDownTrigger[KEY_ID_1Y]) || (keyDownTrigger[KEY_ID_1X]) || keyDownTrigger[P1A1] || keyDownTrigger[P1A2])
				{
					DrawRotaGraph(P1.posp.x + 25 + 6, P1.posp.y + 50 + 15, 1.0f, 3.1415926535897932384626433832795f / 2, dImage, true);
				}
				else
				{
					DrawGraph(P1.posp.x + 6, P1.posp.y + 15, dImage, true);
				}
			}
			else if (P1.dir == 1)
			{
				if ((keyDownTrigger[KEY_ID_1Y]) || (keyDownTrigger[KEY_ID_1X]) || keyDownTrigger[P1A1] || keyDownTrigger[P1A2])
				{
					DrawRotaGraph(P1.posp.x + 25 - 25, P1.posp.y + 50 + 15, 1.0f, 3.1415926535897932384626433832795f, dImage, true);
				}
				else
				{
					DrawRotaGraph(P1.posp.x + 25 - 25, P1.posp.y + 25 + 15, 1.0f, -3.1415926535897932384626433832795f / 2, dImage, true);
				}
			}

			if (P1.skill == SKILL_ID::SKILL_1)
			{
				if (P1.skillFlag == true)
				{
					DrawBox(P1.hitPos.x, P1.hitPos.y, P1.hitoffsetPos.x, P1.hitoffsetPos.y, 0xffff88, true);
					if (P1.Rflag)
					{
						DrawExtendGraph(P1.hitPos.x, P1.hitPos.y, P1.hitoffsetPos.x, P1.hitoffsetPos.y, kensla3, true);
					}
					if (P1.Lflag)
					{
						DrawExtendGraph(P1.hitoffsetPos.x, P1.hitPos.y, P1.hitPos.x, P1.hitoffsetPos.y, kensla4, true);
					}
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
				if (P1.skillFlag == true)
				{

					DrawBox(P1.hitPos.x, P1.hitPos.y, P1.hitoffsetPos.x, P1.hitoffsetPos.y, 0x88ffff, true);
					if (P1.Rflag)
					{
						DrawExtendGraph(P1.hitPos.x, P1.hitPos.y, P1.hitoffsetPos.x, P1.hitoffsetPos.y, magic2, true);

					}
					if (P1.Lflag)
					{
						DrawExtendGraph(P1.hitoffsetPos.x, P1.hitPos.y, P1.hitPos.x, P1.hitoffsetPos.y, magic3, true);
					}
				}
			}
			if (P1.skill == SKILL_ID::SKILL_4)
			{
				if (P1.skillFlag == true)
				{
					DrawBox(P1.hitPos.x, P1.hitPos.y, P1.hitoffsetPos.x, P1.hitoffsetPos.y, 0xffffff, true);
					if (P1.Lflag)
					{

						DrawExtendGraph(P1.hitoffsetPos.x, P1.hitPos.y, P1.hitPos.x, P1.hitoffsetPos.y, laserSet2[Anim], true);

						if (P1.count / 120)
						{

							DrawExtendGraph(P1.hitoffsetPos.x, P1.hitPos.y, P1.hitPos.x, P1.hitoffsetPos.y, laser2[AnimL], true);
						}
						else if (P1.count / 360)
						{
							P1.laserFlag = false;
						}
					}
					if (P1.Rflag)
					{

						DrawExtendGraph(P1.hitPos.x, P1.hitPos.y, P1.hitoffsetPos.x, P1.hitoffsetPos.y, laserSet2[Anim], true);

						if (P1.count / 120)
						{

							DrawExtendGraph(P1.hitPos.x, P1.hitPos.y, P1.hitoffsetPos.x, P1.hitoffsetPos.y, laser2[AnimL], true);
						}
						else if (P1.count / 360)
						{
							P1.laserFlag = false;
						}
					}
				}
			}
		}
	
	}
	if (player2 != CHAR_ID::CHAR_ID_MAX)
	{
		// ÉLÉÉÉâÇP
		if (player2 == CHAR_ID::CHAR_ID_KISI)
		{
			if (P2.dir == 0)
			{
				if ((keyDownTrigger[KEY_ID_2Y]) || (keyDownTrigger[KEY_ID_2X]) || keyDownTrigger[P2A1] || keyDownTrigger[P2A2])
				{
					DrawRotaGraph(P2.posp.x + 25 + 6, P2.posp.y + 50 + 15, 1.0f, 3.1415926535897932384626433832795f / 2, swordImage, true);
				}
				else
				{
					DrawGraph(P2.posp.x + 6, P2.posp.y + 15, swordImage, true);
				}
			}
			else if (P2.dir == 1)
			{
				if ((keyDownTrigger[KEY_ID_2Y]) || (keyDownTrigger[KEY_ID_2X]) || keyDownTrigger[P2A1] || keyDownTrigger[P2A2])
				{
					DrawRotaGraph(P2.posp.x + 25 - 25, P2.posp.y + 50 + 15, 1.0f, 3.1415926535897932384626433832795f, swordImage, true);
				}
				else
				{
					DrawRotaGraph(P2.posp.x + 25 - 25, P2.posp.y + 25 + 15, 1.0f, -3.1415926535897932384626433832795f / 2, swordImage, true);
				}
			}
			if (P2.skill == SKILL_ID::SKILL_1)
			{
				if (P2.skillFlag == true)
				{
					DrawBox(P2.hitPos.x, P2.hitPos.y, P2.hitoffsetPos.x, P2.hitoffsetPos.y, 0xffff88, true);
					if (P2.Rflag)
					{
						DrawTurnGraph(P2.hitPos.x-30,P2.hitPos.y-20,guardImage[AnimG],true);
					}
					if(P2.Lflag)
					{
						DrawGraph(P2.hitoffsetPos.x+30, P2.hitPos.y+20, guardImage[AnimG], true);
					}
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
				if (P2.bufFlag == true)
				{
					DrawGraph(P2.posp.x - 43, P2.posp.y - 55, buffUImage[Anim], true);
				}
			}
			if (P2.skill == SKILL_ID::SKILL_4)
			{
				if (P2.skillFlag == true)
				{
					//DrawBox(P1.hitPos.x, P1.hitPos.y, P1.hitoffsetPos.x, P1.hitoffsetPos.y, 0xffffff, true);
					if (P2.Rflag)
					{
						DrawExtendGraph(P2.hitPos.x, P2.hitPos.y, P2.hitoffsetPos.x, P2.hitoffsetPos.y, kensla1,true);
					}
					if (P2.Lflag)
					{
						DrawExtendGraph(P2.hitoffsetPos.x, P2.hitPos.y, P2.hitPos.x, P2.hitoffsetPos.y, kensla2, true);
					}
				}
			}
		}
		// ÉLÉÉÉâÇQ
		if (player2 == CHAR_ID::CHAR_ID_MDOU)
		{
			if (P2.dir == 0)
			{
				if ((keyDownTrigger[KEY_ID_2Y]) || (keyDownTrigger[KEY_ID_2X]) || keyDownTrigger[P2A1] || keyDownTrigger[P2A2])
				{
					DrawRotaGraph(P2.posp.x + 25 + 6, P2.posp.y + 50 - 25 + 15, 1.0f, 3.1415926535897932384626433832795f / 2, wandImage, true);
				}
				else
				{
					DrawGraph(P2.posp.x + 6, P2.posp.y - 25 + 15, wandImage, true);
				}
			}
			else if (P2.dir == 1)
			{
				if ((keyDownTrigger[KEY_ID_2Y]) || (keyDownTrigger[KEY_ID_2X]) || keyDownTrigger[P2A1] || keyDownTrigger[P2A2])
				{
					DrawRotaGraph(P2.posp.x, P2.posp.y - 25 + 50 + 15, 1.0f, -3.1415926535897932384626433832795f / 2, wandImage, true);
				}
				else
				{
					DrawGraph(P2.posp.x - 25, P2.posp.y - 25 + 15, wandImage, true);
				}
			}
			if (P2.skill == SKILL_ID::SKILL_1)
			{
				if (P2.skillFlag == true)
				{
					DrawBox(P2.hitPos.x, P2.hitPos.y, P2.hitoffsetPos.x, P2.hitoffsetPos.y, 0xffff88, true);
					if (P2.Rflag)
					{
						DrawGraph(P2.hitPos.x-50, P2.hitPos.y-40, magic, true);
					}
					
					if (P2.Lflag)
					{
						DrawGraph( P2.hitoffsetPos.x-50,P2.hitPos.y-40, magic, true);
					}
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
				if (P2.bufFlag == true)
				{
					DrawGraph(P2.posp.x - 43, P2.posp.y - 55, buffUImage[Anim], true);
				}
			}
			if (P2.skill == SKILL_ID::SKILL_4)
			{
				P2.laserFlag = true;
				if (P2.skillFlag == true)
				{

					DrawBox(P2.hitPos.x, P2.hitPos.y, P2.hitoffsetPos.x, P2.hitoffsetPos.y, 0xffff88, true);

					if (P2.Lflag)
					{

						DrawExtendGraph(P2.hitoffsetPos.x, P2.hitPos.y, P2.hitPos.x, P2.hitoffsetPos.y, laserSetImage[Anim], true);

						if (P2.count / 240)
						{

							DrawExtendGraph(P2.hitoffsetPos.x, P2.hitPos.y, P2.hitPos.x, P2.hitoffsetPos.y, laserImage[AnimL], true);
						}
						else if (P2.count / 540)
						{
							P2.laserFlag = false;
						}
					}
					if (P2.Rflag)
					{

						DrawExtendGraph(P2.hitPos.x, P2.hitPos.y, P2.hitoffsetPos.x, P2.hitoffsetPos.y, laserSetImage[Anim], true);

						if (P2.count / 240)
						{

							DrawExtendGraph(P2.hitPos.x, P2.hitPos.y, P2.hitoffsetPos.x, P2.hitoffsetPos.y, laserImage[AnimL], true);
						}
						else if (P2.count / 540)
						{
							P2.laserFlag = false;
						}
					}
				}
			}
		}
		// ÉLÉÉÉâÇR
		if (player2 == CHAR_ID::CHAR_ID_BTOU)
		{
			if (P2.dir == 0)
			{
				if ((keyDownTrigger[KEY_ID_2Y]) || (keyDownTrigger[KEY_ID_2X]) || keyDownTrigger[P2A1] || keyDownTrigger[P2A2])
				{
					DrawGraph(P2.posp.x + 6 + 5, P2.posp.y + 15, punchImage, true);
				}
				else
				{
					DrawGraph(P2.posp.x + 6, P2.posp.y + 15, punchImage, true);
				}
			}
			else if (P2.dir == 1)
			{
				if ((keyDownTrigger[KEY_ID_2Y]) || (keyDownTrigger[KEY_ID_2X]) || keyDownTrigger[P2A1] || keyDownTrigger[P2A2])
				{
					DrawTurnGraph(P2.posp.x - 30, P2.posp.y + 15, punchImage, true);
				}
				else
				{
					DrawTurnGraph(P2.posp.x - 25, P2.posp.y + 15, punchImage, true);
				}
			}
			if (P2.skill == SKILL_ID::SKILL_1)
			{
				if (P2.skillFlag == true)
				{
					DrawBox(P2.hitPos.x, P2.hitPos.y, P2.hitoffsetPos.x, P2.hitoffsetPos.y, 0xffff88, true);

					if (P2.Rflag)
					{
						DrawExtendGraph(P2.hitPos.x - 20, P2.hitPos.y - 30, P2.hitoffsetPos.x + 20, P2.hitoffsetPos.y + 30, upImage[AnimL], true);
					}
					if (P2.Lflag)
					{
						DrawExtendGraph(P2.hitoffsetPos.x - 20, P2.hitPos.y - 30, P2.hitPos.x + 20, P2.hitoffsetPos.y + 30, upImage[AnimL], true);
					}
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
				if (P2.bufFlag == true)
				{
					DrawGraph(P2.posp.x - 43, P2.posp.y - 55, buffUImage[Anim], true);
				}
			}
			if (P2.skill == SKILL_ID::SKILL_4)
			{
				if (P2.bufFlag == true)
				{
					DrawGraph(P2.posp.x - 43, P2.posp.y - 55, healImage[Anim], true);
				}
			}
		}
		// ÉLÉÉÉâÇS
		if (player2 == CHAR_ID::CHAR_ID_4)
		{
			if (P2.dir == 0)
			{
				if ((keyDownTrigger[KEY_ID_2Y]) || (keyDownTrigger[KEY_ID_2X]) || keyDownTrigger[P2A1] || keyDownTrigger[P2A2])
				{
					DrawRotaGraph(P2.posp.x + 25 + 6, P2.posp.y + 50 + 15, 1.0f, 3.1415926535897932384626433832795f / 2, dImage, true);
				}
				else
				{
					DrawGraph(P2.posp.x + 6, P2.posp.y + 15, dImage, true);
				}
			}
			else if (P2.dir == 1)
			{
				if ((keyDownTrigger[KEY_ID_2Y]) || (keyDownTrigger[KEY_ID_2X]) || keyDownTrigger[P2A1] || keyDownTrigger[P2A2])
				{
					DrawRotaGraph(P2.posp.x + 25 - 25, P2.posp.y + 50 + 15, 1.0f, 3.1415926535897932384626433832795f, dImage, true);
				}
				else
				{
					DrawRotaGraph(P2.posp.x + 25 - 25, P2.posp.y + 25 + 15, 1.0f, -3.1415926535897932384626433832795f / 2, dImage, true);
				}
			}
			if (P2.skill == SKILL_ID::SKILL_1)
			{
				if (P2.skillFlag == true)
				{
					DrawBox(P2.hitPos.x, P2.hitPos.y, P2.hitoffsetPos.x, P2.hitoffsetPos.y, 0xffff88, true);
					if (P2.Rflag)
					{
						DrawExtendGraph(P2.hitPos.x, P2.hitPos.y, P2.hitoffsetPos.x, P2.hitoffsetPos.y,kensla3,true);
					}
					if (P2.Lflag)
					{
						DrawExtendGraph(P2.hitoffsetPos.x, P2.hitPos.y, P2.hitPos.x, P2.hitoffsetPos.y,kensla4,true );
					}
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
				if (P2.skillFlag == true)
				{
					
					DrawBox(P2.hitPos.x, P2.hitPos.y, P2.hitoffsetPos.x, P2.hitoffsetPos.y, 0x88ffff, true);
					if (P2.Rflag)
					{
						DrawExtendGraph(P2.hitPos.x, P2.hitPos.y, P2.hitoffsetPos.x, P2.hitoffsetPos.y, magic2,true);

					}
					if (P2.Lflag)
					{
						DrawExtendGraph(P2.hitoffsetPos.x, P2.hitPos.y, P2.hitPos.x, P2.hitoffsetPos.y, magic3, true);
					}
				}
			}
			if (P2.skill == SKILL_ID::SKILL_4)
			{
				if (P2.skillFlag == true)
			{
					DrawBox(P2.hitPos.x, P2.hitPos.y, P2.hitoffsetPos.x, P2.hitoffsetPos.y, 0xffffff, true);
					if (P2.Lflag)
					{

						DrawExtendGraph(P2.hitoffsetPos.x, P2.hitPos.y, P2.hitPos.x, P2.hitoffsetPos.y, laserSet2[Anim], true);

						if (P2.count / 120)
						{

							DrawExtendGraph(P2.hitoffsetPos.x, P2.hitPos.y, P2.hitPos.x, P2.hitoffsetPos.y, laser2[AnimL], true);
						}
						else if (P2.count / 360)
						{
							P2.laserFlag = false;
						}
					}
					if (P2.Rflag)
					{

						DrawExtendGraph(P2.hitPos.x, P2.hitPos.y, P2.hitoffsetPos.x, P2.hitoffsetPos.y, laserSet2[Anim], true);

						if (P2.count / 120)
						{

							DrawExtendGraph(P2.hitPos.x, P2.hitPos.y, P2.hitoffsetPos.x, P2.hitoffsetPos.y, laser2[AnimL], true);
						}
						else if (P2.count / 360)
						{
							P2.laserFlag = false;
						}
					}
				}
			}
		}
	}
	//ÉXÉLÉãUI
	if (player1 != CHAR_ID::CHAR_ID_MAX)
	{
		if (player1 == CHAR_ID::CHAR_ID_KISI)
		{
			DrawExtendGraph(0, 0,60,60, charicon[0], true);

			if (P1.kisi.s1 / 300)
			{
				DrawGraph(50, 60, uitate, true);
			}
			else
			{
				DrawBox(50,60,100,110,0x000000,true);
			}

			if (P1.kisi.s2 / 4200)
			{
				DrawGraph(0, 60, uiheal, true);
			}
			else
			{
				DrawBox(0, 60, 50, 110, 0x000000, true);
			}

			if (P1.kisi.s3 / 60)
			{
				DrawGraph(100, 60, uibuffU, true);
			}
			else
			{
				DrawBox(100, 60, 150, 110, 0x000000, true);
			}

			if (P1.LP<=10)
			{
				DrawGraph(150, 60, uisra, true);
			}
			else
			{
				DrawBox(150, 60, 200, 110, 0x000000, true);
			}
		}
		if (player1 == CHAR_ID::CHAR_ID_MDOU)
		{
			DrawExtendGraph(0, 0, 60, 60, charicon[3], true);
			if (P1.maho.s1/300)
			{
				DrawGraph(50, 60, uimaho, true);
			}
			else
			{
				DrawBox(50, 60, 100, 110, 0x000000, true);
			}
			if (P1.maho.s2/1200)
			{
				DrawGraph(0, 60, uibuffU, true);
			}
			else
			{
				DrawBox(0, 60, 50, 110, 0x000000, true);
			}
			if (P1.maho.s3/1000)
			{
				DrawGraph(100, 60, uibuffU, true);
			}
			else
			{
				DrawBox(100, 60, 150, 110, 0x000000, true);
			}
			if (P1.LP <= 50)
			{
				if (P1.maho.s4/1800)
				{
					DrawGraph(150, 60, uiles, true);
				}
				else
				{
					DrawBox(150, 60, 200, 110, 0x000000, true);
				}
			}
			else
			{
				DrawBox(150, 60, 200, 110, 0x000000, true);
			}
		}
		if (player1 == CHAR_ID::CHAR_ID_BTOU)
		{
			DrawExtendGraph(0, 0, 60, 60, charicon[2], true);

			if (P1.buto.s1/300)
			{
				DrawGraph(50, 60, uihand, true);
			}
			else
			{
				DrawBox(50, 60, 100, 110, 0x000000, true);
			}
			if (P1.buto.s2 / 600)
			{
				DrawGraph(0, 60, uibuffU, true);
			}
			else
			{
				DrawBox(0, 60, 50, 110, 0x000000, true);
			}
			if (P1.buto.s3 / 1200)
			{
				DrawGraph(100, 60, uibuffU, true);
			}
			else
			{
				DrawBox(100, 60, 150, 110, 0x000000, true);
			}
			if (P1.LP <= 30)
			{
				if (P1.buto.s4 / 600)
				{
				
					DrawGraph(150, 60, uiheal, true);
				}
				else
				{
					DrawBox(150, 60, 200, 110, 0x000000, true);
				}
			}
			else
			{
				DrawBox(150, 60, 200, 110, 0x000000, true);
			}
		}
		if (player1 == CHAR_ID::CHAR_ID_4)
		{
			DrawExtendGraph(0, 0, 60, 60, charicon[1], true);
			if (P1.nazo.s1/300)
			{
				DrawGraph(50, 60, uiken, true);
			}
			else
			{
				DrawBox(50,60,100,110,0x0000,true);
			}
			if (P1.nazo.s2 / 600)
			{
				DrawGraph(0, 60, uibuffU, true);
			}
			else
			{
				DrawBox(0, 60, 50, 110, 0x0000, true);
			}
			if (P1.nazo.s3 / 1000)
			{
				DrawGraph(100, 60, uilej, true);
			}
			else
			{
				DrawBox(100, 60, 150, 110, 0x0000, true);
			}
			if (P1.LP <= 50)
			{
				if (P1.nazo.s4 / 1800)
				{
					DrawGraph(150, 60, uisra, true);
				}
				else
				{
					DrawBox(150, 60, 200, 110, 0x0000, true);
				}
			}
			else
			{
				DrawBox(150, 60, 200, 110, 0x0000, true);
			}
		}
	}
	if (player2 != CHAR_ID::CHAR_ID_MAX)
	{
		if (player2 == CHAR_ID::CHAR_ID_KISI)
		{
			DrawExtendGraph(930, 0, 1000, 60, charicon[0], true);

			if (P2.kisi.s1 / 300)
			{
				DrawGraph(850, 60, uitate, true);
			}
			else
			{
				DrawBox(850, 60, 900, 110, 0x000000, true);
			}
			if (P2.kisi.s2 / 4200)
			{
				DrawGraph(800, 60, uiheal, true);
			}
			else
			{
				DrawBox(800, 60, 850, 110, 0x000000, true);
			}
			if (P2.kisi.s3 / 60)
			{
				DrawGraph(900, 60, uibuffU, true);
			}
			else
			{
				DrawBox(900, 60, 950, 110, 0x000000, true);
			}
			if (P2.LP <= 10)
			{
				DrawGraph(950, 60, uisra, true);
			}
			else
			{
				DrawBox(950, 60, 1000, 110, 0x000000, true);
			}
		}
		if (player2 == CHAR_ID::CHAR_ID_MDOU)
		{
			DrawExtendGraph(930, 0, 1000, 60, charicon[3], true);
			if (P2.maho.s1 / 300)
			{
				DrawGraph(850, 60, uimaho, true);
			}
			else
			{
				DrawBox(850, 60, 900, 110, 0x000000, true);
			}
			if (P2.maho.s2 / 1200)
			{
				DrawGraph(800, 60, uibuffU, true);
			}
			else
			{
				DrawBox(800, 60, 850, 110, 0x000000, true);
			}
			if (P2.maho.s3 / 1000)
			{
				DrawGraph(900, 60, uibuffU, true);
			}
			else
			{
				DrawBox(900, 60, 950, 110, 0x000000, true);
			}
			if (P2.LP <= 50)
			{
				if (P2.maho.s4 / 1800)
				{
					DrawGraph(950, 60, uiles, true);
				}
				else
				{
					DrawBox(950, 60, 1000, 110, 0x000000, true);
				}
			}
			else
			{
				DrawBox(950, 60, 1000, 110, 0x000000, true);
			}
		}
		if (player2 == CHAR_ID::CHAR_ID_BTOU)
		{
			DrawExtendGraph(930, 0, 1000, 60, charicon[2], true);
			if (P2.buto.s1 / 300)
			{
				DrawGraph(850, 60, uihand, true);
			}
			else
			{
				DrawBox(850, 60, 900, 110, 0x000000, true);
			}
			if (P2.buto.s2 / 600)
			{
				DrawGraph(800, 60, uibuffU, true);
			}
			else
			{
				DrawBox(800, 60, 850, 110, 0x000000, true);
			}
			if (P2.buto.s3 / 1200)
			{
				DrawGraph(900, 60, uibuffU, true);
			}
			else
			{
				DrawBox(900, 60, 950, 110, 0x000000, true);
			}
			if (P2.buto.s4 / 600)
			{
				if (P2.LP <= 30)
				{
					DrawGraph(950, 60, uiheal, true);
				}
				else
				{
					DrawBox(950, 60, 1000, 110, 0x000000, true);
				}
			}
			else
			{
				DrawBox(950, 60, 1000, 110, 0x000000, true);
			}
		}
		if (player2 == CHAR_ID::CHAR_ID_4)
		{
			DrawExtendGraph(930, 0, 1000, 60, charicon[1], true);
			if (P2.nazo.s1 / 300)
			{
				DrawGraph(850, 60, uilej, true);
			}
			else
			{
				DrawBox(850, 60, 900, 110, 0x0000, true);
			}
			if (P2.nazo.s2 / 600)
			{
				DrawGraph(800, 60, uibuffU, true);
			}
			else
			{
				DrawBox(800, 60, 850, 110, 0x0000, true);
			}
			if (P2.nazo.s3 / 1000)
			{
				DrawGraph(900, 60, uiken, true);
			}
			else
			{
				DrawBox(900, 60, 950, 110, 0x0000, true);
			}
			if (P2.LP <= 50)
			{
				if (P2.nazo.s4 / 1800)
				{
					DrawGraph(950, 60, uisra, true);
				}
				else
				{
					DrawBox(950, 60, 1000, 110, 0x0000, true);
				}
			}
			else
			{
				DrawBox(950, 60, 1000, 110, 0x0000, true);
			}
		}
	}
}

void Skill::SkillCtl(CHAR_ID player1, CHAR_ID player2)
{
	/// player(ãRém)P1
	if (player1 == CHAR_ID::CHAR_ID_KISI)
	{
		if (keyDownTrigger[KEY_ID_1SKILL1] || keyDownTrigger[P1S1])
		{
			//P1.hitPos.x = P1.offsetPosp.x;
			//P1.hitoffsetPos.x = P1.offsetPosp.x + 50;
			P1.skill = SKILL_ID::SKILL_1;
			if (P1.kisi.s1 / 300)//ëÂëÃ5ïb
			{
				P1.skillFlag = true;
				if (P1.dir == 0)
				{
					P1.Rflag = true;
				}
				if (P1.dir == 1)
				{
					P1.Lflag = true;
				}
				P1.count = 0;
			}
		}
		if (P1.skill == SKILL_ID::SKILL_1)
		{
			if (P1.skillFlag == true)
			{
				if (P1.Rflag)
				{

					if (P1.count / 10)
					{
						if (P1.hitoffsetPos.x < P1.Attackoffset.x + 40)
						{
							P1.hitPos.x += 2;
							P1.hitoffsetPos.x += 2;
						}
						if (P1.hitoffsetPos.x > P1.Attackoffset.x + 40)
						{
							P1.skillFlag = false;
							P1.Rflag = false;
							/*	P1.hitPos = { P1.offsetPosp.x + 10,P1.posp.y + 10 };
								P1.hitoffsetPos = { P1.hitPos.x + 50,P1.hitPos.y + 70 };*/
						}
					}

				}
				if (P1.Lflag)
				{
					if (P1.count / 10)
					{
						if (P1.hitoffsetPos.x >= P1.AttackRange.x - 40)
						{
							P1.hitPos.x -= 2;
							P1.hitoffsetPos.x -= 2;
						}
						if (P1.hitoffsetPos.x < P1.AttackRange.x - 40)
						{
							P1.skillFlag = false;
							P1.Lflag = false;
							/*	P1.hitPos = { P1.offsetPosp.x + 10,P1.posp.y + 10 };
								P1.hitoffsetPos = { P1.hitPos.x + 50,P1.hitPos.y + 70 };*/
						}
					}
				}
				P1.kisi.s1 = 0;
			}

		}
		if (keyDownTrigger[KEY_ID_1SKILL4] || keyDownTrigger[P1S4])
		{
			if (P1.SSflag == true)
			{
				if (P1.kisi.s4 / 600)
				{
					if (P1.LP <= 10)
					{
						P1.skill = SKILL_ID::SKILL_4;
						P1.skillFlag = true;
						if (P1.dir == 0)
						{
							P1.Rflag = true;
						}
						if (P1.dir == 1)
						{
							P1.Lflag = true;
						}
						P1.count = 0;
					}
				}
			}
		}
		if (P1.skill == SKILL_ID::SKILL_4)
		{
			if (P1.skillFlag == true)
			{
				if (P1.Rflag)
				{
					P1.SSposoffset = P1.Attackoffset.y + 100;
					P1.SSpos = P1.AttackRange.y - 100;
					P1.SSX = P1.Attackoffset.x + 1000;
					if (!P1.posSetFlag)
					{
						P1.SetPos = P1.SSpos;
						P1.SetoffPos = P1.SSposoffset;
						P1.SetoffX = P1.SSX;
						P1.posSetFlag = true;
					}
					if (P1.count / 5)
					{
						if (P1.hitPos.y > P1.SetPos)
						{
							P1.hitPos.y -= 10;
						}
						if (P1.hitoffsetPos.y < P1.SetoffPos)
						{
							P1.hitoffsetPos.y += 10;
						}
						if (P1.hitoffsetPos.x < P1.SetoffX)
						{
							P1.hitoffsetPos.x += 10;
							P1.hitPos.x += 10;
						}

					}
					if (P1.count / 480)
					{
						P1.skillFlag = false;
						P1.Rflag = false;
						P1.posSetFlag = false;
					}
				}
				if (P1.Lflag)
				{
					P1.SSposoffset = P1.Attackoffset.y + 100;
					P1.SSpos = P1.AttackRange.y - 100;
					P1.SSX = P1.AttackRange.x - 1000;
					if (!P1.posSetFlag)
					{
						P1.SetPos = P1.SSpos;
						P1.SetoffPos = P1.SSposoffset;
						P1.SetoffX = P1.SSX;
						P1.posSetFlag = true;
					}
					if (P1.count / 5)
					{
						if (P1.hitPos.y > P1.SetPos)
						{
							P1.hitPos.y -= 10;
						}
						if (P1.hitoffsetPos.y < P1.SetoffPos)
						{
							P1.hitoffsetPos.y += 10;
						}
						if (P1.hitoffsetPos.x > P1.SetoffX)
						{
							P1.hitoffsetPos.x -= 10;
							P1.hitPos.x -= 10;
						}
					}
					if (P1.count / 480)
					{
						P1.skillFlag = false;
						P1.Rflag = false;
						P1.posSetFlag = false;
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

		if (keyDownTrigger[KEY_ID_1SKILL2] || keyDownTrigger[P1S2])
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
		if (keyDownTrigger[KEY_ID_1SKILL3] || keyDownTrigger[P1S3])
		{
			if (P1.kisi.s3 / 60)
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
	}
	//P2
	if (player2 == CHAR_ID::CHAR_ID_KISI)
	{
		if (keyDownTrigger[KEY_ID_2SKILL1] || keyDownTrigger[P2S1])
		{
			//P1.hitPos.x = P1.offsetPosp.x;
			//P1.hitoffsetPos.x = P1.offsetPosp.x + 50;
			P2.skill = SKILL_ID::SKILL_1;
			if (P2.kisi.s1 / 300)//ëÂëÃ5ïb
			{
				P2.skillFlag = true;
				if (P2.dir == 0)
				{
					P2.Rflag = true;
				}
				if (P2.dir == 1)
				{
					P2.Lflag = true;
				}
				P2.count = 0;
			}
		}
		if (P2.skill == SKILL_ID::SKILL_1)
		{
			if (P2.skillFlag == true)
			{
				if (P2.Rflag)
				{

					if (P2.count / 10)
					{
						if (P2.hitoffsetPos.x < P2.Attackoffset.x + 40)
						{
							P2.hitPos.x += 2;
							P2.hitoffsetPos.x += 2;
						}
						if (P2.hitoffsetPos.x > P2.Attackoffset.x + 40)
						{
							P2.skillFlag = false;
							P2.Rflag = false;
							/*	P1.hitPos = { P1.offsetPosp.x + 10,P1.posp.y + 10 };
								P1.hitoffsetPos = { P1.hitPos.x + 50,P1.hitPos.y + 70 };*/
						}
					}

				}
				if (P2.Lflag)
				{
					if (P2.count / 10)
					{
						if (P2.hitoffsetPos.x >= P2.AttackRange.x - 40)
						{
							P2.hitPos.x -= 2;
							P2.hitoffsetPos.x -= 2;
						}
						if (P2.hitoffsetPos.x < P2.AttackRange.x - 40)
						{
							P2.skillFlag = false;
							P2.Lflag = false;
							/*	P1.hitPos = { P1.offsetPosp.x + 10,P1.posp.y + 10 };
								P1.hitoffsetPos = { P1.hitPos.x + 50,P1.hitPos.y + 70 };*/
						}
					}
				}
				P2.kisi.s1 = 0;
			}

		}
		if (keyDownTrigger[KEY_ID_2SKILL4] || keyDownTrigger[P2S4])
		{
			if (P2.SSflag == true)
			{
				if (P2.kisi.s4 / 600)
				{
					if (P2.LP <= 10)
					{
						P2.skill = SKILL_ID::SKILL_4;
						P2.skillFlag = true;
						if (P2.dir == 0)
						{
							P2.Rflag = true;
						}
						if (P2.dir == 1)
						{
							P2.Lflag = true;
						}
						P2.count = 0;
					}
				}
			}
		}
		if (P2.skill == SKILL_ID::SKILL_4)
		{
			if (P2.skillFlag == true)
			{
				if (P2.Rflag)
				{
					P2.SSposoffset = P2.Attackoffset.y + 100;
					P2.SSpos = P2.AttackRange.y - 100;
					P2.SSX = P2.Attackoffset.x + 1000;
					if (!P2.posSetFlag)
					{
						P2.SetPos = P2.SSpos;
						P2.SetoffPos = P2.SSposoffset;
						P2.SetoffX = P2.SSX;
						P2.posSetFlag = true;
					}
					if (P2.count / 5)
					{
						if (P2.hitPos.y > P2.SetPos)
						{
							P2.hitPos.y -= 10;
						}
						if (P2.hitoffsetPos.y < P2.SetoffPos)
						{
							P2.hitoffsetPos.y += 10;
						}
						if (P2.hitoffsetPos.x < P2.SetoffX)
						{
							P2.hitoffsetPos.x += 10;
							P2.hitPos.x += 10;
						}

					}
					if (P2.count / 480)
					{
						P2.skillFlag = false;
						P2.Rflag = false;
						P2.posSetFlag = false;
					}
				}
				if (P2.Lflag)
				{
					P2.SSposoffset = P2.Attackoffset.y + 100;
					P2.SSpos = P2.AttackRange.y - 100;
					P2.SSX = P2.AttackRange.x - 1000;
					if (!P2.posSetFlag)
					{
						P2.SetPos = P2.SSpos;
						P2.SetoffPos = P2.SSposoffset;
						P2.SetoffX = P2.SSX;
						P2.posSetFlag = true;
					}
					if (P2.count / 5)
					{
						if (P2.hitPos.y > P2.SetPos)
						{
							P2.hitPos.y -= 10;
						}
						if (P2.hitoffsetPos.y < P2.SetoffPos)
						{
							P2.hitoffsetPos.y += 10;
						}
						if (P2.hitoffsetPos.x > P2.SetoffX)
						{
							P2.hitoffsetPos.x -= 10;
							P2.hitPos.x -= 10;
						}
					}
					if (P2.count / 480)
					{
						P2.skillFlag = false;
						P2.Rflag = false;
						P2.posSetFlag = false;
					}
				}
			}
			else if (P2.skillFlag == false)
			{
				P2.SSflag = false;
				P2.hitPos = { P2.offsetPosp.x + 10,P2.posp.y + 10 };
				P2.hitoffsetPos = { P2.hitPos.x + 50,P2.hitPos.y + 70 };
			}
		}

		if (keyDownTrigger[KEY_ID_2SKILL2] || keyDownTrigger[P2S2])
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
		if (keyDownTrigger[KEY_ID_2SKILL3] || keyDownTrigger[P2S3])
		{
			if (P2.kisi.s3 / 60)
			{
				P2.skill = SKILL_ID::SKILL_3;

				P2.skillFlag = true;
				P2.bufFlag = true;
			}
			else
			{
				P2.skillFlag = false;
			}

		}
	}

	///player(ñÇñ@égÇ¢)P1
	if (player1 == CHAR_ID::CHAR_ID_MDOU)
	{
		//P1.Rflag = false;
		if (keyDownTrigger[KEY_ID_1SKILL1] || keyDownTrigger[P1S1])
		{
			P1.skill = SKILL_ID::SKILL_1;
			if (P1.maho.s1 / 300)
			{
				P1.skillFlag = true;
				if (P1.dir == 0)
				{
					P1.Rflag = true;
				}
				if (P1.dir == 1)
				{
					P1.Lflag = true;
				}
				
			}
		}

		if (P1.skill == SKILL_ID::SKILL_1)
		{
			if (P1.skillFlag == true)
			{
				//P1.Lflag = false;
				if (P1.Rflag)
				{

					if (P1.hitoffsetPos.x <= P1.Attackoffset.x + 300)
					{
						if ((P1.dir == 0) || (P1.dir == 1))
						{
							P1.hitPos.x += 10;
							P1.hitoffsetPos.x += 10;
						}
					}
					else if((P1.hitoffsetPos.x >= P1.Attackoffset.x + 300)||(P1.count/85))
					{
						P1.skillFlag = false;
						P1.Rflag = false;


					}
				}
				if (P1.Lflag)
				{
					if (P1.hitoffsetPos.x >= P1.AttackRange.x - 300)
					{
						P1.hitPos.x -= 10;
						P1.hitoffsetPos.x -= 10;
						
					}
					else if ((P1.hitoffsetPos.x <= P1.AttackRange.x - 300) || (P1.count / 85))
					{
						P1.skillFlag = false;
						P1.Lflag = false;
						/*P1.hitPos = { P1.offsetPosp.x + 10,P1.posp.y + 10 };
						P1.hitoffsetPos = { P1.hitPos.x + 50,P1.hitPos.y + 70 };*/
					}
				}
				
			}
		}
		if (keyDownTrigger[KEY_ID_1SKILL4] || keyDownTrigger[P1S4])
		{
			if (P1.LP <= 50)
			{
				P1.skill = SKILL_ID::SKILL_4;
				if (P1.maho.s4 / 1800)
				{
					P1.count = 0;
					P1.skillFlag = true;
					if (P1.dir == 0)
					{
						P1.Rflag = true;
					}
					if (P1.dir == 1)
					{
						P1.Lflag = true;
					}
				}
			}
		}
		if (P1.skill == SKILL_ID::SKILL_4)
		{
			if (P1.skillFlag == true)
			{
				if (P1.Rflag)
				{
					P1.SSposoffset = P1.Attackoffset.y + 100;
					P1.SSpos = P1.AttackRange.y - 100;
					P1.SSX = P1.Attackoffset.x + 1000;
					if (!P1.posSetFlag)
					{
						P1.SetPos = P1.SSpos;
						P1.SetoffPos = P1.SSposoffset;
						P1.SetoffX = P1.SSX;
						P1.posSetFlag = true;
					}
					if ((P1.count / 240)&&(P1.Rflag))
					{
						

						if (P1.hitPos.y > P1.SetPos)
						{
							P1.hitPos.y -= 20;
						}
						if (P1.hitoffsetPos.y < P1.SetoffPos)
						{
							P1.hitoffsetPos.y += 20;
						}
						if (P1.hitoffsetPos.x < P1.SetoffX)
						{
							P1.hitoffsetPos.x += 20;
						}
					}
					if (P1.count / 540)
					{
						P1.skillFlag = false;
						P1.Rflag = false;
						P1.posSetFlag = false;
					}
				}
				if (P1.Lflag)
				{
					P1.SSposoffset = P1.Attackoffset.y + 100;
					P1.SSpos = P1.AttackRange.y - 100;
					P1.SSX = P1.AttackRange.x - 1000;
					if (!P1.posSetFlag)
					{
						P1.SetPos = P1.SSpos;
						P1.SetoffPos = P1.SSposoffset;
						P1.SetoffX = P1.SSX;
						P1.posSetFlag = true;
					}
					if ((P1.count / 240)&&(P1.Lflag))
					{
						

						if (P1.hitPos.y > P1.SetPos)
						{
							P1.hitPos.y -= 20;
						}
						if (P1.hitoffsetPos.y < P1.SetoffPos)
						{
							P1.hitoffsetPos.y += 20;
						}
						if (P1.hitoffsetPos.x > P1.SetoffX)
						{
							P1.hitoffsetPos.x -= 20;
						}
					}
					if (P1.count / 540)
					{
						P1.skillFlag = false;
						P1.Lflag = false;
						P1.posSetFlag = false;
					}
				}
			}
			else if (P1.skillFlag == false)
			{
				P1.posSetFlag = false;
			/*	P1.hitPos = { P1.offsetPosp.x + 10,P1.posp.y + 10 };
				P1.hitoffsetPos = { P1.hitPos.x + 50,P1.hitPos.y + 70 };*/
			}
		}

		if (keyDownTrigger[KEY_ID_1SKILL2] || keyDownTrigger[P1S2])
		{
			P1.skill = SKILL_ID::SKILL_2;
			if (P1.maho.s2 / 1200)
			{
				P1.skillFlag = true;
				P1.bufFlag = true;

			}
		}
		if (keyDownTrigger[KEY_ID_1SKILL3] || keyDownTrigger[P1S3])
		{
			P1.skill = SKILL_ID::SKILL_3;
			if (P1.maho.s3 / 1000)
			{
				P1.skillFlag = true;
				P1.bufFlag = true;
			}
		}
	
		
	}
	//P2
	if (player2 == CHAR_ID::CHAR_ID_MDOU)
	{
		if (keyDownTrigger[KEY_ID_2SKILL1] || keyDownTrigger[P2S1])
		{
			P2.skill = SKILL_ID::SKILL_1;
			if (P2.maho.s1 / 300)
			{
				P2.skillFlag = true;
				if (P2.dir == 0)
				{
					P2.Rflag = true;
				}
				if (P2.dir == 1)
				{
					P2.Lflag = true;
				}

			}
		}

		if (P2.skill == SKILL_ID::SKILL_1)
		{
			if (P2.skillFlag == true)
			{
				//P1.Lflag = false;
				if (P2.Rflag)
				{

					if (P2.hitoffsetPos.x <= P2.Attackoffset.x + 300)
					{
						if ((P2.dir == 0) || (P2.dir == 1))
						{
							P2.hitPos.x += 10;
							P2.hitoffsetPos.x += 10;
						}
					}
					else if ((P2.hitoffsetPos.x >= P2.Attackoffset.x + 300) || (P2.count / 85))
					{
						P2.skillFlag = false;
						P2.Rflag = false;
					}
				}
				if (P2.Lflag)
				{
					if (P2.hitoffsetPos.x >= P2.AttackRange.x - 300)
					{
						P2.hitPos.x -= 10;
						P2.hitoffsetPos.x -= 10;
					}
					else if ((P2.hitoffsetPos.x <= P2.AttackRange.x - 300) || (P2.count / 85))
					{
						P2.skillFlag = false;
						P2.Lflag = false;
						/*P1.hitPos = { P1.offsetPosp.x + 10,P1.posp.y + 10 };
						P1.hitoffsetPos = { P1.hitPos.x + 50,P1.hitPos.y + 70 };*/
					}
				}

			}
		}
		if (keyDownTrigger[KEY_ID_2SKILL4] || keyDownTrigger[P2S4])
		{
			if (P2.LP <= 50)
			{
				P2.skill = SKILL_ID::SKILL_4;
				if (P2.maho.s4 / 1800)
				{
					P2.count = 0;
					P2.skillFlag = true;
					if (P2.dir == 0)
					{
						P2.Rflag = true;
					}
					if (P2.dir == 1)
					{
						P2.Lflag = true;
					}
				}
			}
		}
		if (P2.skill == SKILL_ID::SKILL_4)
		{
			if (P2.skillFlag == true)
			{
				if (P2.Rflag)
				{
					P2.SSposoffset = P2.Attackoffset.y + 100;
					P2.SSpos = P2.AttackRange.y - 100;
					P2.SSX = P2.Attackoffset.x + 1000;
					if (!P2.posSetFlag)
					{
						P2.SetPos = P2.SSpos;
						P2.SetoffPos = P2.SSposoffset;
						P2.SetoffX = P2.SSX;
						P2.posSetFlag = true;
					}
					if ((P2.count / 240) && (P2.Rflag))
					{
						if (P2.hitPos.y > P2.SetPos)
						{
							P2.hitPos.y -= 20;
						}
						if (P2.hitoffsetPos.y < P2.SetoffPos)
						{
							P2.hitoffsetPos.y += 20;
						}
						if (P2.hitoffsetPos.x < P2.SetoffX)
						{
							P2.hitoffsetPos.x += 20;
						}
					}
					if (P2.count / 540)
					{
						P2.skillFlag = false;
						P2.Rflag = false;
						P2.posSetFlag = false;
					}
				}
				if (P2.Lflag)
				{
					P2.SSposoffset = P2.Attackoffset.y + 100;
					P2.SSpos = P2.AttackRange.y - 100;
					P2.SSX = P2.AttackRange.x - 1000;
					if (!P2.posSetFlag)
					{
						P2.SetPos = P2.SSpos;
						P2.SetoffPos = P2.SSposoffset;
						P2.SetoffX = P2.SSX;
						P2.posSetFlag = true;
					}
					if ((P2.count / 240) && (P2.Lflag))
					{
						if (P2.hitPos.y > P2.SetPos)
						{
							P2.hitPos.y -= 20;
						}
						if (P2.hitoffsetPos.y < P2.SetoffPos)
						{
							P2.hitoffsetPos.y += 20;
						}
						if (P2.hitoffsetPos.x > P2.SetoffX)
						{
							P2.hitoffsetPos.x -= 20;
						}
					}
					if (P2.count / 540)
					{
						P2.skillFlag = false;
						P2.Lflag = false;
						P2.posSetFlag = false;
					}
				}
			}
			else if (P2.skillFlag == false)
			{
				P2.posSetFlag = false;
			}
		}

		if (keyDownTrigger[KEY_ID_2SKILL2] || keyDownTrigger[P2S2])
		{
			P2.skill = SKILL_ID::SKILL_2;
			if (P2.maho.s2 / 1200)
			{
				P2.skillFlag = true;
				P2.bufFlag = true;
			}
		}
		if (keyDownTrigger[KEY_ID_2SKILL3] || keyDownTrigger[P2S3])
		{
			P2.skill = SKILL_ID::SKILL_3;
			if (P2.maho.s3 / 1000)
			{
				P2.skillFlag = true;
				P2.bufFlag = true;
			}
		}
	}

	///plaeyr(ïêì¨â∆)P1
	if (player1 == CHAR_ID::CHAR_ID_BTOU)
	{
		if (keyDownTrigger[KEY_ID_1SKILL1] || keyDownTrigger[P1S1])
		{

			P1.skill = SKILL_ID::SKILL_1;
			if (P1.buto.s1 / 300)
			{
				P1.skillFlag = true;
				if (P1.dir == 0)
				{
					P1.Rflag = true;
				}
				if (P1.dir == 1)
				{
					P1.Lflag = true;
				}
			}

		}
		if (P1.skill == SKILL_ID::SKILL_1)
		{
			if (P1.skillFlag == true)
			{
				if (P1.Rflag)
				{
					if (P1.hitPos.y > P1.AttackRange.y - 20)
					{
						P1.hitPos.y -= 5;
						P1.hitoffsetPos.y -= 5;
					}
					if (P1.hitoffsetPos.x < P1.Attackoffset.x + 10)
					{
						P1.hitPos.x += 5;
						P1.hitoffsetPos.x += 5;
					}
					if ((P1.hitoffsetPos.x > P1.Attackoffset.x + 10) && (P1.hitPos.y < P1.AttackRange.y - 20))
					{
						P1.skillFlag = false;
						P1.Rflag = false;
					}
				}
				if (P1.Lflag)
				{
					if (P1.hitPos.y > P1.AttackRange.y - 20)
					{
						P1.hitPos.y -= 5;
						P1.hitoffsetPos.y -= 5;
					}
					if (P1.hitoffsetPos.x > P1.AttackRange.x - 10)
					{
						P1.hitPos.x -= 5;
						P1.hitoffsetPos.x -= 5;
					}
					if ((P1.hitoffsetPos.x < P1.AttackRange.x - 10) && (P1.hitPos.y < P1.AttackRange.y - 20))
					{
						P1.skillFlag = false;
						P1.Lflag = false;
					}
				}
				P1.buto.s1 = 0;
			}
			else if (P1.skillFlag == false)
			{

				/*P1.hitPos = { P1.offsetPosp.x + 10,P1.posp.y + 10 };
				P1.hitoffsetPos = { P1.hitPos.x + 50,P1.hitPos.y + 70 };*/
			}
		}
		
		if (keyDownTrigger[KEY_ID_1SKILL2] || keyDownTrigger[P1S2])
		{
			if (P1.buto.s2 / 600)
			{
				P1.skill = SKILL_ID::SKILL_2;

				P1.skillFlag = true;
				P1.bufFlag = true;
			}
		}
		if (keyDownTrigger[KEY_ID_1SKILL3] || keyDownTrigger[P1S3])
		{
			if (P1.buto.s3 / 1200)
			{
				P1.skill = SKILL_ID::SKILL_3;
				P1.skillFlag = true;
				P1.bufFlag = true;
			}
		}
		if (keyDownTrigger[KEY_ID_1SKILL4] || keyDownTrigger[P1S4])
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
	//P2
	if (player2 == CHAR_ID::CHAR_ID_BTOU)
	{
		if (keyDownTrigger[KEY_ID_2SKILL1] || keyDownTrigger[P2S1])
		{

			P2.skill = SKILL_ID::SKILL_1;
			if (P2.buto.s1 / 300)
			{
				P2.skillFlag = true;
				if (P2.dir == 0)
				{
					P2.Rflag = true;
				}
				if (P2.dir == 1)
				{
					P2.Lflag = true;
				}
			}

		}
		if (P2.skill == SKILL_ID::SKILL_1)
		{
			if (P2.skillFlag == true)
			{
				if (P2.Rflag)
				{
					if (P2.hitPos.y > P2.AttackRange.y - 20)
					{
						P2.hitPos.y -= 5;
						P2.hitoffsetPos.y -= 5;
					}
					if (P2.hitoffsetPos.x < P2.Attackoffset.x + 10)
					{
						P2.hitPos.x += 5;
						P2.hitoffsetPos.x += 5;
					}
					if ((P2.hitoffsetPos.x > P2.Attackoffset.x + 10) && (P2.hitPos.y < P2.AttackRange.y - 20))
					{
						P2.skillFlag = false;
						P2.Rflag = false;
					}
				}
				if (P2.Lflag)
				{
					if (P2.hitPos.y > P2.AttackRange.y - 20)
					{
						P2.hitPos.y -= 5;
						P2.hitoffsetPos.y -= 5;
					}
					if (P2.hitoffsetPos.x > P2.AttackRange.x - 10)
					{
						P2.hitPos.x -= 5;
						P2.hitoffsetPos.x -= 5;
					}
					if ((P2.hitoffsetPos.x < P2.AttackRange.x - 10) && (P2.hitPos.y < P2.AttackRange.y - 20))
					{
						P2.skillFlag = false;
						P2.Lflag = false;
					}
				}
				P2.buto.s1 = 0;
			}
			else if (P2.skillFlag == false)
			{

			}
		}

		if (keyDownTrigger[KEY_ID_2SKILL2] || keyDownTrigger[P2S2])
		{
			if (P2.buto.s2 / 600)
			{
				P2.skill = SKILL_ID::SKILL_2;

				P2.skillFlag = true;
				P2.bufFlag = true;
			}
		}
		if (keyDownTrigger[KEY_ID_2SKILL3] || keyDownTrigger[P2S3])
		{
			if (P2.buto.s3 / 1200)
			{
				P2.skill = SKILL_ID::SKILL_3;
				P2.skillFlag = true;
				P2.bufFlag = true;
			}
		}
		if (keyDownTrigger[KEY_ID_2SKILL4] || keyDownTrigger[P2S4])
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
	///player(íj)P1
	if (player1 == CHAR_ID::CHAR_ID_4)
	{
		if (keyDownTrigger[KEY_ID_1SKILL1] || keyDownTrigger[P1S1])
		{
			if (P1.nazo.s1 / 300)
			{
				P1.skillFlag = true;
				P1.skill = SKILL_ID::SKILL_1;
				if (P1.dir == 0)
				{
					P1.Rflag = true;
				}
				if (P1.dir == 1)
				{
					P1.Lflag = true;
				}
				P1.count = 0;
			}
		}
		if (P1.skill == SKILL_ID::SKILL_1)
		{
			if (P1.skillFlag == true)
			{
				if (P1.Rflag)
				{
					P1.SSposoffset = P1.Attackoffset.x - 50;
					P1.SSpos = P1.AttackRange.y - 100;
					P1.SSX = P1.Attackoffset.x + 300;
					if (!P1.posSetFlag)
					{
						P1.SetPos = P1.SSpos;
						P1.SetoffPos = P1.SSposoffset;
						P1.SetoffX = P1.SSX;
						P1.posSetFlag = true;
					}
					if (P1.count / 5)
					{
						if ((P1.hitoffsetPos.x > P1.SetoffPos) && (P1.hitPos.y > P1.SetPos))
						{
							P1.hitPos.y -= 10;

						}
						if (P1.hitoffsetPos.x < P1.SetoffX)
						{
							P1.hitPos.x += 10;
							P1.hitoffsetPos.x += 10;
						}
						else
						{
							P1.skillFlag = false;
							P1.Rflag = false;
							P1.posSetFlag = false;
								
							/*	P1.hitPos = { P1.offsetPosp.x + 10,P1.posp.y + 10 };
								P1.hitoffsetPos = { P1.hitPos.x + 50,P1.hitPos.y + 70 };*/
						}
					}
				}
				if(P1.Lflag)
				{
					P1.SSposoffset = P1.AttackRange.x + 50;
					P1.SSpos = P1.AttackRange.y - 100;
					P1.SSX = P1.AttackRange.x - 300;
					if (!P1.posSetFlag)
					{
						P1.SetPos = P1.SSpos;
						P1.SetoffPos = P1.SSposoffset;
						P1.SetoffX = P1.SSX;
						P1.posSetFlag = true;
					}
					if (P1.count / 5)
					{
						if ((P1.hitoffsetPos.x < P1.SetoffPos) && (P1.hitPos.y > P1.SetPos))
						{
							P1.hitPos.y -= 10;

						}
						if (P1.hitoffsetPos.x > P1.SetoffX)
						{
							P1.hitPos.x -= 10;
							P1.hitoffsetPos.x -= 10;
						}
						else
						{
							P1.skillFlag = false;
							P1.Lflag = false;
							P1.posSetFlag = false;
							/*	P1.hitPos = { P1.offsetPosp.x + 10,P1.posp.y + 10 };
								P1.hitoffsetPos = { P1.hitPos.x + 50,P1.hitPos.y + 70 };*/
						}
					}
				}
				P1.nazo.s1 = 0;
			}
		}
		if (keyDownTrigger[KEY_ID_1SKILL3] || keyDownTrigger[P1S3])
		{
			if (P1.nazo.s3 / 1000)
			{
				P1.skillFlag = true;
				P1.skill = SKILL_ID::SKILL_3;
				if (P1.dir == 0)
				{
					P1.Rflag = true;
				}
				if (P1.dir == 1)
				{
					P1.Lflag = true;
				}
				/*P1.hitPos.x = P1.offsetPosp.x;
				P1.hitoffsetPos.x = P1.offsetPosp.x + 50;*/
			}
		}
		if (P1.skill == SKILL_ID::SKILL_3)
		{
			if (P1.skillFlag == true)
			{

				if (P1.Rflag)
				{
					if (P1.hitPos.y > P1.AttackRange.y - 20)
					{
						P1.hitPos.y -= 5;
						P1.hitoffsetPos.y -= 5;
					}
					if (P1.hitoffsetPos.x < P1.Attackoffset.x + 10)
					{
						P1.hitPos.x += 5;
						P1.hitoffsetPos.x += 5;
					}
					if ((P1.hitoffsetPos.x > P1.Attackoffset.x + 10) && (P1.hitPos.y < P1.AttackRange.y - 20))
					{
						P1.skillFlag = false;
						P1.Rflag = false;
					}
				}
				if (P1.Lflag)
				{
					if (P1.hitPos.y > P1.AttackRange.y - 20)
					{
						P1.hitPos.y -= 5;
						P1.hitoffsetPos.y -= 5;
					}
					if (P1.hitoffsetPos.x > P1.AttackRange.x - 10)
					{
						P1.hitPos.x -= 5;
						P1.hitoffsetPos.x -= 5;
					}
					if ((P1.hitoffsetPos.x < P1.AttackRange.x - 10) && (P1.hitPos.y < P1.AttackRange.y - 20))
					{
						P1.skillFlag = false;
						P1.Lflag = false;
					}
				}
				P1.nazo.s3 = 0;
			}
				
		}
		if (keyDownTrigger[KEY_ID_1SKILL4] || keyDownTrigger[P1S4])
		{
			if (P1.LP <= 50)
			{
				if (P1.nazo.s4 / 300)
				{
					P1.skillFlag = true;
					P1.count = 0;
					P1.skill = SKILL_ID::SKILL_4;
					if (P1.dir == 0)
					{
						P1.Rflag = true;
					}
					if (P1.dir == 1)
					{
						P1.Lflag = true;
					}
				}

			}

		}
		if (P1.skill == SKILL_ID::SKILL_4)
		{
			if (P1.skillFlag == true)
			{
				if (P1.Rflag)
				{
					P1.SSposoffset = P1.Attackoffset.y + 20;
					P1.SSpos = P1.AttackRange.y - 20;
					P1.SSX = P1.Attackoffset.x + 1000;
					if (!P1.posSetFlag)
					{
						P1.SetPos = P1.SSpos;
						P1.SetoffPos = P1.SSposoffset;
						P1.SetoffX = P1.SSX;
						P1.posSetFlag = true;
					}
					if ((P1.count / 120) && (P1.Rflag))
					{


						if (P1.hitPos.y > P1.SetPos)
						{
							P1.hitPos.y -= 20;
						}
						if (P1.hitoffsetPos.y < P1.SetoffPos)
						{
							P1.hitoffsetPos.y += 20;
						}
						if (P1.hitoffsetPos.x < P1.SetoffX)
						{
							P1.hitoffsetPos.x += 20;
						}
					}
					if (P1.count / 360)
					{
						P1.skillFlag = false;
						P1.Rflag = false;
						P1.posSetFlag = false;
					}
				}
				if (P1.Lflag)
				{
					P1.SSposoffset = P1.Attackoffset.y + 20;
					P1.SSpos = P1.AttackRange.y - 20;
					P1.SSX = P1.AttackRange.x - 1000;
					if (!P1.posSetFlag)
					{
						P1.SetPos = P1.SSpos;
						P1.SetoffPos = P1.SSposoffset;
						P1.SetoffX = P1.SSX;
						P1.posSetFlag = true;
					}
					if ((P1.count / 120) && (P1.Lflag))
					{


						if (P1.hitPos.y > P1.SetPos)
						{
							P1.hitPos.y -= 20;
						}
						if (P1.hitoffsetPos.y < P1.SetoffPos)
						{
							P1.hitoffsetPos.y += 20;
						}
						if (P1.hitoffsetPos.x > P1.SetoffX)
						{
							P1.hitoffsetPos.x -= 20;
						}
					}
					if (P1.count / 360)
					{
						P1.skillFlag = false;
						P1.Lflag = false;
						P1.posSetFlag = false;
					}
				}
			}
			else if (P1.skillFlag == false)
			{
				
			}
		}
		if (keyDownTrigger[KEY_ID_1SKILL2] || keyDownTrigger[P1S2])
		{
			if (P1.nazo.s2 / 600)
			{
				P1.skill = SKILL_ID::SKILL_2;
				P1.skillFlag = true;
				P1.bufFlag = true;
			}
		}
	}
	//P2
	if (player2 == CHAR_ID::CHAR_ID_4)
	{
		if (keyDownTrigger[KEY_ID_2SKILL1] || keyDownTrigger[P2S1])
		{
			if (P2.nazo.s1 / 300)
			{
				P2.skillFlag = true;
				P2.skill = SKILL_ID::SKILL_1;
				if (P2.dir == 0)
				{
					P2.Rflag = true;
				}
				if (P2.dir == 1)
				{
					P2.Lflag = true;
				}
				P2.count = 0;
			}
		}
		if (P2.skill == SKILL_ID::SKILL_1)
		{
			if (P2.skillFlag == true)
			{
				if (P2.Rflag)
				{
					P2.SSposoffset = P2.Attackoffset.x - 50;
					P2.SSpos = P2.AttackRange.y - 100;
					P2.SSX = P2.Attackoffset.x + 300;
					if (!P2.posSetFlag)
					{
						P2.SetPos = P2.SSpos;
						P2.SetoffPos = P2.SSposoffset;
						P2.SetoffX = P2.SSX;
						P2.posSetFlag = true;
					}
					if (P2.count / 5)
					{
						if ((P2.hitoffsetPos.x > P2.SetoffPos) && (P2.hitPos.y > P2.SetPos))
						{
							P2.hitPos.y -= 10;

						}
						if (P2.hitoffsetPos.x < P2.SetoffX)
						{
							P2.hitPos.x += 10;
							P2.hitoffsetPos.x += 10;
						}
						else
						{
							P2.skillFlag = false;
							P2.Rflag = false;
							P2.posSetFlag = false;
						}
					}
				}
				if (P2.Lflag)
				{
					P2.SSposoffset = P2.AttackRange.x + 50;
					P2.SSpos = P2.AttackRange.y - 100;
					P2.SSX = P2.AttackRange.x - 300;
					if (!P2.posSetFlag)
					{
						P2.SetPos = P2.SSpos;
						P2.SetoffPos = P2.SSposoffset;
						P2.SetoffX = P2.SSX;
						P2.posSetFlag = true;
					}
					if (P2.count / 5)
					{
						if ((P2.hitoffsetPos.x < P2.SetoffPos) && (P2.hitPos.y > P2.SetPos))
						{
							P2.hitPos.y -= 10;

						}
						if (P2.hitoffsetPos.x > P2.SetoffX)
						{
							P2.hitPos.x -= 10;
							P2.hitoffsetPos.x -= 10;
						}
						else
						{
							P2.skillFlag = false;
							P2.Lflag = false;
							P2.posSetFlag = false;
						}
					}
				}
				P2.nazo.s1 = 0;
			}
		}
		if (keyDownTrigger[KEY_ID_2SKILL3] || keyDownTrigger[P2S3])
		{
			if (P2.nazo.s3 / 1000)
			{
				P2.skillFlag = true;
				P2.skill = SKILL_ID::SKILL_3;
				if (P2.dir == 0)
				{
					P2.Rflag = true;
				}
				if (P2.dir == 1)
				{
					P2.Lflag = true;
				}
			}
		}
		if (P2.skill == SKILL_ID::SKILL_3)
		{
			if (P2.skillFlag == true)
			{

				if (P2.Rflag)
				{
					if (P2.hitPos.y > P2.AttackRange.y - 20)
					{
						P2.hitPos.y -= 5;
						P2.hitoffsetPos.y -= 5;
					}
					if (P2.hitoffsetPos.x < P2.Attackoffset.x + 10)
					{
						P2.hitPos.x += 5;
						P2.hitoffsetPos.x += 5;
					}
					if ((P2.hitoffsetPos.x > P2.Attackoffset.x + 10) && (P2.hitPos.y < P2.AttackRange.y - 20))
					{
						P2.skillFlag = false;
						P2.Rflag = false;
					}
				}
				if (P2.Lflag)
				{
					if (P2.hitPos.y > P2.AttackRange.y - 20)
					{
						P2.hitPos.y -= 5;
						P2.hitoffsetPos.y -= 5;
					}
					if (P2.hitoffsetPos.x > P2.AttackRange.x - 10)
					{
						P2.hitPos.x -= 5;
						P2.hitoffsetPos.x -= 5;
					}
					if ((P2.hitoffsetPos.x < P2.AttackRange.x - 10) && (P2.hitPos.y < P2.AttackRange.y - 20))
					{
						P2.skillFlag = false;
						P2.Lflag = false;
					}
				}
				P2.nazo.s3 = 0;
			}

		}
		if (keyDownTrigger[KEY_ID_2SKILL4] || keyDownTrigger[P2S4])
		{
			if (P2.LP <= 50)
			{
				if (P2.nazo.s4 / 300)
				{
					P2.skillFlag = true;
					P2.count = 0;
					P2.skill = SKILL_ID::SKILL_4;
					if (P2.dir == 0)
					{
						P2.Rflag = true;
					}
					if (P2.dir == 1)
					{
						P2.Lflag = true;
					}
				}

			}

		}
		if (P2.skill == SKILL_ID::SKILL_4)
		{
			if (P2.skillFlag == true)
			{
				if (P2.Rflag)
				{
					P2.SSposoffset = P2.Attackoffset.y + 20;
					P2.SSpos = P2.AttackRange.y - 20;
					P2.SSX = P2.Attackoffset.x + 1000;
					if (!P2.posSetFlag)
					{
						P2.SetPos = P2.SSpos;
						P2.SetoffPos = P2.SSposoffset;
						P2.SetoffX = P2.SSX;
						P2.posSetFlag = true;
					}
					if ((P2.count / 120) && (P2.Rflag))
					{
						if (P2.hitPos.y > P2.SetPos)
						{
							P2.hitPos.y -= 20;
						}
						if (P2.hitoffsetPos.y < P2.SetoffPos)
						{
							P2.hitoffsetPos.y += 20;
						}
						if (P2.hitoffsetPos.x < P2.SetoffX)
						{
							P2.hitoffsetPos.x += 20;
						}
					}
					if (P2.count / 360)
					{
						P2.skillFlag = false;
						P2.Rflag = false;
						P2.posSetFlag = false;
					}
				}
				if (P2.Lflag)
				{
					P2.SSposoffset = P2.Attackoffset.y + 20;
					P2.SSpos = P2.AttackRange.y - 20;
					P2.SSX = P2.AttackRange.x - 1000;
					if (!P2.posSetFlag)
					{
						P2.SetPos = P2.SSpos;
						P2.SetoffPos = P2.SSposoffset;
						P2.SetoffX = P2.SSX;
						P2.posSetFlag = true;
					}
					if ((P2.count / 120) && (P2.Lflag))
					{
						if (P2.hitPos.y > P2.SetPos)
						{
							P2.hitPos.y -= 20;
						}
						if (P2.hitoffsetPos.y < P2.SetoffPos)
						{
							P2.hitoffsetPos.y += 20;
						}
						if (P2.hitoffsetPos.x > P2.SetoffX)
						{
							P2.hitoffsetPos.x -= 20;
						}
					}
					if (P2.count / 360)
					{
						P2.skillFlag = false;
						P2.Lflag = false;
						P2.posSetFlag = false;
					}
				}
			}
			else if (P2.skillFlag == false)
			{
			
			}
		}
		if (keyDownTrigger[KEY_ID_2SKILL2] || keyDownTrigger[P2S2])
		{
			if (P2.nazo.s2 / 600)
			{
				P2.skill = SKILL_ID::SKILL_2;
				P2.skillFlag = true;
				P2.bufFlag = true;
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
// player1Ç™player2ÇÃçUåÇÇéÛÇØÇÈìñÇΩÇËîªíË
bool Skill::CheckHitP1(Vector2 pos)
{
	if (P2.skillFlag == true)
	{
		if ((P2.hitoffsetPos.x > pos.x) &&
			(P2.hitPos.x < pos.x) &&
			(P2.hitoffsetPos.y > pos.y) &&
			(P2.hitPos.y < pos.y))
		{
			P2.skillFlag = false;
			P1.hitFlag = true;
			return true;
		}
	}
	return false;
}
// player2Ç™player1ÇÃçUåÇÇéÛÇØÇÈìñÇΩÇËîªíË
bool Skill::CheckHitP2(Vector2 pos)
{
	if (P1.skillFlag == true)
	{
		if ((P1.hitoffsetPos.x > pos.x) &&
			(P1.hitPos.x < pos.x) &&
			(P1.hitoffsetPos.y > pos.y) &&
			(P1.hitPos.y < pos.y))
		{
			P1.skillFlag = false;
			P2.hitFlag = true;
			return true;
		}
		//DmageCtl(pos);
	}
	return false;
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
			else if (P2.skillFlag == false)
			{
				if (P2.kisi.s2 / 120)
				{
					P2.bufFlag = false;
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
			else if (P2.skillFlag == false)
			{
				if (P2.kisi.s3 / 120)
				{
					P2.bufFlag = false;
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
				P1.buto.s1 = 0;
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
				P2.buto.s1 = 0;
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

int Skill::HPCtlP1(void)
{
	return P1.LP;
}

int Skill::HPCtlP2(void)
{
	return	P2.LP;
}

void Skill::DmageCtl(Vector2 pos1,Vector2 pos2)
{
	int LPhold = 0;
	
	if (CheckHitP1(pos1))
	{
		if (P1.hitFlag)
		{
			if (P1.defense > 0)
			{
				if (P2.attack > 0)
				{
					P2.HP = P2.dmage + P2.attack;
					LPhold = (P1.LP + P1.defense) - P2.HP;
					P1.LP = LPhold;
				}
				else
				{
					P2.HP = P2.dmage;
					LPhold = (P1.LP + P1.defense) - P2.HP;
					P1.LP = LPhold;
				}
			}
			else
			{
				if (P2.attack > 0)
				{
					P2.HP = P2.dmage + P2.attack;
					LPhold = P1.LP - P2.HP;
					P1.LP = LPhold;
				}
				else
				{
					P2.HP = P2.dmage;
					LPhold = P1.LP - P2.HP;
					P1.LP = LPhold;
				}
			}
		}
	}
	else if(!CheckHitP1(pos1))
	{

	}
	
	int LPhold2 = 0;
	if (CheckHitP2(pos2))
	{
		if (P2.hitFlag == true)
		{

			if (P1.defense > 0)
			{

				if (P1.attack > 0)
				{
					P1.HP = P1.dmage + P1.attack;
					LPhold2 = (P2.LP + P2.defense) - P1.HP;
					P2.LP = LPhold2;
				}
				else
				{
					P1.HP = P1.dmage;
					LPhold2 = (P2.LP + P2.defense) - P1.HP;
					P2.LP = LPhold2;
				}
			}
			else
			{
				if (P1.attack > 0)
				{
					P1.HP = P1.dmage + P1.attack;
					LPhold2 = P2.LP - P1.HP;
					P2.LP = LPhold2;
				}
				else
				{
					P1.HP = P1.dmage;
					LPhold2 = P2.LP - P1.HP;
					P2.LP = LPhold2;
				}

			}
		}
	}
	else if(!CheckHitP2(pos2))
	{

	}
}

void Skill::SpeedCtl(int p1,int p2)
{
	int sphold = 0;
	if(P1.speed>0)
	{
		sphold = p1;
		p1 = sphold+P1.speed;
	}
	else
	{

	}
	int sphold2 = 0;
	if(P2.speed>0)
	{
		sphold2 = p2;
		p2 = sphold2+P2.speed;
	}
	else
	{

	}
}

void Skill::Dir(int p1, int p2)
{
	P1.dir = p1;
	P2.dir = p2;
}

Skill::Skill()
{
	StageSysInit();

	SScountInit();
}

Skill::~Skill()
{
}
