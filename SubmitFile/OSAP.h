#ifndef OSAP_H
#define OSAP_H

#include "Square.h"
class Player;
class Board;

class OSAP : public Square{

public:
	OSAP(int index, Board *board );
	virtual ~OSAP();
	void autoAction(Player *player);
};

#endif
