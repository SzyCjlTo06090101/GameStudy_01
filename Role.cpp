#include "Role.h"
#include <string>
using namespace std;

string Role::ToString() {
	string str;
	str.append("��ɫ����:");
	str.append(this->RoleName);
	str.append(" ְҵ:");
	str.append(this->OccupationStr);
	str.append(" �ȼ�:");
	str.append(to_string(this->Grade));
	return str;
}
