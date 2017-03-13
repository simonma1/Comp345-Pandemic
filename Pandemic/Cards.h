#pragma once
#include <string>
#include <vector>
#include <iostream>
using namespace std;


class Role
{
private:
	string name;

public:
	string getName() { return name; };
	Role(string name);
	Role();
};