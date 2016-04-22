#pragma once
#include <fstream>

class Network
{
public:
	Network();

	//defined virtual so that ~Network() is not inherited by Cell.
	virtual ~Network();

	//memory for node and link are deleted.
	void deleteNode();

	//Randomly generate all the nodes and links.
	void generateNode();

	//void print();

	//change node values for one step
	void steprun();

	//run steprun() several times.
	//void run(int step);

	//return nodeNum
	int getNum();

	//return node value
	bool getVal(int pos);

	//int getStep();
protected:
	//nodeNum up to 1000 is supported. //Other number needs View modification.
	static const int nodeNum = 100;
	//const int step = 10;
	//std::ofstream main;
	//std::ofstream input;
	//std::ofstream graph;
	//std::ofstream output;

	bool* node;
	bool** link;
};

