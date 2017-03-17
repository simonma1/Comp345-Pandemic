#pragma once
#include "Observable.h"

class Observer {
public:
	virtual void update(Observable*) = 0;
};
