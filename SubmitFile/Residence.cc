#include "Residence.h"
#include "Board.h"
#include "Player.h"
using namespace std;

Residence::Residence(int index,std::string name, Board *board, const int purchaseCost):Building(index,name,board,purchaseCost){
}

Residence::~Residence(){}

void Residence::pay(Player *payer){
	bool successfulPay = false;
	int moneyOwning = 0;

	if (owner->resOwned() == 1){
		std::cout << payer->getName() << " is paying " << owner->getName() << std::endl;
		moneyOwning = 25;
		successfulPay = payer->payMoney(25, owner);
	}
	else if (owner->resOwned() == 2){
		std::cout << payer->getName() << " is paying " << owner->getName() << std::endl;
		moneyOwning = 50;
		successfulPay = payer->payMoney(50, owner);
	}
	else if (owner->resOwned() == 3){
		std::cout << payer->getName() << " is paying " << owner->getName() << std::endl;
		moneyOwning = 100;
		successfulPay = payer->payMoney(100, owner);
	}
	else if (owner->resOwned() == 4){
		std::cout << payer->getName() << " is paying " << owner->getName() << std::endl;
		moneyOwning = 200;
		successfulPay = payer->payMoney(200, owner);
	}
	if(!successfulPay){
		payer->setDebtOwner(owner);
		payer->setAmountOwed(moneyOwning);
		cout << "Paying Failed!" << " Now Owing $" << moneyOwning << " To " << owner->getName() << endl;
	}
	//board->printCurrentStatus();
}

void Residence::buy(Player *buyer){
	std::cout << buyer->getName() << " is buying " << name << std::endl;
	bool successfulPay = buyer->payMoney(200, NULL);
	if(successfulPay){
		std::cout << buyer->getName() << " bought " << name << " for $" << purchaseCost << std::endl;
		buyer->addBuilding(this);
	}
	else{
		std::cout << "Purchase failed" << std::endl;
	}
	//board->printCurrentStatus();
}

int Residence::totalWorth() {
	if(isMortgaged){
		return purchaseCost/2;
	}
	else{
		return purchaseCost;		
	}
}

void Residence::printBuildingInfo() {
	if(isMortgaged){
	cout << "	" << name <<" Mortgaged" << endl;

	}
	else{
	cout << "	" << name << endl;
	}
}

bool Residence::mortgage(){
	if(isMortgaged == true){
		cout << "Mortgage Failed!" << endl;
		cout << name << " is Already Mortgaged!" << endl;
		return false;
	}
	else{
		// it's only called by a player, so it must have a owner
		owner->receiveMoney(purchaseCost/2);
		isMortgaged = true;
		cout << name << " is Mortgaged, and " << owner->getName() <<" received $" << purchaseCost/2 << endl;
		return true;
	}
}

bool Residence::unmortgage(){
 	if(isMortgaged == false){
		cout << name << "Unmortgage Failed!" << endl;
		cout << name << " is Not Mortgaged!" << endl;
		return false;
	}
	else{
		// it's only called by a player, so it must have a owner
		int cost;
		cost = purchaseCost/2+purchaseCost/10;
		if (owner->payMoney(cost, NULL)){
			isMortgaged = false;
			cout << name << " is Unmortgaged, and " << owner->getName() <<" Paid $" << cost << endl;
			return true;
		}
		else{
			cout << name << "Unmortgage Failed! Fail to Pay!" << endl;
			return false;
		}
	}
 }

void Residence::getReadyAuction(){
	isMortgaged = false;
	owner = NULL;
}

int Residence::getNumImproved() {
	return 0;
}

bool Residence::buyImprove(){
	cout << "Cannot Buy Improvement For Residences!!" << endl;
	return false;
}

bool Residence::sellImprove(){
	cout << "Cannot Sell Improvement For Residences!!" << endl;
	return false;
}
void Residence::setMonopolyStatus(){}






