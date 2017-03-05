#include <iostream>
#include "Player.h"
#include "Board.h"
#include "Location.h"
#include "Loader.h"
#include "Cards.h"
#include "ReferenceCard.h"
#include <vector>
using namespace std;

int main()
{
	Loader* loader;
	Board board = Board();
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
	vector<Player *> players;
	//Depending on the input will either load an existing game or start a new one
	if (startOrLoad == 1) {//Starts a new game
		loader = new Loader("map.json");//map.json is the default file name
		
		//Creates some value to be passed to the player object. This is for demo purpose
		Role* role = new Role("Scientist");
		Role* role2 = new Role("Medic");

		PlayerCard* card1 = new CityCard("Bitch ass");
		PlayerCard* card2 = new CityCard("Bitch ass nigguh");

		vector<PlayerCard* > cards1;
		cards1.push_back(card1);

		vector<PlayerCard* > cards2;
		cards2.push_back(card2);

		//Creates 2 players
		board.initializeNewPlayer(role);
		board.initializeNewPlayer(role2);

		players = board.getListOfPlayer();
		p1 = players[0];
		p2 = players[1];
	}
	else {
		//Asks the user for the save file name to load
		string filename = "";
		cout << "What is the name of the file you want to load? (No need to put the extension)" << endl;
		cin >> filename;
		filename += ".json";

		loader = new Loader(filename);
		players = loader->loadPlayers();
		p1 = players[0];
		p2 = players[1];
	}

	//Creates Reference card for the players. To be modified later on
	ReferenceCard* ref1 = new ReferenceCard;
	ReferenceCard* ref2 = new ReferenceCard;
	p1->setReferenceCard(ref1);
	p2->setReferenceCard(ref2);

	ref1->displayPossibleActions();

	currentMap = new Map();

	//sets the map from the json in the Map object
	currentMap->setMapLocation(loader->loadMap());
	board.setMap(currentMap);

	cout << board.toString();

	//Prints the players detail
	for (int i = 0; i < players.size(); i++) {
		cout << (*players[i]).toString() << endl;
		cout << endl;
	}
	
	string saveFileName = "save";//save the game state in a file called save.json (for now)
	loader->save(saveFileName, currentMap->getMapLocation());
	loader->save(saveFileName, players);

	//Deletes the pointer used
	delete loader;
	system("Pause");
}