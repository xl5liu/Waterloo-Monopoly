#ifndef VIEW_H
#define VIEW_H


#include <iostream>

class View {
    
    
public:
    View();
    virtual ~View();
    virtual void notify(int index, std::string cmd, char player) = 0;
    virtual void print(std::ostream &out) const = 0;
};


#endif 
