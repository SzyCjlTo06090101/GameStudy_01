#pragma once
#include"Skill.h"
#include <string>
#include <vector>
#include <map>
using namespace std;

class Role {
protected:
	//ְҵID  1.սʿ  2.��ʦ  3.��ʦ
	int OccupationId;
	string OccupationStr;
	//��ɫID
	string Id;
	//��ɫ����
	string RoleName;
	//��ɫ�ȼ�
	int Grade;
	//��ɫ����ֵ
	int HitPoint;
	//�������ֵ
	int maxHitPoint;
	//�����˺�
	int Hurt;
	//��ɫ�����������ĵ���
	int ActionPoints;
	//��ɫ��ǰ����ֵ
	float Experience;
	//��ɫ�������辭��ֵ
	float ExperienceTotal;
	//����״̬ map<buffer״ֵ̬, ʣ��غ���>
	map<int, int>* Buffer = new map<int, int>;
	//����״̬
	map<int, int>* DeBuffer = new map<int, int>;
	//������ڲ���
	int layerl;
	//1���� 
	Skill* SkillOne;
	//2����
	Skill* SkillTwo;
	//3����
	Skill* SkillThree;

	/*****սʿ��������*****/
	//������
	int criticalHit;
	/*****��ʦ��������*****/
	/*****��ʦ��������*****/
public:
	//����
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
	//�غϿ�ʼ
	void RoundStart();
	//�غϽ���
	void RoundEnd();
	//����(�˺�����)
	void Attack();
	//������
	void BeHurt(int Hurt);

	//toString
	string ToString();

	//��ɫ��Ϣ
public:
	int GetOccupationId() {
		return this->OccupationId;
	}
	void SetOccupationId(int OccupationId) {
		switch (OccupationId)
		{
		case 1:this->OccupationStr = "սʿ"; break;
		case 2:this->OccupationStr = "��ʦ"; break;
		case 3:this->OccupationStr = "��ʦ"; break;
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