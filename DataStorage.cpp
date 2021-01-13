#include "StaticConstant.h"
#include "DataStorage.h"
#include <string>
#include <fstream>
#include <iostream>
#include <vector>
#include <direct.h>
#include <io.h>
using namespace std;

bool DataStorage::TestingStorageAndEstablish(string FilePath) {
	try
	{
		fstream fer;
		fer.open(FilePath, ios::in);
		if (!fer) //文件打开失败 -无文件
		{
			ofstream fout(FilePath); //新建文件
			if (fout) {
				fout.close();
			}
		}
		fer.close();
	}
	catch (const std::exception&)
	{
		cout << "文件校验出错" << endl;
		throw;
	}
	return true;
}


void DataStorage::InsertUserInformation(string FilePath, string Str) {
	try
	{
		ofstream file;
		file.open(FilePath, ios::app);
		file << Str;
		file.close();
	}
	catch (const std::exception&)
	{
		cout << "保存失败" << endl;
		throw;
	}
}

string DataStorage::GetFileData(string FilePath) {
	try
	{
		string str;
		ifstream file;
		file.open(FilePath);
		while (file)
		{
			string content;
			file >> content;
			str += content;
		}
		return str;
	}
	catch (const std::exception&)
	{
		cout << "查询数据失败" << endl;
		throw;
	}
}


bool DataStorage::GetFileDataAndTesting(string FilePath, string Str) {
	try
	{
		ifstream file;
		file.open(FilePath);
		while (file)
		{
			string content;
			file >> content;
			if (Str == content) //逐行比较内容
			{
				file.close();
				return true;
			}
		}
		file.close();
		return false;
	}
	catch (const std::exception&)
	{
		cout << "查询数据失败" << endl;
		throw;
	}
}
/*
	FilePath 文件路径
	StaticSub 需要判断文件每行内容的开始下标
	EndSub 需要判断文件每行内容的结束下标
	Str 比较的字段
*/
bool DataStorage::CheckPerLineContent(string FilePath, int StaticSub, int EndSub, string Str) {
	try
	{
		ifstream file;
		file.open(FilePath);
		while (file)
		{
			string content;
			file >> content;
			if (Str == content.substr(StaticSub, EndSub)) //逐行比较内容
			{
				file.close();
				return true;
			}
		}
		file.close();
		return false;
	}
	catch (const std::exception&)
	{
		throw;
	}

}

void DataStorage::TestingCatalog(vector<string>* FilePath) {
	try
	{
		for (string Path : *FilePath)
		{
			if (_access(Path.c_str(), 0) == -1)	//如果文件夹不存在
				_mkdir(Path.c_str()); //则创建
		}
	}
	catch (const std::exception&)
	{
		throw;
	}
}

//先读出保存文件所有内容 然后比较每一行内容  根据id找到需要覆盖的信息 替换成要保存得内容 然后全部保存回文件
//如果没有一行相同 则最后新增一条数据
void DataStorage::RolePreservation(string path, string content, string roleId) {
	try
	{
		vector<string>* ver = new vector<string>;
		bool b = true;
		//打开文件获取内容
		ifstream file;
		file.open(path);
		while (file)
		{
			string tContent;
			file >> tContent;
			if (tContent.empty())
				continue;
			if (tContent.find(roleId) == tContent.npos) //字符串中查询不到子字符串地址时返回npos值
			{
				ver->push_back(tContent);
			}
			else
			{
				ver->push_back(content);
				b = false;
			}
		}
		file.close();

		if (b) //b为true 说明这是一条新建的数据 追加到最后
		{
			ver->push_back(content);
		}

		//重新写入文件
		ofstream ofr;
		ofr.open(path, ios::trunc);
		for (string v : *ver) {
			ofr << v << endl;
		}
		ofr.close();
		delete(ver);
		ver = NULL;
	}
	catch (const std::exception&)
	{
		cout << "保存失败" << endl;
		throw;
	}
}


