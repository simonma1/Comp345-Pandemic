#include <iostream>
#include "Pawn.h"
#include "PlayerCard.h"
#include "Player.h"
#include "ReferenceCard.h"
#include "RoleCard.h"
#include "Square.h"

using namespace std;

int main()
{
	// Creating the players
	Player* harrison = new Player();
	Player* simon = new Player();

	//Creating the roles
	RoleCard* scientist = new RoleCard();
	RoleCard* explorer = new RoleCard();

	//Setting the role's colors
	scientist->setColor("blue");
	explorer->setColor("red");

	//Status update
	cout << "scientist is " << scientist->getColor() << " and explorer is " << explorer->getColor() << endl;
	system("PAUSE");

	//Setting the player's roles
	harrison->setRole(scientist);
	simon->setRole(explorer);

	//Creating the pawns
	Pawn* hPawn = new Pawn(harrison->getRole()->getColor());
	Pawn* sPawn = new Pawn(simon->getRole()->getColor());

	//Status update
	cout << "hPawn is " << hPawn->getColor() << " and sPawn is " << sPawn->getColor() << endl;

	//Setting the pawns
	harrison->setPawn(hPawn);
	simon->setPawn(sPawn);

	//Status update
	cout << "Harrison\'s role " + harrison->getRole()->getColor() << endl;
	cout << "Harrison\'s pawn " + harrison->getPawn()->getColor() << endl;

	system("PAUSE");

	cout << "Simon\'s role " + simon->getRole()->getColor() << endl;
	cout << "Simon\'s pawn " + simon->getPawn()->getColor() << endl;

	system("PAUSE");
}