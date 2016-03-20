#pragma once
#include "Network.h"
class Cell :
	public Network
{
public:
	Cell();
	Cell(Cell& parent);//initial state always by random
	Cell(Cell& parent, double mutability);//mutability from 0 to 1
	~Cell();

	int getX();
	int getY();

	void ObserveThink(bool worldValue);
	int thinking(bool worldValue);
	void move(int moveFlag, int max);
	void steprun(bool worldValue, int max);
	//void move(bool neuron1, bool neuron2, int max);
	bool isAlive();

	const int cellSize = 10;

private:
	int x;
	int y;
	const int minDelay = 10;
	const int maxDelay = 30;
	int notHunger;
};

