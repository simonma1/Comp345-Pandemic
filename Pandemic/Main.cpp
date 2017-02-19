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
	Player *p1;
	Player *p2;
	Map* currentMap;
	int startOrLoad=0;
	
	//Welcome message
	std::cout << "Welcome to Pandemic!!!!" << endl;
	std::cout << "Do you want to:" << endl;
	std::cout << "1. Start New Game" << endl;
	std::cout << "2. Load a Game" << endl;

	cin >> startOrLoad;//User's choice of starting a new game or loading an existing one
	cin.clear();//New line for input
	cin.ignore(numeric_limits<streamsize>::max(), '\n');//Ignores data that is not an integer

	//Will keep asking the user until a valid response has been given
	while ((startOrLoad != 1) && (startOrLoad != 2)) {
		std::cout << "You entered an invalid value. Please Try Again." << endl;
		cin >> startOrLoad;
		cin.clear();
		cin.ignore(numeric_limits<streamsize>::max(), '\n');
	}

	//Depending on the input will either load an existing game or start a new one
	if (startOrLoad == 1) {//Starts a new game
		loader = new Loader("map.json");//map.json is the default file name
	}
	else {
		//Asks the user for the save file name to load
		string filename = "";
		cout << "What is the name of the file you want to load? (No need to put the extension)" << endl;
		cin >> filename;
		filename += ".json";

		loader = new Loader(filename);
	}

	currentMap = new Map();
	//sets the map from the json in the Map object
	currentMap->setMapLocation(loader->loadMap());

	vector<Player *> loadedPlayers = loader->loadPlayers();
	p1 = loadedPlayers[0];
	p2 = loadedPlayers[1];
	
	string saveFileName = "save";//save the game state in a file called save.json (for now)
	loader->save(saveFileName, currentMap->getMapLocation());
	loader->save(saveFileName, loadedPlayers);

	cout << currentMap->toString();

	//Deletes the pointer used
	delete loader;
	delete currentMap;
	system("Pause");
	
}