#ifndef SQUARE_H
#define SQUARE_H
#include <string>


class Board;
class Player;

class Square{

protected:	
	Board *board;
	Player *playersHere[7];
	bool canImprove;
	int index;
	std::string name;

public:
	Square(int index,std::string name, Board *board);
	virtual ~Square();
	virtual void autoAction(Player *player) = 0;
	void addPlayer(Player *player);
	void removePlayer(Player *player);
	void setCanImprove(bool setting);
	bool getCanImprove();
	std::string getName();
};

#endif
