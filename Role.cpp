#include "Role.h"
#include "UuidUtils.h"
#include <string>
using namespace std;

string Role::ToString() {
	string str;
	str.append("职业:");
	str.append(this->OccupationId + ";");
	str.append("角色名称:");
	str.append(this->RoleName + ";");
	str.append("等级");
	str.append(this->Grade + ";");
	return str;
}
