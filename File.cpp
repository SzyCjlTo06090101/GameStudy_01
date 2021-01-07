#include <iostream>
#include <fstream>
#include "File.h"
#include <windows.h>
using namespace std;

bool File::EstablishNewUserFile() {
	return true;
}


bool File::EstablishNewFile() {
	return true;
}

/*根据文件名称 在相对路径中新建文件*/
bool File::EstablishTextFile(char FIleName[]) {
	//bool b = CreateDirectory(TEXT(""), NULL);

	ofstream fout(".\\Record\\a.txt");
	if (fout) {
		fout.close();
	}
	return true;
}

/*读取文档*/
char File::QueryTextFile() {
	return NULL;
}