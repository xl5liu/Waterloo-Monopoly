#ifndef PLAYER_H
#define PLAYER_H 
#include <string>

class Building;
class Board;


class Player {
	Board *board;
	bool bankruptcy;
	bool inJail;
	int jailDays;
	int rollUpNum;
	int money;
	int location;
	const std::string name;
	const char character;
	int playerIndex;
	int numBuildingsOwned;
	Building * buildingsOwned[28];
	int amountOwed;
	Player *debtOwner;



public:
	Player(std::string name, const char character, int playerIndex, Board *board);
	~Player();
	bool payMoney(int amount, Player * receiver);
	void receiveMoney(int amount);

	bool getOutJail(std::string cmd);
	void getInJail();
	void addJailDays();
	int getJailStatus();
	int getJailDays();

	void move(int index);
	void moveBack(int index);
	void goBankrupt(Player *receiver);
	int resOwned();
	int gymOwned();
	void addBuilding(Building * building);
	void removeBuilding(Building * building);
	int totalWorth();
	std::string getName();
	int getMoney();
	int getLocation();
	void setLocation(int setting);
	int getRollUpNum();
	void setRollUpNum(int setting);
	void printBuildingsOwned();
	bool mortgageBuilding(std::string property);
	bool unmortgageBuilding(std::string property);
	bool buyImprove(std::string property);
	bool sellImprove(std::string property);
	int getAmountOwed();
	Player *getDebtOwner();
	void setMortgage(std::string name);
	void setInJail(int setting);
	void setMoney(int setting);
	void setAmountOwed(int owe);
	void setDebtOwner(Player * debter);
	char getCharacter();
	void setBankruptcy(bool setting);
	bool getBankruptcy();
	void setPlayerIndex(int setting);
	int getPlayerIndex();
	Building *getBuilding(std::string building);
	bool trade(Player *responder, Building *buildingGive, Building *buildingRecieve);
	bool trade(Player *responder, int amountGive , Building *building);
	bool trade(Player *responder, Building *building, int amountReceive);
};








#endif
