#pragma once
#include "Role.h"
using namespace std;

class Warrior :public Role {
private:
	//������
	float CriticalHit;
public:
	//��ʼ��
	Warrior();
public:
	float GetCriticalHit() {
		return this->CriticalHit;
	}
	void SetCriticalHit(float CriticalHit) {
		this->CriticalHit = CriticalHit;
	}

	//��ɫ����
	string ToStringExhibition();
	//��ɫ����ʱ���ַ���
	string PreservationToString();
};