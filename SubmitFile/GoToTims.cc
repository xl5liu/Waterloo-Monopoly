#include "GoToTims.h"
#include "Board.h"
#include "Player.h"
using namespace std;

GoToTims::GoToTims(int index, Board *board ):Square(index,"Go To Tims",board){

}

GoToTims::~GoToTims(){}

void GoToTims::autoAction(Player *player){
	player->getInJail();
}
