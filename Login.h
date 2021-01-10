#pragma once
#include <string>
#include "StaticConstant.h"
using namespace std;

class Login {
private:
	const string UserPath = Constant::UserPath;
public:
	Login();
	//ÕËºÅÃÜÂëµÇÂ½ µÇÂ½³É¹¦ºó·µ»ØÓÃ»§Ãû³Æ
	bool AccountPasswordLogin();
	//ÕËºÅÃÜÂë×¢²á
	bool AccountPasswordRegister();
private:
	string UsernameAndPasswordMerga();
public:
	string UserName;
};