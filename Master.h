#pragma once
#include "Role.h"
using namespace std;

class Master :public Role {
private:
	
public:
	//��ʼ��
	Master();
public:
	//��ɫ����
	string ToStringExhibition();
	//��ɫ����ʱ���ַ���
	string PreservationToString();
};