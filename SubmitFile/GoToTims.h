#ifndef GOTOTIMS_H
#define GOTOTIMS_H

#include "Square.h"
class Player;
class Board;

class GoToTims : public Square {

public:
	GoToTims(int index, Board *board );
	virtual ~GoToTims();
	void autoAction(Player *player);
};

#endif
