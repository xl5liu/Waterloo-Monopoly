#ifndef GOOSENESTING_H
#define GOOSENESTING_H

#include "Square.h"
class Player;
class Board;

class GooseNesting : public Square{

public:
	GooseNesting(int index, Board *board );
	virtual ~GooseNesting();
	void autoAction(Player *player);
};

#endif