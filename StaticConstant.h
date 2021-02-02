#pragma once
#include "Role.h"
#include "Skill.h"
#include <string>
#include <vector>
using namespace std;


class Constant {
public:
	/**************************存储路径***************************/
	static const string Path; //存储总路径
	static const string UserPath; //存储用户账号信息的路径
	static const string RolesPath; //存储角色信息路径


	/***************************等待显示**************************/
	static void LoDing();
	/***************************菜单展示**************************/
	static void LoginDisplay(); //登录界面
	static void RoleEstablishDisplay(); //角色创建界面
	static void RoleEstablishInformationDisplay(); //角色创建界面
	static void RoleChoiceDisplay(vector<map<string, string>> Rol); //角色选择界面

	/**************************角色初始化************************/
	static Role* RoleInitialization(int occupationId, string uuid, int grade, float ex, int layerl);

	/*战士技能初始化*/
	static vector<Skill*>* WarriorSkillInitialization(int grade, int hurt);


	/*************************保存角色信息字符串****************************/
	static string PreservationToString(Role* role);


	/**************************角色信息展示*********************************/
	static bool RoleExhibition(char OccupationId);
};
