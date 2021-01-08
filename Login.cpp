#include <iostream>
#include <string>
#include "Login.h"
#include "DataStorage.h"
using namespace std;

Login::Login() {
	//����Ƿ�����û���Ϣ�洢�ļ� ���������½�
	DataStorage::TestingStorageAndEstablish(this->UserPath);
}

//�˺������½
bool Login::AccountPasswordLogin() {
	try
	{
		string User = this->UsernameAndPasswordMerga();
		if (DataStorage::GetFileDataAndTesting(this->UserPath, User)) {
			this->UserName = User.substr(0, User.find_last_of(":"));
			return true;
		}
		else
		{
			this->UserName = "";
			return false;
		}
		
	}
	catch (const std::exception&)
	{
		cout << "��¼�쳣" << endl;
		throw;
	}
	
}


//�˺�����ע��
bool Login::AccountPasswordRegister() {
	try
	{
		string User = this->UsernameAndPasswordMerga();
		DataStorage::InsertUserInformation(this->UserPath, User);
		cout << "ע��ɹ�" << endl;
		return true;
	}
	catch (const std::exception&)
	{
		cout << "ע���쳣" << endl;
		throw;
	}
}

string Login::UsernameAndPasswordMerga() {
	string UserName;
	string PassWord;
	cout << "--------------------------------" << endl;
	cout << "�������û�������:";
	cin >> UserName;
	cout << endl << "����������:";
	cin >> PassWord;
	cout << endl;
	//��װ��Ϣ��У��
	string User = UserName + ":" + PassWord;
	return User;
}