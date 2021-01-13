#include "StaticConstant.h"
#include "Role.h"
#include <string>
#include <iostream>
#include <Windows.h>
#include <vector>
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

void Constant::RoleEstablishInformationDisplay() {
    cout << "输入Y确认角色创建" << endl;
    cout << "输入任意字符返回角色创建" << endl;
}

void Constant::RoleChoiceDisplay(vector<Role>* Rol) {
    cout << "-------------------------" << endl;
    for (Role r : *Rol)
    {
        cout << "---" << r.ToString() << "--" << endl;
    }
    cout << "---x.创建              --" << endl;
    cout << "---0.后退              --" << endl;
    cout << "-------------------------" << endl;
}