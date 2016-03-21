#pragma once
#include "Network.h"
class Cell :
	public Network
{
public:
	Cell();
	Cell(int px, int py, int pnotHunger);
	Cell(const Cell& parent);//initial state always by random
	Cell(Cell& parent, double mutability);//mutability from 0 to 1
	~Cell();

	int getX();
	int getY();

	void setup(int px, int py, int pnotHunger);
	void ObserveThink(bool worldValue);
	int thinking(bool worldValue);
	void move(int moveFlag, int max);
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

