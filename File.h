#pragma once

class File {
public:
	//��ȡ��½�ļ���½��Ϣ
	char GetLoginFile();
	//����û�ע����Ϣ
	void InsertUserInformation();
	//�������û��ļ�
	bool EstablishNewUserFile();

	//����txt�ĵ�
	static bool EstablishTextFile(char FileName[]);
	//д���ĵ�

	//��ȡ�ĵ�
	char QueryTextFile();
private:
	//�����ļ�
	bool EstablishNewFile();
};
