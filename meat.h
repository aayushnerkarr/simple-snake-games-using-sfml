#pragma once
#include <SFML/Graphics.hpp>
using namespace sf;
class meat
{
private:
	RectangleShape** meat = nullptr;

	int width, height, cell_size;
public:
	meat(int width, int height, int cell_size);
	~meat();

	void meatSetup();
	void drawmeat(RenderWindow& window);
};

