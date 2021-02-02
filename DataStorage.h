#pragma once
#include <string>
#include <vector>
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
	//逐行校验文件指定内容
	static bool CheckPerLineContent(string FilePath, int StaticSub, int EndSub, string Str);
	//校验指定目录是否存在
	static void TestingCatalog(vector<string>* FilePath);
	//用户角色存档保存
	static void RolePreservation(string path, string content, string roleId);
	

};