#pragma once
using namespace std;


class File {
public:

	//创建txt文档
	static bool EstablishTextFile(string FileName);
	//读取文档
	static string QueryTextFile(string FIleName);
	//写入文档
	static void WriteInFile(string FIleName);


	//获取登陆文件登陆信息
	char GetLoginFile();
	//添加用户注册信息
	void InsertUserInformation();
	//创建新用户文件
	bool EstablishNewUserFile();


};
