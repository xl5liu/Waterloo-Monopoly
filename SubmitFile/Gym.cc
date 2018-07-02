#include "Gym.h"
#include "Board.h"
#include "Player.h"
using namespace std;


Gym::Gym(int index,std::string name, Board *board, const int purchaseCost):Building(index,name,board,purchaseCost){
}

Gym::~Gym(){}

void Gym::pay(Player *payer){
	board->rollDice();
	int dice1 = board->getDice1();
 	int dice2 = board->getDice2();
 	int sum = dice1 + dice2;
 	int moneyOwning = 0;
 	bool successfulPay = false;

	if (owner->gymOwned() == 1){
		std::cout << payer->getName() << " is paying " << owner->getName() << std::endl;
		moneyOwning = 4*sum;
		successfulPay = payer->payMoney(moneyOwning, owner);
	}
	else if (owner->gymOwned() == 2){
		std::cout << payer->getName() << " is paying " << owner->getName() << std::endl;
		moneyOwning = 10*sum;
		successfulPay = payer->payMoney(moneyOwning, owner);
	}
	if(!successfulPay){
		payer->setDebtOwner(owner);
		payer->setAmountOwed(moneyOwning);
		cout << "Paying Failed!" << " Now Owing $" << moneyOwning << " To " << owner->getName() << endl;
	}
	//board->printCurrentStatus();

}

void Gym::buy(Player *buyer){
	std::cout << buyer->getName() << " is buying " << name << std::endl;
	bool successfulPay = buyer->payMoney(150, NULL);
	if(successfulPay){
		std::cout << buyer->getName() << " bought " << name << " for $" << purchaseCost << std::endl;
		buyer->addBuilding(this);
	}
	else{
		std::cout << "Purchase failed" << std::endl;
	}
	//board->printCurrentStatus();
}

int Gym::totalWorth() {
	if(isMortgaged){
		return purchaseCost/2;
	}
	else{
		return purchaseCost;		
	}
}

void Gym::printBuildingInfo() {
	if(isMortgaged){
	cout << "	" << name <<" Mortgaged" << endl;

	}
	else{
	cout << "	" << name << endl;
	}
}

bool Gym::mortgage(){
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
bool Gym::unmortgage(){
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

void Gym::getReadyAuction(){
	isMortgaged = false;
	owner = NULL;
}

int Gym::getNumImproved() {
	return 0;
}

bool Gym::buyImprove(){
	cout << "Cannot Buy Improvement For Gyms!!" << endl;
	return false;
}

bool Gym::sellImprove(){
	cout << "Cannot Sell Improvement For Gyms!!" << endl;
	return false;
}

void Gym::setMonopolyStatus(){}

