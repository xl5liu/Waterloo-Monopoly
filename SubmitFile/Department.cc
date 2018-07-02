#include "Department.h"
#include "AcademicBuilding.h"
#include <iostream>
using namespace std;

Department::Department(int numBuildings, std::string name):numBuildings(numBuildings),name(name){
	members[0] = NULL;
	members[1] = NULL;
	members[2] = NULL;

}

Department::~Department(){}

void Department::setMonopolyStatus(){
	//cout << "In set Monopoly function" << endl;
	bool sameOwner;
	bool allNotisMortgaged;
	if (numBuildings == 3) {
		sameOwner = (members[0]->getOwner() == members[1]->getOwner()) && (members[1]->getOwner() == members[2]->getOwner());
		allNotisMortgaged = (((!members[0]->getMortgaged()) && (!members[1]->getMortgaged())) && (!members[2]->getMortgaged()));

		if(sameOwner && allNotisMortgaged){
			int i = 0;
			while((i < 3) && members[i] != NULL){
				members[i]->setMonopoly(true);
				i++;
			}
		}
		else{
			int i = 0;
			while((i < 3) && members[i] != NULL){
				//cout << "In while loop" << endl;
				members[i]->setMonopoly(false);
				i++;
			}
			//cout << "Out of while loop" << endl;
		}
		//cout << "Exiting set Monopoly function" << endl;
	} 
	else {
		sameOwner = ( members[0]->getOwner() == members[1]->getOwner());
		allNotisMortgaged = ((!members[0]->getMortgaged()) && (!members[1]->getMortgaged()));
		if (sameOwner && allNotisMortgaged){
			int i = 0;
			while(members[i] != NULL){
				members[i]->setMonopoly(true);
				i++;
			}
		}
		else{
			int i = 0;
			while(members[i] != NULL){
				members[i]->setMonopoly(false);
				i++;
			}
		}
		
	}
}

void Department::addMember(AcademicBuilding *building){
	int i = 0;
	while(members[i] != NULL){
		i++;
	}
	members[i] = building;
}

AcademicBuilding * Department::getBuilding(string name) {
	for (int i = 0; (i < 3) && members[i] != NULL; ++i) {
	//	cout << "In while loop" << endl;
			if(members[i]->getName() == name) {
				return members[i];
			}
	}
//	cout << "out of while" << endl;
	return NULL;

}


bool Department::anyImprove(){
	bool anyImprove = false;
	for (int i = 0; i < numBuildings; ++i){
		if(members[i]->getNumImproved() > 0){
			anyImprove = true;
		}
	}
	return anyImprove;
}





