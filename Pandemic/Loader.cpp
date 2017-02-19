#include "Loader.h"

/*
	The loader class will act as the class that will either load a game, existing or new, as well as save the game
*/

//Creates a new Loader with the will name to load when starting the game
Loader::Loader(string filename) {
	try {
		ifstream i(filename);
		i >> this->j;
	}
	catch (const std::invalid_argument& ia) {
		//Catches exception where the file entered does not exist and starts a new game
		ifstream i("map.json");
		i >> this->j;
		std::cerr << "Invalid argument: " << ia.what() << '\n';
		cerr << "Starting a New Game";
	}
}

//Will return the a map containing all initialized locations to be saved in the Map class
std::map<int, Location> Loader::loadMap() {
	map<int, Location> cityMap;
	//j[location] is the array with all the different cities. Thus each object can be accessed like a regular array
	for (int i = 0; i < j["location"].size(); i++) {
		//Loops through all cities in the JSON and puts them in a list that will be given to the map
		int cityId = j["location"][i]["id"].get<int>();
		Location l{//Calls the constructor of Location object, thus order is important to be the same
			cityId,
			j["location"][i]["city"].get<std::string>(),
			j["location"][i]["area"].get<std::string>(),
			j["location"][i]["adjacent"].get<std::vector<int>>(),
			j["location"][i]["yellow"].get<int>(),
			j["location"][i]["blue"].get<int>(),
			j["location"][i]["black"].get<int>(),
			j["location"][i]["red"].get<int>()
		};

		cityMap[cityId] = l;
	}
	return cityMap;
}

//Given the filename, will save the state of the board to a json file of that name
//The order will not be as the original file since it is stored alphabetically in the json
void Loader::save(string filename, map<int, Location> cities) {
	for (int i = 1; i < (cities.size() + 1); i++) {
	
		//i-1 because the keys in the map start at 1, but in an array, indexing starts at 0
		out["location"][i-1]["area"] = cities.at(i).getArea();
		out["location"][i-1]["city"] = cities.at(i).getCity();
		out["location"][i-1]["id"] = cities.at(i).getId();
		out["location"][i - 1]["yellow"] = cities.at(i).getYellow();
		out["location"][i - 1]["blue"] = cities.at(i).getBlue();
		out["location"][i - 1]["black"] = cities.at(i).getBlack();
		out["location"][i - 1]["red"] = cities.at(i).getRed();
		out["location"][i - 1]["adjacent"] = cities.at(i).getConnections();
	
	}

	//Saves the game information to a new or existing file of the specified name
	std::ofstream o(filename + ".json");
	o << std::setw(4) << this->out << std::endl;
}

vector<Player *> Loader::loadPlayers() {
	Player *player1;
	Player *player2;
	vector<Player *> players;

	players.push_back(player1);
	players.push_back(player2);

	int i = 0;
	for (auto &player : players) {

		Role *r = new Role (j["Players"][i]["role"].get<string>());

		vector<string> playerCardNames = j["Players"][i]["playercards"].get<vector<string>>();
		vector<PlayerCard *> pcards;

		for (auto &cardName : playerCardNames) { // for each playerCardName, create a new player card and store it in a vector. 
			PlayerCard *pc = new PlayerCard(cardName);
			pcards.push_back(pc);
		}

		Pawn *pawn = new Pawn(Color(j["Players"][i]["pawn"]["color"].get<int>())); // The color int is read from the json (since enum stored as int) 
																  //and dynamically created and allocated
		

		int playerLocation = j["Players"][i]["pawn"]["location"].get<int>();

		pawn->setPawnLocation(playerLocation);

		Player* p = new Player( // Create the player with the role, and the pawn
			r,
			pawn
		);

		player = p;
		player->setPlayerCards(pcards);

		i++;
	}


	return players;
}

//Save the state of the players in the json.
void Loader::save(string filename, vector<Player *> players) {
	for (int i = 0; i < 2; i++) {
		// Save player's role
		out["Players"][i]["role"] = players[i]->getRole()->getName();


		// Save player's cards 
		for (int j = 0; j < players[i]->getPlayerCards().size(); j++) {
			out["Players"][i]["playercards"][j] = players[i]->getPlayerCards()[j]->getCardName();
		}


		// Save player's pawn color, and location.
		out["Players"][i]["pawn"]["color"] = players[i]->getPlayerPawn()->getPawnColor();
		out["Players"][i]["pawn"]["location"] = players[i]->getPlayerPawn()->getCurrentLocation();
	}
	

	//Saves the game information to a new or existing file of the specified name
	std::ofstream o(filename + ".json");
	o << std::setw(4) << this->out << std::endl;
}