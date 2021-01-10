#include <iostream>
#include <string>
#include <Windows.h>
#include "StaticConstant.h"
#include "Login.h"
using namespace std;

void GameStart();
void LoginStart(Login* lg);

//逻辑进程
void GameStart() {
	try
	{
		Login* lg = new Login();
		/*1.进入登录进程*/
		LoginStart(lg);
		//判断是否登录成功
		if (lg->UserName.empty())
			cout << "登录错误" << endl;
		//登录成功 进入角色选择进程

		cout << lg->UserName << endl;
		delete(lg);
	}
	catch (const std::exception&)
	{
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

int main() {
	//游戏开始运行
	GameStart();
}