#include "Board.h"
#include "Controller.h"
#include "Player.h"
#include "Department.h"
#include "Square.h"
#include "AcademicBuilding.h"
#include "Residence.h"
#include "Gym.h"
#include "OSAP.h"
#include "DCTimsLine.h"
#include "GoToTims.h"
#include "GooseNesting.h"
#include "Tuition.h"
#include "CoopFee.h"
#include "SLC.h"
#include "NeedlesHall.h"
#include "Building.h"
#include <iostream>
#include <string>
#include <cstdlib>
#include <ctime>
#include <fstream>
#include <sstream>
using namespace std;

Board::Board(){

	departmentList[0] = new Department(2, "Arts1");
	departmentList[1] = new Department(3, "Arts2");
	departmentList[2] = new Department(3, "Eng");
	departmentList[3] = new Department(3, "Health");
	departmentList[4] = new Department(3, "Env");
	departmentList[5] = new Department(3, "Sci1");
	departmentList[6] = new Department(3, "Sci2");
	departmentList[7] = new Department(2, "Math");
	
	theGrid[0] = new GooseNesting(0, this);

	theGrid[1] = new AcademicBuilding(1, "EV1", this, departmentList[4], 220, 150, 18, 90, 250, 700, 875, 1050);

	theGrid[2] = new NeedlesHall(2, this);

	theGrid[3] = new AcademicBuilding(3, "EV2", this, departmentList[4], 220, 150, 18, 90, 250, 700, 875, 1050);

	theGrid[4] = new AcademicBuilding(4, "EV3", this, departmentList[4], 240, 150, 20, 100, 300, 750, 925, 1100);

	theGrid[5] = new Residence(5, "V1", this, 200);

	theGrid[6] = new AcademicBuilding(6, "PHYS", this, departmentList[5], 260, 150, 22, 110, 330, 800, 975, 1150);

	theGrid[7] = new AcademicBuilding(7, "B1", this, departmentList[5], 260, 150, 22, 110, 330, 800, 975, 1150);

	theGrid[8] = new Gym(8,"CIF",this, 150);

	theGrid[9] = new AcademicBuilding(9, "B2", this, departmentList[5], 280, 150, 24, 120, 360, 850, 1025, 1200);

	theGrid[10] = new GoToTims(10, this);

	theGrid[11] = new AcademicBuilding(11, "EIT", this, departmentList[6], 300, 200, 26, 130, 390, 900, 1100, 1275);

	theGrid[12] = new AcademicBuilding(12, "ESC", this, departmentList[6], 300, 200, 26, 130, 390, 900, 1100, 1275);

	theGrid[13] = new SLC(13, this);

	theGrid[14] = new AcademicBuilding(14, "C2", this, departmentList[6], 320, 200, 28, 150, 450, 1000, 1200, 1400);

	theGrid[15] = new Residence(15, "REV", this, 200);

	theGrid[16] = new NeedlesHall(16, this);

	theGrid[17] = new AcademicBuilding(17, "MC", this, departmentList[7], 350, 200, 35, 175, 500, 1100, 1300, 1500);

	theGrid[18] = new CoopFee(18, this);

	theGrid[19] = new AcademicBuilding(19, "DC", this, departmentList[7], 400, 200, 50, 200, 600, 1400, 1700, 2000);

	theGrid[20] = new OSAP(20, this);

	theGrid[21] = new AcademicBuilding(21, "AL", this, departmentList[0], 40, 50, 2, 10, 30, 90, 160, 250);

	theGrid[22] = new SLC(22, this);

	theGrid[23] = new AcademicBuilding(23, "ML", this, departmentList[0], 60, 50, 4, 20, 60, 180, 320, 450);

	theGrid[24] = new Tuition(24, this);

	theGrid[25] = new Residence(25, "MKV", this, 200);

	theGrid[26] = new AcademicBuilding(26, "ECH", this, departmentList[1], 100, 50, 6, 30, 90, 270, 400, 550);

	theGrid[27] = new NeedlesHall(27, this);

	theGrid[28] = new AcademicBuilding(28, "PAS", this, departmentList[1], 100, 50, 6, 30, 90, 270, 400, 550);

	theGrid[29] = new AcademicBuilding(29, "HH", this, departmentList[1], 120, 50, 8, 40, 100, 300, 450, 600);

	theGrid[30] = new DCTimsLine(30, this);

	theGrid[31] = new AcademicBuilding(31, "RCH", this, departmentList[2], 140, 100, 10, 50, 150, 450, 625,750);

	theGrid[32] = new Gym(32,"PAC", this, 150);

	theGrid[33] = new AcademicBuilding(33, "DWE", this, departmentList[2], 140, 100, 10, 50, 150, 450, 625, 750);

	theGrid[34] = new AcademicBuilding(34, "CPH", this, departmentList[2], 160, 100, 12, 60, 180, 500, 700, 900);

	theGrid[35] = new Residence(35, "UWP", this, 200);

	theGrid[36] = new AcademicBuilding(36, "LHI", this, departmentList[3], 180, 100, 14, 70, 200, 550, 750, 950);

	theGrid[37] = new SLC(37, this);

	theGrid[38] = new AcademicBuilding(38, "BMH", this, departmentList[3], 180, 100, 14, 70, 200, 550, 750, 950);

	theGrid[39] = new AcademicBuilding(39, "OPT", this, departmentList[3], 200, 100, 16, 80, 220, 600, 800, 1000);





	notification = NULL;


	for (int i = 0; i < 7; ++i){
		players[i] = NULL;
	}

	currentPlayer = NULL;
	currentPlayerIndex = 0;
	numPlayers = 0;
	rollUpLeft = 4;
	dice1 = 0;
	dice2 = 0;
	doublesInTurn = 0;
	currentPlayerRolled = false;
}

Board::~Board(){
	for (int i = 0; i < 40; ++i){
		delete theGrid[i];
	}
	for (int j = 0; j < numPlayers; ++j){
		delete players[j];
	}
	for (int k = 0; k < 8; ++k) {
		delete departmentList[k];
	}
}

void Board::init (int numPlayers, Controller *gameNotification) {
	bool avaliableG = true;
	bool avaliableB = true;
	bool avaliableD = true;
	bool avaliableP = true;
	bool avaliableS = true;
	bool avaliable$ = true;
	bool avaliableL = true;
	bool avaliableT = true;

	this->numPlayers = numPlayers;
	notification = gameNotification;
	for (int i = 0; i < numPlayers; ++i) {
		cout << "Please enter the name of Player " << i + 1 << " :" << endl;
		string inputName;
		cin >> inputName;
		cout << inputName << endl;
		cout << "Please enter the character to represent Player " << i + 1 << " on the board (G/B/D/P/S/$/L/T):" << endl;
		char inputChar;
		while (cin >> inputChar){
			if (inputChar == 'G'){
				if(avaliableG == true){
					avaliableG =false;
					break;
				}
				else{
					cout << inputChar << " Has Been Taken. Please Choose Another Character." << endl; 
				}
			}
			else if (inputChar == 'B'){
				if(avaliableB == true){
					avaliableB =false;
					break;
				}
				else{
					cout << inputChar << " Has Been Taken. Please Choose Another Character." << endl; 
				}
			}
			else if (inputChar == 'D'){
				if(avaliableD == true){
					avaliableD =false;
					break;
				}
				else{
					cout << inputChar << " Has Been Taken. Please Choose Another Character." << endl; 
				}
			}
			else if (inputChar == 'P'){
				if(avaliableP == true){
					avaliableP =false;
					break;
				}
				else{
					cout << inputChar << " Has Been Taken. Please Choose Another Character." << endl; 
				}
			}
			else if (inputChar == 'S'){
				if(avaliableS == true){
					avaliableS =false;
					break;
				}
				else{
					cout << inputChar << " Has Been Taken. Please Choose Another Character." << endl; 
				}
			}
			else if (inputChar == '$'){
				if(avaliable$ == true){
					avaliable$ =false;
					break;
				}
				else{
					cout << inputChar << " Has Been Taken. Please Choose Another Character." << endl; 
				}
			}
			else if (inputChar == 'L'){
				if(avaliableL == true){
					avaliableL =false;
					break;
				}
				else{
					cout << inputChar << " Has Been Taken. Please Choose Another Character." << endl; 
				}
			}
			else if (inputChar == 'T'){
				if(avaliableT == true){
					avaliableT =false;
					break;
				}
				else{
					cout << inputChar << " Has Been Taken. Please Choose Another Character." << endl; 
				}
			}
			else{
				cout << "Invalid Character" << endl;
			}
		}
		cout << inputChar << endl;
		players[i] = new Player(inputName, inputChar, i, this);
		notify(20, "addPlayer", inputChar);
	}
	currentPlayer = players[0];
	currentPlayerIndex = 0;

}

void Board::change(int index, string cmd, Player* player) {
	if(cmd == "removePlayer") {
		theGrid[index]->removePlayer(player);
	} else if (cmd == "addPlayer") {
		theGrid[index]->addPlayer(player);
	}

}

void Board::notify(int index, string cmd, char player) {
	notification->notify(index, cmd, player);
}

void Board::next() {
	if (currentPlayer->getAmountOwed() != 0){
		cout << "You Owe: $"<< currentPlayer->getAmountOwed() << ". You Cannot Proceed Until You Have Paid Your Debt!" << endl;
	}
	else{
		if(currentPlayerIndex == (numPlayers - 1)) {
			currentPlayerIndex = 0;
			currentPlayer = players[currentPlayerIndex];
		} else {
			currentPlayerIndex++;
			currentPlayer = players[currentPlayerIndex];
		}
		currentPlayerRolled = false;
		doublesInTurn = 0;
	}
}

Player *Board::getCurrentPlayer(){
	return currentPlayer;
}

void Board::rollDice(){
	srand(time(NULL));
	dice1 = (rand() % 6) + 1;
	dice2 = (rand() % 6) + 1;
}

void Board::roll() {

	if(currentPlayer->getJailStatus()){
		if (currentPlayer->getJailDays() == 2){

			rollDice();
			int sumOfRoll = dice1 + dice2;
			cout << "First Dice: " << dice1 << " ...Second Dice: " << dice2 << " ...Total rolled: " << sumOfRoll << "!" << endl;

			if(dice1 == dice2){
				bool outJail = currentPlayer->getOutJail("roll");
				int sumOfRoll = dice1 + dice2;
				int newLocation = currentPlayer->getLocation() + sumOfRoll;
				if(dice1 == dice2){
					doublesInTurn += 1;
				}else{
					currentPlayerRolled = true;
				}
				if(newLocation >= 40) {
					currentPlayer->move(newLocation - 40);
				} else {
					currentPlayer->move(newLocation);
				}
				cout << currentPlayer->getName() << " has moved to " << theGrid[currentPlayer->getLocation()]->getName() << endl;
				theGrid[currentPlayer->getLocation()]->autoAction(currentPlayer);
			}
			else{
				if(currentPlayer->getMoney() < 50){
					if(currentPlayer->getRollUpNum() == 0){
						bool successfulPay = currentPlayer->payMoney(50, NULL);
						if(!successfulPay){
							currentPlayer->setDebtOwner(NULL);
							currentPlayer->setAmountOwed(50);
							cout << "Paying Failed!" << " Now Owing $" << 50 << " To School" << endl;
						}
					}
					else{
						bool dummy = currentPlayer->getOutJail("useRoll");
						int sumOfRoll = dice1 + dice2;
						int newLocation = currentPlayer->getLocation() + sumOfRoll;
						if(dice1 == dice2){
							doublesInTurn += 1;
						}else{
							currentPlayerRolled = true;
						}
						if(newLocation >= 40) {
							currentPlayer->move(newLocation - 40);
						} else {
							currentPlayer->move(newLocation);
						}
						cout << currentPlayer->getName() << " has moved to " << theGrid[currentPlayer->getLocation()]->getName() << endl;
						theGrid[currentPlayer->getLocation()]->autoAction(currentPlayer);
					}
						return;	
				}
				else if (currentPlayer->getRollUpNum() == 0){
					cout << "You Must Pay To Get Out Of Jail Now" <<endl;
					bool dummy = currentPlayer->getOutJail("pay");
					int sumOfRoll = dice1 + dice2;
					int newLocation = currentPlayer->getLocation() + sumOfRoll;

						currentPlayerRolled = true;

					if(newLocation >= 40) {
						currentPlayer->move(newLocation - 40);
					} else {
						currentPlayer->move(newLocation);
					}
					cout << currentPlayer->getName() << " has moved to " << theGrid[currentPlayer->getLocation()]->getName() << endl;
					theGrid[currentPlayer->getLocation()]->autoAction(currentPlayer);

				}
				else{
					cout << "You Must Pay or Use A Roll Up The Rim Cup!(pay/useCup)" << endl;
					string response;
					while(cin>>response){
						if (response == "pay"){
							bool dummy = currentPlayer->getOutJail("pay");
							int sumOfRoll = dice1 + dice2;
							int newLocation = currentPlayer->getLocation() + sumOfRoll;

								currentPlayerRolled = true;

							if(newLocation >= 40) {
								currentPlayer->move(newLocation - 40);
							} else {
								currentPlayer->move(newLocation);
							}
							cout << currentPlayer->getName() << " has moved to " << theGrid[currentPlayer->getLocation()]->getName() << endl;
							theGrid[currentPlayer->getLocation()]->autoAction(currentPlayer);
						}
						else if(response == "useCup"){
							bool dummy = currentPlayer->getOutJail("useRoll");
							int sumOfRoll = dice1 + dice2;
							int newLocation = currentPlayer->getLocation() + sumOfRoll;
							if(dice1 == dice2){
								doublesInTurn += 1;
							}else{
								currentPlayerRolled = true;
							}
							if(newLocation >= 40) {
								currentPlayer->move(newLocation - 40);
							} else {
								currentPlayer->move(newLocation);
							}
							cout << currentPlayer->getName() << " has moved to " << theGrid[currentPlayer->getLocation()]->getName() << endl;
							theGrid[currentPlayer->getLocation()]->autoAction(currentPlayer);
						}
						else{
							cout << "Invalid Response!" <<endl;
						}
					}
				}
			}

		}
		else {
			cout << "Would You Like To Pay Or Use Roll Up The Rim Cup? (pay/useCup/no)" << endl;
		string answer;
		bool outJail = false;
		while(cin>>answer){
			if (answer == "pay"){
				outJail = currentPlayer->getOutJail("pay");
				break;
			}
			else if(answer == "useCup"){
				outJail = currentPlayer->getOutJail("useRoll");
				break;
			}
			else if(answer == "no"){
				rollDice();
				int sumOfRoll = dice1 + dice2;
				cout << "First Dice: " << dice1 << " ...Second Dice: " << dice2 << " ...Total rolled: " << sumOfRoll << "!" << endl;
				if(dice1 == dice2){
					outJail = currentPlayer->getOutJail("roll");
					currentPlayerRolled = true;
				}
				else{
					outJail = false;
					currentPlayerRolled = true;
				}
				break;
			}
			else {
				cout << "Invalid Response" << endl;
			}
		}
		if(outJail){
			if (currentPlayerRolled){
				int sumOfRoll = dice1 + dice2;
				int newLocation = currentPlayer->getLocation() + sumOfRoll;
				if(dice1 == dice2){
					doublesInTurn += 1;
				}else{
					currentPlayerRolled = true;
				}
				if(newLocation >= 40) {
					currentPlayer->move(newLocation - 40);
				} else {
					currentPlayer->move(newLocation);
				}
				cout << currentPlayer->getName() << " has moved to " << theGrid[currentPlayer->getLocation()]->getName() << endl;
				theGrid[currentPlayer->getLocation()]->autoAction(currentPlayer);
			}
			else{
				rollDice();
				int sumOfRoll = dice1 + dice2;
				int newLocation = currentPlayer->getLocation() + sumOfRoll;

				if(dice1 == dice2){
					doublesInTurn += 1;
				}else{
					currentPlayerRolled = true;
				}

				if(doublesInTurn == 3){
					currentPlayer->getInJail();
					return;
				}

				if(newLocation >= 40) {
					currentPlayer->move(newLocation - 40);
				} else {
					currentPlayer->move(newLocation);
				}
				cout << "First Dice: " << dice1 << " ...Second Dice: " << dice2 << " ...Total rolled: " << sumOfRoll << "!" << endl;
				cout << currentPlayer->getName() << " has moved to " << theGrid[currentPlayer->getLocation()]->getName() << endl; 
				
				theGrid[currentPlayer->getLocation()]->autoAction(currentPlayer);
			}
		}else{
			currentPlayer->addJailDays();
			currentPlayerRolled = true;
		}
		}
		
	}
	else{
		rollDice();
		int sumOfRoll = dice1 + dice2;
		int newLocation = currentPlayer->getLocation() + sumOfRoll;

		if(dice1 == dice2){
			doublesInTurn += 1;
		}else{
			currentPlayerRolled = true;
		}

		if(doublesInTurn == 3){
			currentPlayer->getInJail();
			return;
		}

		if(newLocation >= 40) {
			currentPlayer->move(newLocation - 40);
		} else {
			currentPlayer->move(newLocation);
		}
		cout << "First Dice: " << dice1 << " ...Second Dice: " << dice2 << " ...Total rolled: " << sumOfRoll << "!" << endl;
		cout << currentPlayer->getName() << " has moved to " << theGrid[currentPlayer->getLocation()]->getName() << endl; 
		
		theGrid[currentPlayer->getLocation()]->autoAction(currentPlayer);
	}
	
}


void Board::roll(int num1 , int num2){
	dice1 = num1;
	dice2 = num2;

	if(currentPlayer->getJailStatus()){
		if (currentPlayer->getJailDays() == 2){
			int sumOfRoll = dice1 + dice2;
			cout << "First Dice: " << dice1 << " ...Second Dice: " << dice2 << " ...Total rolled: " << sumOfRoll << "!" << endl;

			if(dice1 == dice2){
				bool outJail = currentPlayer->getOutJail("roll");
				int sumOfRoll = dice1 + dice2;
				int newLocation = currentPlayer->getLocation() + sumOfRoll;
				if(dice1 == dice2){
					doublesInTurn += 1;
				}else{
					currentPlayerRolled = true;
				}
				if(newLocation >= 40) {
					currentPlayer->move(newLocation - 40);
				} else {
					currentPlayer->move(newLocation);
				}
				cout << currentPlayer->getName() << " has moved to " << theGrid[currentPlayer->getLocation()]->getName() << endl;
				theGrid[currentPlayer->getLocation()]->autoAction(currentPlayer);
			}
			else{
				if(currentPlayer->getMoney() < 50){
					if(currentPlayer->getRollUpNum() == 0){
						bool successfulPay = currentPlayer->payMoney(50, NULL);
						if(!successfulPay){
							currentPlayer->setDebtOwner(NULL);
							currentPlayer->setAmountOwed(50);
							cout << "Paying Failed!" << " Now Owing $" << 50 << " To School" << endl;
						}
					}
					else{
						bool dummy = currentPlayer->getOutJail("useRoll");
						int sumOfRoll = dice1 + dice2;
						int newLocation = currentPlayer->getLocation() + sumOfRoll;
						if(dice1 == dice2){
							doublesInTurn += 1;
						}else{
							currentPlayerRolled = true;
						}
						if(newLocation >= 40) {
							currentPlayer->move(newLocation - 40);
						} else {
							currentPlayer->move(newLocation);
						}
						cout << currentPlayer->getName() << " has moved to " << theGrid[currentPlayer->getLocation()]->getName() << endl;
						theGrid[currentPlayer->getLocation()]->autoAction(currentPlayer);
					}
						return;	
				}
				else if (currentPlayer->getRollUpNum() == 0){
					cout << "You Must Pay To Get Out Of Jail Now" <<endl;
					bool dummy = currentPlayer->getOutJail("pay");
					int sumOfRoll = dice1 + dice2;
					int newLocation = currentPlayer->getLocation() + sumOfRoll;

						currentPlayerRolled = true;

					if(newLocation >= 40) {
						currentPlayer->move(newLocation - 40);
					} else {
						currentPlayer->move(newLocation);
					}
					cout << currentPlayer->getName() << " has moved to " << theGrid[currentPlayer->getLocation()]->getName() << endl;
					theGrid[currentPlayer->getLocation()]->autoAction(currentPlayer);

				}
				else{
					cout << "You Must Pay or Use A Roll Up The Rim Cup!(pay/useCup)" << endl;
					string response;
					while(cin>>response){
						if (response == "pay"){
							bool dummy = currentPlayer->getOutJail("pay");
							int sumOfRoll = dice1 + dice2;
							int newLocation = currentPlayer->getLocation() + sumOfRoll;

								currentPlayerRolled = true;

							if(newLocation >= 40) {
								currentPlayer->move(newLocation - 40);
							} else {
								currentPlayer->move(newLocation);
							}
							cout << currentPlayer->getName() << " has moved to " << theGrid[currentPlayer->getLocation()]->getName() << endl;
							theGrid[currentPlayer->getLocation()]->autoAction(currentPlayer);
						}
						else if(response == "useCup"){
							bool dummy = currentPlayer->getOutJail("useRoll");
							int sumOfRoll = dice1 + dice2;
							int newLocation = currentPlayer->getLocation() + sumOfRoll;
							if(dice1 == dice2){
								doublesInTurn += 1;
							}else{
								currentPlayerRolled = true;
							}
							if(newLocation >= 40) {
								currentPlayer->move(newLocation - 40);
							} else {
								currentPlayer->move(newLocation);
							}
							cout << currentPlayer->getName() << " has moved to " << theGrid[currentPlayer->getLocation()]->getName() << endl;
							theGrid[currentPlayer->getLocation()]->autoAction(currentPlayer);
						}
						else{
							cout << "Invalid Response!" <<endl;
						}
					}
				}
			}

		}
		else {
			cout << "Would You Like To Pay Or Use Roll Up The Rim Cup? (pay/useCup/no)" << endl;
		string answer;
		bool outJail = false;
		while(cin>>answer){
			if (answer == "pay"){
				outJail = currentPlayer->getOutJail("pay");
				break;
			}
			else if(answer == "useCup"){
				outJail = currentPlayer->getOutJail("useRoll");
				break;
			}
			else if(answer == "no"){
				int sumOfRoll = dice1 + dice2;
				cout << "First Dice: " << dice1 << " ...Second Dice: " << dice2 << " ...Total rolled: " << sumOfRoll << "!" << endl;
				if(dice1 == dice2){
					outJail = currentPlayer->getOutJail("roll");
					currentPlayerRolled = true;
				}
				else{
					outJail = false;
					currentPlayerRolled = true;
				}
				break;
			}
			else {
				cout << "Invalid Response" << endl;
			}
		}
		if(outJail){
			if (currentPlayerRolled){
				int sumOfRoll = dice1 + dice2;
				int newLocation = currentPlayer->getLocation() + sumOfRoll;
				if(dice1 == dice2){
					doublesInTurn += 1;
				}else{
					currentPlayerRolled = true;
				}
				if(newLocation >= 40) {
					currentPlayer->move(newLocation - 40);
				} else {
					currentPlayer->move(newLocation);
				}
				cout << currentPlayer->getName() << " has moved to " << theGrid[currentPlayer->getLocation()]->getName() << endl;
				theGrid[currentPlayer->getLocation()]->autoAction(currentPlayer);
			}
			else{
				int sumOfRoll = dice1 + dice2;
				int newLocation = currentPlayer->getLocation() + sumOfRoll;

				if(dice1 == dice2){
					doublesInTurn += 1;
				}else{
					currentPlayerRolled = true;
				}

				if(doublesInTurn == 3){
					currentPlayer->getInJail();
					return;
				}

				if(newLocation >= 40) {
					currentPlayer->move(newLocation - 40);
				} else {
					currentPlayer->move(newLocation);
				}
				cout << "First Dice: " << dice1 << " ...Second Dice: " << dice2 << " ...Total rolled: " << sumOfRoll << "!" << endl;
				cout << currentPlayer->getName() << " has moved to " << theGrid[currentPlayer->getLocation()]->getName() << endl; 
				
				theGrid[currentPlayer->getLocation()]->autoAction(currentPlayer);
			}
		}else{
			currentPlayer->addJailDays();
			currentPlayerRolled = true;
		}
		}
		
	}
	else{
		int sumOfRoll = dice1 + dice2;
		int newLocation = currentPlayer->getLocation() + sumOfRoll;

		if(dice1 == dice2){
			doublesInTurn += 1;
		}else{
			currentPlayerRolled = true;
		}

		if(doublesInTurn == 3){
			currentPlayer->getInJail();
			return;
		}

		if(newLocation >= 40) {
			currentPlayer->move(newLocation - 40);
		} else {
			currentPlayer->move(newLocation);
		}
		cout << "First Dice: " << dice1 << " ...Second Dice: " << dice2 << " ...Total rolled: " << sumOfRoll << "!" << endl;
		cout << currentPlayer->getName() << " has moved to " << theGrid[currentPlayer->getLocation()]->getName() << endl; 
		
		theGrid[currentPlayer->getLocation()]->autoAction(currentPlayer);
	}


}

int Board::getDice1(){
	return dice1;
}

int Board::getDice2(){
	return dice2;
}

int Board::getNumPlayers(){
	return numPlayers;
}
bool Board::getCurrentPlayerRolled(){
	return currentPlayerRolled;
}

void Board::printCurrentStatus() {
	cout << "Current Player: " << currentPlayer->getName() << endl;
	cout << "Money: " << currentPlayer->getMoney() << endl;
}

bool Board::trade(string name, string give, string receive){
	cout << "In Trade" << endl;
	Player *proposer = currentPlayer;
	Player *responder = NULL;
	bool foundResponder = false;
	for (int i = 0; i < numPlayers; ++i){
		if(players[i]->getName() == name){
			responder = players[i];
			foundResponder = true;
			break;
		}
	}
//	cout << "set proposer and receiver" << endl;
	if(!foundResponder) {
		cout << "Invalid Name Input! Trade Failed." << endl;
		return false;
	}
	istringstream giveSS(give);
	int amountGive;
	Building *buildingGive;
	giveSS >> amountGive;
	if (giveSS.fail()){
		amountGive = -1;
		buildingGive = proposer->getBuilding(give);
		if(buildingGive == NULL){
			cout << "Trade Failed! You Cannot Give A Building That You Do Not Own!" << endl;
			return false;
		}
	}
	else{
		if (amountGive < 0){
			cout << "Trade Failed! You Cannot Give Negative Amounts!" << endl;
			return false;
		}
		if (amountGive > currentPlayer->getMoney()){
			cout << "Trade Failed! You Don't Have Enough Money To Make The Offer!" << endl;
			return false;
		}
		buildingGive = NULL;
	}
	istringstream receiveSS(receive);
	int amountReceive;
	Building *buildingReceive;
	receiveSS >> amountReceive;
	if (receiveSS.fail()){
		amountReceive = -1;
		buildingReceive = responder->getBuilding(receive);
		if(buildingReceive == NULL){
			cout << "Trade Failed! "<< name << " Does Not Have The Building That You Want To Trade!" << endl;
			return false;
		}
	}
	else{
		if (amountReceive < 0) {
			cout << "Trade Failed! You Cannot Receive Negative Amounts!" << endl;
			return false;
		}
		if (amountReceive > responder->getMoney()){
			cout << "Trade Failed! "<< name << " Does Not Have Enough Money To Trade With You!" << endl;
			return false;
		}
		buildingReceive = NULL;
	}

	//building NULL means not trading building, amount == -1 means not trading amount
	if((amountGive != -1) && (amountReceive != -1)){
		cout << "Trade Failed! Cannot Trade Money For Money!" << endl;
		return false;
	}
	else if ((buildingGive != NULL) && (buildingReceive != NULL)){
//		cout << "Going to call player trade" << endl;
		return proposer->trade(responder, buildingGive, buildingReceive);
	}
	else if ((amountGive != -1) && (buildingReceive != NULL)){
		return proposer->trade(responder, amountGive, buildingReceive);
	}
	else if ((buildingGive != NULL) && (amountReceive != -1)){
		return proposer->trade(responder, buildingGive, amountReceive);
	}
	else{
		cout << "Something Wrong With amountReceive/amountGive/buildingGive/buildingReceive" << endl; 
		return false;
	}
}

bool Board::buyImprove(std::string property){
	return currentPlayer->buyImprove(property);
}

bool Board::sellImprove(std::string property){
	return currentPlayer->sellImprove(property);
}

bool Board::mortgage(std::string property){
	return currentPlayer->mortgageBuilding(property);
}

bool Board::unmortgage(std::string property){
	return currentPlayer->unmortgageBuilding(property);
}
void Board::bankruptcy(Player *player){
	if(player->getMoney() >= player->getAmountOwed()){
		cout << "Have Enough Money For His/Her Debt; He/She CANNOT Go Bankrupt!" << endl;
		return;
	}else{
		cout << "Are You Sure You Want To Declare Bankruptcy? (y/n)" << endl;
		char response;
		cin >> response;
		if(response == 'y' ) {
			bool isCurrentPlayer =false;
			player->goBankrupt(player->getDebtOwner());
			notification->notify(player->getLocation(), "removePlayer", player->getCharacter());
			cout << player->getName() << " Has Gone Bankrupt!" << endl;
			player->setBankruptcy(true);
			if (player == currentPlayer) {
				isCurrentPlayer = true;
			}
			for (int i = 0; i < 7; ++i){
				if (players[i] == player){
					delete players[i];
					cout << "1" << endl;
					players[i] = NULL;
					for (int j = i; j < 6; ++j){	
						cout << "2" << endl;
						players[j] = players[j+1];
						cout << "3" << endl;
						if(players[j] != NULL){
							players[j]->setPlayerIndex(players[j]->getPlayerIndex() -1);
						}
					}
				}
			}
			//delete players[6];
			cout << "4" << endl;
			players[6] = NULL;
			cout << "5" << endl;
			numPlayers -= 1;
			cout << "6" << endl;
			currentPlayerRolled = false;
			if (isCurrentPlayer) {
				if(currentPlayerIndex >= numPlayers){
					currentPlayer = players[0];
					cout << "7" << endl;
					return;
				}
				else{
					currentPlayer = players[currentPlayerIndex];
					cout << "8" << endl;
					return;
				}
			} else {
				currentPlayerIndex = currentPlayer->getPlayerIndex();
			}

		} else if (response == 'n') {
			return;
		} else {
			cout << "Invalid Input" << endl;
			return;
		}
	}
}

void Board::assets(){
    	//Player Info
    	cout << currentPlayer->getName() << "'s Assets:" << endl;
    	cout << "	Cash: $" << currentPlayer->getMoney() << endl;
    	cout << "	Buildings Owned:" << endl;
    	currentPlayer->printBuildingsOwned();
    	cout << "	Number of Roll Up the Rim Cups Currently Owned: " << currentPlayer->getRollUpNum() << endl;
}

void Board::auction(Building *building, bool forBankrupt) {
	cout << "Starting Auction for " << building->getName() << endl;
	Player * activeBidders[numPlayers];
	int numActiveBidders = numPlayers;
	Player * highestBidder;
	int currentBid = 1;
	cout << "Starting Bidding Price is: $" << currentBid << endl;
	if(forBankrupt) {
		for (int i = 0; i < numPlayers; ++i) {
			if(players[i] == currentPlayer) {
				activeBidders[i] = NULL;
				continue;
			}
			activeBidders[i] = players[i];
		}
		numActiveBidders--;
	} else {
		for (int i = 0; i < numPlayers; ++i) {
			activeBidders[i] = players[i];
		}
	}
	for(int w = 0; w < numPlayers; ++w) {
		if(activeBidders[w] != NULL ) {
			highestBidder = activeBidders[w];
			break;
		}
	}
	while (numActiveBidders > 1) {
		//cout << "in while" << endl;

		for(int j = 0; j < numPlayers; ++j) {
			if(activeBidders[j] == NULL) {
				continue;
			} else if (activeBidders[j] == highestBidder) {
				continue;
			}
			cout << "Current Bidder: " << activeBidders[j]->getName() << endl;
			cout << "Current Highest Bid: $" << currentBid << endl;
			string input;
			while(true) {
				cout << "Please choose to either raise the bid, or withdraw. (Bid <amount> / Withdraw)" << endl;
				cin >> input;
				if (input == "Bid") {
					int bidAmount;
					cin >> bidAmount;
					if (bidAmount < currentBid) {
						cout << "Cannot bid lower than the current highest bid!" << endl;
					} else {
						currentBid = bidAmount;
						highestBidder = activeBidders[j];
						break;
					}
				} else if (input == "Withdraw") {
					activeBidders[j] = NULL;
					numActiveBidders--;
					break;
				} else {
					cout << "Invalid Input!" << endl;
				}
			}
		}
	}
//	cout << "Out of While" << endl;
	cout << highestBidder->getName() << " Won The Auction by Bidding $" << currentBid << endl;
	bool successfulPay = highestBidder->payMoney(currentBid, NULL);
	if(successfulPay) {
		highestBidder->addBuilding(building);
	} else {
		highestBidder->setDebtOwner(NULL);
		highestBidder->setAmountOwed(currentBid);
		while(highestBidder->getAmountOwed() != 0){
			cout << "Payment Failed!" << " Now Owing $" << currentBid << " To " << "The School!" << endl;
			cout << "You must either try to raise enough money through mortgaging properties or trading, OR declare bankruptcy." << endl;
			cout << "Please enter what you would like to do: (mortgage <property> / trade <name> <give> <receive> / bankrupt)" << endl;
			string inputCmd;
			while(cin >> inputCmd) {
				if(inputCmd == "mortgage") {
					cin >> inputCmd;
					bool successfulMortgage = highestBidder->mortgageBuilding(inputCmd);
					if(successfulMortgage) {
						Player * actualCurrentPlayer = currentPlayer;
						int actualCurrentPlayerIndex = currentPlayerIndex;
						currentPlayer = highestBidder;
						currentPlayerIndex = highestBidder->getPlayerIndex();
						payOwed();
						currentPlayer = actualCurrentPlayer;
						currentPlayerIndex = actualCurrentPlayerIndex;
						break;
					} else {
						break;
					}
				} else if (inputCmd == "trade") {
					string inputName;
					string inputGive;
					string inputReceive;
					cin >> inputName;
					cin >> inputGive;
					cin >> inputReceive;
					trade(inputName, inputGive, inputReceive);
				} else if (inputCmd == "bankrupt") {
					bankruptcy(highestBidder);

				} else {
					cout << "Invalid Input!" << endl;
				}
			}
		}
		highestBidder->addBuilding(building);
	}
}


void Board::save(std::string fileName) {
	if (currentPlayer->getAmountOwed() != 0){
		cout << "You Owe: $"<< currentPlayer->getAmountOwed() << ". You Cannot Save Until You Have Paid Your Debt!" << endl;
	} else {
		ofstream saveFile(fileName.c_str());
		saveFile << numPlayers << endl;
		for (int i = 0; i < numPlayers; ++i) {
			int convertedLocation = convertPosition(players[i]->getLocation());
			saveFile << players[i]->getName() << " " << players[i]->getCharacter() << " " << players[i]->getRollUpNum() << " " << players[i]->getMoney() << " " << convertedLocation;
			if(convertedLocation == 10) {
				saveFile << " " << players[i]->getJailStatus();
				if(players[i]->getJailStatus() == 0) {
					saveFile << endl;
				} else {
					saveFile << " " << players[i]->getJailDays() << endl;
				}
			} else {
				saveFile << endl;
			}
		}
		for (int j = 20; j < 40; ++j) {
			if(theGrid[j]->getName() != "Collect OSAP" && theGrid[j]->getName() != "SLC" && theGrid[j]->getName() != "Tuition"
				&& theGrid[j]->getName() != "Needles Hall" && theGrid[j]->getName() != "DC Tims Line") {
				Square *sp = theGrid[j];
				Building *bp = dynamic_cast<Building *>(sp);
				saveFile << bp->getName() << " ";
				if( bp->getOwner() == NULL) {
					saveFile << "BANK" << " ";
				}
				else {
					saveFile << bp->getOwner()->getName() << " ";
				}
				if(bp->getMortgaged()) {
					saveFile << "-1" << endl;
				} else {
					saveFile << bp->getNumImproved() << endl;
				}		
			}
		}
		for (int k = 0; k < 20; ++k) {
			if(theGrid[k]->getName() != "Goose Nesting" && theGrid[k]->getName() != "SLC" && theGrid[k]->getName() != "Go To Tims"
				&& theGrid[k]->getName() != "Needles Hall" && theGrid[k]->getName() != "Coop Fee") {
				Square *sp = theGrid[k];
				Building *bp = dynamic_cast<Building *>(sp);
				saveFile << bp->getName() << " ";
				if( bp->getOwner() == NULL) {
					saveFile << "BANK" << " ";
				}
				else {
					saveFile << bp->getOwner()->getName() << " ";
                }
                if(bp->getMortgaged()) {
                    saveFile << "-1" << endl;
                } else {
                    saveFile << bp->getNumImproved() << endl;
                }
			} 
		}
	}
}


int Board::convertPosition(int location) {
	if (location >= 20) {
		return location - 20;
	}
	else {
		return location + 20;
	}
}

bool Board::load(std::string fileName, Controller *gameNotification) {
	notification = gameNotification;
	ifstream inputFile(fileName.c_str());
	string inputLine;
	int inputNumPlayers;
	inputFile >> inputNumPlayers;
	numPlayers = inputNumPlayers;
	getline(inputFile, inputLine);
	for (int i = 0; i < numPlayers; ++i) {
		getline(inputFile, inputLine);
		istringstream iinputLine(inputLine);
		string inputName;
		iinputLine >> inputName;
		cout << "Player " << i + 1 << "is :" << inputName << endl;
		char inputChar;
		iinputLine >> inputChar;
		cout << "Player " << i + 1 << "is represented by " << inputChar << " on the board" << endl;
		int inputTimsCups;
		iinputLine >> inputTimsCups;
		rollUpLeft -= inputTimsCups;
		if(rollUpLeft < 0) {
			cout << "Load failed due to invalid input from the load file. Number of Tim Cups owned by all players cannot exceed 4." << endl;
			return false;
		}
		cout << "Player " << i + 1 << "has " << inputTimsCups << " Roll Up the Rim cups" << endl;
		int inputMoney;
		iinputLine >> inputMoney;
		cout << "Player " << i + 1 << "has $" << inputMoney << endl;
		int inputPosition;
		iinputLine >> inputPosition;
		inputPosition = convertPosition(inputPosition);
		if(inputPosition == 10) {
			cout << "Load failed due to invalid input from the load file. Player cannot start on the square Go to DC Tims Line " << endl;
			return false;
		}
		cout << "Player " << i + 1 << "is at " <<  theGrid[inputPosition]->getName() << endl;
		players[i] = new Player(inputName, inputChar, inputPosition, this);
		players[i]->setLocation(inputPosition);
		players[i]->setRollUpNum(inputTimsCups);
		players[i]->setMoney(inputMoney);

		if(inputPosition == 30) {
			int onTimsLine;
			iinputLine >> onTimsLine;
			if(onTimsLine == 0){
				cout << "Player is not in Tim's Line" << endl;
			} else {
				int inputNumDays;
				iinputLine >> inputNumDays;
				if(!(inputNumDays >= 0 && inputNumDays <= 2)) {
					cout << "Load failed due to invalid input from the load file. Number of days in Tims line must be between 0 and 2, inclusive." << endl;
					return false;
				}
				//players[i]->getInJail();
				players[i]->setInJail(inputNumDays);
			}
		}
		notify(inputPosition, "addPlayer", inputChar);

	}

	for (int i = 0; i < 28; ++i) {
		getline(inputFile, inputLine);
		istringstream iinputLine(inputLine);
		string buildingName;
		iinputLine >> buildingName;
		int j = 0;
		while (j < 40) {
			if(buildingName == theGrid[j]->getName()) {
				break;
			}
			++j;
		}
		string inputOwner;
		iinputLine >> inputOwner;
		if(inputOwner == "BANK") {
			continue;
		}
		int k =0;
		Square * sp = theGrid[j];
		Building * bp = dynamic_cast<Building *>(sp);
		while(k < numPlayers) {
			if(inputOwner == players[k]->getName()){
				players[k]->addBuilding(bp);
				break;
			}
			k++;
		}


		int inputImprovements;
		iinputLine >> inputImprovements;
		if(buildingName == "V1" || buildingName == "REV" || buildingName == "MKV" || buildingName == "UWP" 
			|| buildingName == "CIF" || buildingName == "PAC") {

			if(inputImprovements > 0) {
				cout << "Load failed due to invalid input from the load file. Gyms and Residences cannot have improvements." << endl;
				return false;
			} else {
				continue;
			}
		}
		AcademicBuilding * currBuilding;
		for(int z = 0; z < 8; z++) {
		//	cout << "In load while" << endl;
			currBuilding = departmentList[z]->getBuilding(buildingName);
			if (currBuilding != NULL) {
				break;
			}
		}
		//cout << "out of load while" << endl;
        if(inputImprovements == -1) {
            players[k]->setMortgage(buildingName);
        } else {
            currBuilding->setNumImproved(inputImprovements);
        }
		if(inputImprovements > 0) {
			currBuilding->setMonopoly(true);
		}
		for(int s = 0; s < inputImprovements; s++) {
	//		cout << "In improve while" << endl;
			notify(j, "addImprovement", 'I');
		}

	//	cout << "Out of load while" << endl;

	}
	currentPlayer = players[0];
	currentPlayerIndex = 0;
	notify(0, "display", ' ');
	return true;
}

void Board::payOwed(){
	if(currentPlayer->getAmountOwed() != 0){
		if(currentPlayer->getMoney() >= currentPlayer->getAmountOwed()){
			currentPlayer->payMoney(currentPlayer->getAmountOwed(), currentPlayer->getDebtOwner());
			currentPlayer->setAmountOwed(0);
			currentPlayer->setDebtOwner(NULL);
		}
	}
}

int Board::getRollUpLeft(){
	return rollUpLeft;
}

void Board::setRollUpLeft(int setting){
	rollUpLeft = setting;
}

Square *Board::getSquare(int index){
	return theGrid[index];
}

void Board::showWinStatus(){
	cout << players[0]->getName() << " WON!!!!!!!!!!!!!!!!!!!!!!!!" << endl;
	cout << "CONGRATULATIONS :D" << endl;
}






