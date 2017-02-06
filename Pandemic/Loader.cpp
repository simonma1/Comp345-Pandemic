#include "Loader.h"

Loader::Loader(string filename) {
	std::ifstream i("map.json");
	i >> this->j;
}

std::vector<Location> Loader::loadMap() {
	vector<Location> cityList;
	//j[location] is the array with all the different cities
	for (int i = 0; i < j["location"].size(); i++) {
		//Loops through all cities in the JSON and puts them in a list that will be given to the map
		Location l{
			j["location"][i]["id"].get<int>(),
			j["location"][i]["city"].get<std::string>(),
			j["location"][i]["area"].get<std::string>()
		};

		cityList.push_back(l);
		std::cout << l.toString() << endl;
	}
	return cityList;
}

Player loadPlayers() {
	return Player();
}