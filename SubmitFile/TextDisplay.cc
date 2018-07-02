#include "TextDisplay.h"
#include <string>

const int TextDisplay::blocks[40][2] = {{0, 0}, {0, 8}, {0, 16}, {0, 24}, {0, 32}, {0, 40}, {0, 48}, {0, 56}, {0, 64}, {0, 72}, {0, 80}, {5, 80}, {10, 80}, {15, 80}, {20, 80}, {25, 80}, {30, 80}, {35, 80}, {40, 80}, {45, 80}, {50, 80}, {50, 72}, {50, 64}, {50, 56}, {50, 48}, {50, 40}, {50, 32}, {50, 24}, {50, 16}, {50, 8}, {50, 0}, {45, 0}, {40, 0}, {35, 0}, {30, 0}, {25, 0}, {20, 0}, {15, 0}, {10, 0}, {5, 0}};

void TextDisplay::print(std::ostream &out) const {
	for(int i = 0; i < 56; i ++) {
		for(int j = 0; j < 89; j++ ) {
			out << theDisplay[i][j];
		}
		out << std::endl;
	}
}

void drawTopBlankSquare(int topCornerY, int topCornerX, char (&board)[56][89],std::string name){
	
	for (int i = 0; i < 9; ++i){
		board[topCornerY][topCornerX+i] = '_';	 
	}

	for (int i = 1; i < 6; ++i){
		board[topCornerY+i][topCornerX+0] = '|';
		board[topCornerY+i][topCornerX+8] = '|';
	}

	for (int i = 1; i < 8; ++i){
		board[topCornerY+5][topCornerX+i] = '_';
	}

	for (int i = 1; i < 8; ++i){
		board[topCornerY+1][topCornerX+i] = name[i-1];
	}

	for (int i = 1; i < 8; ++i){
		board[topCornerY+2][topCornerX+i] = name[i+6];
	}

}

void drawTopSquare(int topCornerY, int topCornerX, char (&board)[56][89], std::string name){
	
	for (int i = 0; i < 9; ++i){
		board[topCornerY][topCornerX+i] = '_';	 
	}

	for (int i = 1; i < 6; ++i){
		board[topCornerY+i][topCornerX+0] = '|';
		board[topCornerY+i][topCornerX+8] = '|';
	}

	for (int i = 1; i < 8; ++i){
		board[topCornerY+5][topCornerX+i] = '_';
	}

	for (int i = 1; i < 8; ++i){
		board[topCornerY+2][topCornerX+i] = '-';
	}

	for (int i = 1; i < 8; ++i){
		board[topCornerY+3][topCornerX+i] = name[i-1];
	}
}

void drawSideBlankSquare(int topCornerY, int topCornerX, char (&board)[56][89], std::string name){
	
	for (int i = 1; i < 8; ++i){
		board[topCornerY][topCornerX+i] = '_';	 
	}
	for (int i = 0; i < 6; ++i)
	{
		board[topCornerY+i][topCornerX+0] = '|';
		board[topCornerY+i][topCornerX+8] = '|';
	}
	for (int i = 1; i < 8; ++i)
	{
		board[topCornerY+5][topCornerX+i] = '_';
	}
		for (int i = 1; i < 8; ++i){
		board[topCornerY+1][topCornerX+i] = name[i-1];
	}
	for (int i = 1; i < 8; ++i){
		board[topCornerY+2][topCornerX+i] = name[i+6];
	}

}

void drawSideSquare(int topCornerY, int topCornerX, char (&board)[56][89], std::string name){
	
	for (int i = 1; i < 8; ++i){
		board[topCornerY][topCornerX+i] = '_';	 
	}

	for (int i = 0; i < 6; ++i){
		board[topCornerY+i][topCornerX+0] = '|';
		board[topCornerY+i][topCornerX+8] = '|';
	}

	for (int i = 1; i < 8; ++i){
		board[topCornerY+5][topCornerX+i] = '_';
	}

	for (int i = 1; i < 8; ++i){
		board[topCornerY+2][topCornerX+i] = '-';
	}
	for (int i = 1; i < 8; ++i){
		board[topCornerY+3][topCornerX+i] = name[i-1];
	}
}

void drawSpecialSquareRight(int topCornerY, int topCornerX, char (&board)[56][89], std::string name){
	
	for (int i = 0; i < 8; ++i){
		board[topCornerY][topCornerX+i] = '_';	 
	}

	for (int i = 1; i < 6; ++i){
		board[topCornerY+i][topCornerX+0] = '|';
		board[topCornerY+i][topCornerX+8] = '|';
	}

	for (int i = 1; i < 8; ++i){
		board[topCornerY+5][topCornerX+i] = '_';
	}

	for (int i = 1; i < 8; ++i){
		board[topCornerY+2][topCornerX+i] = '-';
	}

	board[topCornerY][topCornerX+8] ='|';

	for (int i = 1; i < 8; ++i){
		board[topCornerY+3][topCornerX+i] = name[i-1];
	}
}

void drawSpecialSquareLeft(int topCornerY, int topCornerX, char (&board)[56][89], std::string name ){
	
	for (int i = 1; i < 9; ++i){
		board[topCornerY][topCornerX+i] = '_';	 
	}

	for (int i = 1; i < 6; ++i){
		board[topCornerY+i][topCornerX+0] = '|';
		board[topCornerY+i][topCornerX+8] = '|';
	}

	for (int i = 1; i < 8; ++i){
		board[topCornerY+5][topCornerX+i] = '_';
	}

	for (int i = 1; i < 8; ++i){
		board[topCornerY+2][topCornerX+i] = '-';
	}

	board[topCornerY][topCornerX] ='|';

	for (int i = 1; i < 8; ++i){
		board[topCornerY+3][topCornerX+i] = name[i-1];
	}
}

void drawB(int topCornerY, int topCornerX, char (&board)[56][89]){
	int coordinates[15][2]={{0,0},{1,0},{2,0},{0,1},{3,1},{0,2},{1,2},{2,2},{3,2},{0,3},{3,3},{0,4},{1,4},{2,4},{3,4}};
	for (int i = 0; i < 5; ++i){
		for (int j = 0; j < 5; ++j){
			for (int k = 0; k < 15; ++k){
				if ((coordinates[k][0] == j) && (coordinates[k][1] == i)){
					board[topCornerY+i][topCornerX+j] = '#';
				}
			}
		}
	}
}


void draw7(int topCornerY, int topCornerX, char (&board)[56][89]){
	int coordinates[9][2]={{0,0},{1,0},{2,0},{3,0},{4,0},{3,1},{2,2},{1,3},{0,4}};
	for (int i = 0; i < 5; ++i){
		for (int j = 0; j < 5; ++j)
		{
			for (int k = 0; k < 9; ++k)
			{
				if ((coordinates[k][0] == j) && (coordinates[k][1] == i)){
					board[topCornerY+i][topCornerX+j] = '#';
				}
			}
		}
	}
}

void draw0(int topCornerY, int topCornerX, char (&board)[56][89]){
	int coordinates[12][2]={{1,0},{2,0},{3,0},{0,1},{4,1},{0,2},{4,2},{0,3},{4,3},{1,4},{2,4},{3,4}};
	for (int i = 0; i < 5; ++i){
		for (int j = 0; j < 5; ++j)
		{
			for (int k = 0; k < 12; ++k)
			{
				if ((coordinates[k][0] == j) && (coordinates[k][1] == i)){
					board[topCornerY+i][topCornerX+j] = '#';
				}
			}
		}
	}
}


TextDisplay::TextDisplay(): View(){
	
	for(int i = 0; i < 56; i ++) {
		for(int j = 0; j < 89; j++ ) {
			theDisplay[i][j] = ' ';
		}
	}

	drawTopBlankSquare(blocks[0][0],blocks[0][1], theDisplay, "Goose  Nesting");
	drawTopSquare(blocks[1][0],blocks[1][1], theDisplay, "EV1    ");
	drawTopBlankSquare(blocks[2][0],blocks[2][1], theDisplay, "NEEDLESHALL   ");
	drawTopSquare(blocks[3][0],blocks[3][1], theDisplay, "EV2    ");
	drawTopSquare(blocks[4][0],blocks[4][1], theDisplay, "EV3    ");
	drawTopBlankSquare(blocks[5][0],blocks[5][1], theDisplay, "V1            ");
	drawTopSquare(blocks[6][0],blocks[6][1], theDisplay, "PHYS   ");
	drawTopSquare(blocks[7][0],blocks[7][1], theDisplay, "B1     ");
	drawTopBlankSquare(blocks[8][0],blocks[8][1], theDisplay, "CIF           ");
	drawTopSquare(blocks[9][0],blocks[9][1], theDisplay, "B2     ");
	drawTopBlankSquare(blocks[10][0],blocks[10][1], theDisplay, "GO TO  TIMS   ");
	drawSideSquare(blocks[11][0],blocks[11][1], theDisplay, "EIT    ");
	drawSideSquare(blocks[12][0],blocks[12][1], theDisplay, "ESC    ");
	drawSideBlankSquare(blocks[13][0],blocks[13][1], theDisplay, "SLC           ");
	drawSideSquare(blocks[14][0],blocks[14][1], theDisplay, "C2     ");
	drawSideBlankSquare(blocks[15][0],blocks[15][1], theDisplay, "REV           ");
	drawSideBlankSquare(blocks[16][0],blocks[16][1], theDisplay, "NEEDLESHALL   ");
	drawSideSquare(blocks[17][0],blocks[17][1], theDisplay, "MC     ");
	drawSideBlankSquare(blocks[18][0],blocks[18][1], theDisplay, "COOP   FEE    ");
	drawSideSquare(blocks[19][0],blocks[19][1], theDisplay, "DC     ");
	drawSideBlankSquare(blocks[20][0],blocks[20][1], theDisplay, "COLLECTOSAP   ");
	drawSpecialSquareRight(blocks[21][0],blocks[21][1], theDisplay, "AL     ");
	drawTopBlankSquare(blocks[22][0],blocks[22][1], theDisplay, "SLC           ");
	drawTopSquare(blocks[23][0],blocks[23][1], theDisplay, "ML     ");
	drawTopBlankSquare(blocks[24][0],blocks[24][1], theDisplay, "TUITION       ");
	drawTopBlankSquare(blocks[25][0],blocks[25][1], theDisplay, "MKV           ");
	drawTopSquare(blocks[26][0],blocks[26][1], theDisplay, "ECH    ");
	drawTopBlankSquare(blocks[27][0],blocks[27][1], theDisplay, "NEEDLESHALL   ");
	drawTopSquare(blocks[28][0],blocks[28][1], theDisplay, "PAS    ");
	drawSpecialSquareLeft(blocks[29][0],blocks[29][1], theDisplay, "HH     ");
	drawSideBlankSquare(blocks[30][0],blocks[30][1], theDisplay, "DC TimsLine   ");
	drawSideSquare(blocks[31][0],blocks[31][1], theDisplay, "RCH    ");
	drawSideBlankSquare(blocks[32][0],blocks[32][1], theDisplay, "PAC           ");
	drawSideSquare(blocks[33][0],blocks[33][1], theDisplay, "DWE    ");
	drawSideSquare(blocks[34][0],blocks[34][1], theDisplay, "CPH    ");
	drawSideBlankSquare(blocks[35][0],blocks[35][1], theDisplay, "UWP           ");
	drawSideSquare(blocks[36][0],blocks[36][1], theDisplay, "LHI    ");
	drawSideBlankSquare(blocks[37][0],blocks[37][1], theDisplay, "SLC           ");
	drawSideSquare(blocks[38][0],blocks[38][1], theDisplay, "BMH    ");
	drawSideSquare(blocks[39][0],blocks[39][1], theDisplay, "OPT    ");

	for (int i = 0; i < 41; ++i)
	{
		theDisplay[24][24+i] = '_';		
	}
	for (int i = 1; i < 8; ++i)
	{
		theDisplay[24+i][24] = '|';
		theDisplay[24+i][64] = '|';
	}
	for (int i = 1; i < 40; ++i)
	{
		theDisplay[31][24+i] = '_';		
	}
	drawB(26,27,theDisplay);
	drawB(26,33,theDisplay);
	draw7(26,39,theDisplay);
	draw0(26,45,theDisplay);
	draw0(26,51,theDisplay);
	draw0(26,57,theDisplay);
}
TextDisplay::~TextDisplay(){}

void TextDisplay::notify(int index, std::string cmd, char player){
	int row = blocks[index][0];
	int column = blocks[index][1];

	if (cmd == "removePlayer"){
		for (int i = 1; i < 8; ++i)
		{
			if (theDisplay[row+4][column+i] == player){
				theDisplay[row+4][column+i] = ' ';
				break;
			}
		}
	}
	else if(cmd == "addPlayer"){
		for (int i = 1; i < 8; ++i)
		{
			if (theDisplay[row+4][column+i] == ' '){
				theDisplay[row+4][column+i] = player;
				break;
			}
		}
	}
	else if(cmd == "removeImprovement"){
		for (int i = 7; i > 0; --i)
		{
			if (theDisplay[row+1][column+i] == 'I'){
				theDisplay[row+1][column+i] = ' ';
				break;
			}
		}
		
	}
	else if(cmd == "addImprovement"){
			for (int i = 1; i < 8; ++i)
		{
			if (theDisplay[row+1][column+i] == ' '){
				theDisplay[row+1][column+i] = 'I';
				break;
			}
		}
	}
	else if (cmd == "display") {
		print(std::cout);
		return;
	}
	print(std::cout);
}
