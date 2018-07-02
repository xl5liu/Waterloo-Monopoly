#ifndef SLC_H
#define SLC_H

#include "Square.h"
class Player;
class Board;

class SLC : public Square{

public:
	SLC(int index, Board *board );
	virtual ~SLC();
	void autoAction(Player *player);
};

#endif