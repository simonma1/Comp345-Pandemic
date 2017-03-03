#include "Board.h"

/*
The board class will act as an intermediary between location and player
*/

Board::Board()
{
}

//Destructor for the Board object. Will delete every player from the vector of player pointer
Board::~Board()
{
	for (int i = 0; i < players.size(); i++)
	{
		delete players[i];
	}
}

void Board::addPlayer(Player * p)
{
	players.push_back(p);
}

/*
Creates a new player to be put in the list of player. The player will be given a pawn of a 
random color. No 2 players will receive the same one. The pawn will be link to the class of 
that color
*/
void Board::initializeNewPlayer(Role* role)
{
	Player* player = new Player();
	string color = getRandomColorFromRemaining();//Returns the color of the pawn
	player->setPawn(color);//Sets the pawn with the color for the player
	player->setRole(role);
	addPlayer(player);//adds the player to the list of player

}

//Generates a random color from the colors list for a new player
string Board::getRandomColorFromRemaining()
{
	srand(time(NULL));//Allows for the randomness
	int randomNum = rand() % colors.size();//Normalizes the value by the amount of colors available
	string color = colors[randomNum];//Gets the color at the index randomly chosen
	colors.erase(colors.begin() + randomNum);//Removes the color from the list
	return color;
}
