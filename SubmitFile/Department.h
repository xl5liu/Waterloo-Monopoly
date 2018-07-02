#ifndef DEPARTMENT_H
#define DEPARTMENT_H
#include <string>

class AcademicBuilding;

class Department{
	AcademicBuilding *members[3];
	int numBuildings;
	std::string name;
public:
	Department(int numBuildings, std::string name);
	~Department();
	void setMonopolyStatus();
	void addMember(AcademicBuilding *building);
	AcademicBuilding *getBuilding(std::string name);
	bool anyImprove();
};
#endif
