#include "Minister.h"
#include "UuidUtils.h"
#include <string>
#include <iostream>
#include <vector>
using namespace std;

Minister::Minister() {
	this->OccupationId = 3;
	this->Id = Uuid::GetUUID();
	this->Grade = 1;
	this->HitPoint = 400;
	this->Hurt = 27;
	this->ActionPoints = 10;
	this->Experience = 0;
	this->ExperienceTotal = 100;
	this->Buffer = new vector<int>;
	this->DeBuffer = new vector<int>;
	this->layerl = 1;
}


string Minister::ToStringExhibition() {
	string str;
	string sp;
	cout << "法师：免疫持续伤害" << endl;
	cout << "被动：梧桐灯——免疫持续伤害" << endl;
	cout << "一技能：治愈术——回复已损失生命值的20%持续二回合" << endl;
	cout << "二技能：燃烧术——对敌方最多三个敌人造成基础伤害 并持续造成基础伤害的70%的烧伤伤害三回合" << endl;
	cout << "三技能：催眠术——是对手进入睡眠状态持续两回合" << endl;
	cout << "属性数值" << endl;
	cout << "等级：";
	cout << this->Grade << endl;
	cout << "生命值：";
	cout << this->HitPoint << endl;
	cout << "基础攻击：";
	cout << this->Hurt << endl;;
	return str;
}

string Minister::PreservationToString() {
	string str = to_string(OccupationId) + ":" + Id + ":" + to_string(Grade) + ":" + RoleName + ":"
		+ to_string(HitPoint) + ":" + to_string(Hurt) + ":" + to_string(Experience) + ":" + to_string(layerl) + ";";
	return str;
}