#pragma once
#include <string>
#include <vector>
#include <iostream>
#include <time.h>
#include <map>
#include "Role.h"
using namespace std;

class RoleUtils {
public:
    //随机数 1-100整数
    static int GetRandomNumber()
    {
        int RandomNumber;
        srand((unsigned)time(NULL));//time()用系统时间初始化种。为rand()生成不同的随机种子。
        RandomNumber = rand() % 100 + 1;//生成1~100随机数
        return RandomNumber;
    }

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
    static vector<map<string, string>> StringSplitRole(const vector<string>* RoleStrs) //字符串分割到数组
    {
        vector<map<string, string>> RoleVec;
        for (string RoleStr : *RoleStrs)
        {
            vector<string>* Roles = StringSplit(RoleStr, ":");
            Role* Rol = new Role();
            Rol->SetOccupationId(atoi((*Roles)[0].c_str()));
            Rol->SetId((*Roles)[1]);
            Rol->SetGrade(atoi((*Roles)[2].c_str()));
            Rol->SetRoleName((*Roles)[3]);
            Rol->SetExperience(atoi((*Roles)[4].c_str()));
            Rol->SetLayerl(atoi((*Roles)[5].c_str()));
            // TODO 分装到Role DOTO
            map<string, string> ma;
            ma.insert(map<string, string>::value_type ("id", Rol->GetId()));
            ma.insert(map<string, string>::value_type ("toString", Rol->ToString()));
            RoleVec.push_back(ma);
            delete(Rol);
            Rol = NULL;
        }
        return RoleVec;
    }

    //获取选定角色信息
    static Role* StringSplitRoleInitialization(const vector<string>* RoleStrs, string roleId) {
        for (string RoleStr : *RoleStrs)
        {
            vector<string>* Roles = StringSplit(RoleStr, ":");
            if ((*Roles)[1] == roleId)
            {
                Role* rol = new Role();
                rol->SetOccupationId(atoi((*Roles)[0].c_str()));
                rol->SetId((*Roles)[1]);
                rol->SetGrade(atoi((*Roles)[2].c_str()));
                rol->SetRoleName((*Roles)[3]);
                rol->SetExperience(atoi((*Roles)[4].c_str()));
                rol->SetLayerl(atoi((*Roles)[5].c_str()));
                return rol;
            }
        }
        return NULL;
    }
};