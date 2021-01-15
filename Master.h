#pragma once
#include "Role.h"
using namespace std;

class Master :public Role {
private:
	
public:
	//初始化
	Master();
public:
	//角色介绍
	string ToStringExhibition();
	//角色保存时的字符串
	string PreservationToString();
};