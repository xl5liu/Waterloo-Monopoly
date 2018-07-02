#include "Tuition.h"
#include "Board.h"
#include "Player.h"
using namespace std;

Tuition::Tuition(int index, Board *board ):Square(index,"Tuition",board){

}

Tuition::~Tuition(){}

void Tuition::autoAction(Player *player){
	cout << "You need to pay tuition! Choose between:" << endl;
	cout << "1. Pay $300 tuition" << endl;
	cout << "2. 10 percent of your total worth (including savings, " << endl;
	cout <<"   printed price of all buildings you own, and costs of each improvement)" << endl;
	cout << "Enter 1 or 2" << endl;
	int input;
	int moneyOwning;
	bool successfulPay = false;
	while (cin >> input) {
		if(input == 1 ) {
			cout << "Paying first option!" << endl;
			moneyOwning = 300;
			successfulPay = player->payMoney(moneyOwning, NULL);
			break;
		} else if (input == 2) {
			cout << "Paying second option!" << endl;
			int worth = player->totalWorth();
			moneyOwning = worth / 10;
			successfulPay = player->payMoney(moneyOwning, NULL);
			break;
		} else {
			cout << "Invalid input. Choose 1 or 2." << endl;
		}
	}
	if(!successfulPay){
		player->setDebtOwner(NULL);
		player->setAmountOwed(moneyOwning);
		cout << "Paying Failed!" << " Now Owing $" << moneyOwning << " To School!" << endl;
	}
}