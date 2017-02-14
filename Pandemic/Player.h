#pragma once
#include "Square.h"
#include "Pawn.h"
#include "ReferenceCard.h"
#include "RoleCard.h"
#include <vector>
#include <algorithm>
#include "PlayerCard.h"

class Player {
public:
	Player();
	~Player();


	RoleCard* getRole();
	void setRole(RoleCard* newRoleCard);
	Pawn* getPawn();
	void setPawn(Pawn* newPawn);
	vector<PlayerCard*> getPlayerCards();
	void addPlayerCard(PlayerCard* newPlayerCard);

private:
	Pawn* pawn;
	ReferenceCard* referenceCard;
	RoleCard* roleCard;
	vector<PlayerCard*> playerCards;
};