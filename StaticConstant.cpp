#include "StaticConstant.h"
#include <string>
#include <iostream>
#include <Windows.h>
using namespace std;

const string Constant::UserPath = ".\\Record\\User.txt";
const string Constant::RolesPath = ".\\Record\\Roles\\%s.txt"; //��ɫ��Ϣ�洢���ļ���Ϊ�û���+���



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