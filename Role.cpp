#include "Role.h"
#include <string>
using namespace std;

string Role::ToString() {
	string str;
	str.append("角色名称:");
	str.append(this->RoleName);
	str.append(" 职业:");
	str.append(this->OccupationStr);
	str.append(" 等级:");
	str.append(to_string(this->Grade));
	return str;
}
