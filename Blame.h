#pragma once
#include <string>
#include <vector>
using namespace std;

class Blame {
protected:
	//����
	string name;
	//Ѫ��
	int hitPoint;
	//�˺�
	int hurt;
	//����״̬
	vector<int>* buffer;
	//����״̬
	vector<int>* deBuffer;

public:
	//�غϿ�ʼ
	void RoundStart();
	//�غϽ���
	void RoundEnd();
	//����(�˺�����)
	void Attack();
	//������
	void BeHurt(double Hurt);
	//1���� 
	void SkillOne();
	//2����
	void SkillTwo();
	//3����
	void SkillThree();

public:
	void SetName(string name) {
		this->name = name;
	}
	string GetName() {
		return this->name;
	}

	void SetHitPoint(int hitPoint) {
		this->hitPoint = hitPoint;
	}
	int GetHitPoint() {
		return this->hitPoint;
	}

	void SetHurt(int hurt) {
		this->hurt = hurt;
	}
	int GetHurt() {
		return this->hurt;
	}

	void SetName(string name) {
		this->name = name;
	}
	string GetName() {
		return this->name;
	}

	void SetName(string name) {
		this->name = name;
	}
	string GetName() {
		return this->name;
	}

	vector<int>* GetBuffer() {
		return this->buffer;
	}
	void SetBuffer(vector<int>* Buffer) {
		this->buffer = Buffer;
	}

	vector<int>* GetDeBuffer() {
		return this->deBuffer;
	}
	void SetDeBuffer(vector<int>* DeBuffer) {
		this->deBuffer = DeBuffer;
	}
};