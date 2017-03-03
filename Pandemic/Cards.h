#include <string>
#pragma once

class ReferenceCard
{
private:
	std::string name;

public:
	std::string getName(){ return name; };
	ReferenceCard(std::string);
};

class PlayerCard
{
private:
	std::string cardName;

public:
	std::string getCardName();
	PlayerCard(std::string cardName);

};

class Role
{
private:
	std::string name;

public:
	std::string getName() { return name; };
	Role(std::string name);
};