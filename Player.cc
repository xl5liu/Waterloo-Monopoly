#include "Player.h"
#include "Building.h"
#include "Board.h"
#include <iostream> 
using namespace std;

Player::Player(string name, const char character, int playerIndex, Board *board): board(board), name(name), character(character), playerIndex(playerIndex) {
	bankruptcy = false;
	inJail = false;
	jailDays = 0;
	rollUpNum = 0;
	money = 1500;
	location = 20;
	numBuildingsOwned = 0;
	amountOwed = 0;
	debtOwner = NULL;
	for(int i = 0; i < 28; i++) {
		buildingsOwned[i] = NULL;
	}
}




Player::~Player() {}


bool Player::payMoney(int amount, Player * receiver) {
	if (receiver == NULL){
		if(money >= amount){
			money -= amount;
			cout << name << " paid School " << "$" << amount << "." <<endl;
			return true; 
		}
		else{
			return false;
		}
	}
	else{
		if(money >= amount){
			money -= amount;
			receiver->receiveMoney(amount);
			cout << name << " paid " << receiver->name << " $" << amount << "." <<endl;
			return true; 
		}
		else{
			return false;
		}
	}

}


void Player::receiveMoney(int amount) {
	money += amount;
	cout << name <<" has received $" << amount << endl;
}

bool Player::getOutJail(std::string cmd){
	if(cmd == "useRoll"){
		if (rollUpNum > 0){
			inJail = false;
			jailDays = 0;
			rollUpNum -= 1;
			return true;
		}
		else{
			cout << "You Do Not Have Any Roll Up the Rim Cups!" << endl;
			return false;
		}
	}
	else if(cmd == "pay"){
		if (money >= 50){
			bool dummy = payMoney(50,NULL);
			inJail = false;
			jailDays = 0;
			if(dummy == false){
				cout << "Something Wrong with money/payMoney" << endl;
				return false;
			}
			return true;
		}
		else{
			cout << "You Do Not Have Enough To Pay" << endl;
			return false;
		}
	}
	else if(cmd == "roll"){
		inJail = false;
		jailDays = 0;
		cout << "You Are Out of Jail By Rolling Double." << endl;
		return true;
	}
	else{
		cout << "Invalid Command/ Bug" <<endl;
		return false;
	}
}
void Player::getInJail(){
	int prevLocation = location;
	location = 30;
	inJail = true;
	board->notify(prevLocation, "removePlayer", character);
	board->notify(location, "addPlayer", character);
	board->change(prevLocation, "removePlayer", this);
	board->change(location,"addPlayer", this);
	jailDays = 1;
	cout << name << " Is In Jail" << endl;

}
void Player::addJailDays(){
	jailDays += 1;
}
int Player::getJailStatus() {
	if(inJail) {
		return 1;
	} else {
		return 0;
	}
}

int Player::getJailDays(){
	return jailDays;
}

void Player::move(int index) {
	int prevLocation = location;
	location = index;
	cout << name << " is moving" << endl;
	board->notify(prevLocation, "removePlayer", character);
	board->notify(location, "addPlayer", character);
	board->change(prevLocation, "removePlayer", this);
	board->change(location,"addPlayer", this);
	if((prevLocation < 20) && (location > 20)){
		money += 200;
		cout << name << " just passed OSAP, and collected $200." << endl;
	}
}

void Player::moveBack(int index) {
	int prevLocation = location;
	location = index;
	cout << name << " is moving" << endl;
	board->notify(prevLocation, "removePlayer", character);
	board->notify(location, "addPlayer", character);
	board->change(prevLocation, "removePlayer", this);
	board->change(location,"addPlayer", this);
}	

int Player::resOwned() {
	int counter = 0;
	for(int i = 0; i < numBuildingsOwned; i++) {
		if(buildingsOwned[i]->getName() == "V1" || buildingsOwned[i]->getName() == "REV" || 
			buildingsOwned[i]->getName() == "MKV" || buildingsOwned[i]->getName() == "UWP") {
			counter++;
		}
	}
	return counter;
}

int Player::gymOwned() {
	int counter = 0;
	for(int i = 0; i < numBuildingsOwned; i++) {
		if(buildingsOwned[i]->getName() == "CIF" || buildingsOwned[i]->getName() == "PAC") {
			counter++;
		}
	}
	return counter;
}

void Player::addBuilding(Building * building) {
	buildingsOwned[numBuildingsOwned] = building;
	numBuildingsOwned++;
	building->setOwner(this);
	building->setMonopolyStatus();
	cout << name << " Now Owns " << building->getName() << endl;
}

void Player::removeBuilding(Building * building) {
	building->setOwner(NULL);
	for(int i =0; i < numBuildingsOwned; i++) {
		if (buildingsOwned[i] == building) {
			buildingsOwned[i] = NULL;
			numBuildingsOwned--;
			for(int j = i; j < numBuildingsOwned; j++) {
				buildingsOwned[j] = buildingsOwned[j + 1];
				buildingsOwned[j+1] = NULL;
			}

			break;
		}
	}
	building->setMonopolyStatus();
}

int Player::totalWorth() {
	int worth = money;
	for(int i = 0; i < numBuildingsOwned; i++) {
		worth += buildingsOwned[i]->totalWorth();
	}
	return worth;
}

string Player::getName(){
	return name;
}

int Player::getMoney(){
	return money;
}

int Player::getLocation(){
	return location;
}

void Player::setLocation(int setting) {
	location = setting;
}


int Player::getRollUpNum(){
	return rollUpNum;
}

void Player::printBuildingsOwned(){
	if (numBuildingsOwned == 0) {
		cout << "Do Not Own Any Buildings" << endl;
	} else {
		for (int i = 0; i < numBuildingsOwned; ++i) {
			buildingsOwned[i]->printBuildingInfo();
		}
	}
}

bool Player::mortgageBuilding(std::string property){
	for (int i = 0; i < numBuildingsOwned; ++i){
		if(buildingsOwned[i]->getName() == property){
			return buildingsOwned[i]->mortgage();
			
		}
	}
	cout << "You Do Not Own " << property << endl;
	return false;
}

bool Player::unmortgageBuilding(std::string property){
	for (int i = 0; i < numBuildingsOwned; ++i){
		if(buildingsOwned[i]->getName() == property){
			return buildingsOwned[i]->unmortgage();
			
		}
	}
	cout << "You Do Not Own " << property << endl;
	return false;
}

bool Player::buyImprove(std::string property){
	for (int i = 0; i < numBuildingsOwned; ++i){
		if(buildingsOwned[i]->getName() == property){
			return buildingsOwned[i]->buyImprove();
			
		}
	}
	cout << "You Do Not Own " << property << endl;
	return false;
}

bool Player::sellImprove(std::string property){
	for (int i = 0; i < numBuildingsOwned; ++i){
		if(buildingsOwned[i]->getName() == property){
			return buildingsOwned[i]->sellImprove();
			
		}
	}
	cout << "You Do Not Own " << property << endl;
	return false;
}

int Player::getAmountOwed(){
	return amountOwed;
}

Player *Player::getDebtOwner(){
	return debtOwner;
}

void Player::setMortgage(std::string name) {
	for (int i = 0; i < numBuildingsOwned; ++i)
	{
		if(buildingsOwned[i]->getName() == name) {
			buildingsOwned[i]->setMortgaged(true);
			break;
		}
	}
}

void Player::setInJail(int setting) {
	inJail = setting;
}

void Player::setRollUpNum(int setting) {
	rollUpNum = setting;
}

void Player::setMoney(int setting) {
	money = setting;
}

void Player::setAmountOwed(int owe){
	amountOwed = owe;
}

void Player::setDebtOwner( Player *debter){
	debtOwner = debter;
}
void Player::goBankrupt(Player *receiver){
	if(receiver == NULL){
		for (int i = 0; i < numBuildingsOwned; ++i){
			buildingsOwned[i]->getReadyAuction();
			board->auction(buildingsOwned[i], true);
		}
		rollUpNum = 0;
	}
	else{
		receiver->setMoney(receiver->getMoney() + money);
		receiver->setRollUpNum(rollUpNum + receiver->getRollUpNum());
		for (int i = 0; i < numBuildingsOwned; ++i){
			buildingsOwned[i]->setOwner(receiver);
			receiver->addBuilding(buildingsOwned[i]);
			if(buildingsOwned[i]->getMortgaged()){
				char response;
				cout << "Does "<< receiver->getName() << " Want To Unmortgage Now To Avoid An Addtional 10 Percent Unmortgaging Cost Later? (y/n)" <<endl;
				while(cin >> response){
					if (response == 'y'){
						buildingsOwned[i]->unmortgage();
						break;
					}
					else if(response == 'n') {
						int moneyOwning = buildingsOwned[i]->getPurchaseCost()/10;
						bool successfulPay = receiver->payMoney(moneyOwning, NULL);
						if(!successfulPay){
							receiver->setDebtOwner(NULL);
							receiver->setAmountOwed(moneyOwning);
							cout << "Paying Failed!" << " Now Owing $" << moneyOwning << " To School!" << endl;
						}
						break;
					}
					else{
						cout << "Invalid Input!" <<endl;
					}
				}
			}

		}
	}
}

char Player::getCharacter(){
	return character;
}

int Player::getPlayerIndex(){
	return playerIndex;
}

void Player::setPlayerIndex(int setting){
	 playerIndex = setting;
}
void Player::setBankruptcy(bool setting){
	bankruptcy = setting;
}
bool Player::getBankruptcy(){
	return bankruptcy;
}

Building *Player::getBuilding(string building){
	Building *pointer = NULL;
	for (int i = 0; i < numBuildingsOwned; ++i){
		if(buildingsOwned[i]->getName() == building){
			pointer = buildingsOwned[i];
		}
	}
	return pointer;
}

bool Player::trade(Player *responder, Building *buildingGive, Building *buildingRecieve){

	if (buildingGive->getMortgaged()){
		cout << "Please Note That " << buildingGive->getName() << " Is Mortgaged!" << endl;
	}
	cout << "Checked building is mortgaged or not" << endl;
	if (buildingRecieve->getMortgaged()){
		cout << "Please Note That "<<  buildingRecieve->getName() << " Is Mortgaged!" << endl;
	}
	cout << responder->getName() << ", Would You Like To Accept This Trade? (accept/reject)" << endl;
	string response;
	while (cin >> response){
		if(response == "accept"){
			cout << "Trade Accepted" << endl;

			this->removeBuilding(buildingGive);
			responder->addBuilding(buildingGive);
			if(buildingGive->getMortgaged()){
				char response;
				cout << "Does "<< responder->getName() << " Want To Unmortgage Now To Avoid An Addtional 10 Percent Unmortgaging Cost Later? (y/n)" <<endl;
				while(cin >> response){
					if (response == 'y'){
						buildingGive->unmortgage();
						break;
					}
					else if(response == 'n') {
						int moneyOwning = buildingGive->getPurchaseCost()/10;
						bool successfulPay = responder->payMoney(moneyOwning, NULL);
						if(!successfulPay){
							responder->setDebtOwner(NULL);
							responder->setAmountOwed(moneyOwning);
							cout << "Paying Failed!" << " Now Owing $" << moneyOwning << " To School!" << endl;
						}
						break;
					}
					else{
						cout << "Invalid Input!" <<endl;
					}
				}
			}
			

			responder->removeBuilding(buildingRecieve);
			this->addBuilding(buildingRecieve);
			if(buildingRecieve->getMortgaged()){
				char response;
				cout << "Does "<< this->getName() << " Want To Unmortgage Now To Avoid An Addtional 10 Percent Unmortgaging Cost Later? (y/n)" <<endl;
				while(cin >> response){
					if (response == 'y'){
						buildingRecieve->unmortgage();
						break;
					}
					else if(response == 'n') {
						int moneyOwning = buildingRecieve->getPurchaseCost()/10;
						bool successfulPay = this->payMoney(moneyOwning, NULL);
						if(!successfulPay){
							debtOwner = NULL;
							amountOwed = moneyOwning;
							cout << "Paying Failed!" << " Now Owing $" << moneyOwning << " To School!" << endl;
						}
						break;
					}
					else{
						cout << "Invalid Input!" <<endl;
					}
				}
			}
			return true;
		}
		else if (response == "reject" ){
			cout << "Trade Rejected!" << endl;
			return false;
		}
		else{
			cout << "Invalid Response!" << endl;
		}
	}
	return false;
}

bool Player::trade(Player *responder, int amountGive , Building *buildingRecieve){
	if (buildingRecieve->getMortgaged()){
		cout << "Please Note That " << buildingRecieve->getName() << " Is Mortgaged!" << endl;
	}
	cout << responder->getName() << ", Would You Like To Accept This Trade? (accept/reject)" << endl;
	string response;
	while (cin >> response){
		if(response == "accept"){
			cout << "Trade Accepted" << endl;

			money -= amountGive;
			responder->setMoney(responder->getMoney() + amountGive);

			responder->removeBuilding(buildingRecieve);
			this->addBuilding(buildingRecieve);
			if(buildingRecieve->getMortgaged()){
				char response;
				cout << "Does "<< name << " Want To Unmortgage Now To Avoid An Addtional 10 Percent Unmortgaging Cost Later? (y/n)" <<endl;
				while(cin >> response){
					if (response == 'y'){
						buildingRecieve->unmortgage();
						break;
					}
					else if(response == 'n') {
						int moneyOwning = buildingRecieve->getPurchaseCost()/10;
						bool successfulPay = this->payMoney(moneyOwning, NULL);
						if(!successfulPay){
							debtOwner = NULL;
							amountOwed = moneyOwning;
							cout << "Paying Failed!" << " Now Owing $" << moneyOwning << " To School!" << endl;
						}
						break;
					}
					else{
						cout << "Invalid Input!" <<endl;
					}
				}
			}
			return true;

		}
		else if (response == "reject" ){
			cout << "Trade Rejected!" << endl;
			return false;
		}
		else{
			cout << "Invalid Response!" << endl;
		}
	}
	return false;

}

bool Player::trade(Player *responder, Building *buildingGive, int amountReceive){
	if (buildingGive->getMortgaged()){
		cout << "Please Note That " << buildingGive->getName() << " Is Mortgaged!" << endl;
	}
	cout << responder->getName() << ", Would You Like To Accept This Trade? (accept/reject)" << endl;
	string response;
	while (cin >> response){
		if(response == "accept"){
			cout << "Trade Accepted" << endl;

			money += amountReceive;
			responder->setMoney(responder->getMoney() - amountReceive);

			this->removeBuilding(buildingGive);
			responder->addBuilding(buildingGive);
			if(buildingGive->getMortgaged()){
				char response;
				cout << "Does "<< name << " Want To Unmortgage Now To Avoid An Addtional 10 Percent Unmortgaging Cost Later? (y/n)" <<endl;
				while(cin >> response){
					if (response == 'y'){
						buildingGive->unmortgage();
						break;
					}
					else if(response == 'n') {
						int moneyOwning = buildingGive->getPurchaseCost()/10;
						bool successfulPay = responder->payMoney(moneyOwning, NULL);
						if(!successfulPay){
							responder->setDebtOwner(NULL);
							responder->setAmountOwed(moneyOwning);
							cout << "Paying Failed!" << " Now Owing $" << moneyOwning << " To School!" << endl;
						}
						break;
					}
					else{
						cout << "Invalid Input!" <<endl;
					}
				}
			}
			return true;

		}
		else if (response == "reject" ){
			cout << "Trade Rejected!" << endl;
			return false;
		}
		else{
			cout << "Invalid Response!" << endl;
		}
	}
	return false;
}






