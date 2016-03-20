#pragma once
class World
{
public:
	World();
	~World();

	void generateRandomWorld();
	void generateSquareWave();//with Wavelength=10
	void deleteWorld();
	bool getValue(int x, int y);
	void changeValue(int x, int y);
	int getMax() {
		return maxPos;
	}
	int getLength() {
		return length;
	}

private:
	const int maxPos = 40;
	const int length = 2 * maxPos + 1;
	bool** value;
};

