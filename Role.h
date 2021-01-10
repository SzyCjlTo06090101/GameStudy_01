#pragma once
#include <string>
using namespace std;

class Role {
protected:
	//��ɫID
	string Id;
	//��ɫ����
	string RoleName;
	//��ɫ�ȼ�
	int Grade;
	//��ɫ����ֵ
	double HitPoint;
	//�����˺�
	int Hurt;
	//��ɫ�ж���
	int ActionPoints;
	//��ɫ����ֵ
	double Experience;
	//��ɫ�������辭��ֵ
	double ExperienceTotal;
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
};