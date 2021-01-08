#pragma once
#include <string>
#include "StaticConstant.h"
using namespace std;

class Login {
private:
	const string UserPath = ".\\Record\\User.txt";
public:
	Login();
	//账号密码登陆 登陆成功后返回用户名称
	bool AccountPasswordLogin();
	//账号密码注册
	bool AccountPasswordRegister();
private:
	string UsernameAndPasswordMerga();
public:
	string UserName;
};