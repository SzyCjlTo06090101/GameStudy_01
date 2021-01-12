#include "Warrior.h"
#include "UuidUtils.h"
#include <string>
#include <vector>
using namespace std;

Warrior::Warrior(string Name) {
	this->OccupationId = 1;
	this->Id = GetUUID();
	this->RoleName = Name;
	this->Grade = 1;
	this->HitPoint = 300;
	this->Hurt = 15;
	this->ActionPoints = 10;
	this->Experience = 0;
	this->ExperienceTotal = 100;
	this->Buffer = new vector<int>;
	this->DeBuffer = new vector<int>;
	this->CriticalHit = 0.1f;
}