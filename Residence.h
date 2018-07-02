#ifndef RESIDENCE_H
#define RESIDENCE_H

#include "Building.h"
class Player;
class Board;

class Residence : public Building{

public:
	Residence(int index,std::string name, Board *board, const int purchaseCost);
	virtual ~Residence();
	void pay(Player *payer);
	void buy(Player *buyer);
	virtual int totalWorth();
	virtual void printBuildingInfo();
	virtual bool mortgage();
	virtual bool unmortgage();
	virtual void getReadyAuction();
	virtual int getNumImproved();
	virtual bool buyImprove();
 	virtual bool sellImprove();
 	virtual void setMonopolyStatus();
};

#endif