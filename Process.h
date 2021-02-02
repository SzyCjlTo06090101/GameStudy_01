//����
#include <iostream>
#include <string>
#include <Windows.h>
#include <vector>
#include "StaticConstant.h"
#include "Login.h"
#include "DataStorage.h"
#include "RoleUtils.h"
#include "BlameUtils.h"
using namespace std;

void GameStart();
void LoginStart(Login* lg);
string RoleChoice(string UserName);
void RoleEstablish(string path);
void Roleinitialization(string userName, string roleId);

//�߼�����
void GameStart() {
	try
	{
		/*У����Դ�ļ����Ƿ���� �������򴴽�*/
		vector<string>* FilePaths = new vector<string>;
		FilePaths->push_back(Constant::Path);
		FilePaths->push_back(Constant::RolesPath);
		DataStorage::TestingCatalog(FilePaths);
		while (true)
		{
			/*1.�����¼����*/
			Login* lg = new Login();
			LoginStart(lg);

			//��¼�ɹ� �����ɫѡ�����
			string roleId = RoleChoice(lg->UserName);

			//��ɫid��Ϊ��ʱ������Ϸ �����Ƴ�
			if (!roleId.empty())
			{
				//��ɫ��ʼ��
				Role* role = RoleUtils::StringSplitRoleInitialization(RoleUtils::StringSplit(DataStorage::GetFileData(Constant::RolesPath + lg->UserName + ".txt"), ";"), roleId);;
				cout << role->ToString() << endl;
				//ս������

				delete(role);
				role = NULL;
			}
			delete(lg);
			lg = NULL;
		}
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
		rewind(stdin); //��������
		system("cls");
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
				Constant::LoDing();
				system("cls");
				return;
			}
		case '2'://ע��
			lg->AccountPasswordRegister();
			system("cls");
			break;
		case '0'://�˳�
			exit(0);
		default:
			cout << "ѡ�����������ѡ��" << endl;
		}
		Constant::LoDing();
		system("cls");
	}
}

//��Ϸ��ʼ����ɫѡ�����
string RoleChoice(string UserName) {
	//У���û��Ƿ��н�ɫ��Ϣ�洢�ļ� �������򴴽�
	string path = Constant::RolesPath + UserName + ".txt";
	DataStorage::TestingStorageAndEstablish(path);
	while (true)
	{
		//��ȡ�˺����н�ɫ��Ϣ
		string RoleString = DataStorage::GetFileData(path);
		//��ֻ�ý�ɫ��Ϣ
		vector<map<string, string>> roles = RoleUtils::StringSplitRole(RoleUtils::StringSplit(RoleString, ";"));

		Constant::RoleChoiceDisplay(roles);
		char pt = getchar();
		rewind(stdin); //��������
		system("cls");
		if (pt == '0') //���˲˵�
		{
			return "";
		}
		else if (pt == 'x') //�½���ɫ
		{
			RoleEstablish(path);
		}
		else //ѡ���ɫ
		{
			//���ؽ�ɫid
			return (roles)[atoi(&pt) - 1]["id"];
		}
		Constant::LoDing();
		system("cls");
	}
	return "";
}

//������ɫ����
void RoleEstablish(string path) {
	while (true)
	{
		Constant::RoleEstablishDisplay();
		char pt = getchar();
		rewind(stdin); //��������
		bool b = Constant::RoleExhibition(pt);
		if (b)
		{
			cout << "�Ƿ�ȷ�ϴ���(y/n):";
			char ct = getchar();
			rewind(stdin); //��������
			if (ct == 'y')
			{
				Role* role = Constant::RoleInitialization(atoi(&pt), "", 1, 0, 1);
				cout << "�������ɫ���ƣ�";
				string name;
				cin >> name;
				rewind(stdin); //��������
				role->SetRoleName(name);
				//����
				DataStorage::RolePreservation(path, Constant::PreservationToString(role), role->GetId());
				return;
			}
		}
		Constant::LoDing();
		system("cls");
	}
}


//��ɫ��ʼ������ �������ɫ��ս������
void Roleinitialization(string userName, string roleId) {
	
}
