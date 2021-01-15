#include "Warrior.h"
#include "UuidUtils.h"
#include <string>
#include <iostream>
#include <vector>
using namespace std;

Warrior::Warrior() {
	this->OccupationId = 1;
	this->Id = Uuid::GetUUID();
	this->Grade = 1;
	this->HitPoint = 300;
	this->Hurt = 15;
	this->ActionPoints = 10;
	this->Experience = 0;
	this->ExperienceTotal = 100;
	this->Buffer = new vector<int>;
	this->DeBuffer = new vector<int>;
	this->CriticalHit = 0.1f;
	this->layerl = 1;
}


string Warrior::ToStringExhibition() {
	string str;
	string sp;
	cout << "սʿ��ӵ�ж��صı�������" << endl;
	cout << "������ʥ�ס���ÿ���ܵ��˺�����������10%,���������󱩻��ʻָ���ʼֵ" << endl;
	cout << "һ���ܣ�ս֮��־�����»غ��״ι����˺���������" << endl;
	cout << "�����ܣ���ħ���С������120%������˺�" << endl;
	cout << "�����ܣ���ʥ�þ��������300%������˺� ����������ֵ����15%��ɴ���" << endl;
	cout << "������ֵ" << endl;
	cout << "�ȼ���";
	cout << this->Grade << endl;
	cout << "����ֵ��";
	cout << this->HitPoint << endl;
	cout << "����������";
	cout << this->Hurt << endl;
	cout << "�������ʣ�";
	cout << this->CriticalHit << endl;
	return str;
}

string Warrior::PreservationToString() {
	string str = to_string(OccupationId) + ":" + Id + ":" + to_string(Grade) + ":" + RoleName + ":" 
		+ to_string(HitPoint) + ":" + to_string(Hurt) + ":" + to_string(Experience) + ":" + to_string(CriticalHit) + ":" + to_string(layerl) + ";";
	return str;
}