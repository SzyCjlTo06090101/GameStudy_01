#pragma once
#include <string>
#include <vector>
using namespace std;

class Role {
protected:
	//职业ID  1.战士  2.法师  3.牧师
	int OccupationId;
	//角色ID
	string Id;
	//角色名称
	string RoleName;
	//角色等级
	int Grade;
	//角色生命值
	double HitPoint;
	//基础伤害
	int Hurt;
	//角色行动点
	int ActionPoints;
	//角色经验值
	double Experience;
	//角色升级所需经验值
	double ExperienceTotal;
	//增益状态
	vector<int>* Buffer;
	//减益状态
	vector<int>* DeBuffer;
public:
	//回合开始
	void RoundStart();
	//回合结束
	void RoundEnd();
	//攻击
	void Attack(vector<Role> objs);
	//被攻击
	void BeHurt(double Hurt);
	//1技能 
	void SkillOne();
	//2技能
	void SkillTwo();
	//3技能
	void SkillThree();

	//toString
	string ToString();
public:
	string GetId() {
		return this->Id;
	}
	void SetId(string Id) {
		this->Id = Id;
	}

	string GetRoleName() {
		return this->RoleName;
	}
	void SetRoleName(string RoleName) {
		this->RoleName = RoleName;
	}

	int GetGrade() {
		return this->Grade;
	}
	void SetGrade(int Grade) {
		this->Grade = Grade;
	}

	double GetHitPoint() {
		return this->HitPoint;
	}
	void SetHitPoint(double HitPoint) {
		this->HitPoint = HitPoint;
	}
	
	int GetHurt() {
		return this->Hurt;
	}
	void SetHurt(int Hurt) {
		this->Hurt = Hurt;
	}

	int GetActionPoints() {
		return this->ActionPoints;
	}
	void SetActionPoints(int ActionPoints) {
		this->ActionPoints = ActionPoints;
	}

	double GetExperience() {
		return this->Experience;
	}
	void SetExperience(double Experience) {
		this->Experience = Experience;
	}

	double GetExperienceTotal() {
		return this->ExperienceTotal;
	}
	void SetExperienceTotal(double ExperienceTotal) {
		this->ExperienceTotal = ExperienceTotal;
	}

	vector<int>* GetBuffer() {
		return this->Buffer;
	}
	void SetBuffer(vector<int>* Buffer) {
		this->Buffer = Buffer;
	}

	vector<int>* GetDeBuffer() {
		return this->DeBuffer;
	}
	void SetDeBuffer(vector<int>* DeBuffer) {
		this->DeBuffer = DeBuffer;
	}
};