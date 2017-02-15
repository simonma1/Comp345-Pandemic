#include <iostream>
#include "Player.h"
#include "Board.h"
#include "Location.h"
#include "Loader.h"
#include <vector>
using namespace std;

int main()
{
	Loader* loader;
	Board board;
	Player p1;
	Map currentMap;
	int startOrLoad=0;
	

	std::cout << "Welcome to Pandemic!!!!" << endl;
	std::cout << "Do you want to:" << endl;
	std::cout << "1. Start New Game" << endl;
	std::cout << "2. Load a Game" << endl;

	cin >> startOrLoad;
	cin.clear();
	cin.ignore(numeric_limits<streamsize>::max(), '\n');//Ignores data that is not an integer

	while ((startOrLoad != 1) && (startOrLoad != 2)) {
		std::cout << "You entered an invalid value. Please Try Again." << endl;
		cin >> startOrLoad;
		cin.clear();
		cin.ignore(numeric_limits<streamsize>::max(), '\n');
	}

	//Depending on the input will either load an existing game or start a new one
	if (startOrLoad == 1) {//Starts a new game
		loader = new Loader("map.json");
	}
	else {
		//Loading to be implemented
		loader = new Loader("map.json");
	}

	//sets the map from the json in the Map object
	currentMap.setMapLocation(loader->loadMap());


	string saveFileName = "save";
	loader->save(saveFileName, currentMap.getMapLocation());

	delete loader;//Deletes the loader pointer
	system("Pause");
	
}