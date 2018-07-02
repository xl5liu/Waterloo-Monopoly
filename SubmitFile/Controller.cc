#include "Controller.h"
#include "View.h"
#include "TextDisplay.h"
#include "Board.h"
#include <sstream>
using namespace std;

Controller::Controller(){
	td = new TextDisplay();
	board = new Board();
}

Controller::~Controller(){
	delete td;
	delete board;
}

void Controller::notify(int index, string cmd, char player){
	td->notify(index, cmd, player); 
}

void Controller::init(istream &input, Board &board){
	cout << "Please enter the number of players (2-7) : " << endl;
	string inputRead;
	while(cin >> inputRead) {
		istringstream iinput(inputRead);
		int inputNumPlayers;
		if (iinput >> inputNumPlayers) {
			if (inputNumPlayers >= 2 && inputNumPlayers <= 7) {
				board.init(inputNumPlayers, this);
				break;
			} 
			else {
				cout << "Invalid input!" << endl;
				cout << "Please enter the number of players (2-7) :" << endl;
			}
		}
		else {
			cout << "Invalid input, you did not enter a number! Please enter Please enter the number of players (2-7) :" << endl;
		}
	}
}

//    void save(Board &board);


bool Controller::load(std::string file, Board &board){
	return board.load(file, this);
}




bool Controller::checkWin(Board &board){
	if (board.getNumPlayers() == 1){
		return true;
	} 
	else{
		return false;
	}
}

void Controller::play(bool test, bool load, string file){
	if(!load){
		cout << "Welcome to BB7K" << endl;
		init(cin, *board);
	}
	if(load){
		cout << "Loading saved game!" << endl;
		bool loadSuccess = this->load(file, *board);
		if (!loadSuccess){
			return;
		}
	}
	if(test){
		cout << "Testing Mode!" << endl;
	}
	while(!checkWin(*board) && !cin.fail()){
		board->printCurrentStatus();
		board->payOwed();
		if(test){
			cout << "Please enter an action command (roll <num1> <num2> / next / assets / mortgage <property> / unmortgage <property> / improve <property> buy/sell / trade <name> <give> <receive> / bankrupt / save <fileName> / quit)" << endl;
		}
		else{
			cout << "Please enter an action command (roll / next / assets / mortgage <property> / unmortgage <property> / improve <property> buy/sell / trade <name> <give> <receive> / bankrupt / save <fileName> / quit)" << endl;
		}
		string inputCommand;
		cin >> inputCommand;


		if(inputCommand == "quit") {
			break;
		}	
		else if (inputCommand == "roll"){
				if(board->getCurrentPlayerRolled() == false){
					if (test){
						while(true) {
							string inputNum1;
							cin >> inputNum1;
							string inputNum2;
							cin >> inputNum2;
							inputNum1 = inputNum1 + " " + inputNum2;
							cout << inputNum1 << endl; 
							istringstream iinputNums(inputNum1);
							int num1;
							int num2;
							if(iinputNums >> num1 && iinputNums >> num2) {
								if(num1 >= 1 && num1 <= 6 && num2 >=1 && num2 <=6) {
									board->roll(num1,num2);
									break;
								} else {
									cout << "Invalid Input!" << endl;
								}
							}
							else {
								cout << "Invalid Input! Enter Numbers!" << endl;
							}
						}
					}
					else{
						board->roll();
					}
			

				}
				else{
					notify(0, "display", ' ');
					cout << "You already rolled. Cannot roll again!" << endl;
				}			
		} 
		else if (inputCommand == "assets") {
			notify(0, "display", ' ');
			board->assets();
		}
		else if (inputCommand == "bankrupt"){
			notify(0, "display", ' ');
			board->bankruptcy(board->getCurrentPlayer());
		}
		else if (inputCommand == "improve") {
			notify(0, "display", ' ');
			string property;
			string option;
			cin >> property;
			cin >> option;
			if(option == "buy"){
				board->buyImprove(property);
			}
			else if(option == "sell"){
				board->sellImprove(property);
			}
			else{
				cout << "Invalid Option" << endl;
			}
		}
		else if (inputCommand == "mortgage") {
			notify(0, "display", ' ');
			string property;
			cin >> property;
			board->mortgage(property);
		}
		else if (inputCommand == "unmortgage") {
			notify(0, "display", ' ');
			string property;
			cin >> property;
			board->unmortgage(property);
		}
		else if (inputCommand == "next"){
			notify(0, "display", ' ');
			if(board->getCurrentPlayerRolled() == true){
				board->next();
			}
			else{
				cout << "You have not rolled yet. Please roll first!" << endl;
			}
		}
		else if(inputCommand == "save") {
			string saveFileName;
			cin >> saveFileName;
			board->save(saveFileName);
		} 
		else if (inputCommand == "trade") {
			string inputName;
			string inputGive;
			string inputReceive;
			cin >> inputName;
			cin >> inputGive;
			cin >> inputReceive;
			board->trade(inputName, inputGive, inputReceive);
		}
		else{
			cout << "Invalid command" << endl;
		}	
	}
	if(board->getNumPlayers() == 1){
		board->showWinStatus();
	}
	
}















