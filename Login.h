#pragma once
#include <string>
#include "StaticConstant.h"
using namespace std;

class Login {
private:
	const string UserPath = Constant::UserPath;
public:
	Login();
	//�˺������½ ��½�ɹ��󷵻��û�����
	bool AccountPasswordLogin();
	//�˺�����ע��
	bool AccountPasswordRegister();
private:
	string UsernameAndPasswordMerga();
public:
	string UserName;
};