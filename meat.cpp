#include "meat.h"

void meat::meatSetup()
{
	for (int i = 0; i < width / cell_size; i++) {
		meat[i] = new RectangleShape[height / cell_size];
		for (int j = 0; j < height / cell_size; j++) {
			RectangleShape cell(Vector2f(cell_size, cell_size));
			cell.setOutlineThickness(1);
			cell.setOutlineColor(Color::Green);
			cell.setFillColor(Color::Black);
			cell.setPosition(i * cell_size, j * cell_size);
			meat[i][j] = cell;
		}
	}
}

void meat::drawmeat(RenderWindow& window)
{
	for (int i = 0; i < width / cell_size; i++) {
		for (int j = 0; j < height / cell_size; j++) {
			window.draw(meat[i][j]);
		}
	}
}

meat::meat(int width, int height, int cell_size):width(width),height(height),cell_size(cell_size)
{
	meat = new RectangleShape * [width / cell_size];
}

meat::~meat()
{
	delete[] meat;
}

