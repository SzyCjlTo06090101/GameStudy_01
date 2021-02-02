#include "StaticConstant.h"
#include "Role.h"
#include "Skill.h"
#include "UuidUtils.h"
#include <string>
#include <iostream>
#include <Windows.h>
#include <vector>
#include <map>
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
    cout << "---请选择：";
}

void Constant::RoleEstablishDisplay() {
    cout << "-------------------------" << endl;
    cout << "---1.战士              --" << endl;
    cout << "---2.法师              --" << endl;
    cout << "---3.牧师              --" << endl;
    cout << "---0.后退              --" << endl;
    cout << "-------------------------" << endl;
    cout << "---请选择：";

}

void Constant::RoleEstablishInformationDisplay() {
    cout << "输入Y确认角色创建" << endl;
    cout << "输入任意字符返回角色创建" << endl;
}

void Constant::RoleChoiceDisplay(vector<map<string, string>> Rol) {
    cout << "-------------------------" << endl;
    for (int i = 0; i < Rol.size(); i++) {
        if (Rol[i].count("toString") > 0)
        {
            cout << "---" << i + 1 << "." << Rol[i]["toString"] << "--" << endl;
        }
    }
    cout << "---x.创建              --" << endl;
    cout << "---0.后退              --" << endl;
    cout << "-------------------------" << endl;
    cout << "---请选择：";

}

/*角色初始化*/
Role* Constant::RoleInitialization(int occupationId, string uuid, int grade, float ex, int layerl) {
    Role* role = new Role();
    //角色类型
    role->SetOccupationId(occupationId);
    //角色id
    role->SetId(uuid.empty() ? Uuid::GetUUID() : uuid);
    //角色等级
    role->SetGrade(grade);
    //角色当前经验值
    role->SetExperience(ex);
    //增益buff
    role->SetBuffer(new map<int, int>);
    //减益buff
    role->SetDeBuffer(new map<int, int>);
    //玩家所在层数
    role->SetLayerl(layerl);
    return role;
}

//战士技能初始化
vector<Skill*>* Constant::WarriorSkillInitialization(int gradem, int hurt) {
    Skill* skillOne = new Skill();
    skillOne->SetName("战之意志");
    skillOne->SetDescribe("下回合首次攻击伤害增加三倍");
    skillOne->SetHurt(3);
    skillOne->SetType(2);
    skillOne->SetCooling(3);
    skillOne->SetActionPoints(3);

    Skill* skillTwo = new Skill();
    skillTwo->SetName("屠魔光刃");
    skillTwo->SetDescribe("造成120%点基础伤害");
    skillTwo->SetHurt(hurt * 1.2);
    skillOne->SetType(1);
    skillOne->SetCooling(2);
    skillOne->SetActionPoints(6);

    Skill* skillThree = new Skill();
    skillThree->SetName("神圣裁决");
    skillThree->SetDescribe("造成300%点基础伤害 若怪物生命值低于15%造成处决");
    skillThree->SetHurt(hurt * 3);
    skillThree->SetType(1);
    skillThree->SetCooling(7);
    skillThree->SetActionPoints(7);

    vector<Skill*>* skills = new vector<Skill*>;
    skills->push_back(skillOne);
    skills->push_back(skillTwo);
    skills->push_back(skillThree);
    return skills;
}

// OccupationId 职业id
bool Constant::RoleExhibition(char occupationId){
    system("cls");
    switch (occupationId)
    {
    case '1': 
        cout << "战士：拥有独特的暴击概率" << endl;
        cout << "被动：圣甲——每次受到伤害暴击率增加10%,触发暴击后暴击率恢复初始值" << endl;
        cout << "一技能：战之意志——下回合首次攻击伤害增加三倍" << endl;
        cout << "二技能：屠魔光刃——造成120%点基础伤害" << endl;
        cout << "三技能：神圣裁决——造成300%点基础伤害 若怪物生命值低于15%造成处决" << endl;
        break;
    case '2':
        cout << "法师：每回合自动回血" << endl;
        cout << "被动：灵目-愈——每回合回复已损失血量10%" << endl;
        cout << "一技能：灵域-封——在一个回合后冰封所有敌人一回合使其无法攻击 造成基础伤害" << endl;
        cout << "二技能：灵焰-烬——召唤流星砸向所有敌人造成晕眩一回合 造成基础伤害" << endl;
        cout << "三技能：灵爆-茫——消耗当前生命值40%召唤大天使 之后大天使持续三个回合 " <<
            "并且每个回合随机使用火球 - 烧伤，冰球 - 冰冻，光球 - 失明 攻击单个敌人造成基础攻击的150 % 伤害" << endl;
        break;
    case '3':
        cout << "法师：免疫持续伤害" << endl;
        cout << "被动：梧桐灯——免疫持续伤害" << endl;
        cout << "一技能：治愈术——回复已损失生命值的20%持续二回合" << endl;
        cout << "二技能：燃烧术——对敌方最多三个敌人造成基础伤害 并持续造成基础伤害的70%的烧伤伤害三回合" << endl;
        cout << "三技能：催眠术——是对手进入睡眠状态持续两回合" << endl;
        break;
    default:
        cout << "请选择正确选项" << endl;
        return false;
        break;
    }
    return true;
}

string Constant::PreservationToString(Role* role) {
    string str = to_string(role->GetOccupationId()) + ":" + role->GetId() + ":" + to_string(role->GetGrade()) + ":" + role->GetRoleName() + ":"
        + to_string(role->GetExperience()) + ":" + to_string(role->GetLayerl()) + ";";
    return str;
}