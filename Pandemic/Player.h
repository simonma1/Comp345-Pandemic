#pragma once
#include "Square.h"
#include "Pawn.h"
#include "ReferenceCard.h"
#include "RoleCard.h"
#include <vector>
#include "PlayerCard.h"

class Player {
public:
	Player();
	void setRole(RoleCard role);
	RoleCard getRole();
	


private:
	Pawn* pawn;
	ReferenceCard referenceCard;
	RoleCard roleCard;
	vector<PlayerCard> playerCards;
};