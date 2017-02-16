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
	Map* currentMap;
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
		//Asks the user for the save file name
		string filename = "";
		cout << "What is the name of the file you want to load? (No need to put the extension)" << endl;
		cin >> filename;
		filename += ".json";

		loader = new Loader(filename);
	}
	currentMap = new Map();
	//sets the map from the json in the Map object
	currentMap->setMapLocation(loader->loadMap());
	currentMap->printConnections();


	string saveFileName = "save";
	loader->save(saveFileName, currentMap->getMapLocation());

	//Deletes the pointer used
	delete loader;
	delete currentMap;
	system("Pause");
	
}