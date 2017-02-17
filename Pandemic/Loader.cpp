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

	Role r1{
		j["Players"][0]["role"].get<string>()
	};

	vector<string> playerCardNames1 = j["Players"][0]["playercards"].get<vector<string>>();
	vector<PlayerCard *> pc1;

	for (auto &cardName : playerCardNames1) { // for each playerCardName, create a new player card and store it in a vector. 
		PlayerCard *pc = new PlayerCard(cardName);
		pc1.push_back(pc);
	}

	Pawn pawn1{
		Color(j["Players"][0]["pawn"][0]["color"].get<int>()) // The color int is read from the json (since enum stored as int) 
															  //and dynamically created and allocated
	};

	Location p1location{
		j["location"][0]["id"].get<int>(),
		j["location"][0]["city"].get<std::string>(),
		j["location"][0]["area"].get<std::string>(),
		j["location"][0]["adjacent"].get<std::vector<int>>(),
		j["location"][0]["yellow"].get<int>(),
		j["location"][0]["blue"].get<int>(),
		j["location"][0]["black"].get<int>(),
		j["location"][0]["red"].get<int>()
	};

	pawn1.setPawnLocation(p1location);

	Player p1{ // Create the player with the role, and the pawn
		&r1,
		&pawn1
	};
	
	player1 = &p1;
	player1->setPlayerCards(pc1);

	players.push_back(player1);
	players.push_back(player2);

	return players;
}

//Save the state of the players in the json.
void Loader::save(string filename, Player *player1, Player *player2) {

	// Save player1's role
	out["Players"][0]["role"] = player1->getRole()->getName();

	// Save player1's cards 
	int i = 0;
	for (auto &card : player1->getPlayerCards()) {
		out["Players"][0]["playercards"][i] = card->getCardName();
	}

	// Save player1's pawn color, and location.
	out["Players"][0]["pawn"][0]["color"] = player1->getPlayerPawn()->getPawnColor();
	out["Players"][0]["pawn"][0]["location"][0]["id"] = player1->getPlayerPawn()->getCurrentLocation().getId();
	out["Players"][0]["pawn"][0]["location"][0]["city"] = player1->getPlayerPawn()->getCurrentLocation().getCity();
	out["Players"][0]["pawn"][0]["locationId"][0]["area"] = player1->getPlayerPawn()->getCurrentLocation().getArea();
	out["Players"][0]["pawn"][0]["locationId"][0]["yellow"] = player1->getPlayerPawn()->getCurrentLocation().getYellow();
	out["Players"][0]["pawn"][0]["locationId"][0]["red"] = player1->getPlayerPawn()->getCurrentLocation().getRed();
	out["Players"][0]["pawn"][0]["locationId"][0]["blue"] = player1->getPlayerPawn()->getCurrentLocation().getBlue();
	out["Players"][0]["pawn"][0]["locationId"][0]["black"] = player1->getPlayerPawn()->getCurrentLocation().getBlack();
	out["Players"][0]["pawn"][0]["locationId"][0]["adjacent"] = player1->getPlayerPawn()->getCurrentLocation().getConnections();


	
	//--------------------



	// Save player2's role
	out["Players"][1]["role"] = player2->getRole()->getName();

	// Save player2's cards
	i = 0;
	for (auto &card : player2->getPlayerCards()) {
		out["Players"][1]["playercards"][i] = card->getCardName();
	}

	// Save player2's pawn color, and location. 
	out["Players"][1]["pawn"][0]["color"] = player2->getPlayerPawn()->getPawnColor();
	out["Players"][1]["pawn"][0]["location"][0]["id"] = player2->getPlayerPawn()->getCurrentLocation().getId();
	out["Players"][1]["pawn"][0]["location"][0]["city"] = player2->getPlayerPawn()->getCurrentLocation().getCity();
	out["Players"][1]["pawn"][0]["location"][0]["area"] = player2->getPlayerPawn()->getCurrentLocation().getArea();
	out["Players"][1]["pawn"][0]["location"][0]["yellow"] = player2->getPlayerPawn()->getCurrentLocation().getYellow();
	out["Players"][1]["pawn"][0]["location"][0]["red"] = player2->getPlayerPawn()->getCurrentLocation().getRed();
	out["Players"][1]["pawn"][0]["location"][0]["blue"] = player2->getPlayerPawn()->getCurrentLocation().getBlue();
	out["Players"][1]["pawn"][0]["location"][0]["black"] = player2->getPlayerPawn()->getCurrentLocation().getBlack();
	out["Players"][1]["pawn"][0]["location"][0]["adjacent"] = player2->getPlayerPawn()->getCurrentLocation().getCity();



	//Saves the game information to a new or existing file of the specified name
	std::ofstream o(filename + ".json");
	o << std::setw(4) << this->out << std::endl;
}