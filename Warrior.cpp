#include "Warrior.h"
#include "UuidUtils.h"
#include <string>
#include <iostream>
#include <vector>
using namespace std;

Warrior::Warrior() {
	this->OccupationId = 1;
	this->Id = Uuid::GetUUID();
	this->Grade = 1;
	this->HitPoint = 300;
	this->Hurt = 15;
	this->ActionPoints = 10;
	this->Experience = 0;
	this->ExperienceTotal = 100;
	this->Buffer = new vector<int>;
	this->DeBuffer = new vector<int>;
	this->CriticalHit = 0.1f;
	this->layerl = 1;
}


string Warrior::ToStringExhibition() {
	string str;
	string sp;
	cout << "战士：拥有独特的暴击概率" << endl;
	cout << "被动：圣甲——每次受到伤害暴击率增加10%,触发暴击后暴击率恢复初始值" << endl;
	cout << "一技能：战之意志——下回合首次攻击伤害增加三倍" << endl;
	cout << "二技能：屠魔光刃——造成120%点基础伤害" << endl;
	cout << "三技能：神圣裁决——造成300%点基础伤害 若怪物生命值低于15%造成处决" << endl;
	cout << "属性数值" << endl;
	cout << "等级：";
	cout << this->Grade << endl;
	cout << "生命值：";
	cout << this->HitPoint << endl;
	cout << "基础攻击：";
	cout << this->Hurt << endl;
	cout << "暴击概率：";
	cout << this->CriticalHit << endl;
	return str;
}

string Warrior::PreservationToString() {
	string str = to_string(OccupationId) + ":" + Id + ":" + to_string(Grade) + ":" + RoleName + ":" 
		+ to_string(HitPoint) + ":" + to_string(Hurt) + ":" + to_string(Experience) + ":" + to_string(CriticalHit) + ":" + to_string(layerl) + ";";
	return str;
}