#include <iostream>
#include <string>
#include <Windows.h>
#include <vector>
#include "StaticConstant.h"
#include "Login.h"
#include "DataStorage.h"
#include "Warrior.h"
#include "RoleUtils.h"
using namespace std;

void GameStart();
void LoginStart(Login* lg);
void RoleChoice(string UserName);
void RoleEstablish(string path);

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
			RoleChoice(lg->UserName);
			delete(lg);
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
void RoleChoice(string UserName) {
	//校验用户是否有角色信息存储文件 不存在则创建
	string path = Constant::RolesPath + UserName + ".txt";
	DataStorage::TestingStorageAndEstablish(path);
	while (true)
	{
		//获取账号所有角色信息
		string RoleString = DataStorage::GetFileData(path);
		//拆分获得角色信息
		vector<Role>* Roles = RoleUtils::StringSplitRole(RoleUtils::StringSplit(RoleString, ";"));

		Constant::RoleChoiceDisplay(Roles);
		char pt = getchar();
		rewind(stdin); //清理缓冲区
		if (pt == '0') //后退菜单
		{
			return;
		}
		else if (pt == 'x') //新建角色
		{
			system("cls");
			RoleEstablish(path);
		}
		else //选择角色
		{

		}
		Constant::LoDing();
		system("cls");
		delete(Roles);
		Roles = NULL;
	}
}

//创建角色进程
void RoleEstablish(string path) {
	while (true)
	{
		Constant::RoleEstablishDisplay();
		char pt = getchar();
		rewind(stdin); //清理缓冲区
		switch (pt)
		{
		case '1': 
		{
			system("cls");
			Warrior* war = new Warrior();
			war->ToStringExhibition();
			Constant::RoleEstablishInformationDisplay();
			pt = getchar(); getchar(); //防止输入渗透
			if (pt == 'y')
			{
				cout << "请输入角色名称:";
				string name;
				cin >> name;
				war->SetRoleName(name);
				DataStorage::RolePreservation(path, war->PreservationToString(), war->GetId());
			}
			delete(war);
			war = NULL;
			return;
		}
		case '2':
			cout << "法师未规划" << endl;
			break;
		case '3':
			cout << "牧师未规划" << endl;
			break;
		case '0'://后退
			return;
		default:
			cout << "选项错误请重新选择" << endl;
		}
		Constant::LoDing();
		system("cls");
	}
}

int main() {
	//游戏开始运行
	GameStart();
	
}