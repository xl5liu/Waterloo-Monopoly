#include "SLC.h"
#include "Board.h"
#include "Player.h"
#include <cstdlib>
#include <ctime>
#include <string>
using namespace std;

SLC::SLC(int index, Board *board ):Square(index,"SLC",board){

}

SLC::~SLC(){}

void SLC::autoAction(Player *player){
	cout << player->getName() <<" Landed On SLC." << endl;

	if(board->getRollUpLeft() == 0){
		srand(time(NULL));
		int randomNum = rand() % 24;
		if(randomNum == 0){
			cout << player->getName() <<" Advance To Collect OSAP" << endl;
			player->move(20);
			board->getSquare(player->getLocation())->autoAction(player);
		}
		else if(randomNum == 1){
//			player->getInJail();
			cout << player->getName() <<" Go To DC Tims Line" << endl;
		}
		else if((randomNum >= 2) && (randomNum <= 5)){
			cout << player->getName() <<" Is Moving 3 Forward." << endl;
			cout << "Please Enter continue To Continue!" << endl;
			string response;
			while(cin >> response){
				if(response == "continue"){
					break;
				}
				else{
					cout << "Please Enter continue!" << endl;
				}
			}
			player->move(player->getLocation() + 3);
			cout << player->getName() << " has moved to " << board->getSquare(player->getLocation())->getName() << endl;
			board->getSquare(player->getLocation())->autoAction(player);

		}
		else if((randomNum >= 6) && (randomNum <= 9)){
			cout << player->getName() <<" Is Moving 2 Forward." << endl;
			cout << "Please Enter continue To Continue!" << endl;
			string response;
			while(cin >> response){
				if(response == "continue"){
					break;
				}
				else{
					cout << "Please Enter continue!" << endl;
				}
			}
			player->move(player->getLocation() + 2);
			cout << player->getName() << " has moved to " << board->getSquare(player->getLocation())->getName() << endl;
			board->getSquare(player->getLocation())->autoAction(player); 
		}
		else if((randomNum >= 10) && (randomNum <= 12)){
			cout << player->getName() <<" Is Moving 1 Forward." << endl;
			cout << "Please Enter continue To Continue!" << endl;
			string response;
			while(cin >> response){
				if(response == "continue"){
					break;
				}
				else{
					cout << "Please Enter continue!" << endl;
				}
			}
			player->move(player->getLocation() + 1); 
			cout << player->getName() << " has moved to " << board->getSquare(player->getLocation())->getName() << endl;
			board->getSquare(player->getLocation())->autoAction(player);
		}
		else if((randomNum >= 13) && (randomNum <= 16)){
			cout << player->getName() <<" Is Moving 1 Backward." << endl;
			cout << "Please Enter continue To Continue!" << endl;
			string response;
			while(cin >> response){
				if(response == "continue"){
					break;
				}
				else{
					cout << "Please Enter continue!" << endl;
				}
			}
			player->moveBack(player->getLocation() - 1);
			cout << player->getName() << " has moved to " << board->getSquare(player->getLocation())->getName() << endl;
			board->getSquare(player->getLocation())->autoAction(player); 
		}
		else if((randomNum >= 17) && (randomNum <= 20)){
			cout << player->getName() <<" Is Moving 2 Backward." << endl;
			cout << "Please Enter continue To Continue!" << endl;
			string response;
			while(cin >> response){
				if(response == "continue"){
					break;
				}
				else{
					cout << "Please Enter continue!" << endl;
				}
			}
			player->moveBack(player->getLocation() - 2); 
			cout << player->getName() << " has moved to " << board->getSquare(player->getLocation())->getName() << endl;
			board->getSquare(player->getLocation())->autoAction(player);
		}
		else if((randomNum >= 21) && (randomNum <= 23)){
			cout << player->getName() <<" Is Moving 3 Backward." << endl;
			cout << "Please Enter continue To Continue!" << endl;
			string response;
			while(cin >> response){
				if(response == "continue"){
					break;
				}
				else{
					cout << "Please Enter continue!" << endl;
				}
			}
			player->moveBack(player->getLocation() - 3);
			cout << player->getName() << " has moved to " << board->getSquare(player->getLocation())->getName() << endl;
			board->getSquare(player->getLocation())->autoAction(player); 
		}
		else{
			cout << "Something Wrong with Random Number Shit!!!!!!!!!!!!!" << endl;
		}
	}
	else if (board->getRollUpLeft() > 0){
		srand(time(NULL));
		int randomRoll = rand() % 100;
		if (randomRoll == 0) {
			player->setRollUpNum(player->getRollUpNum() + 1);
			board->setRollUpLeft(board->getRollUpLeft() - 1);
			cout << "You Just Received A Roll Up the Rim Cup!!!!!!!!!!!!!!!" << endl;
		}
		else{
			srand(time(NULL));
			int randomNum = rand() % 24;
			if(randomNum == 0){
			cout << player->getName() <<" Advance To Collect OSAP" << endl;
			player->move(20);
			board->getSquare(player->getLocation())->autoAction(player);
		}
		else if(randomNum == 1){
//			player->getInJail();
			cout << player->getName() <<" Go To DC Tims Line" << endl;
		}
		else if((randomNum >= 2) && (randomNum <= 5)){
			cout << player->getName() <<" Is Moving 3 Forward." << endl;
			cout << "Please Enter continue To Continue!" << endl;
			string response;
			while(cin >> response){
				if(response == "continue"){
					break;
				}
				else{
					cout << "Please Enter continue!" << endl;
				}
			}
			player->move(player->getLocation() + 3);
			cout << player->getName() << " has moved to " << board->getSquare(player->getLocation())->getName() << endl;
			board->getSquare(player->getLocation())->autoAction(player);

		}
		else if((randomNum >= 6) && (randomNum <= 9)){
			cout << player->getName() <<" Is Moving 2 Forward." << endl;
			cout << "Please Enter continue To Continue!" << endl;
			string response;
			while(cin >> response){
				if(response == "continue"){
					break;
				}
				else{
					cout << "Please Enter continue!" << endl;
				}
			}
			player->move(player->getLocation() + 2);
			cout << player->getName() << " has moved to " << board->getSquare(player->getLocation())->getName() << endl;
			board->getSquare(player->getLocation())->autoAction(player); 
		}
		else if((randomNum >= 10) && (randomNum <= 12)){
			cout << player->getName() <<" Is Moving 1 Forward." << endl;
			cout << "Please Enter continue To Continue!" << endl;
			string response;
			while(cin >> response){
				if(response == "continue"){
					break;
				}
				else{
					cout << "Please Enter continue!" << endl;
				}
			}
			player->move(player->getLocation() + 1); 
			cout << player->getName() << " has moved to " << board->getSquare(player->getLocation())->getName() << endl;
			board->getSquare(player->getLocation())->autoAction(player);
		}
		else if((randomNum >= 13) && (randomNum <= 16)){
			cout << player->getName() <<" Is Moving 1 Backward." << endl;
			cout << "Please Enter continue To Continue!" << endl;
			string response;
			while(cin >> response){
				if(response == "continue"){
					break;
				}
				else{
					cout << "Please Enter continue!" << endl;
				}
			}
			player->moveBack(player->getLocation() - 1);
			cout << player->getName() << " has moved to " << board->getSquare(player->getLocation())->getName() << endl;
			board->getSquare(player->getLocation())->autoAction(player); 
		}
		else if((randomNum >= 17) && (randomNum <= 20)){
			cout << player->getName() <<" Is Moving 2 Backward." << endl;
			cout << "Please Enter continue To Continue!" << endl;
			string response;
			while(cin >> response){
				if(response == "continue"){
					break;
				}
				else{
					cout << "Please Enter continue!" << endl;
				}
			}
			player->moveBack(player->getLocation() - 2); 
			cout << player->getName() << " has moved to " << board->getSquare(player->getLocation())->getName() << endl;
			board->getSquare(player->getLocation())->autoAction(player);
		}
		else if((randomNum >= 21) && (randomNum <= 23)){
			cout << player->getName() <<" Is Moving 3 Backward." << endl;
			cout << "Please Enter continue To Continue!" << endl;
			string response;
			while(cin >> response){
				if(response == "continue"){
					break;
				}
				else{
					cout << "Please Enter continue!" << endl;
				}
			}
			player->moveBack(player->getLocation() - 3);
			cout << player->getName() << " has moved to " << board->getSquare(player->getLocation())->getName() << endl;
			board->getSquare(player->getLocation())->autoAction(player); 
		}
		else{
			cout << "Something Wrong with Random Number Shit!!!!!!!!!!!!!" << endl;
		}
		}

	}
	else {
		cout << "Something Wrong With RollUpLeft!!!!!!" << endl;
	}
	

}