#include "Master.h"
#include "UuidUtils.h"
#include <string>
#include <iostream>
#include <vector>
using namespace std;

Master::Master() {
	this->OccupationId = 2;
	this->Id = Uuid::GetUUID();
	this->Grade = 1;
	this->HitPoint = 260;
	this->Hurt = 25;
	this->ActionPoints = 10;
	this->Experience = 0;
	this->ExperienceTotal = 100;
	this->Buffer = new vector<int>;
	this->DeBuffer = new vector<int>;
	this->layerl = 1;
}


string Master::ToStringExhibition() {
	string str;
	string sp;
	cout << "��ʦ��ÿ�غ��Զ���Ѫ" << endl;
	cout << "��������Ŀ-������ÿ�غϻظ�����ʧѪ��10%" << endl;
	cout << "һ���ܣ�����-�⡪����һ���غϺ�������е���һ�غ�ʹ���޷����� ��ɻ����˺�" << endl;
	cout << "�����ܣ�����-�������ٻ������������е��������ѣһ�غ� ��ɻ����˺�" << endl;
	cout << "�����ܣ��鱬-ã�������ĵ�ǰ����ֵ40%�ٻ�����ʹ ֮�����ʹ���������غ� " <<
		"����ÿ���غ����ʹ�û��� - ���ˣ����� - ���������� - ʧ�� ��������������ɻ���������150 % �˺�" << endl;
	cout << "������ֵ" << endl;
	cout << "�ȼ���";
	cout << this->Grade << endl;
	cout << "����ֵ��";
	cout << this->HitPoint << endl;
	cout << "����������";
	cout << this->Hurt << endl;;
	return str;
}

string Master::PreservationToString() {
	string str = to_string(OccupationId) + ":" + Id + ":" + to_string(Grade) + ":" + RoleName + ":"
		+ to_string(HitPoint) + ":" + to_string(Hurt) + ":" + to_string(Experience) + ":" + to_string(layerl) + ";";
	return str;
}