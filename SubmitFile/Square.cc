#include "Square.h"
#include "Board.h"
#include "Player.h"
using namespace std;


Square::Square(int index,std::string name, Board *board): board(board), index(index), name(name){
	canImprove = false;
	for (int i = 0; i < 7; ++i)
	{
		playersHere[i] = NULL;
	}
}

Square::~Square(){};

void Square::addPlayer(Player *player){
	
	for (int i = 0; i < 7; ++i){

		if(playersHere[i] == NULL){

			playersHere[i] = player;
			break;
		}
	}
}

void Square::removePlayer(Player *player){
	for (int i = 0; i < 7; ++i){

		if(playersHere[i] == player){
			
			playersHere[i] = NULL;

			for(int j=i; j<6; ++j){
				playersHere[j] = playersHere[j+1];
				playersHere[j+1] = NULL;
			}

			break;
		}
	}
}

void Square::setCanImprove(bool setting){
	canImprove = setting;
}

bool Square::getCanImprove(){
	return canImprove;
}

string Square::getName(){
	return name;
}





