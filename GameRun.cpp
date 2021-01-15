#include <iostream>
#include <string>
#include <Windows.h>
#include <vector>
#include "StaticConstant.h"
#include "Login.h"
#include "DataStorage.h"
#include "Warrior.h"
#include "Master.h"
#include "Minister.h"
#include "RoleUtils.h"
using namespace std;

void GameStart();
void LoginStart(Login* lg);
string RoleChoice(string UserName);
void RoleEstablish(string path);

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
				cout << roleId << endl;
			}
			delete(lg);
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
		vector<Role>* Roles = RoleUtils::StringSplitRole(RoleUtils::StringSplit(RoleString, ";"));

		Constant::RoleChoiceDisplay(Roles);
		char pt = getchar();
		rewind(stdin); //��������
		if (pt == '0') //���˲˵�
		{
			return "";
		}
		else if (pt == 'x') //�½���ɫ
		{
			system("cls");
			RoleEstablish(path);
		}
		else //ѡ���ɫ
		{
			//���ؽ�ɫid
			string rolesId = (*Roles)[atoi(&pt) - 1].GetId();
			delete(Roles);
			Roles = NULL;
			return rolesId;
		}
		Constant::LoDing();
		system("cls");
		delete(Roles);
		Roles = NULL;
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
		switch (pt)
		{
		case '1': 
		{
			system("cls");
			Warrior* war = new Warrior();
			war->ToStringExhibition();
			Constant::RoleEstablishInformationDisplay();
			char pt = getchar();
			rewind(stdin); //��������
			if (pt == 'y')
			{
				cout << "�������ɫ����:";
				string name;
				cin >> name;
				rewind(stdin); //��������
				war->SetRoleName(name);
				DataStorage::RolePreservation(path, war->PreservationToString(), war->GetId());
			}
			delete(war);
			war = NULL;
			return;
		}
		case '2':
		{
			system("cls");
			Master* mas = new Master();
			mas->ToStringExhibition();
			Constant::RoleEstablishInformationDisplay();
			char pt = getchar();
			rewind(stdin); //��������
			if (pt == 'y')
			{
				cout << "�������ɫ����:";
				string name;
				cin >> name;
				rewind(stdin); //��������
				mas->SetRoleName(name);
				DataStorage::RolePreservation(path, mas->PreservationToString(), mas->GetId());
			}
			delete(mas);
			mas = NULL;
			return;
		}
		case '3':
		{
			system("cls");
			Minister* min = new Minister();
			min->ToStringExhibition();
			Constant::RoleEstablishInformationDisplay();
			char pt = getchar();
			rewind(stdin); //��������
			if (pt == 'y')
			{
				cout << "�������ɫ����:";
				string name;
				cin >> name;
				rewind(stdin); //��������
				min->SetRoleName(name);
				DataStorage::RolePreservation(path, min->PreservationToString(), min->GetId());
			}
			delete(min);
			min = NULL;
			return;
		}
		case '0'://����
			return;
		default:
			cout << "ѡ�����������ѡ��" << endl;
		}
		Constant::LoDing();
		system("cls");
	}
}

int main() {
	//��Ϸ��ʼ����
	GameStart();
	
}