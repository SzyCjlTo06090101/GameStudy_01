#include <iostream>
#include <fstream>
#include <string>
#include "File.h"
#include <windows.h>
using namespace std;

/*�����ļ����� �����·�����½��ļ�*/
bool File::EstablishTextFile(string FIleName) {
	ifstream file;
	file.open(FIleName, ios::in);
	if (!file) {
		ofstream fout(FIleName);
		if (fout) {
			fout.close();
		}
	}
	return true;
}

/*��ȡ�ĵ�*/
string File::QueryTextFile(string FIleName) {
	string data;
	string str;
	ifstream file;
	file.open(FIleName, ios::in);
	while (file >> str) {
		data += str;
	}
	cout << data << endl;
	file.close();
	return data;
}

/*д���ĵ�*/
void File::WriteInFile(string FIleName) {
	ofstream outfile;
	outfile.open(FIleName, ios::app); //׷��ģʽ
	string str = "username:password;";
	// ���ļ�д���û����������
	outfile << str << endl;
	// �رմ򿪵��ļ�
	outfile.close();
}