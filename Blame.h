#pragma once
#include <string>
#include <vector>
using namespace std;

class Blame {
protected:
	//名称
	string name;
	//血量
	int hitPoint;
	//伤害
	int hurt;
	//增益状态
	vector<int>* buffer;
	//减益状态
	vector<int>* deBuffer;

public:
	//回合开始
	void RoundStart();
	//回合结束
	void RoundEnd();
	//攻击(伤害计算)
	void Attack();
	//被攻击
	void BeHurt(double Hurt);
	//1技能 
	void SkillOne();
	//2技能
	void SkillTwo();
	//3技能
	void SkillThree();

public:
	void SetName(string name) {
		this->name = name;
	}
	string GetName() {
		return this->name;
	}

	void SetHitPoint(int hitPoint) {
		this->hitPoint = hitPoint;
	}
	int GetHitPoint() {
		return this->hitPoint;
	}

	void SetHurt(int hurt) {
		this->hurt = hurt;
	}
	int GetHurt() {
		return this->hurt;
	}

	void SetName(string name) {
		this->name = name;
	}
	string GetName() {
		return this->name;
	}

	void SetName(string name) {
		this->name = name;
	}
	string GetName() {
		return this->name;
	}

	vector<int>* GetBuffer() {
		return this->buffer;
	}
	void SetBuffer(vector<int>* Buffer) {
		this->buffer = Buffer;
	}

	vector<int>* GetDeBuffer() {
		return this->deBuffer;
	}
	void SetDeBuffer(vector<int>* DeBuffer) {
		this->deBuffer = DeBuffer;
	}
};