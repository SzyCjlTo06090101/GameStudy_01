#pragma once
#include "Role.h"
using namespace std;

class Warrior :public Role {
private:
	//暴击率
	float CriticalHit;
public:
	//初始化
	Warrior();
public:
	float GetCriticalHit() {
		return this->CriticalHit;
	}
	void SetCriticalHit(float CriticalHit) {
		this->CriticalHit = CriticalHit;
	}

	//角色介绍
	string ToStringExhibition();
	//角色保存时的字符串
	string PreservationToString();
};