#pragma once
// ’è”éŒ¾


//½·Ù‚Ì¸×½
class Skill
{
private:
	//ÒİÊŞ•Ï”

	//skillƒCƒ[ƒWŠi”[
	int	skillimage1;
	int	skillimage2;
	int	skillimage3;
	int	skillimage4;
	int	skillimage5;
	int	skillimage6;
	int	skillimage7;
	int	skillimage8;
	int	skillimage9;
	int	skillimage10;
	int	skillimage11;
	int	skillimage12;
	int	skillimage13;
	int	skillimage14;
	int	skillimage15;
	int	skillimage16;


public:
	//ÒİÊŞŠÖ”
	bool SkillGameInit(void);
	void SkillCtl(void);
	void	SkillDraw(void);

	void CreateSkill1(Pos	pos);
	void CreateSkill4(Pos	pos);
	
	void DeleteSkill1(int index);
	void DeleteSkill4(int index);

	Pos   GetPos1(int index);
	Pos   GetPos2(int index);

	bool SkillFlag1(int index);
	bool SkillFlag2(int index);
	bool SkillFlag3(int index);
	bool SkillFlag4(int index);
	bool SkillFlag5(int index);
	bool SkillFlag6(int index);
	bool SkillFlag7(int index);
	bool SkillFlag8(int index);
	bool SkillFlag9(int index);
	bool SkillFlag10(int index);
	bool SkillFlag11(int index);
	bool SkillFlag12(int index);
	bool SkillFlag13(int index);
	bool SkillFlag14(int index);
	bool SkillFlag15(int index);
	bool SkillFlag16(int index);


	Skill();
	~Skill();
};