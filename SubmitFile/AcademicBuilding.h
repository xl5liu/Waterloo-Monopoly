#ifndef ACADEMICBUILDING_H
#define ACADEMICBUILDING_H

#include <iostream>
#include "Building.h"
class Department;
class Board;
class Player;

class AcademicBuilding : public Building{
	const int improvementCost;
	int tuitionWithImprov[6];
	int numImproved;
	bool inMonopoly;
	Department *department;


public:
	AcademicBuilding(int index, std::string name, Board *board, Department *department, const int purchaseCost, const int improvementCost,int t0, int t1, int t2, int t3, int t4, int t5);
	virtual ~AcademicBuilding();
	void pay(Player *payer);
	void buy(Player *buyer);
	bool getMonopoly();
	void setMonopoly(bool setting);
	virtual int totalWorth();
	int getNumImproved();
	void setNumImproved(int setting);
	virtual void printBuildingInfo();
	virtual bool mortgage();
	virtual bool unmortgage();
	virtual void getReadyAuction();
	virtual bool buyImprove();
 	virtual bool sellImprove();
 	virtual void setMonopolyStatus();
	
};

#endif
