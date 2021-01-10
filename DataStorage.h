#pragma once
#include <string>
using namespace std;

class DataStorage {
public:
	//检测文件是否存在 不存在则创建文件
	static bool TestingStorageAndEstablish(string FilePath);
	//向文件中存储用户信息
	static void InsertUserInformation(string FilePath, string Str);
	//查询文件数据
	static string GetFileData(string FilePath);
	//查询文件数据并校验字符串是否存在
	static bool GetFileDataAndTesting(string FilePath, string Str);
	//逐行校验文件制定内容
	static bool CheckPerLineContent(string FilePath, int StaticSub, int EndSub, string Str);
	

};