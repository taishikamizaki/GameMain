#include "DxLib.h"
#include "stage.h"

int chipImage[7];
int matiImage[43];
int tougiImage[12];
int yamaImage[23];
int hamaImage;
int timeImage[10];
int healImage[10];
int buffAImage[10];
int buffDImage[10];
int buffSImage[10];
int buffUImage[10];
int slashImage[16];
int slash2Image[16];
int slash3Image[12];
int laserImage[5];
bool hamaFlag;
int yamabgm;
int matibgm;
int tougibgm;
int hamaCnt;
XY mapSize;
XY hamaPos;
PlayChar id;
int HP;			// playerHP
int LP;			// playerÇÃèâä˙ÉâÉCÉtÉ|ÉCÉìÉg
int dmage;		// playerÇ™ó^Ç¶ÇÈÉ_ÉÅÅ[ÉW
int attack;		// playerÇÃçUåÇóÕ(ïtó^Ç≥ÇÍÇΩêîíl)
int defense;	// playerÇÃñhå‰óÕ(ïtó^Ç≥ÇÍÇΩêîíl)
int speed;		// playerÇÃà⁄ìÆë¨ìx
enum MAP_ID mapID;
SKILL_ID skill;
player P1;
player P2;
int count;
SScount kisi;
SScount maho;
SScount buto;
SScount nazo;
bool SSflag;	//î≠ìÆÇPâÒóp
bool skillFlag;
bool hitFlag;
bool bufFlag;
char keystate[256];
int map[MAP_Y][MAP_X];
int mapyama[MAP_Y][MAP_X] = {
{0,0,0,0 ,0,0,0,0 ,0,0,0,0 ,0,0,0,0 ,0,0,0,0,},
{13,14,8,8 ,8,8,8,8 ,11,13,14,8 ,8,13,14,8 ,8,8,8,8,},
{9,10,8,8 ,8,8,8,9 ,17,10,8,8 ,8,8,8,8 ,13,14,8,8,},
{5,5,3,8 ,19,4,2,5 ,5,5,3,8 ,8,2,3,4 ,8,8,8,8,},

{5,5,5,3 ,2,5,5,5 ,5,5,5,3 ,2,5,5,5 ,3,4,4,2,},
{12,12,12,12 ,12,12,12,12 ,12,12,12,12 ,12,12,12,12 ,12,12,12,12,},
{16,16,16,16 ,16,16,16,16 ,16,16,16,16 ,16,16,16,16 ,16,16,16,16,},
{16,16,16,16 ,16,16,16,16 ,20,21,21,22 ,16,16,16,16 ,16,16,16,16,},

{6,6,6,6 ,6,6,6,6 ,6,6,6,6 ,6,6,6,6 ,6,6,6,6,},
{7,6,6,6 ,20,22,6,6 ,7,7,7,7 ,6,6,20,22 ,7,7,7,7,},
{15,15,15,15 ,15,15,15,15 ,15,15,15,15 ,15,15,15,15 ,15,15,15,15,},
{1,1,1,1 ,1,1,1,1 ,1,1,1,1 ,1,1,1,1 ,1,1,1,1,},
};
int maphamaguri[MAP_Y][MAP_X] = {
{2,0,0,0 ,1,0,0,1 ,0,0,0,0 ,1,0,0,1 ,0,0,0,3,},
{2,0,0,0 ,1,0,0,1 ,0,0,0,0 ,1,0,0,1 ,0,0,0,3,},
{2,0,0,0 ,1,0,0,1 ,0,0,0,0 ,1,0,0,1 ,0,0,0,3,},
{2,0,0,0 ,1,0,0,1 ,0,0,0,0 ,1,0,0,1 ,0,0,0,3,},

{2,0,0,0 ,1,0,0,1 ,0,0,0,0 ,1,0,0,1 ,0,0,0,3,},
{2,0,0,0 ,1,0,0,1 ,0,0,0,0 ,1,0,0,1 ,0,0,0,3,},
{2,0,0,0 ,1,0,0,1 ,0,0,0,0 ,1,0,0,1 ,0,0,0,3,},
{2,0,0,0 ,1,0,0,1 ,0,0,0,0 ,1,0,0,1 ,0,0,0,3,},

{2,0,0,0 ,1,0,0,1 ,0,0,0,0 ,1,0,0,1 ,0,0,0,3,},
{2,0,0,0 ,1,0,0,1 ,0,0,0,0 ,1,0,0,1 ,0,0,0,3,},
{2,0,0,0 ,1,0,0,1 ,0,0,0,0 ,1,0,0,1 ,0,0,0,3,},
{6,6,6,6 ,6,6,6,6 ,6,6,6,6 ,6,6,6,6 ,6,6,6,6,},
};
int mapmati[MAP_Y][MAP_X] = {
{16,16,16,16 ,16,16,16,16 ,16,16,16,16 ,16,16,16,16 ,16,16,16,16,},
{19,19,19,19 ,19,19,19,19 ,20,21,19,19 ,19,19,19,19 ,19,19,19,19,},
{19,20,21,19 ,19,19,19,19 ,19,19,19,19 ,19,20,21,19 ,19,19,23,19,},
{19,19,19,19 ,19,20,21,19 ,19,19,19,40 ,19,19,19,19 ,19,19,19,19,},

{19,19,19,19 ,19,19,19,19 ,19,19,40,19 ,19,19,19,19 ,20,21,19,19,},
{40,19,19,19 ,19,39,19,19 ,19,19,19,40 ,19,20,21,19 ,19,19,39,19,},
{35,35,35,35 ,35,38,35,35 ,35,36,37,35 ,35,35,35,35 ,35,35,38,35,},
{12,11,11,13 ,4,3,3,5 ,33,41,42,34 ,12,11,11,13 ,4,3,3,5,},

{9,9,9,9 ,1,1,1,1 ,17,31,32,17 ,9,9,9,9 ,1,1,1,1,},
{9,10,15,9 ,1,2,7,1 ,27,28,29,30 ,22,10,15,9 ,1,2,7,1,},
{9,9,8,9 ,1,1,8,8 ,24,25,25,26 ,22,22,14,9 ,1,1,6,8,},
{0,0,0,0 ,0,0,0,0 ,0,0,0,0 ,0,0,0,0 ,0,0,0,0,},
};
int maptougi[MAP_Y][MAP_X] = {
{10,4,4,10 ,10,4,4,10 ,10,4,4,10 ,10,4,4,10 ,10,4,4,10,},
{11,11,11,11 ,11,11,11,11 ,11,11,11,11 ,11,11,11,11 ,11,11,11,11,},
{3,4,4,9 ,9,4,4,3 ,9,4,4,9 ,3,4,4,9 ,9,4,4,3,},
{2,4,4,10 ,10,4,4,2 ,10,4,4,10 ,2,4,4,10 ,10,4,4,2,},

{5,6,6,6 ,6,6,6,5 ,6,6,6,6 ,5,6,6,6 ,6,6,6,5,},
{5,8,8,8 ,8,8,8,5 ,8,8,8,8 ,5,8,8,8 ,8,8,8,5,},
{5,8,8,8 ,8,8,8,5 ,8,8,8,8 ,5,8,8,8 ,8,8,8,5,},
{5,8,8,8 ,8,8,8,5 ,8,8,8,8 ,5,8,8,8 ,8,8,8,5,},

{1,1,1,1 ,1,1,1,1 ,1,1,1,1 ,1,1,1,1 ,1,1,1,1,},
{0,0,0,0 ,0,0,0,0 ,0,0,0,0 ,0,0,0,0 ,0,0,0,0,},
{0,0,0,0 ,0,0,0,0 ,0,0,0,0 ,0,0,0,0 ,0,0,0,0,},
{7,7,7,7 ,7,7,7,7 ,7,7,7,7 ,7,7,7,7 ,7,7,7,7,},
};
int WINAPI WinMain(HINSTANCE, HINSTANCE, LPSTR, int)
{
	if (!SysInit())
	{
		return 0;
	}
	// ï`âÊëŒè€ÉOÉâÉtÉBÉbÉNÇçÏê¨

	// πﬁ∞—Ÿ∞Ãﬂ
	//-------------------------
	while (ProcessMessage() == 0 && CheckHitKey(KEY_INPUT_ESCAPE) == 0)
	{
		hamaCnt++;
		if (hamaCnt > HAMA_CNT_2)
		{
			hamaCnt = 0;
		}
		StageGameInit();
		ScreenFlip();
	}
	DxLib_End();
	return 0;
}

// ºΩ√—èàóù
//-------------------------
bool SysInit(void)
{
	bool rtnFlag = true;
	// ºΩ√—èàóù
	//---------------------
	SetWindowText("BaseProject");
	// ºΩ√—èàóù
	SetGraphMode(SCREEN_SIZE_X, SCREEN_SIZE_Y, 16); // 800Å~600ƒﬁØƒ65536êF”∞ƒﬁÇ…ê›íË
	ChangeWindowMode(true);							// true:Window false:ÃŸΩ∏ÿ∞›
	if (DxLib_Init() == -1)							// DX◊≤Ãﬁ◊ÿèâä˙âªèàóù
	{
		return -1;
	}
	SetDrawScreen(DX_SCREEN_BACK);					// Ç–Ç∆Ç‹Ç∏ ﬁØ∏ ﬁØÃßÇ…ï`âÊ

	// ------∏ﬁ◊Ã®Ø∏ÇÃìoò^------
	LoadDivGraph("image/hamaguriroom.png", 7, 7, 1, CHIP_SIZE_X, CHIP_SIZE_Y, chipImage, false);
	LoadDivGraph("image/mati.png", 43, 43, 1, CHIP_SIZE_X, CHIP_SIZE_Y, matiImage, false);
	LoadDivGraph("image/tougizyou.png", 12, 12, 1, CHIP_SIZE_X, CHIP_SIZE_Y, tougiImage, false);
	LoadDivGraph("image/yama.png", 23, 23, 1, CHIP_SIZE_X, CHIP_SIZE_Y, yamaImage, false);
	LoadDivGraph("image/É^ÉCÉÄ.png", 10, 10, 1, TIME_SIZE_X, TIME_SIZE_Y, timeImage, false);
	LoadDivGraph("image/Heal.png", 10, 10, 1, 120, 120, healImage, false);
	LoadDivGraph("image/Attackbuff.png", 10, 10, 1, 120, 120, buffAImage, false);
	LoadDivGraph("image/Defensebuff.png", 10, 10, 1, 120, 120, buffDImage, false);
	LoadDivGraph("image/Speedbuff.png", 10, 10, 1, 120, 120, buffSImage, false);
	LoadDivGraph("image/Uniquebuff.png", 10, 10, 1, 120, 120, buffUImage, false);
	LoadDivGraph("image/slash1.png", 16, 4, 4, 320, 240, slashImage, false);
	LoadDivGraph("image/slash2.png", 16, 4, 4, 320, 240, slash2Image, false);
	LoadDivGraph("image/slash3.png", 12, 5, 3, 192, 192, slash3Image, false);
	LoadDivGraph("image/laser.png", 5, 1, 5, 320, 120, laserImage, false);
	(hamaImage = LoadGraph("image/yaku.png"));
	// ------ïœêîèâä˙âª------
	StageSysInit();
	SoundSysInit();
	return rtnFlag;
}

void StageSysInit(void)
{
	hamaFlag = false;
	hamaPos = { 0,0 };
	hamaCnt = 0;
	skillFlag = false;
	SSflag = true;
	bufFlag = false;
	hitFlag = false;
	count = 0;
	mapSize.x = MAP_X;
	mapSize.y = MAP_Y;
	skill = SKILL_ID::SKILL_MAX;
	mapID = MAP_ID::MAP_ID_MATI;
	for (int y = 0; y < mapSize.y; y++)
	{
		for (int x = 0; x < mapSize.x; x++)
		{
			map[y][x] = maptougi[y][x];
		}
	}
	PlayerInit();
	CharInit();
	SScountInit();
}

void SoundSysInit(void)
{
	yamabgm = LoadSoundMem("sound/yama.mp3");
	matibgm = LoadSoundMem("sound/mati.mp3");
	tougibgm = LoadSoundMem("sound/tougizyou.mp3");
	
	SoundGameInit();
}

void StageGameInit(void)
{
	StageDraw();
	for (int y = 0; y < mapSize.y; y++)
	{
		for (int x = 0; x < mapSize.x; x++)
		{
			if (map[y][x] == mapyama[y][x])
			{
				mapID = MAP_ID::MAP_ID_YAMA;
			}
			else if (map[y][x] == mapmati[y][x])
			{
				mapID = MAP_ID::MAP_ID_MATI;
			}
			else if (map[y][x] == maptougi[y][x])
			{
				mapID = MAP_ID::MAP_ID_TOUGI;
			}
		}
	}

	
	hamaPos.x = GetRand(SCREEN_SIZE_X-1);
	hamaPos.y = GetRand(SCREEN_SIZE_Y-HAMA_SIZE_Y-1);

	SkillCtl();
	

	count++;
	P1.Scount++;
}

void SoundGameInit(void)
{
	int randam;
	switch (mapID)
	{
	case MAP_ID::MAP_ID_YAMA:
		SetVolumeMusic(10);
		PlayMusic("sound/yama.mp3", DX_PLAYTYPE_LOOP);
		break;
	case MAP_ID::MAP_ID_MATI:
		SetVolumeMusic(10);
		PlayMusic("sound/mati.mp3", DX_PLAYTYPE_LOOP);
		break;
	case MAP_ID::MAP_ID_TOUGI:
		
		PlayMusic("sound/tougizyou.mp3", DX_PLAYTYPE_LOOP);
		break;
	default:
		break;
	}
	if (mapID == MAP_ID::MAP_ID_YAMA)
	{
		SetVolumeMusic(80);
	}
	if (mapID == MAP_ID::MAP_ID_MATI)
	{
		SetVolumeMusic(100);
	}
	if (mapID == MAP_ID::MAP_ID_TOUGI)
	{
		SetVolumeMusic(100);
	}
	
}

void PlayerInit(void)
{
	id = PlayChar::P_NAZO;
	P1.posp = { 100,450 };
	P1.offsetPosp = { 200,550 };
	P1.hitPos = { P1.offsetPosp.x + 10,P1.posp.y + 10 };
	P1.hitoffsetPos = { P1.hitPos.x + 50,P1.hitPos.y + 70 };
	P1.AttackRange = {0 ,300};
	P1.Attackoffset = {300,P1.offsetPosp.y};
	P1.Scount = 0;
	

	P2.posp = { 800,450 };
	P2.offsetPosp = { 900,550 };
	P2.hitPos = { P2.offsetPosp.x + 10,P2.posp.y + 10 };
	P2.hitoffsetPos = { P2.hitPos.x + 50,P2.hitPos.y + 70 };
	P2.AttackRange = { 700 ,300 };
	P2.Attackoffset = { 1000,P2.offsetPosp.y };
	P2.Scount = 0;

}

void CharInit(void)
{
	if (id == PlayChar::P_KISI)
	{
		HP = 0;
		LP = 100;
		dmage = 10;
		attack = 0;
		defense = 0;
		speed = 0;
	}
	if (id == PlayChar::P_MAHO)
	{
		HP = 0;
		LP = 50;
		dmage = 10;
		attack = 0;
		defense = 0;
		speed = 0;
	}
	if (id == PlayChar::P_BUTO)
	{
		HP = 0;
		LP = 30;
		dmage = 10;
		attack = 0;
		defense = 0;
		speed = 0;
	}
	if (id == PlayChar::P_NAZO)
	{
		HP = 0;
		LP = 50;
		dmage = 10;
		attack = 0;
		defense = 0;
		speed = 0;
	}
}

void SScountInit(void)
{
	kisi.s1 = 0;
	kisi.s2 = 0;
	kisi.s3 = 0;
	kisi.s4 = 0;

	maho.s1 = 0;
	maho.s2 = 0;
	maho.s3 = 0;
	maho.s4 = 0;
	
	buto.s1 = 0;
	buto.s2 = 0;
	buto.s3 = 0;
	buto.s4 = 0;
	
	nazo.s1 = 0;
	nazo.s2 = 0;
	nazo.s3 = 0;
	nazo.s4 = 0;
}

void StageDraw()
{
	int Anim = (P1.Scount / 5) % 10;
	int AnimS = (P1.Scount / 5) % 16;
	int AnimI = (P1.Scount / 5) % 12;
	int AnimL = (P1.Scount / 5) % 5;
	for (int y = 0; y<mapSize.y;y++)
	{
		for(int x = 0; x < mapSize.x; x++)
		{
			DrawGraph(x*CHIP_SIZE_X, y*CHIP_SIZE_Y, tougiImage[map[y][x]], true);
		}
	}
	DrawGraph(SCREEN_SIZE_X/2-TIME_SIZE_X,0,timeImage[0],true);
	//DrawFormatString(0, 0,0x000000,"%d", hamaCnt);
	//DrawFormatString(0, 20, 0x000000, "count:%d", count);
	//DrawFormatString(0, 40, 0x000000, "Scount:%d", P1.Scount);
	//DrawFormatString(0, 60, 0x000000, "HP:%d", HP);
	//DrawFormatString(0, 80, 0x000000, "LP:%d", LP);
	//DrawFormatString(0, 100, 0x000000, "dmege:%d", dmage);
	//DrawFormatString(0, 120, 0x000000, "attack:%d", attack);
	//DrawFormatString(0, 140, 0x000000, "defense:%d", defense);
	//DrawFormatString(0, 160, 0x000000, "speed:%d", speed);
	//DrawFormatString(0, 180, 0x000000, "s1:%d", kisi.s1);
	//DrawFormatString(0, 200, 0x000000, "s2:%d", kisi.s2);
	//DrawFormatString(0, 220, 0x000000, "s3:%d", kisi.s3);
	//DrawFormatString(0, 240, 0x000000, "s4:%d", kisi.s4);
	//DrawFormatString(70,180, 0x000000, "s1:%d", maho.s1);
	//DrawFormatString(70, 200, 0x000000, "s2:%d", maho.s2);
	//DrawFormatString(70, 220, 0x000000, "s3:%d", maho.s3);
	//DrawFormatString(70, 240, 0x000000, "s4:%d", maho.s4);
	//DrawFormatString(140, 180, 0x000000, "s1:%d", buto.s1);
	//DrawFormatString(140, 200, 0x000000, "s2:%d", buto.s2);
	//DrawFormatString(140, 220, 0x000000, "s3:%d", buto.s3);
	//DrawFormatString(140, 240, 0x000000, "s4:%d", buto.s4);
	//DrawFormatString(210, 180, 0x000000, "s1:%d", nazo.s1);
	//DrawFormatString(210, 200, 0x000000, "s2:%d", nazo.s2);
	//DrawFormatString(210, 220, 0x000000, "s3:%d", nazo.s3);
	//DrawFormatString(210, 240, 0x000000, "s4:%d", nazo.s4);
	if (hamaCnt > HAMA_CNT_1)
	{
		DrawGraph(hamaPos.x, hamaPos.y, hamaImage, true);
	}
	//P1
	DrawBox(P1.AttackRange.x, P1.AttackRange.y, P1.Attackoffset.x, P1.Attackoffset.y, 0x000000, false);
	DrawBox(P1.posp.x, P1.posp.y, P1.offsetPosp.x, P1.offsetPosp.y, 0xff00ff, false);
	//P2
	DrawBox(P2.AttackRange.x, P2.AttackRange.y, P2.Attackoffset.x, P2.Attackoffset.y, 0x000000, false);
	DrawBox(P2.posp.x, P2.posp.y, P2.offsetPosp.x, P2.offsetPosp.y, 0xff00ff, false);
	if (skill == SKILL_ID::SKILL_1)
	{
		if (skillFlag == true)
		{
			DrawBox(P1.hitPos.x, P1.hitPos.y, P1.hitoffsetPos.x, P1.hitoffsetPos.y, 0xffff88, true);
			//DrawGraph(P1.hitoffsetPos.x+10,posp.y-120,slashImage[AnimS],true);
		}
	}
	if (skill == SKILL_ID::SKILL_2)
	{
		if (bufFlag == true)
		{
			DrawGraph(P1.posp.x - 10, P1.posp.y - 10, buffDImage[Anim], true);
		}
	}
	if (skill == SKILL_ID::SKILL_3)
	{
		//DrawBox(posp.x, posp.y, offsetPosp.x, offsetPosp.y,  0x88ffff, true);
		//DrawGraph(P1.posp.x - 10, P1.posp.y - 10, buffUImage[Anim], true);

		if (skillFlag == true)
		{
			DrawBox(P1.hitPos.x, P1.hitPos.y, P1.hitoffsetPos.x, P1.hitoffsetPos.y, 0x88ffff, true);
		}
	}
	if (skill == SKILL_ID::SKILL_4)
	{
		//DrawBox(posp.x, posp.y, offsetPosp.x, offsetPosp.y, 0xffffff, true);
		//DrawGraph(P1.posp.x - 10, P1.posp.y - 10, healImage[Anim], true);
		if (skillFlag == true)
		{
			//DrawGraph(P1.posp.x - 10, P1.posp.y - 10, laserImage[AnimL], true);
			DrawBox(P1.hitPos.x, P1.hitPos.y, P1.hitoffsetPos.x, P1.hitoffsetPos.y, 0xffffff, true);
		}
	}
	
}

void SkillDraw(void)
{
}

void HamaTime(void)
{
	
	
}

void SkillCtl()
{
	if (CheckHitKey(KEY_INPUT_A) == 1)
	{
		P1.posp.x -= 3;
		P1.offsetPosp.x -= 3;
		P1.AttackRange.x -= 3;
		P1.Attackoffset.x -= 3;
	}
	if (CheckHitKey(KEY_INPUT_D) == 1)
	{
		P1.posp.x += 3;
		P1.offsetPosp.x += 3;
		P1.AttackRange.x += 3;
		P1.Attackoffset.x += 3;
	}


	/// player1(ãRém)
	if (id == PlayChar::P_KISI)
	{
		if (CheckHitKey(KEY_INPUT_U) == 1)
		{

			P1.hitPos.x = P1.offsetPosp.x;
			P1.hitoffsetPos.x = P1.offsetPosp.x + 50;
			skill = SKILL_ID::SKILL_1;
			if (kisi.s1 / 300)//ëÂëÃ5ïb
			{
				skillFlag = true;
				count = 0;
			}
		}
		if (skill == SKILL_ID::SKILL_1)
		{
			if (skillFlag == true)
			{

				if (count / 10)
				{
					if (P1.hitoffsetPos.x < P1.Attackoffset.x - 40)
					{
						P1.hitPos.x += 2;
						P1.hitoffsetPos.x += 2;
					}
					else
					{
						skillFlag = false;
						P1.hitPos = { P1.offsetPosp.x + 10,P1.posp.y + 10 };
						P1.hitoffsetPos = { P1.hitPos.x + 50,P1.hitPos.y + 70 };
					}
					if (P1.offsetPosp.x > P1.hitPos.x)
					{
						skillFlag = false;
						P1.hitPos = { P1.offsetPosp.x + 10,P1.posp.y + 10 };
						P1.hitoffsetPos = { P1.hitPos.x + 50,P1.hitPos.y + 70 };
					}
				}
				kisi.s1 = 0;
			}

		}

		if (CheckHitKey(KEY_INPUT_I) == 1)
		{
			if (kisi.s2 / 4200)
			{
				skill = SKILL_ID::SKILL_2;
			
				skillFlag = true;

			}

		}
		if (CheckHitKey(KEY_INPUT_J) == 1)
		{
			if (kisi.s3 / 60)
			{
				skill = SKILL_ID::SKILL_3;
			
				skillFlag = true;
			}

		}
		if (CheckHitKey(KEY_INPUT_K) == 1)
		{
			if (SSflag == true)
			{
				if (LP <= 10)
				{
					skill = SKILL_ID::SKILL_4;
					skillFlag = true;
					count = 0;
				}
			}
		}
		if (skill == SKILL_ID::SKILL_4)
		{
			if (skillFlag == true)
			{
				if (count / 5)
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
						skillFlag = false;
					}
				}
			}
			else if (skillFlag == false)
			{
				SSflag = false;
				P1.hitPos = { P1.offsetPosp.x + 10,P1.posp.y + 10 };
				P1.hitoffsetPos = { P1.hitPos.x + 50,P1.hitPos.y + 70 };
			}
		}
	}

	///player2(ñÇñ@égÇ¢)
	if (id == PlayChar::P_MAHO)
	{
		if (CheckHitKey(KEY_INPUT_U) == 1)
		{

			skill = SKILL_ID::SKILL_1;
			if (maho.s1 / 300)
			{
				skillFlag = true;
			}
		}
		if (skill == SKILL_ID::SKILL_1)
		{
			if (skillFlag == true)
			{
				if (P1.hitoffsetPos.x < P1.Attackoffset.x + 300)
				{
					P1.hitPos.x += 10;
					P1.hitoffsetPos.x += 10;
				}
				else
				{
					skillFlag = false;
					P1.hitPos = { P1.offsetPosp.x + 10,P1.posp.y + 10 };
					P1.hitoffsetPos = { P1.hitPos.x + 50,P1.hitPos.y + 70 };
				}
			}
		}
		if (CheckHitKey(KEY_INPUT_I) == 1)
		{
			skill = SKILL_ID::SKILL_2;
			if (maho.s2 / 1200)
			{
				skillFlag = true;
			}
		}
		if (CheckHitKey(KEY_INPUT_J) == 1)
		{
			skill = SKILL_ID::SKILL_3;
			if (maho.s3 / 1000)
			{
				skillFlag = true;
			}
		}
		if (CheckHitKey(KEY_INPUT_K) == 1)
		{
			if (LP <= 50)
			{
				skill = SKILL_ID::SKILL_4;
				if (maho.s4 / 1800)
				{
					count = 0;
					skillFlag = true;
				}
			}
		}
		if (skill == SKILL_ID::SKILL_4)
		{
			if (skillFlag == true)
			{
				if (count / 240)
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
				if (count / 540)
				{
					skillFlag = false;
				}
			}
			else if (skillFlag == false)
			{
				P1.hitPos = { P1.offsetPosp.x + 10,P1.posp.y + 10 };
				P1.hitoffsetPos = { P1.hitPos.x + 50,P1.hitPos.y + 70 };
			}
		}
	}

	///plaeyr3(ïêì¨â∆)
	if (id == PlayChar::P_BUTO)
	{
		if (CheckHitKey(KEY_INPUT_U) == 1)
		{

			skill = SKILL_ID::SKILL_1;
			if (buto.s1 / 300)
			{
				skillFlag = true;
			}

		}
		if (skill == SKILL_ID::SKILL_1)
		{
			if (skillFlag == true)
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
					skillFlag = false;
				}
				buto.s1 = 0;
			}
			else if (skillFlag == false)
			{
				
				P1.hitPos = { P1.offsetPosp.x + 10,P1.posp.y + 10 };
				P1.hitoffsetPos = { P1.hitPos.x + 50,P1.hitPos.y + 70 };
			}
		}

		if (CheckHitKey(KEY_INPUT_I) == 1)
		{
			if (buto.s2 / 600)
			{
				skill = SKILL_ID::SKILL_2;
			
				skillFlag = true;
			}
		}
		if (CheckHitKey(KEY_INPUT_J) == 1)
		{
			if (buto.s3 / 1200)
			{
				skill = SKILL_ID::SKILL_3;
				skillFlag = true;
			}
		}
		if (CheckHitKey(KEY_INPUT_K) == 1)
		{
			if (buto.s4 / 600)
			{
				if (LP <= 30)
				{
					skill = SKILL_ID::SKILL_4;
					skillFlag = true;
				}
			}
		}
	}
	///player4(íj)
	if (id == PlayChar::P_NAZO)
	{
		if (CheckHitKey(KEY_INPUT_U) == 1)
		{
			if (nazo.s1 / 300)
			{
				skillFlag = true;
				skill = SKILL_ID::SKILL_1;
			}
		}
		if (skill == SKILL_ID::SKILL_1)
		{
			if (skillFlag == true)
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
					skillFlag = false;
					P1.hitPos = { P1.offsetPosp.x + 10,P1.posp.y + 10 };
					P1.hitoffsetPos = { P1.hitPos.x + 50,P1.hitPos.y + 70 };
				}
				nazo.s1 = 0;
			}
		}

		if (CheckHitKey(KEY_INPUT_I) == 1)
		{
			if (nazo.s2 / 600)
			{
				skill = SKILL_ID::SKILL_2;
				skillFlag = true;
				bufFlag = true;
			}
		}
		if (CheckHitKey(KEY_INPUT_J) == 1)
		{
			if (nazo.s3 / 1000)
			{
				skillFlag = true;
				skill = SKILL_ID::SKILL_3;
				P1.hitPos.x = P1.offsetPosp.x;
				P1.hitoffsetPos.x = P1.offsetPosp.x + 50;
			}
		}
		if (skill == SKILL_ID::SKILL_3)
		{
			if (skillFlag == true)
			{
				if (P1.hitPos.y > 450)
				{
					P1.hitPos.y -= 1;
					P1.hitoffsetPos.y -= 1;
				}
				if(P1.hitoffsetPos.x < P1.Attackoffset.x-40)
				{
					P1.hitPos.x += 1;
					P1.hitoffsetPos.x += 1;
					
				}
				else
				{
					skillFlag = false;
				}
				nazo.s3 = 0;
			}
			else if (skillFlag == false)
			{
				P1.hitPos = { P1.offsetPosp.x + 10,P1.posp.y + 10 };
				P1.hitoffsetPos = { P1.hitPos.x + 50,P1.hitPos.y + 70 };
			}
		}
		if (CheckHitKey(KEY_INPUT_K) == 1)
		{
			if (LP <= 50)
			{
				if (nazo.s4 / 1800)
				{
					skillFlag = true;
					count = 0;
					skill = SKILL_ID::SKILL_4;
				}
				
			}
		
		}
		if (skill == SKILL_ID::SKILL_4)
		{
			if (skillFlag == true)
			{
				if (count / 60)
				{
					if (P1.hitPos.y > 450)
					{
						P1.hitPos.y -= 20;
					}
					if (P1.hitoffsetPos.x < P1.Attackoffset.x+100)
					{
						P1.hitoffsetPos.x += 20;
					}
				}
				if (count / 120)
				{
					skillFlag = false;
				}
			}
			else if (skillFlag == false)
			{
				P1.hitPos = { P1.offsetPosp.x + 10,P1.posp.y + 10 };
				P1.hitoffsetPos = { P1.hitPos.x + 50,P1.hitPos.y + 70 };
			}
		}
	}

	P1skill();
	P2skill();
	P3skill();
	P4skill();

	kisi.s1++;
	kisi.s2++;
	kisi.s3++;
	kisi.s4++;

	maho.s1++;
	maho.s2++;
	maho.s3++;
	maho.s4++;

	buto.s1++;
	buto.s2++;
	buto.s3++;
	buto.s4++;

	nazo.s1++;
	nazo.s2++;
	nazo.s3++;
	nazo.s4++;
}

void CheckHit()
{
	if ((P1.hitoffsetPos.x > P2.posp.x) &&
		(P1.hitPos.x < P2.offsetPosp.x) &&
		(P1.hitoffsetPos.y > P2.posp.y) &&
		(P1.hitPos.y < P2.offsetPosp.y))
	{
		skillFlag = false;
		hitFlag = true;
	}
}

bool P1skill(void)
{
	int LPhold=0;
	int Dehold = 0;
	int Athold=0;
	if (id == PlayChar::P_KISI)
	{
		switch (skill)
		{
		case SKILL_ID::SKILL_1:
			if (kisi.s1 / 300)
			{
				dmage = 10;
				if (defense < 20)
				{
					Dehold = defense + 5;
					defense = Dehold;
				}
				else if (defense == 20)
				{
					//è„å¿
				}
			}
			break;
		case SKILL_ID::SKILL_2:
			if (skillFlag == true)
			{
				HP = 50;
				if (HP == 50)
				{
					LPhold = LP + HP;
					LP = LPhold;
					if (LP >= 100)
					{
						LP = 100;
					}
				}
				kisi.s2 = 0;
				skillFlag = false;
			}
			//P1.Scount = 4200;//ëÂëÃ70ïb
			break;
		case SKILL_ID::SKILL_3:
			
			if (skillFlag == true)
			{
				if (LP > 10)
				{
					HP = 10;
					LPhold = LP - HP;
					LP = LPhold;
					Athold = attack + 5;
					attack = Athold;
				}
				else if (LP == 10)
				{

				}
				kisi.s3 = 0;
				skillFlag = false;
			}
			
			
			break;
		case SKILL_ID::SKILL_4:
			if (HP <= 10)
			{
				dmage = 40;
			}
			break;
		case SKILL_ID::SKILL_MAX:
			break;
		default:
			break;
		}
		return true;
	}
}

bool P2skill(void)
{
	int LPhold = 0;
	int Dehold = 0;
	int Athold = 0;
	int Sphold = 0;
	if (id == PlayChar::P_MAHO)
	{
		switch (skill)
		{
		case SKILL_ID::SKILL_1:
			if (skillFlag == true)
			{
				dmage = 7;
				maho.s1 = 0;
			}
			break;
		case SKILL_ID::SKILL_2:
			if (skillFlag == true)
			{
				speed = 6;
				maho.s2 = 0;
				skillFlag = false;
			}
			else if (skillFlag == false)
			{

				if (maho.s2 / 300)
				{
					speed = 0;
				}

			}
			break;
		case SKILL_ID::SKILL_3:
			if (skillFlag == true)
			{

				defense = 30;
				HP = 5;
				if (HP == 5)
				{
					LPhold = LP - HP;
					LP = LPhold;
				}
				
				maho.s3 = 0;
				skillFlag = false;
			}
			else if (skillFlag == false)
			{
				
				if (maho.s3 / 300)
				{
					defense = 0;
				}
				
			}
			break;
		case SKILL_ID::SKILL_4:
			if (skillFlag == true)
			{
				if (HP <= 50)
				{
					dmage = 40;
				}
				maho.s4 = 0;
			}
			break;
		case SKILL_ID::SKILL_MAX:
			break;
		default:
			break;
		}
		return true;
	}
}

bool P3skill(void)
{
	int LPhold = 0;
	int Dehold = 0;
	int Athold = 0;
	int Sphold = 0;
	if (id == PlayChar::P_BUTO)
	{
		switch (skill)
		{
		case SKILL_ID::SKILL_1:
			if (skillFlag == true)
			{
				dmage = 15;

			}
			
			break;
		case SKILL_ID::SKILL_2:
			if (skillFlag == true)
			{
				defense = 5;
				skillFlag = false;
				buto.s2 = 0;
			}
			else if (skillFlag == false)
			{

				if (buto.s2 / 180)
				{
					defense = 0;
				}
			}
			break;
		case SKILL_ID::SKILL_3:
			if (skillFlag == true)
			{
				attack = 10;
				buto.s3 = 0;
			}
			else if (skillFlag == false)
			{
				if (buto.s3 / 600)
				{
					attack = 0;
				}
			}
			break;
		case SKILL_ID::SKILL_4:
			if (skillFlag == true)
			{
				if (LP <= 30)
				{
					HP = 20;
					LPhold = LP + HP;
					LP = LPhold;
					speed = 5;
				}
				skillFlag = false;
				buto.s4 = 0;
			}
			else if (skillFlag == false)
			{
				if (buto.s4/300)
				{
					speed = 0;
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
}

bool P4skill(void)
{
	int LPhold = 0;
	int Dehold = 0;
	int Athold = 0;
	int Sphold = 0;
	if (id == PlayChar::P_NAZO)
	{
		switch (skill)
		{
		case SKILL_ID::SKILL_1:
			if (skillFlag == true)
			{
				dmage = 15;

			}
			break;
		case SKILL_ID::SKILL_2:
			if (skillFlag == true)
			{
				defense = 5;
				nazo.s2 = 0;
				skillFlag = false;
			}
			else if (skillFlag == false)
			{
				if (nazo.s2 / 300)
				{
					defense = 0;
					bufFlag = false;
				}
			}
			break;
		case SKILL_ID::SKILL_3:
			if (skillFlag == true)
			{
				dmage = 15;
				if (hitFlag == true)
				{
					HP = 20;
					LPhold = LP + HP;
					LP = LPhold;
				}
			}
			break;
		case SKILL_ID::SKILL_4:
			if (skillFlag == true)
			{
				if (LP <= 50)
				{
					dmage = 60;
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
}

XY PosToIndex(XY pos)
{
	XY index;
	index.x = pos.x / CHIP_SIZE_X;
	index.y = pos.y / CHIP_SIZE_Y;
	return index;
}

XY IndexToPos(XY index)
{
	XY pos;
	pos.x = index.x * CHIP_SIZE_X;
	pos.y = index.y * CHIP_SIZE_Y;
	return pos;
}

bool IsPass(XY pos)
{
	XY index;
	index = PosToIndex(pos);
	switch (mapyama[index.y][index.x])
	{
	case 1:
	case 20:
	case 21:
	case 22:
		return false;
		break;
	default:
		break;
	}
	switch (maphamaguri[index.y][index.x])
	{
	case 2:
	case 3:
	case 6:
		return false;
		break;
	default:
		break;
	}
	switch (mapmati[index.y][index.x])
	{
	case 0:
	case 8:
	case 22:
	case 23:
		return false;
		break;
	default:
		break;
	}
	switch (maptougi[index.y][index.x])
	{
	case 7:
		return false;
		break;
	default:
		break;
	}
	return true;
}

