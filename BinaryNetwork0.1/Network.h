#pragma once
#include <fstream>

class Network
{
public:
	Network();
	~Network();
	void deleteNode();
	void generateNode();
	void print();
	void steprun();
	void run(int step);
	int getNum();
	bool getVal(int pos);
	//int getStep();
private:
	const int nodeNum = 100;//nodeNum up to 1000 is supported.
	//const int step = 10;
	std::ofstream main;
	std::ofstream input;
	std::ofstream graph;
	std::ofstream output;

	bool* node;
	bool** link;
};
