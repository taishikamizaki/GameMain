#pragma once
// 定数宣言


class Skill
{
private:
	//ﾒﾝﾊﾞ変数

	//skillイメージ格納
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
	//ﾒﾝﾊﾞ関数
	bool SkillGameInit(void);
	void SkillCtl(void);
	void	SkillDraw(void);

	void CreateSkill1(Pos	pos);
	void CreateSkill4(Pos	pos);
	
	void DeleteSkill1(int index);
	void DeleteSkill4(int index);




	Skill();
	~Skill();
};