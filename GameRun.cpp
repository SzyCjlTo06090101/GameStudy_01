#include <iostream>
#include <string>
#include "File.h"
#include "StaticConstant.h"
using namespace std;

int main() {
	//游戏开始运行
	string path = Constant::SharePath + Constant::userPath;
	File::EstablishTextFile(path);
	File::WriteInFile(path);
	File::QueryTextFile(path);
	
}