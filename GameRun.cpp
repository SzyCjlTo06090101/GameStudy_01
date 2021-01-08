#include <iostream>
#include <string>
#include <Windows.h>
#include "StaticConstant.h"
#include "Login.h"
using namespace std;

void GameStart();
string LoginStart();

Login* lg = new Login();

//逻辑进程
void GameStart() {
	try
	{
		/*1.进入登录进程*/
		LoginStart();
	}
	catch (const std::exception&)
	{
		return;
	}
}

//登录进程
string LoginStart() {
	while (true)
	{
		Constant::LoginDisplay();
		char pt = getchar();
		switch (pt)
		{
		case '1'://登录
			lg->AccountPasswordLogin();
			if (lg->UserName.empty())
				cout << "用户或密码错误" << endl;
			else
				cout << "登陆成功" << endl;
			break;
		case '2'://注册
			lg->AccountPasswordRegister(); break;
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