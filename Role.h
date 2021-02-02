#pragma once
#include"Skill.h"
#include <string>
#include <vector>
#include <map>
using namespace std;

class Role {
protected:
	//职业ID  1.战士  2.法师  3.牧师
	int OccupationId;
	string OccupationStr;
	//角色ID
	string Id;
	//角色名称
	string RoleName;
	//角色等级
	int Grade;
	//角色生命值
	int HitPoint;
	//最大生命值
	int maxHitPoint;
	//基础伤害
	int Hurt;
	//角色正常攻击消耗点数
	int ActionPoints;
	//角色当前经验值
	float Experience;
	//角色升级所需经验值
	float ExperienceTotal;
	//增益状态 map<buffer状态值, 剩余回合数>
	map<int, int>* Buffer = new map<int, int>;
	//减益状态
	map<int, int>* DeBuffer = new map<int, int>;
	//玩家所在层数
	int layerl;
	//1技能 
	Skill* SkillOne;
	//2技能
	Skill* SkillTwo;
	//3技能
	Skill* SkillThree;

	/*****战士特有属性*****/
	//暴击率
	int criticalHit;
	/*****法师特有属性*****/
	/*****牧师特有属性*****/
public:
	//销毁
	~Role() {
		delete(Buffer);
		Buffer = NULL;
		delete(DeBuffer);
		DeBuffer = NULL;
		delete(SkillOne);
		SkillOne = NULL;
		delete(SkillTwo);
		SkillTwo = NULL;
		delete(SkillThree);
		SkillThree = NULL;
	}
	//回合开始
	void RoundStart();
	//回合结束
	void RoundEnd();
	//攻击(伤害计算)
	void Attack();
	//被攻击
	void BeHurt(int Hurt);

	//toString
	string ToString();

	//角色信息
public:
	int GetOccupationId() {
		return this->OccupationId;
	}
	void SetOccupationId(int OccupationId) {
		switch (OccupationId)
		{
		case 1:this->OccupationStr = "战士"; break;
		case 2:this->OccupationStr = "法师"; break;
		case 3:this->OccupationStr = "牧师"; break;
		default:break;
		}
		this->OccupationId = OccupationId;
	}

	string GetOccupationStr() {
		return this->OccupationStr;
	}
	void SetOccupationId(string OccupationStr) {
		this->OccupationStr = OccupationStr;
	}

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
	void SetGrade(int Grade);

	int GetHitPoint() {
		return this->HitPoint;
	}
	void SetHitPoint(int HitPoint) {
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

	float GetExperience() {
		return this->Experience;
	}
	void SetExperience(float Experience) {
		this->Experience = Experience;
	}

	float GetExperienceTotal() {
		return this->ExperienceTotal;
	}
	void SetExperienceTotal(float ExperienceTotal) {
		this->ExperienceTotal = ExperienceTotal;
	}

	map<int, int>* GetBuffer() {
		return this->Buffer;
	}
	void SetBuffer(map<int, int>* Buffer) {
		this->Buffer = Buffer;
	}

	map<int, int>* GetDeBuffer() {
		return this->DeBuffer;
	}
	void SetDeBuffer(map<int, int>* DeBuffer) {
		this->DeBuffer = DeBuffer;
	}
	
	int GetLayerl() {
		return this->layerl;
	}
	void SetLayerl(int layerl) {
		this->layerl = layerl;
	}

	int GetCriticalHit() {
		return this->criticalHit;
	}
	void SetCriticalHit(int criticalHit) {
		this->criticalHit = criticalHit;
	}

	Skill* GetSkillOne() {
		return this->SkillOne;
	}
	void SetSkillOne(Skill* SkillOne) {
		this->SkillOne = SkillOne;
	}

	Skill* GetSkillTwo() {
		return this->SkillTwo;
	}
	void SetSkillTwo(Skill* SkillTwo) {
		this->SkillTwo = SkillTwo;
	}

	Skill* GetSkillThree() {
		return this->SkillThree;
	}
	void SetSkillThree(Skill* SkillThree) {
		this->SkillThree = SkillThree;
	}

};