#include "OSAP.h"
#include "Board.h"
#include "Player.h"
using namespace std;

OSAP::OSAP(int index, Board *board ):Square(index,"Collect OSAP",board){

}

OSAP::~OSAP(){}

void OSAP::autoAction(Player *player){
	player->receiveMoney(200);
}