#include <iostream>
#include <string>
#include "Login.h"
#include "DataStorage.h"
using namespace std;

Login::Login() {
	//检查是否存在用户信息存储文件 不存在则新建
	DataStorage::TestingStorageAndEstablish(this->UserPath);
}

//账号密码登陆
bool Login::AccountPasswordLogin() {
	try
	{
		string User = this->UsernameAndPasswordMerga();
		if (DataStorage::GetFileDataAndTesting(this->UserPath, User)) {
			this->UserName = User.substr(0, User.find_last_of(":"));
			return true;
		}
		else
		{
			this->UserName = "";
			return false;
		}
		
	}
	catch (const std::exception&)
	{
		cout << "登录异常" << endl;
		throw;
	}
	
}


//账号密码注册
bool Login::AccountPasswordRegister() {
	try
	{
		string User = this->UsernameAndPasswordMerga() + "\n";
		//校验用户是否已经存在,(用户名重复时 长度相同)
		if (DataStorage::CheckPerLineContent(this->UserPath, 0, User.find_last_of(":"), User.substr(0, User.find_last_of(":")))) {
			cout << "注册失败,用户已存在" << endl;
			return false;
		}
		DataStorage::InsertUserInformation(this->UserPath, User);
		cout << "注册成功" << endl;
		return true;
	}
	catch (const std::exception&)
	{
		cout << "注册异常" << endl;
		throw;
	}
}

string Login::UsernameAndPasswordMerga() {
	string UserName;
	string PassWord;
	cout << "--------------------------------" << endl;
	cout << "请输入用户名名称:";
	cin >> UserName;
	cout << endl << "请输入密码:";
	cin >> PassWord;
	cout << endl;
	//组装信息并校验
	string User = UserName + ":" + PassWord;
	return User;
}