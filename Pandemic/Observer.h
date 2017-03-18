#pragma once
#include "Observable.h"

class Observable;

class Observer {
public:
	virtual void update(Observable*) = 0;
};