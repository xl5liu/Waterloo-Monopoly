#include "GooseNesting.h"
#include "Board.h"
#include "Player.h"
using namespace std;

GooseNesting::GooseNesting(int index, Board *board ):Square(index,"Goose Nesting",board){

}

GooseNesting::~GooseNesting(){}

void GooseNesting::autoAction(Player *player){
	cout << "You've been attacked by a flock of nesting geese! You managed to get away safely though :D" << endl;
}
