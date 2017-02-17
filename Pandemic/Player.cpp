#include "Player.h"



Role Player::getRole()
{
	return role;
}

//The player will move the Pawn 
Location Player::movePawn()
{
	return playerPawn->getCurrentLocation();//Returns the current location for now
}

//Constructor for the player. 
Player::Player() {
	playerPawn = new Pawn();

}

string Player::toString(){
	string playerInfo = "Here is the info of the player:\n" "Pawn:"+ playerPawn->getColor() + "\n";

	return playerInfo;
}

Player::~Player() {
	delete playerPawn;
}

