#include <string>
#include <vector>
using namespace std;
#pragma once

//Each player will be handed out 3 random city cards at the start of the game. It should be noted that while there is more information on this card
//, the implementation of this class is left to the individual handling DISTINCT PART 3). The following is a vector of strings that correspond to the cities referred to by the city cards of the game.
static vector<string> citiesConnect = {
	"Montreal, Blue",
	"New York, Blue",
	"Washington, Blue",
	"Chicago, Blue",
	"Atlanta, Blue",
	"San Francisco, Blue",
	"London, Blue",
	"Paris, Blue",
	"Madrid, Blue",
	"Milan, Blue",
	"Essen, Blue",
	"St-Petersburg, Blue",

	"Los Angeles, Yellow",
	"Miami, Yellow",
	"Mexico City, Yellow",
	"Bogota, Yellow",
	"Lima, Yellow",
	"Santiago, Yellow",
	"Bueno Aires, Yellow",
	"Sao Paolo, Yellow",
	"Lagos, Yellow",
	"Kinshasa, Yellow",
	"Johannesburg, Yellow",
	"Khartoum, Yellow",

	"Algiers, Black",
	"Cairo, Black",
	"Istanbul, Black",
	"Baghdad, Black",
	"Riyadh, Black",
	"Moscow, Black",
	"Tehran, Black",
	"Karachi, Black",
	"Delhi, Black",
	"Mumbai, Black",
	"Kolkata, Black",
	"Chennai, Black",

	"Bangkok, Red",
	"Jakarta, Red",
	"Hong Kong, Red",
	"Ho Chi Minh City, Red",
	"Shanghai, Red",
	"Beijing, Red",
	"Seoul, Red",
	"Tokyo, Red",
	"Osaka, Red",
	"Taipei, Red",
	"Manila, Red",
	"Sydney, Red",
};

class CityCard {

private:
	string randomCity;

public:
	CityCard();

	//Getter method for the city location
	string getCityCardLocation();
};