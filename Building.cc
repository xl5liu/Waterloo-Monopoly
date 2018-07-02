#include "Building.h"
#include "Player.h"
#include "Board.h"
using namespace std;


Building::Building(int index,std::string name, Board *board, const int purchaseCost) : Square(index,name,board),purchaseCost(purchaseCost){
	owner = NULL;
	isMortgaged = false;
}
 Building::~Building(){};


 void Building::autoAction(Player *currentPlayer){
 	if(owner == NULL){
 		cout<<"Would you like to purchase this building for $"<<purchaseCost<<"?(y/n)"<<endl;
 		char answer;
 		while(std::cin>>answer){
 			if(answer == 'y'){
 				buy(currentPlayer);
 				break;
 			}
 			else if(answer == 'n'){
 				board->auction(this, false);
 				break;
 			}
 			else{
 				cout<<"Invalid Input!!!!" << endl;
 			}
 		}
 	}
 	else if(owner == currentPlayer){
 	}
 	else{
 		if(isMortgaged == true){}
 		else{
 			pay(currentPlayer);
		}
 	}
 }


 Player *Building::getOwner(){
 	return owner;
 }

 void Building::setOwner(Player *currentPlayer){
 	owner = currentPlayer;
 }

 void Building::setMortgaged(bool setting) {
	isMortgaged = setting;
}

bool Building::getMortgaged(){
	return isMortgaged;
}
int Building::getPurchaseCost(){
	return purchaseCost;
}



