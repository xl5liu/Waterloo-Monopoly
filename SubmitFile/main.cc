#include "Controller.h" 

#include <iostream>
#include <string>
#include <cstring>
using namespace std;

int main(int argc, char* argv[]){
	bool isTesting = false;
	bool isLoading = false;
	string fileName = "";
	for (int i = 1; i < argc; ++i) {
		if (!strcmp( argv[i], "-testing") ){
			isTesting = true;
		}
		else if(!strcmp( argv[i], "-load")){
			fileName = argv[i+1];
			i++;
			isLoading = true;
		}
		else{
			cout << "Invalid Command Line Arguments! Options: No Arguments / -testing / -load <fileName>" << endl;
			return 0;
		}
	}
	Controller c;
	c.play(isTesting, isLoading, fileName);

}
