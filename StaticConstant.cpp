#include "StaticConstant.h"
#include <string>
#include <iostream>
#include <Windows.h>
using namespace std;

const string Constant::Path = ".\\Record";
const string Constant::UserPath = ".\\Record\\User.txt";
const string Constant::RolesPath = ".\\Record\\Roles\\"; //角色信息存储的文件名为用户名



void Constant::LoDing() {
    //公等待1.5秒
    for (int i = 0; i < 3; i++)
    {
        Sleep(500);
        cout << "--";
    }
}

void Constant::LoginDisplay() {
    cout << "-------------------------" << endl;
    cout << "---1.登录              --" << endl;
    cout << "---2.注册              --" << endl;
    cout << "---0.退出              --" << endl;
    cout << "-------------------------" << endl;
}

void Constant::RoleEstablishDisplay() {
    cout << "-------------------------" << endl;
    cout << "---1.战士              --" << endl;
    cout << "---2.法师              --" << endl;
    cout << "---3.牧师              --" << endl;
    cout << "---0.后退              --" << endl;
    cout << "-------------------------" << endl;
}

void Constant::RoleChoiceDisplay(string Chioce[]) {
    cout << "-------------------------" << endl;
    for (int i = 0; i < Chioce->length(); i++)
    {
        cout << "---" << Chioce[i] << "--" << endl;
    }
    cout << "---9.创建              --" << endl;
    cout << "---0.后退              --" << endl;
    cout << "-------------------------" << endl;
}