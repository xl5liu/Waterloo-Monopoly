#ifndef NEEDLESHALL_H
#define NEEDLESHALL_H

#include "Square.h"
class Player;
class Board;

class NeedlesHall : public Square{

public:
	NeedlesHall(int index, Board *board );
	virtual ~NeedlesHall();
	void autoAction(Player *player);
};

#endif