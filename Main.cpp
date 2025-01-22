#include <SFML/Graphics.hpp>
#include <iostream>

#include "meat.h"
#include "Snake.h"
#include "Food.h"

using namespace sf;
using namespace std;

const int height = 600;
const int width = 600;

int main() {

	srand(time(0));

	RenderWindow* window = new RenderWindow(VideoMode(width, height), "Normal Snake Game");
	window->setFramerateLimit(15);

	meat* _meat = new meat(width, height, 30);
	_meat->meatSetup();

	Snake* _snake = new Snake(width, height, 30);

	Food* food = new Food(&_snake, width, height, 30);

	while (window->isOpen()) {
		Event event;

		if (window->pollEvent(event)) {
			if (event.type == Event::Closed) {
				delete _meat;
				delete _snake;
				delete food;
				window->close();
			}
		}

		_snake->update_snake();

		window->clear();
		
		_meat->drawmeat(*window);
		_snake->draw_snake(*window);
		food->drawFood(&window);

		window->display();
	}


	return 0;
}