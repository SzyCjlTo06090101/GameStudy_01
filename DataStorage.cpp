#include "StaticConstant.h"
#include "DataStorage.h"
#include <string>
#include <fstream>
#include <iostream>
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

void DataStorage::TestingCatalog(string FilePath[]) {
	try
	{
		for (int i = 0; i < FilePath->length(); i++)
		{
			if (_access(FilePath[i].c_str(), 0) == -1)	//如果文件夹不存在
				_mkdir(FilePath[i].c_str());				//则创建
		}
	}
	catch (const std::exception&)
	{
		throw;
	}
}


