#pragma once
#include <string>
#include <time.h>
using namespace std;

class BlameUtils {
public:
	//��������������
	static int RandomMonster() {
		int number;
		srand((unsigned)time(NULL));//time()��ϵͳʱ���ʼ���֡�Ϊrand()���ɲ�ͬ��������ӡ�
		number = rand() % 4 + 1;//����1~4�����
		return number;
	}
};