#pragma once
class World
{
public:
	//need to select the world configuration. need to set initial value of world.
	World();

	//initialize the world with given parameter.
	World(int pmax, int plength);

	//deleteWorld()
	~World();

	//just change the parameters.
	void setup(int pmax, int plength);

	void generateRandomWorld();

	//need to setup wavelength.
	void generateSquareWave();

	void generateLine();

	void deleteWorld();

	bool getValue(int x, int y);

	//update when Cell is here.
	void updateValue(int x, int y);

	int getMax() {
		return maxPos;
	}

	int getLength() {
		return length;
	}

private:
	//static const int maxPos = 40;
	//static const int length = 2 * maxPos + 1;
	//int maxPos = 40;
	//int length = 2 * maxPos + 1;

	//the maximum x coordinate
	int maxPos;
	//the total length in x direction, length = 2 * maxPos + 1.
	int length;

	bool** value;
};

