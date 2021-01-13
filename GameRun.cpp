#include <iostream>
#include <string>
#include <Windows.h>
#include <vector>
#include "StaticConstant.h"
#include "Login.h"
#include "DataStorage.h"
#include "Warrior.h"
#include "RoleUtils.h"
using namespace std;

void GameStart();
void LoginStart(Login* lg);
void RoleChoice(string UserName);
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
			RoleChoice(lg->UserName);
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
void RoleChoice(string UserName) {
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
			return;
		}
		else if (pt == 'x') //�½���ɫ
		{
			system("cls");
			RoleEstablish(path);
		}
		else //ѡ���ɫ
		{

		}
		Constant::LoDing();
		system("cls");
		delete(Roles);
		Roles = NULL;
	}
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
			pt = getchar(); getchar(); //��ֹ������͸
			if (pt == 'y')
			{
				cout << "�������ɫ����:";
				string name;
				cin >> name;
				war->SetRoleName(name);
				DataStorage::RolePreservation(path, war->PreservationToString(), war->GetId());
			}
			delete(war);
			war = NULL;
			return;
		}
		case '2':
			cout << "��ʦδ�滮" << endl;
			break;
		case '3':
			cout << "��ʦδ�滮" << endl;
			break;
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