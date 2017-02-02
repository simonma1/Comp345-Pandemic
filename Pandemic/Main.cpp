#include <iostream>
#include "Player.h"
#include "Board.h"
#include "Location.h"
#include "json.hpp"
#include <vector>
#include <fstream>
using namespace std;
using json = nlohmann::json;

int main()
{

	Board board;
	Player p1;
	vector<Location> cityList;//List of cities that will be created for the map

	Map currentMap;

	
	
	
	// read a JSON file
	std::ifstream i("map.json");
	json j;
	i >> j;
	
	//j[location] is the array with all the different cities
	for (int i = 0; i < j["location"].size(); i++) {
		//Loops through all cities in the JSON and puts them in a list that will be given to the map
		Location l{
			j["location"][i]["city"].get<std::string>(),
			j["location"][i]["area"].get<std::string>()
		};
	
		cityList.push_back(l);
		std::cout << l.toString() << endl;
	
	}

	//Pass the list of city created to the map. Useful for when we will have to print it
	currentMap.setMapLocation(cityList);


	std::cout << cityList.size() << endl;

	system("Pause");
	
}