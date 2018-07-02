#ifndef DCTIMSLINE_H
#define DCTIMSLINE_H

#include "Square.h"
class Player;
class Board;

class DCTimsLine : public Square{

public:
	DCTimsLine(int index, Board *board );
	virtual ~DCTimsLine();
	void autoAction(Player *player);
};

#endif
