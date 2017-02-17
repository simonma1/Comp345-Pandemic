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

Player Loader::loadPlayers() {
	return Player();
}

//Save the state of the players in the json.
void Loader::save(string filename, Player* player1, Player* player2) {

	// Save player1's role
	out["Players"][0]["role"] = player1->getRole().getName();

	// Save player1's cards
	int i = 0;
	for (auto &card : player1->getPlayerCards()) {
		out["Players"][0]["playercards"][i] = card->getCardName();;
	}

	// Save player1's pawn color, and locationID. The reason why we don't want to save the entire location class is because the state
	// of the location will be saved in the locations part of the json. We will only be using the id from here to fetch the information
	// in that part of the json.
	out["Players"][0]["pawn"][0]["color"] = player1->getPlayerPawn().getPawnColor();
	out["Players"][0]["pawn"][0]["locationId"] = player1->getPlayerPawn().getCurrentLocation().getId();


	
	//--------------------



	// Save player2's role
	out["Players"][1]["role"] = player2->getRole().getName();

	// Save player2's cards
	i = 0;
	for (auto &card : player2->getPlayerCards()) {
		out["Players"][1]["playercards"][i] = card->getCardName();;
	}

	// Save player2's pawn color, and locationID. The reason why we don't want to save the entire location class is because the state
	// of the location will be saved in the locations part of the json. We will only be using the id from here to fetch the information
	// in that part of the json.
	out["Players"][1]["pawn"][0]["color"] = player2->getPlayerPawn().getPawnColor();
	out["Players"][1]["pawn"][0]["locationId"] = player2->getPlayerPawn().getCurrentLocation().getId();


	//Saves the game information to a new or existing file of the specified name
	std::ofstream o(filename + ".json");
	o << std::setw(4) << this->out << std::endl;
}