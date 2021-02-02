#pragma once
#include<string>
#include<vector>
using namespace std;

class Skill {
private:
	//技能名称
	string name;
	//技能描述
	string describe;
	//技能类型 1.实时伤害技能 2.buff技能 3.deBuff技能
	int type;
	//技能伤害 技能类型为：1.造成的实时伤害 2.增益值 3.对怪物的减益值
	int hurt;
	//造成的buff持续回合数
	int continuedCooling;
	//冷却回合数
	int cooling;
	//默认冷却回合数
	int maxCooling;
	//消耗行动点数
	int actionPoints;

public:
	string GetName() {
		return this->name;
	}
	void SetName(string name) {
		this->name = name;
	}

	string GetDescribe() {
		return this->describe;
	}
	void SetDescribe(string describe) {
		this->describe = describe;
	}

	int GetType() {
		return this->type;
	}
	void SetType(int type) {
		this->type = type;
	}

	int GetHurt() {
		return this->hurt;
	}
	void SetHurt(int hurt) {
		this->hurt = hurt;
	}

	int GetContinuedCooling() {
		return this->continuedCooling;
	}
	void SetContinuedCooling(int continuedCooling) {
		this->continuedCooling = continuedCooling;
	}

	int GetCooling() {
		return this->cooling;
	}
	void SetCooling(int cooling) {
		this->cooling = cooling;
	}

	int GetMaxCooling() {
		return this->maxCooling;
	}
	void SetMaxCooling(int maxCooling) {
		this->maxCooling = maxCooling;
	}
	
	int GetActionPoints() {
		return this->actionPoints;
	}
	void SetActionPoints(int actionPoints) {
		this->actionPoints = actionPoints;
	}
};