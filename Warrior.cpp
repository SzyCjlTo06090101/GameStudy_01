#include "Warrior.h"
#include "UuidUtils.h"
#include <string>
using namespace std;

Warrior::Warrior(string Name) {
	this->Id = GetUUID();
	this->RoleName = Name;
	this->Grade = 1;
	this->HitPoint = 300;
	this->Hurt = 15;
	this->ActionPoints = 10;
	this->Experience = 0;
	this->ExperienceTotal = 100;
	this->CriticalHit = 0.1f;
}