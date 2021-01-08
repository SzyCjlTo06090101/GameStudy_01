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


bool DataStorage::GetFileDataAndTesting(string FilePath, string str) {
	try
	{
		ifstream file;
		file.open(FilePath);
		while (file)
		{
			string content;
			file >> content;
			if (str == content) //���бȽ�����
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


