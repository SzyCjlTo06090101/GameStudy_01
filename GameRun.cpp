#include <iostream>
#include <string>
#include <Windows.h>
#include "StaticConstant.h"
#include "Login.h"
using namespace std;

void GameStart();
void LoginStart(Login* lg);

//�߼�����
void GameStart() {
	try
	{
		Login* lg = new Login();
		/*1.�����¼����*/
		LoginStart(lg);
		//�ж��Ƿ��¼�ɹ�
		if (lg->UserName.empty())
			cout << "��¼����" << endl;
		//��¼�ɹ� �����ɫѡ�����

		cout << lg->UserName << endl;
		delete(lg);
	}
	catch (const std::exception&)
	{
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

int main() {
	//��Ϸ��ʼ����
	GameStart();
}