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

/*�����ļ����� �����·�����½��ļ�*/
bool File::EstablishTextFile(char FIleName[]) {
	//bool b = CreateDirectory(TEXT(""), NULL);

	ofstream fout(".\\Record\\a.txt");
	if (fout) {
		fout.close();
	}
	return true;
}

/*��ȡ�ĵ�*/
char File::QueryTextFile() {
	return NULL;
}