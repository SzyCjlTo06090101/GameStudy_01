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
		if (!fer) //�ļ���ʧ�� -���ļ�
		{
			ofstream fout(FilePath); //�½��ļ�
			if (fout) {
				fout.close();
			}
		}
		fer.close();
	}
	catch (const std::exception&)
	{
		cout << "�ļ�У�����" << endl;
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
		cout << "����ʧ��" << endl;
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
		cout << "��ѯ����ʧ��" << endl;
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
			if (Str == content) //���бȽ�����
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
		cout << "��ѯ����ʧ��" << endl;
		throw;
	}
}
/*
	FilePath �ļ�·��
	StaticSub ��Ҫ�ж��ļ�ÿ�����ݵĿ�ʼ�±�
	EndSub ��Ҫ�ж��ļ�ÿ�����ݵĽ����±�
	Str �Ƚϵ��ֶ�
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
			if (Str == content.substr(StaticSub, EndSub)) //���бȽ�����
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

