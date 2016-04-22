#pragma once
#include "Network.h"
class Cell :
	public Network
{
public:
	//A node is generated at (0,0) with initNotHunger.
	Cell();

	//A node generated with specific value.
	Cell(int px, int py, int pnotHunger);

	//A node is generated at (0,0) with initNotHunger, random node value, and links from parent Cell.
	Cell(const Cell& parent);

	//high mutability results in more variation from parent Cell, random node value.
	Cell(Cell& parent, double mutability);//mutability from 0 to 1

	//deleteNode().
	~Cell();

	int getX();
	int getY();

	//change the cell position and notHunger
	void setup(int px, int py, int pnotHunger);

	//node value change one step with given visual stimulus.
	void ObserveThink(bool worldValue);

	//decides move direction by average the nodes.
	int thinking(bool worldValue);

	//Change cell position. 0-right, 1-up, 2-left, 3-down.
	void move(int moveFlag, int max);

	//change notHunger and move()
	void steprun(bool worldValue, int max);

	bool isAlive();

private:
	int x;
	int y;
	int notHunger;
	static const int initNotHunger = 3;
	static const int minDelay = 50;
	static const int maxDelay = 100;
	//int x = 0;
	//int y = 0;
	//int notHunger = 10;
};

