#ifndef TUITION_H
#define TUITION_H

#include "Square.h"
class Player;
class Board;

class Tuition : public Square{

public:
	Tuition(int index, Board *board );
	virtual ~Tuition();
	void autoAction(Player *player);
};

#endif
