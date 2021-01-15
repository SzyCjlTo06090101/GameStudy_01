#include "Master.h"
#include "UuidUtils.h"
#include <string>
#include <iostream>
#include <vector>
using namespace std;

Master::Master() {
	this->OccupationId = 2;
	this->Id = Uuid::GetUUID();
	this->Grade = 1;
	this->HitPoint = 260;
	this->Hurt = 25;
	this->ActionPoints = 10;
	this->Experience = 0;
	this->ExperienceTotal = 100;
	this->Buffer = new vector<int>;
	this->DeBuffer = new vector<int>;
	this->layerl = 1;
}


string Master::ToStringExhibition() {
	string str;
	string sp;
	cout << "法师：每回合自动回血" << endl;
	cout << "被动：灵目-愈——每回合回复已损失血量10%" << endl;
	cout << "一技能：灵域-封——在一个回合后冰封所有敌人一回合使其无法攻击 造成基础伤害" << endl;
	cout << "二技能：灵焰-烬——召唤流星砸向所有敌人造成晕眩一回合 造成基础伤害" << endl;
	cout << "三技能：灵爆-茫——消耗当前生命值40%召唤大天使 之后大天使持续三个回合 " <<
		"并且每个回合随机使用火球 - 烧伤，冰球 - 冰冻，光球 - 失明 攻击单个敌人造成基础攻击的150 % 伤害" << endl;
	cout << "属性数值" << endl;
	cout << "等级：";
	cout << this->Grade << endl;
	cout << "生命值：";
	cout << this->HitPoint << endl;
	cout << "基础攻击：";
	cout << this->Hurt << endl;;
	return str;
}

string Master::PreservationToString() {
	string str = to_string(OccupationId) + ":" + Id + ":" + to_string(Grade) + ":" + RoleName + ":"
		+ to_string(HitPoint) + ":" + to_string(Hurt) + ":" + to_string(Experience) + ":" + to_string(layerl) + ";";
	return str;
}