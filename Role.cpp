#include "Role.h"
#include "UuidUtils.h"
#include "Skill.h"
#include "StaticConstant.h"
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
	str.append(" ����:");
	str.append(to_string(this->layerl));
	return str;
}

//�ȼ����� --�����Դ���
void Role::SetGrade(int Grade) {
	vector<Skill*>* skills = new vector<Skill*>;

	this->Grade = Grade;
	this->ExperienceTotal = (float)Grade * 100;
	/*սʿ����*/
	if (this->OccupationId == 1)
	{
		//�����˺�
		this->Hurt = 15 * ((Grade - 1) * 5);
		//���Ѫ��
		this->maxHitPoint = 300 * ((Grade - 1) * 40);
		//�������������ж�����
		this->ActionPoints = 2;
		//������
		int craitical = Grade * 2;
		if (craitical > 80)
		{
			craitical = 80;
		}
		this->criticalHit = craitical;
		//����
		skills = Constant::WarriorSkillInitialization(Grade, this->Hurt);
	}

	if (!skills->empty())
	{
		this->SkillOne = (*skills)[0];
		this->SkillTwo = (*skills)[1];
		this->SkillThree = (*skills)[2];
		delete(skills);
		skills = NULL;
	}
}

