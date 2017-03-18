#pragma once
#include "Map.h"
#include "Observer.h"

class MapObserverViewer : public Observer {
public:
	void update(Observable* o);
};
