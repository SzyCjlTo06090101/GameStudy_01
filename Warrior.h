#pragma once
#include "Role.h"
using namespace std;

class Warrior :public Role {
private:
	//±©»÷ÂÊ
	float CriticalHit;
public:
	//³õÊ¼»¯
	Warrior(string Name);

public:
	float GetCriticalHit() {
		return this->CriticalHit;
	}
	void SetCriticalHit(float CriticalHit) {
		this->CriticalHit = CriticalHit;
	}
};