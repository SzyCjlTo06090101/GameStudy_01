#pragma once

class File {
public:
	//��ȡ��½�ļ���½��Ϣ
	char GetLoginFile();
	//����û�ע����Ϣ
	void InsertUserInformation();
	//�������û��ļ�
	bool EstablishNewUserFile();

private:
	//�����ļ�
	bool EstablishNewFile();
};
