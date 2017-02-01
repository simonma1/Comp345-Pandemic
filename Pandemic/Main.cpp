#include <iostream>;
#include "Player.h";
#include "Board.h"
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

	std::cout << j["map"]["areas"][1]["area"] << endl;
	system("Pause");
	
}