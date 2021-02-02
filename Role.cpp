#include "Role.h"
#include "UuidUtils.h"
#include "Skill.h"
#include "StaticConstant.h"
#include <string>
using namespace std;

string Role::ToString() {
	string str;
	str.append("角色名称:");
	str.append(this->RoleName);
	str.append(" 职业:");
	str.append(this->OccupationStr);
	str.append(" 等级:");
	str.append(to_string(this->Grade));
	str.append(" 层数:");
	str.append(to_string(this->layerl));
	return str;
}

//等级设置 --带属性处理
void Role::SetGrade(int Grade) {
	vector<Skill*>* skills = new vector<Skill*>;

	this->Grade = Grade;
	this->ExperienceTotal = (float)Grade * 100;
	/*战士属性*/
	if (this->OccupationId == 1)
	{
		//基础伤害
		this->Hurt = 15 * ((Grade - 1) * 5);
		//最大血量
		this->maxHitPoint = 300 * ((Grade - 1) * 40);
		//正常攻击消耗行动点数
		this->ActionPoints = 2;
		//暴击率
		int craitical = Grade * 2;
		if (craitical > 80)
		{
			craitical = 80;
		}
		this->criticalHit = craitical;
		//技能
		skills = Constant::WarriorSkillInitialization(Grade, this->Hurt);
	}

	if (!skills->empty())
	{
		this->SkillOne = (*skills)[0];
		this->SkillTwo = (*skills)[1];
		this->SkillThree = (*skills)[2];
		delete(skills);
		skills = NULL;
	}
}

