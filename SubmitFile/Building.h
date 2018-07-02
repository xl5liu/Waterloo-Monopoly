#ifndef BUILDING_H
#define BUILDING_H

class Player;
class Board;
#include "Square.h"
#include <iostream>

class Building : public Square{

protected:
	const int purchaseCost;
	Player *owner;
	bool isMortgaged;

 public:
 	Building(int index,std::string name, Board *board, const int purchaseCost);
 	virtual ~Building();
 	void autoAction(Player *player);
 	virtual void pay(Player *payer) = 0;
 	virtual void buy(Player *buyer) = 0;
 	Player *getOwner();
 	void setOwner(Player *player);
 	virtual int totalWorth() = 0;
 	virtual void printBuildingInfo() = 0;
 	void setMortgaged(bool setting);
 	bool getMortgaged();
 	virtual bool mortgage() = 0;
 	virtual bool unmortgage() = 0;
 	virtual void getReadyAuction() = 0;
 	virtual int getNumImproved() = 0;
 	virtual bool buyImprove() = 0;
 	virtual bool sellImprove() = 0;
 	virtual void setMonopolyStatus() = 0;
 	int getPurchaseCost();


}; 
#endif
