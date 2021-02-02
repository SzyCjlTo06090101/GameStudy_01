//进程
#include <iostream>
#include <string>
#include <Windows.h>
#include <vector>
#include "StaticConstant.h"
#include "Login.h"
#include "DataStorage.h"
#include "RoleUtils.h"
#include "BlameUtils.h"
using namespace std;

void GameStart();
void LoginStart(Login* lg);
string RoleChoice(string UserName);
void RoleEstablish(string path);
void Roleinitialization(string userName, string roleId);

//逻辑进程
void GameStart() {
	try
	{
		/*校验资源文件夹是否存在 不存在则创建*/
		vector<string>* FilePaths = new vector<string>;
		FilePaths->push_back(Constant::Path);
		FilePaths->push_back(Constant::RolesPath);
		DataStorage::TestingCatalog(FilePaths);
		while (true)
		{
			/*1.进入登录进程*/
			Login* lg = new Login();
			LoginStart(lg);

			//登录成功 进入角色选择进程
			string roleId = RoleChoice(lg->UserName);

			//角色id不为空时进入游戏 否则推出
			if (!roleId.empty())
			{
				//角色初始化
				Role* role = RoleUtils::StringSplitRoleInitialization(RoleUtils::StringSplit(DataStorage::GetFileData(Constant::RolesPath + lg->UserName + ".txt"), ";"), roleId);;
				cout << role->ToString() << endl;
				//战斗进程

				delete(role);
				role = NULL;
			}
			delete(lg);
			lg = NULL;
		}
	}
	catch (const std::exception&)
	{
		cout << "进程异常" << endl;
		return;
	}
}

//登录进程
void LoginStart(Login* lg) {
	while (true)
	{
		Constant::LoginDisplay();
		char pt = getchar();
		rewind(stdin); //清理缓冲区
		system("cls");
		switch (pt)
		{
		case '1'://登录
			lg->AccountPasswordLogin();
			if (lg->UserName.empty())
			{
				cout << "用户或密码错误" << endl;
				break;
			}
			else
			{
				cout << "登陆成功" << endl;
				Constant::LoDing();
				system("cls");
				return;
			}
		case '2'://注册
			lg->AccountPasswordRegister();
			system("cls");
			break;
		case '0'://退出
			exit(0);
		default:
			cout << "选项错误请重新选择" << endl;
		}
		Constant::LoDing();
		system("cls");
	}
}

//游戏开始、角色选择进程
string RoleChoice(string UserName) {
	//校验用户是否有角色信息存储文件 不存在则创建
	string path = Constant::RolesPath + UserName + ".txt";
	DataStorage::TestingStorageAndEstablish(path);
	while (true)
	{
		//获取账号所有角色信息
		string RoleString = DataStorage::GetFileData(path);
		//拆分获得角色信息
		vector<map<string, string>> roles = RoleUtils::StringSplitRole(RoleUtils::StringSplit(RoleString, ";"));

		Constant::RoleChoiceDisplay(roles);
		char pt = getchar();
		rewind(stdin); //清理缓冲区
		system("cls");
		if (pt == '0') //后退菜单
		{
			return "";
		}
		else if (pt == 'x') //新建角色
		{
			RoleEstablish(path);
		}
		else //选择角色
		{
			//返回角色id
			return (roles)[atoi(&pt) - 1]["id"];
		}
		Constant::LoDing();
		system("cls");
	}
	return "";
}

//创建角色进程
void RoleEstablish(string path) {
	while (true)
	{
		Constant::RoleEstablishDisplay();
		char pt = getchar();
		rewind(stdin); //清理缓冲区
		bool b = Constant::RoleExhibition(pt);
		if (b)
		{
			cout << "是否确认创建(y/n):";
			char ct = getchar();
			rewind(stdin); //清理缓冲区
			if (ct == 'y')
			{
				Role* role = Constant::RoleInitialization(atoi(&pt), "", 1, 0, 1);
				cout << "请输入角色名称：";
				string name;
				cin >> name;
				rewind(stdin); //清理缓冲区
				role->SetRoleName(name);
				//保存
				DataStorage::RolePreservation(path, Constant::PreservationToString(role), role->GetId());
				return;
			}
		}
		Constant::LoDing();
		system("cls");
	}
}


//角色初始化进程 进入各角色的战斗进程
void Roleinitialization(string userName, string roleId) {
	
}
