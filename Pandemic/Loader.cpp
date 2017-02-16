#include "Loader.h"

Loader::Loader(string filename) {
	try {
		ifstream i(filename);
		i >> this->j;
	}
	catch (const std::invalid_argument& ia) {
		ifstream i("map.json");
		i >> this->j;
		std::cerr << "Invalid argument: " << ia.what() << '\n';
		cerr << "Starting a New Game";
	}
}

std::map<int, Location> Loader::loadMap() {
	map<int, Location> cityMap;
	//j[location] is the array with all the different cities
	for (int i = 0; i < j["location"].size(); i++) {
		//Loops through all cities in the JSON and puts them in a list that will be given to the map
		int cityId = j["location"][i]["id"].get<int>();
		Location l{
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
		std::cout << l.toString() << endl;
	}
	return cityMap;
}

//Given the filename, will save the state of the board to a json file of that name
void Loader::save(string filename, map<int, Location> cities) {
	for (int i = 1; i < (cities.size() + 1); i++) {
	
		out["location"][i-1]["area"] = cities.at(i).getArea();
		out["location"][i-1]["city"] = cities.at(i).getCity();
		out["location"][i-1]["id"] = cities.at(i).getId();
		out["location"][i - 1]["yellow"] = cities.at(i).getYellow();
		out["location"][i - 1]["blue"] = cities.at(i).getBlue();
		out["location"][i - 1]["black"] = cities.at(i).getBlack();
		out["location"][i - 1]["red"] = cities.at(i).getRed();
		out["location"][i - 1]["adjacent"] = cities.at(i).getConnections();
	
	}

	std::ofstream o(filename + ".json");
	o << std::setw(4) << this->out << std::endl;
}

Player Loader::loadPlayers() {
	return Player();
}