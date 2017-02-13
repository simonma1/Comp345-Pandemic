#include "Loader.h"

Loader::Loader(string filename) {
	std::ifstream i("map.json");
	i >> this->j;
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
			j["location"][i]["area"].get<std::string>()
		};

		cityMap[cityId] = l;
		std::cout << l.toString() << endl;
	}
	return cityMap;
}

Player Loader::loadPlayers() {
	return Player();
}