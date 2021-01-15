#include "Minister.h"
#include "UuidUtils.h"
#include <string>
#include <iostream>
#include <vector>
using namespace std;

Minister::Minister() {
	this->OccupationId = 3;
	this->Id = Uuid::GetUUID();
	this->Grade = 1;
	this->HitPoint = 400;
	this->Hurt = 27;
	this->ActionPoints = 10;
	this->Experience = 0;
	this->ExperienceTotal = 100;
	this->Buffer = new vector<int>;
	this->DeBuffer = new vector<int>;
	this->layerl = 1;
}


string Minister::ToStringExhibition() {
	string str;
	string sp;
	cout << "��ʦ�����߳����˺�" << endl;
	cout << "��������ͩ�ơ������߳����˺�" << endl;
	cout << "һ���ܣ������������ظ�����ʧ����ֵ��20%�������غ�" << endl;
	cout << "�����ܣ�ȼ���������Եз��������������ɻ����˺� ��������ɻ����˺���70%�������˺����غ�" << endl;
	cout << "�����ܣ������������Ƕ��ֽ���˯��״̬�������غ�" << endl;
	cout << "������ֵ" << endl;
	cout << "�ȼ���";
	cout << this->Grade << endl;
	cout << "����ֵ��";
	cout << this->HitPoint << endl;
	cout << "����������";
	cout << this->Hurt << endl;;
	return str;
}

string Minister::PreservationToString() {
	string str = to_string(OccupationId) + ":" + Id + ":" + to_string(Grade) + ":" + RoleName + ":"
		+ to_string(HitPoint) + ":" + to_string(Hurt) + ":" + to_string(Experience) + ":" + to_string(layerl) + ";";
	return str;
}