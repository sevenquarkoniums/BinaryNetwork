#pragma once
class World
{
public:
	World();
	~World();

	void generateWorld();
	void deleteWorld();
	bool getValue(int x, int y);
	void changeValue(int x, int y);

private:
	const int maxPos = 100;
	int length = 2 * maxPos + 1;
	bool** value;
};

