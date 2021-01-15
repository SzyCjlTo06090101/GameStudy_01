#pragma once
#include <string>
#include <vector>
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
	//������ڲ���
	int layerl;
public:
	//�غϿ�ʼ
	void RoundStart();
	//�غϽ���
	void RoundEnd();
	//����(�˺�����)
	void Attack();
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
	void SetGrade(int Grade) {
		this->Grade = Grade;
		this->ExperienceTotal = Grade * 10;
	}

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
	
	int GetLayerl() {
		return this->layerl;
	}
	void SetLayerl(int layerl) {
		this->layerl = layerl;
	}

};