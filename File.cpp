#include <iostream>
#include <fstream>
#include <string>
#include "File.h"
#include <windows.h>
using namespace std;

/*根据文件名称 在相对路径中新建文件*/
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

/*读取文档*/
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

/*写入文档*/
void File::WriteInFile(string FIleName) {
	ofstream outfile;
	outfile.open(FIleName, ios::app); //追加模式
	string str = "username:password;";
	// 向文件写入用户输入的数据
	outfile << str << endl;
	// 关闭打开的文件
	outfile.close();
}