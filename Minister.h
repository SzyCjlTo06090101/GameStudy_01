#pragma once
#include "Role.h"
using namespace std;

class Minister :public Role {
private:

public:
	//��ʼ��
	Minister();
public:
	//��ɫ����
	string ToStringExhibition();
	//��ɫ����ʱ���ַ���
	string PreservationToString();
};