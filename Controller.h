

#ifndef CONTROLLER_H
#define CONTROLLER_H

#include <iostream>

class View;
class Board;

class Controller {
    View *td;
    Board *board;

    void init(std::istream &input, Board &board);
//    void save(Board &board);
    bool load(std::string file, Board &board);
    bool checkWin(Board &board);
        
public:
    Controller();
    ~Controller();
    void notify(int index, std::string cmd, char player);
    void play(bool test, bool load, std::string file);
};


#endif 
