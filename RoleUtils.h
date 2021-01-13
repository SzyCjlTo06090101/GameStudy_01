#pragma once
#include <string>
#include <vector>
#include <iostream>
#include "Role.h"
#include "Warrior.h"
using namespace std;

class RoleUtils {
public:
    //����ַ���
    static vector<string>* StringSplit(const std::string& Str, const string& Pattern) //�ַ����ָ����
    {
        char* strc = new char[strlen(Str.c_str()) + 1];
        strcpy(strc, Str.c_str());
        vector<string>* ReturnStr = new vector<string>;
        char* tmpStr = strtok(strc, Pattern.c_str());
        while (tmpStr != NULL)
        {
            ReturnStr->push_back(string(tmpStr));
            tmpStr = strtok(NULL, Pattern.c_str());
        }
        delete[] strc;
        return ReturnStr;
    }


    //��ֽ�ɫ�洢�ַ��� ��װ����ɫ����
    static vector<Role>* StringSplitRole(const vector<string>* RoleStrs) //�ַ����ָ����
    {
        vector<Role>* RoleVec = new vector<Role>;
        for (string RoleStr : *RoleStrs)
        {
            vector<string>* Roles = StringSplit(RoleStr, ":");
            Role* Rol = new Role();
            // TODO ��װ��Role DOTO
            RoleVec->push_back(*Rol);
            delete(Rol);
            Rol = NULL;
        }
        return RoleVec;
    }
};