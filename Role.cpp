#include "Role.h"
#include "UuidUtils.h"
#include <string>
using namespace std;

string Role::ToString() {
	string str;
	str.append("ְҵ:");
	str.append(this->OccupationId + ";");
	str.append("��ɫ����:");
	str.append(this->RoleName + ";");
	str.append("�ȼ�");
	str.append(this->Grade + ";");
	return str;
}
