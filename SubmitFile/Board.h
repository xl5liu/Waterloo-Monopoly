

#ifndef BOARD_H
#define BOARD_H

class Controller;
class Player;
class Department;
class Square;
class Building;
#include <iostream>

class Board {
	Square *theGrid[40];
	Controller *notification;
	Department *departmentList[8];
	Player *players[7];
	Player *currentPlayer;
	int currentPlayerIndex;
	int numPlayers;
	int rollUpLeft;
	int dice1;
	int dice2;
	int doublesInTurn;
	bool currentPlayerRolled;
	int convertPosition(int location);
public:
	Board();
	~Board();
	void init (int numPlayers, Controller *gameNotificaiton);
	void change(int index, std::string cmd, Player *player);
    void notify(int index, std::string cmd, char player);

    void rollDice();
    void roll();
    void roll(int num1 , int num2);
    int getDice1();
    int getDice2();
    int getNumPlayers();
    bool getCurrentPlayerRolled();
    void printCurrentStatus();

    void next();
    Player *getCurrentPlayer();
    bool trade(std::string name, std::string give, std::string receive);
	bool buyImprove(std::string property);
	bool sellImprove(std::string property);
    bool mortgage(std::string property);
    bool unmortgage(std::string property);
    void bankruptcy(Player *player);
    void assets();
   void auction(Building *building, bool forBankrupt);
    void save(std::string filename);
    bool load(std::string fileName, Controller *gameNotificaiton);
    int getCurrentPlayerAmountOwed();
    int getCurrentPlayerMoney();
    void payOwed();
    int getRollUpLeft();
    void setRollUpLeft(int setting);
    Square *getSquare(int index);
    void showWinStatus();


};

#endif 

