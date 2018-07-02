#include "NeedlesHall.h"
#include "Board.h"
#include "Player.h"
#include <cstdlib>
#include <ctime>
using namespace std;

NeedlesHall::NeedlesHall(int index, Board *board ):Square(index,"Needles Hall",board){

}

NeedlesHall::~NeedlesHall(){}

void NeedlesHall::autoAction(Player *player){
	bool successfulPay = true;
	int moneyOwning = 0;

	if(board->getRollUpLeft() == 0){
		srand(time(NULL));
		int randomNum = rand() % 18;
		if(randomNum == 0){
			moneyOwning = 200;
			cout << player->getName() <<" Landed On Needles Hall." << endl;
			successfulPay = player->payMoney(moneyOwning, NULL);
		}
		else if((randomNum >= 1) && (randomNum <= 2)){
			moneyOwning = 100;
			cout << player->getName() <<" Landed On Needles Hall." << endl;
			successfulPay = player->payMoney(moneyOwning, NULL);
		}
		else if((randomNum >= 3) && (randomNum <= 5)){
			moneyOwning = 50;
			cout << player->getName() <<" Landed On Needles Hall." << endl;
			successfulPay = player->payMoney(moneyOwning, NULL);
		}
		else if((randomNum >= 6) && (randomNum <= 11)){
			player->receiveMoney(25);
			cout << player->getName() <<" Landed On Needles Hall." << endl;
			cout << player->getName() <<" Received $25!" << endl;
		}
		else if((randomNum >= 12) && (randomNum <= 14)){
			player->receiveMoney(50);
			cout << player->getName() <<" Landed On Needles Hall." << endl;
			cout << player->getName() <<" Received $50!" << endl;
		}
		else if((randomNum >= 15) && (randomNum <= 26)){
			player->receiveMoney(100);
			cout << player->getName() <<" Landed On Needles Hall." << endl;
			cout << player->getName() <<" Received $100!" << endl;
		}	
		else if(randomNum == 17){
			player->receiveMoney(200);
			cout << player->getName() <<" Landed On Needles Hall." << endl;
			cout << player->getName() <<" Received $200!" << endl;
		}
		else{
			cout << "Something Wrong with Random Number Shit!!!!!!!!!!!!!" << endl;
		}
	}
	else if (board->getRollUpLeft() > 0){
		srand(time(NULL));
		int randomRoll = rand() % 100;
		if ((randomRoll == 0) && (board->getRollUpLeft() > 0)) {
			player->setRollUpNum(player->getRollUpNum() + 1);
			board->setRollUpLeft(board->getRollUpLeft() - 1);
			cout << player->getName() <<" Landed On Needles Hall." << endl;
			cout << "You Just Received A Roll Up the Rim Cup!!!!!!!!!!!!!!!" << endl;
		}
		else{
			srand(time(NULL));
			int randomNum = rand() % 18;
			if(randomNum == 0){
				moneyOwning = 200;
				cout << player->getName() <<" Landed On Needles Hall." << endl;
				successfulPay = player->payMoney(moneyOwning, NULL);
			}
			else if((randomNum >= 1) && (randomNum <= 2)){
				moneyOwning = 100;
				cout << player->getName() <<" Landed On Needles Hall." << endl;
				successfulPay = player->payMoney(moneyOwning, NULL);
			}
			else if((randomNum >= 3) && (randomNum <= 5)){
				moneyOwning = 50;
				cout << player->getName() <<" Landed On Needles Hall." << endl;
				successfulPay = player->payMoney(moneyOwning, NULL);
			}
			else if((randomNum >= 6) && (randomNum <= 11)){
				player->receiveMoney(25);
				cout << player->getName() <<" Landed On Needles Hall." << endl;
				cout << player->getName() <<" Received $25!" << endl;
			}
			else if((randomNum >= 12) && (randomNum <= 14)){
				player->receiveMoney(50);
				cout << player->getName() <<" Landed On Needles Hall." << endl;
				cout << player->getName() <<" Received $50!" << endl;
			}
			else if((randomNum >= 15) && (randomNum <= 26)){
				player->receiveMoney(100);
				cout << player->getName() <<" Landed On Needles Hall." << endl;
				cout << player->getName() <<" Received $100!" << endl;
			}	
			else if(randomNum == 17){
				player->receiveMoney(200);
				cout << player->getName() <<" Landed On Needles Hall." << endl;
				cout << player->getName() <<" Received $200!" << endl;
			}
			else{
				cout << "Something Wrong with Random Number Shit!!!!!!!!!!!!!" << endl;
			}
		}
	}
	else {
		cout << "Something Wrong With RollUpLeft!!!!!!" << endl;
	}
	if(!successfulPay){
		player->setDebtOwner(NULL);
		player->setAmountOwed(moneyOwning);
		cout << "Paying Failed!" << " Now Owing $" << moneyOwning << " To School!" << endl;
	}
}
