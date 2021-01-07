#pragma once

class File {
public:
	//获取登陆文件登陆信息
	char GetLoginFile();
	//添加用户注册信息
	void InsertUserInformation();
	//创建新用户文件
	bool EstablishNewUserFile();

private:
	//创建文件
	bool EstablishNewFile();
};
