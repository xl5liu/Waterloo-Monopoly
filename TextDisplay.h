#ifndef TEXTDISPLAY_H
#define TEXTDISPLAY_H

#include <iostream>
#include "View.h"


class TextDisplay : public View{

	static const int blocks[40][2];
	char theDisplay[56][89];
public:
	TextDisplay();
	~TextDisplay();
	virtual void notify(int index, std::string cmd, char player);
	virtual void print(std::ostream &out) const;
};


#endif