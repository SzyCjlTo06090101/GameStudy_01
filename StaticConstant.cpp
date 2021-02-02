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
    cout << "---��ѡ��";
}

void Constant::RoleEstablishDisplay() {
    cout << "-------------------------" << endl;
    cout << "---1.սʿ              --" << endl;
    cout << "---2.��ʦ              --" << endl;
    cout << "---3.��ʦ              --" << endl;
    cout << "---0.����              --" << endl;
    cout << "-------------------------" << endl;
    cout << "---��ѡ��";

}

void Constant::RoleEstablishInformationDisplay() {
    cout << "����Yȷ�Ͻ�ɫ����" << endl;
    cout << "���������ַ����ؽ�ɫ����" << endl;
}

void Constant::RoleChoiceDisplay(vector<map<string, string>> Rol) {
    cout << "-------------------------" << endl;
    for (int i = 0; i < Rol.size(); i++) {
        if (Rol[i].count("toString") > 0)
        {
            cout << "---" << i + 1 << "." << Rol[i]["toString"] << "--" << endl;
        }
    }
    cout << "---x.����              --" << endl;
    cout << "---0.����              --" << endl;
    cout << "-------------------------" << endl;
    cout << "---��ѡ��";

}

/*��ɫ��ʼ��*/
Role* Constant::RoleInitialization(int occupationId, string uuid, int grade, float ex, int layerl) {
    Role* role = new Role();
    //��ɫ����
    role->SetOccupationId(occupationId);
    //��ɫid
    role->SetId(uuid.empty() ? Uuid::GetUUID() : uuid);
    //��ɫ�ȼ�
    role->SetGrade(grade);
    //��ɫ��ǰ����ֵ
    role->SetExperience(ex);
    //����buff
    role->SetBuffer(new map<int, int>);
    //����buff
    role->SetDeBuffer(new map<int, int>);
    //������ڲ���
    role->SetLayerl(layerl);
    return role;
}

//սʿ���ܳ�ʼ��
vector<Skill*>* Constant::WarriorSkillInitialization(int gradem, int hurt) {
    Skill* skillOne = new Skill();
    skillOne->SetName("ս֮��־");
    skillOne->SetDescribe("�»غ��״ι����˺���������");
    skillOne->SetHurt(3);
    skillOne->SetType(2);
    skillOne->SetCooling(3);
    skillOne->SetActionPoints(3);

    Skill* skillTwo = new Skill();
    skillTwo->SetName("��ħ����");
    skillTwo->SetDescribe("���120%������˺�");
    skillTwo->SetHurt(hurt * 1.2);
    skillOne->SetType(1);
    skillOne->SetCooling(2);
    skillOne->SetActionPoints(6);

    Skill* skillThree = new Skill();
    skillThree->SetName("��ʥ�þ�");
    skillThree->SetDescribe("���300%������˺� ����������ֵ����15%��ɴ���");
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

// OccupationId ְҵid
bool Constant::RoleExhibition(char occupationId){
    system("cls");
    switch (occupationId)
    {
    case '1': 
        cout << "սʿ��ӵ�ж��صı�������" << endl;
        cout << "������ʥ�ס���ÿ���ܵ��˺�����������10%,���������󱩻��ʻָ���ʼֵ" << endl;
        cout << "һ���ܣ�ս֮��־�����»غ��״ι����˺���������" << endl;
        cout << "�����ܣ���ħ���С������120%������˺�" << endl;
        cout << "�����ܣ���ʥ�þ��������300%������˺� ����������ֵ����15%��ɴ���" << endl;
        break;
    case '2':
        cout << "��ʦ��ÿ�غ��Զ���Ѫ" << endl;
        cout << "��������Ŀ-������ÿ�غϻظ�����ʧѪ��10%" << endl;
        cout << "һ���ܣ�����-�⡪����һ���غϺ�������е���һ�غ�ʹ���޷����� ��ɻ����˺�" << endl;
        cout << "�����ܣ�����-�������ٻ������������е��������ѣһ�غ� ��ɻ����˺�" << endl;
        cout << "�����ܣ��鱬-ã�������ĵ�ǰ����ֵ40%�ٻ�����ʹ ֮�����ʹ���������غ� " <<
            "����ÿ���غ����ʹ�û��� - ���ˣ����� - ���������� - ʧ�� ��������������ɻ���������150 % �˺�" << endl;
        break;
    case '3':
        cout << "��ʦ�����߳����˺�" << endl;
        cout << "��������ͩ�ơ������߳����˺�" << endl;
        cout << "һ���ܣ������������ظ�����ʧ����ֵ��20%�������غ�" << endl;
        cout << "�����ܣ�ȼ���������Եз��������������ɻ����˺� ��������ɻ����˺���70%�������˺����غ�" << endl;
        cout << "�����ܣ������������Ƕ��ֽ���˯��״̬�������غ�" << endl;
        break;
    default:
        cout << "��ѡ����ȷѡ��" << endl;
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