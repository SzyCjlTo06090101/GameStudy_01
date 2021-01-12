#pragma once
#include <string>
#include <vector>
using namespace std;

class Role {
protected:
	//ְҵID  1.սʿ  2.��ʦ  3.��ʦ
	int OccupationId;
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
	//����״̬
	vector<int>* Buffer;
	//����״̬
	vector<int>* DeBuffer;
public:
	//�غϿ�ʼ
	void RoundStart();
	//�غϽ���
	void RoundEnd();
	//����
	void Attack(vector<Role> objs);
	//������
	void BeHurt(double Hurt);
	//1���� 
	void SkillOne();
	//2����
	void SkillTwo();
	//3����
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