#pragma once
#include <string>
#include <time.h>
using namespace std;

class BlameUtils {
public:
	//随机生存怪物类型
	static int RandomMonster() {
		int number;
		srand((unsigned)time(NULL));//time()用系统时间初始化种。为rand()生成不同的随机种子。
		number = rand() % 4 + 1;//生成1~4随机数
		return number;
	}
};