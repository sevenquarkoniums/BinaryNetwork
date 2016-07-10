#include "stdafx.h"
#include "Network.h"
#include <fstream>


Network::Network()
	:node(NULL), link(NULL)
{
	//main.open("main.txt");
	//output.open("output.txt");
}


Network::~Network()
{
	deleteNode();
	//main.close();
	//output.close();
}

void Network::deleteNode() {
	if (node != NULL) {
		delete[] node;
		node = NULL;
	}
	if (link != NULL) {
		for (int row = 0; row < nodeNum; row++) {
			if (link[row] != NULL) {
				delete[] link[row];
				link[row] = NULL;
			}
		}
		delete[] link;
		link = NULL;
	}
}

void Network::generateNode() {
	if (node != NULL || link != NULL) {
		deleteNode();
	}
	node = new bool[nodeNum];
	for (int i = 0; i < nodeNum; i++) {
		//node[i] = bool(rand() % 2); //randomly initialize the state of neurons in the brain
		node[i] = bool(i % 2); //always initialize in a definite type, so that the sons of the living cells perform better.
	}

	link = new bool*[nodeNum];
	for (int i = 0; i < nodeNum; i++) {
		link[i] = new bool[nodeNum];
	}
	for (int i = 0; i < nodeNum; i++) {
		for (int j = 0; j < i; j++) {
			link[i][j] = link[j][i];
		}
		link[i][i] = 1;
		for (int j = i + 1; j < nodeNum; j++) {
			link[i][j] = bool(rand() % 2);
		}
	}

}

//void Network::print() {
//	input.open("input.txt");
//	graph.open("graph.txt");
//
//	for (int i = 0; i < nodeNum; i++) {
//		input << node[i] << "\t";
//	}
//	input << "\n";
//	for (int i = 0; i < nodeNum; i++) {
//		for (int j = 0; j < nodeNum; j++) {
//			graph << link[i][j] << "\t";
//		}
//		graph << "\n";
//	}
//
//	input.close();
//	graph.close();
//
//}

void Network::steprun() {
	bool* nodeTemp=new bool[nodeNum];
	for (int inode = 0; inode < nodeNum; inode++) {
		int sum = 0;
		for (int jnode = 0; jnode < inode; jnode++) {
			if (link[inode][jnode] == 1 && node[jnode] == 1) {
				sum++;
			}
		}
		for (int jnode = inode + 1; jnode < nodeNum; jnode++) {
			if (link[inode][jnode] == 1 && node[jnode] == 1) {
				sum++;
			}
		}
		//main << sum << "\n";
		nodeTemp[inode] = bool(sum % 2);
	}
	for (int inode = 0; inode < nodeNum; inode++) {
		node[inode] = nodeTemp[inode];
	}

    //output.txt should be open if outputs.
	//for (int inode = 0; inode < nodeNum; inode++) {
	//	output << node[inode];// << "\t";
	//}
	//output << "\n";

	delete[] nodeTemp;
}

//void Network::run(int step) {//output.txt should be open.
//	for (int istep = 0; istep < step; istep++) {
//		steprun();
//	}
//}

int Network::getNum()
{
	return nodeNum;
}

bool Network::getVal(int pos)
{
	return node[pos];
}

//int Network::getStep()
//{
//	return step;
//}
