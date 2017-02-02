#include <iostream>;
#include "Player.h";
#include "Board.h"
#include "Location.h"
#include "json.hpp"
#include <fstream>
using namespace std;
using json = nlohmann::json;

int main()
{

	Board board;
	Player p1;
	
	
	// read a JSON file
	std::ifstream i("map.json");
	json j;
	i >> j;
	
	for (int i = 0; i < j["location"].size(); i++) {
		Location l{
			j["location"][i]["city"].get<std::string>(),
			j["location"][i]["area"].get<std::string>()
		};
	
		std::cout << l.toString() << endl;
	
	}


	std::cout << j["location"].size() << endl;

	system("Pause");
	
}