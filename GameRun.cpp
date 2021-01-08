#include <iostream>
#include <string>
#include <Windows.h>
#include "StaticConstant.h"
#include "Login.h"
using namespace std;

void GameStart();
string LoginStart();

Login* lg = new Login();

//�߼�����
void GameStart() {
	try
	{
		/*1.�����¼����*/
		LoginStart();
	}
	catch (const std::exception&)
	{
		return;
	}
}

//��¼����
string LoginStart() {
	while (true)
	{
		Constant::LoginDisplay();
		char pt = getchar();
		switch (pt)
		{
		case '1'://��¼
			lg->AccountPasswordLogin();
			if (lg->UserName.empty())
				cout << "�û����������" << endl;
			else
				cout << "��½�ɹ�" << endl;
			break;
		case '2'://ע��
			lg->AccountPasswordRegister(); break;
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

int main() {
	//��Ϸ��ʼ����
	GameStart();
}