#include "AcademicBuilding.h"
#include "Player.h"
#include "Department.h"
#include "Board.h"
using namespace std;

AcademicBuilding::AcademicBuilding(int index,std::string name, Board *board, Department *department, 
				 const int purchaseCost, const int improvementCost,
				 int t0, int t1, int t2, int t3, int t4, int t5): 
				 Building(index,name,board,purchaseCost), improvementCost(improvementCost),
				 department(department) {
				 	tuitionWithImprov[0] = t0;
				 	tuitionWithImprov[1] = t1;
				 	tuitionWithImprov[2] = t2;
				 	tuitionWithImprov[3] = t3;
				 	tuitionWithImprov[4] = t4;
				 	tuitionWithImprov[5] = t5;
				 	numImproved = 0;
				 	inMonopoly = false;
				 	department->addMember(this);

}


AcademicBuilding::~AcademicBuilding(){}

void AcademicBuilding::setMonopolyStatus(){
	department->setMonopolyStatus();
}

void AcademicBuilding::pay(Player *payer){
	bool successfulPay = false;
	int moneyOwning = 0;
	if(numImproved == 0){
		if (inMonopoly == false) {
			std::cout << payer->getName() << " is paying " << owner->getName() << std::endl;
			moneyOwning = tuitionWithImprov[0];
			successfulPay = payer->payMoney(moneyOwning, owner);
		} else {
			std::cout << payer->getName() << " is paying " << owner->getName() << std::endl;
			moneyOwning = tuitionWithImprov[0]*2;
			successfulPay = payer->payMoney(moneyOwning, owner);
		}
	}
	else{
		std::cout << payer->getName() << " is paying " << owner->getName() << std::endl;
		moneyOwning = tuitionWithImprov[numImproved];
		successfulPay = payer->payMoney(tuitionWithImprov[numImproved], owner);
	}
	if(!successfulPay){
		payer->setDebtOwner(owner);
		payer->setAmountOwed(moneyOwning);
		cout << "Paying Failed!" << " Now Owing $" << moneyOwning << " To " << owner->getName() << endl;
	}
	//board->printCurrentStatus();
}
void AcademicBuilding::buy(Player *buyer){
	std::cout << buyer->getName() << " is buying " << name << std::endl;
	bool successfulPay= buyer->payMoney(purchaseCost, NULL);
	if (successfulPay == true) {
		std::cout << buyer->getName() << " bought " << name << " for $" << purchaseCost << std::endl;
		buyer->addBuilding(this);
		department->setMonopolyStatus();
	} else {
		std::cout << "Purchase failed" << std::endl;
	}
	//board->printCurrentStatus();
}

bool AcademicBuilding::getMonopoly(){
	return inMonopoly;
}
void AcademicBuilding::setMonopoly(bool setting){
	inMonopoly = setting;
}

int AcademicBuilding::totalWorth() {
		int worth = 0;
	if(isMortgaged){
		worth = purchaseCost/2;
	}
	else{
		worth = purchaseCost + (improvementCost * numImproved);
	}
	return worth;
}

int AcademicBuilding::getNumImproved() {
	return numImproved;
}

void AcademicBuilding::setNumImproved(int setting) {
	numImproved = setting;
}

void AcademicBuilding::printBuildingInfo() {
	if(isMortgaged){
		cout << "	" << name << ": " << numImproved << " Improvements" << " Mortgaged" << endl;

	}
	else{
		cout << "	" << name << ": " << numImproved << " Improvements" << endl;
	}
}

bool AcademicBuilding::mortgage(){
	if(isMortgaged == true){
		cout << "Mortgage Failed!" << endl;
		cout << name << " is Already Mortgaged!" << endl;
		return false;
	}
	else if(inMonopoly){
		cout << "inMonopoly" << endl;
		if(department->anyImprove() && (numImproved == 0)){
			cout << "Mortgage Failed!" << endl;
			cout << "You Need to Sell The Improvements On Other Buildings In This Monopoly Block!" << endl;
			return false;	
		}
		else if(numImproved > 0){
			cout << "Mortgage Failed!" << endl;
			cout << "You Need to Sell Improvements On This Building!" << endl;
			return false;	
		}
		else{
			cout << numImproved << endl;
			owner->receiveMoney(purchaseCost/2);
			isMortgaged = true;
			department->setMonopolyStatus();
			cout << name << " is Mortgaged, and " << owner->getName() <<" received $" << purchaseCost/2 << endl;
			return true;
		}
	}
	else{
		// it's only called by a player, so it must have a owner
		owner->receiveMoney(purchaseCost/2);
		isMortgaged = true;
		cout << name << " is Mortgaged, and " << owner->getName() <<" received $" << purchaseCost/2 << endl;
		return true;
	}
}

bool AcademicBuilding::unmortgage(){
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
			department->setMonopolyStatus();
			return true;
		}
		else{
			cout << name << "Unmortgage Failed! Fail to Pay!" << endl;
			return false;
		}
	}
 }

void AcademicBuilding::getReadyAuction(){
	owner = NULL;
	isMortgaged = false;
	numImproved = 0;
}

bool AcademicBuilding::buyImprove(){
	if(!inMonopoly){
		cout << "Cannot Buy Improvements Until You Own All Buildings In This Monopoly Block" << endl;
		return false;
	}
	else if(isMortgaged){
		cout << name << " Is Mortgaged, Unable To Buy Improvements!" << endl;
		return false;
	}
	else if (numImproved == 5){
		cout << "Your Bulding Already Has A Working Wireless Access Point(WAP), It Can Not Be Improved Further." << endl;
		return false;
	}
	else {
		bool successfulPay = owner->payMoney(improvementCost, NULL);
		if(successfulPay){
			numImproved += 1;
			board->notify(index, "addImprovement", 'I');
			cout << "Improvement Succeeds! " << name << " Now Has " << numImproved << " Improvements!" << endl;
			return true;
		}

		else{
			cout << "Payment Failed, Unable To Buy Improvements!" << endl;
			return false;
		}
	}
}
bool AcademicBuilding::sellImprove(){
	if(isMortgaged == true){
		cout << name << " Is Mortgaged, It Does Not Have Any Improvement To Sell!" << endl;
		return false;	
	}
	else if(numImproved == -1){
		cout << name << " Is Mortgaged, It Does Not Have Any Improvement To Sell! (numImproved == -1) && (isMortgaged == false)" << endl;
		return false;	
	}
	else if(numImproved == 0){
		cout << name << " Does Not Have Any Improvement To Sell!" << endl;
		return false;
	}
	else if((numImproved > 0) && (numImproved <= 5)){
		numImproved -= 1;
		board->notify(index, "removeImprovement", 'I');
		owner->receiveMoney(improvementCost/2);
		cout << "1 Improvement Sold! " << name << " Now Has " << numImproved << " Improvements!" << endl;
		return true;
	}
	else{
		cout << "Something Wrong With numImproved in " << name << "!" <<endl;
		return false;
	}
}


