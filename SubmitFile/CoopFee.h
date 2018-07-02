#ifndef COOPFEE_H
#define COOPFEE_H

#include "Square.h"
class Player;
class Board;

class CoopFee : public Square{

public:
	CoopFee(int index, Board *board );
	virtual ~CoopFee();
	void autoAction(Player *player);
};

#endif
