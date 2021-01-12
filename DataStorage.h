#pragma once
#include <string>
using namespace std;

class DataStorage {
public:
	//����ļ��Ƿ���� �������򴴽��ļ�
	static bool TestingStorageAndEstablish(string FilePath);
	//���ļ��д洢�û���Ϣ
	static void InsertUserInformation(string FilePath, string Str);
	//��ѯ�ļ�����
	static string GetFileData(string FilePath);
	//��ѯ�ļ����ݲ�У���ַ����Ƿ����
	static bool GetFileDataAndTesting(string FilePath, string Str);
	//����У���ļ��ƶ�����
	static bool CheckPerLineContent(string FilePath, int StaticSub, int EndSub, string Str);
	//У��ָ��Ŀ¼�Ƿ����
	static void TestingCatalog(string FilePath[]);
	

};