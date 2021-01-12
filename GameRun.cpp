#include <iostream>
#include <string>
#include <Windows.h>
#include "StaticConstant.h"
#include "Login.h"
#include "DataStorage.h"
#include "RoleUtils.h"
using namespace std;

void GameStart();
void LoginStart(Login* lg);
void RoleChoice(string UserName);

//�߼�����
void GameStart() {
	try
	{
		/*У����Դ�ļ����Ƿ���� �������򴴽�*/
		string FilePath[] = {Constant::Path, Constant::UserPath, Constant::RolesPath};
		DataStorage::TestingCatalog(FilePath);

		/*1.�����¼����*/
		Login* lg = new Login();
		LoginStart(lg);

		//��¼�ɹ� �����ɫѡ�����
		RoleChoice(lg->UserName);

		cout << lg->UserName << endl;
		delete(lg);
	}
	catch (const std::exception&)
	{
		cout << "�����쳣" << endl;
		return;
	}
}

//��¼����
void LoginStart(Login* lg) {
	while (true)
	{
		Constant::LoginDisplay();
		char pt = getchar();
		switch (pt)
		{
		case '1'://��¼
			lg->AccountPasswordLogin();
			if (lg->UserName.empty()) 
			{
				cout << "�û����������" << endl;
				break;
			}
			else
			{
				cout << "��½�ɹ�" << endl;
				return;
			}
		case '2'://ע��
			lg->AccountPasswordRegister();
			break;
		case '0'://�˳�
			exit(0);
		default:
			cout << "ѡ�����������ѡ��" << endl;
		}
		getchar(); //��ֹ������͸
		Constant::LoDing();
		system("cls");
	}
}

//��Ϸ��ʼ����ɫѡ�����
void RoleChoice(string UserName) {
	//У���û��Ƿ��н�ɫ��Ϣ�洢�ļ� �������򴴽�
	string path = Constant::RolesPath + UserName;
	DataStorage::TestingStorageAndEstablish(path);
	//��ȡ�˺����н�ɫ��Ϣ
	string RoleString = DataStorage::GetFileData(path);
	//��ֻ�ý�ɫ��Ϣ
}

int main() {
	//��Ϸ��ʼ����
	//GameStart();

	vector<string>* str =  RoleUtils::StringSplit("qwe;ert;tyu;", ";");
	delete(str);
	
}