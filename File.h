#pragma once

class File {
public:
	//获取登陆文件登陆信息
	char GetLoginFile();
	//添加用户注册信息
	void InsertUserInformation();
	//创建新用户文件
	bool EstablishNewUserFile();

	//创建txt文档
	static bool EstablishTextFile(char FileName[]);
	//写入文档

	//读取文档
	char QueryTextFile();
private:
	//创建文件
	bool EstablishNewFile();
};
