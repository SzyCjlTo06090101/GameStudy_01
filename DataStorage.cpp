#include "StaticConstant.h"
#include "DataStorage.h"
#include <string>
#include <fstream>
#include <iostream>
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


void DataStorage::InsertUserInformation(string FilePath, string str) {
	try
	{
		ofstream file;
		file.open(FilePath, ios::app);
		file << str;
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


bool DataStorage::GetFileDataAndTesting(string FilePath, string str) {
	try
	{
		ifstream file;
		file.open(FilePath);
		while (file)
		{
			string content;
			file >> content;
			if (str == content) //逐行比较内容
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


