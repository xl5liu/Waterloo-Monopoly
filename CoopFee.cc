#include "CoopFee.h"
#include "Board.h"
#include "Player.h"
using namespace std;

CoopFee::CoopFee(int index, Board *board ):Square(index,"Coop Fee",board){

}

CoopFee::~CoopFee(){}

void CoopFee::autoAction(Player *player){
	cout << "Pay $150 for coop fee!" << endl;
	bool successfulPay = player->payMoney(150, NULL);
	if(!successfulPay){
		player->setDebtOwner(NULL);
		player->setAmountOwed(150);
		cout << "Paying Failed!" << " Now Owing $150 To School!" << endl;
	}
}