#pragma once
#include "Role.h"
#include "Skill.h"
#include <string>
#include <vector>
using namespace std;


class Constant {
public:
	/**************************�洢·��***************************/
	static const string Path; //�洢��·��
	static const string UserPath; //�洢�û��˺���Ϣ��·��
	static const string RolesPath; //�洢��ɫ��Ϣ·��


	/***************************�ȴ���ʾ**************************/
	static void LoDing();
	/***************************�˵�չʾ**************************/
	static void LoginDisplay(); //��¼����
	static void RoleEstablishDisplay(); //��ɫ��������
	static void RoleEstablishInformationDisplay(); //��ɫ��������
	static void RoleChoiceDisplay(vector<map<string, string>> Rol); //��ɫѡ�����

	/**************************��ɫ��ʼ��************************/
	static Role* RoleInitialization(int occupationId, string uuid, int grade, float ex, int layerl);

	/*սʿ���ܳ�ʼ��*/
	static vector<Skill*>* WarriorSkillInitialization(int grade, int hurt);


	/*************************�����ɫ��Ϣ�ַ���****************************/
	static string PreservationToString(Role* role);


	/**************************��ɫ��Ϣչʾ*********************************/
	static bool RoleExhibition(char OccupationId);
};
