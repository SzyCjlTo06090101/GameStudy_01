#pragma once
#include <string>
using namespace std;


class Constant {
public:
	/**************************存储路径***************************/
	static const string UserPath; //存储用户账号信息的路径
	static const string RolesPath; //存储角色信息路径


	/***************************等待显示**************************/
	static void LoDing();
	/***************************菜单展示**************************/
	static void LoginDisplay(); //登录界面
};
