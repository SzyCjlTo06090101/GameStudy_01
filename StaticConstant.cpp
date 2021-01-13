#include "StaticConstant.h"
#include "Role.h"
#include <string>
#include <iostream>
#include <Windows.h>
#include <vector>
using namespace std;

const string Constant::Path = ".\\Record";
const string Constant::UserPath = ".\\Record\\User.txt";
const string Constant::RolesPath = ".\\Record\\Roles\\"; //��ɫ��Ϣ�洢���ļ���Ϊ�û���



void Constant::LoDing() {
    //���ȴ�1.5��
    for (int i = 0; i < 3; i++)
    {
        Sleep(500);
        cout << "--";
    }
}

void Constant::LoginDisplay() {
    cout << "-------------------------" << endl;
    cout << "---1.��¼              --" << endl;
    cout << "---2.ע��              --" << endl;
    cout << "---0.�˳�              --" << endl;
    cout << "-------------------------" << endl;
}

void Constant::RoleEstablishDisplay() {
    cout << "-------------------------" << endl;
    cout << "---1.սʿ              --" << endl;
    cout << "---2.��ʦ              --" << endl;
    cout << "---3.��ʦ              --" << endl;
    cout << "---0.����              --" << endl;
    cout << "-------------------------" << endl;
}

void Constant::RoleEstablishInformationDisplay() {
    cout << "����Yȷ�Ͻ�ɫ����" << endl;
    cout << "���������ַ����ؽ�ɫ����" << endl;
}

void Constant::RoleChoiceDisplay(vector<Role>* Rol) {
    cout << "-------------------------" << endl;
    for (Role r : *Rol)
    {
        cout << "---" << r.ToString() << "--" << endl;
    }
    cout << "---x.����              --" << endl;
    cout << "---0.����              --" << endl;
    cout << "-------------------------" << endl;
}