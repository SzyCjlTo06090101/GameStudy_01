#pragma once
#include <string>
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
	static void RoleChoiceDisplay(string Choice[]); //��ɫѡ�����
};
