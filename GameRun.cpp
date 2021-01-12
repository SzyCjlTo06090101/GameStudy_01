#include <iostream>
#include <string>
#include <Windows.h>
#include "StaticConstant.h"
#include "Login.h"
#include "DataStorage.h"
#include "RoleUtils.h"
using namespace std;

void GameStart();
void LoginStart(Login* lg);
void RoleChoice(string UserName);

//逻辑进程
void GameStart() {
	try
	{
		/*校验资源文件夹是否存在 不存在则创建*/
		string FilePath[] = {Constant::Path, Constant::UserPath, Constant::RolesPath};
		DataStorage::TestingCatalog(FilePath);

		/*1.进入登录进程*/
		Login* lg = new Login();
		LoginStart(lg);

		//登录成功 进入角色选择进程
		RoleChoice(lg->UserName);

		cout << lg->UserName << endl;
		delete(lg);
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
				return;
			}
		case '2'://注册
			lg->AccountPasswordRegister();
			break;
		case '0'://退出
			exit(0);
		default:
			cout << "选项错误请重新选择" << endl;
		}
		getchar(); //防止输入渗透
		Constant::LoDing();
		system("cls");
	}
}

//游戏开始、角色选择进程
void RoleChoice(string UserName) {
	//校验用户是否有角色信息存储文件 不存在则创建
	string path = Constant::RolesPath + UserName;
	DataStorage::TestingStorageAndEstablish(path);
	//获取账号所有角色信息
	string RoleString = DataStorage::GetFileData(path);
	//拆分获得角色信息
}

int main() {
	//游戏开始运行
	//GameStart();

	vector<string>* str =  RoleUtils::StringSplit("qwe;ert;tyu;", ";");
	delete(str);
	
}