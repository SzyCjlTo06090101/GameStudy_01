#pragma once
#include<string>
#include<vector>
using namespace std;

class Skill {
private:
	//��������
	string name;
	//��������
	string describe;
	//�������� 1.ʵʱ�˺����� 2.buff���� 3.deBuff����
	int type;
	//�����˺� ��������Ϊ��1.��ɵ�ʵʱ�˺� 2.����ֵ 3.�Թ���ļ���ֵ
	int hurt;
	//��ɵ�buff�����غ���
	int continuedCooling;
	//��ȴ�غ���
	int cooling;
	//Ĭ����ȴ�غ���
	int maxCooling;
	//�����ж�����
	int actionPoints;

public:
	string GetName() {
		return this->name;
	}
	void SetName(string name) {
		this->name = name;
	}

	string GetDescribe() {
		return this->describe;
	}
	void SetDescribe(string describe) {
		this->describe = describe;
	}

	int GetType() {
		return this->type;
	}
	void SetType(int type) {
		this->type = type;
	}

	int GetHurt() {
		return this->hurt;
	}
	void SetHurt(int hurt) {
		this->hurt = hurt;
	}

	int GetContinuedCooling() {
		return this->continuedCooling;
	}
	void SetContinuedCooling(int continuedCooling) {
		this->continuedCooling = continuedCooling;
	}

	int GetCooling() {
		return this->cooling;
	}
	void SetCooling(int cooling) {
		this->cooling = cooling;
	}

	int GetMaxCooling() {
		return this->maxCooling;
	}
	void SetMaxCooling(int maxCooling) {
		this->maxCooling = maxCooling;
	}
	
	int GetActionPoints() {
		return this->actionPoints;
	}
	void SetActionPoints(int actionPoints) {
		this->actionPoints = actionPoints;
	}
};