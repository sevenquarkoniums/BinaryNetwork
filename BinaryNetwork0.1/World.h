#pragma once
class World
{
public:
	World();
	World(int pmax, int plength);
	~World();

	void setup(int pmax, int plength);
	void generateRandomWorld();
	void generateSquareWave();//with Wavelength=10
	void deleteWorld();
	bool getValue(int x, int y);
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
	int maxPos;
	int length;

	bool** value;
};

