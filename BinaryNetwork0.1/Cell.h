#pragma once
#include "Network.h"
class Cell :
	public Network
{
public:
	Cell();
	Cell(Cell& parent);
	~Cell();

	int getX();
	int getY();

	void steprun(bool worldValue);
	void thinking(bool worldValue);
	void move(bool neuron1, bool neuron2);
	bool isAlive();

private:
	int x;
	int y;
	const int maxDelay = 30;
	int notHunger;
};

