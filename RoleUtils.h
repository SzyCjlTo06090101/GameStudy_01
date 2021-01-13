#pragma once
#include <string>
#include <vector>
#include <iostream>
#include "Role.h"
#include "Warrior.h"
using namespace std;

class RoleUtils {
public:
    //拆分字符串
    static vector<string>* StringSplit(const std::string& Str, const string& Pattern) //字符串分割到数组
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


    //拆分角色存储字符串 封装到角色对象
    static vector<Role>* StringSplitRole(const vector<string>* RoleStrs) //字符串分割到数组
    {
        vector<Role>* RoleVec = new vector<Role>;
        for (string RoleStr : *RoleStrs)
        {
            vector<string>* Roles = StringSplit(RoleStr, ":");
            Role* Rol = new Role();
            // TODO 分装到Role DOTO
            RoleVec->push_back(*Rol);
            delete(Rol);
            Rol = NULL;
        }
        return RoleVec;
    }
};