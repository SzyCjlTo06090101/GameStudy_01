#pragma once
using namespace std;


class File {
public:

	//����txt�ĵ�
	static bool EstablishTextFile(string FileName);
	//��ȡ�ĵ�
	static string QueryTextFile(string FIleName);
	//д���ĵ�
	static void WriteInFile(string FIleName);


	//��ȡ��½�ļ���½��Ϣ
	char GetLoginFile();
	//����û�ע����Ϣ
	void InsertUserInformation();
	//�������û��ļ�
	bool EstablishNewUserFile();


};
