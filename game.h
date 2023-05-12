#pragma once
#include "settings.h"

class Game {
public:
	Game() {
		window.create(sf::VideoMode(WINDOW_WIDTH, WINDOW_HEIGHT), WINDOW_TITLE);
		window.setFramerateLimit(FPS);
	}

	void play() {
		while (window.isOpen()) {
			checkEvents();
			update();
			checkCollisions();
			draw();
		}
	}
private:
	sf::RenderWindow window;
	sf::RectangleShape block[COL_LINE][COL_ROW];
	//Player player;

	void checkEvents() {
		sf::Event event;
		while (window.pollEvent(event)) {
			if (event.type == sf::Event::Closed)
				window.close();
		}
	}

	void update() {
		//player.update();
		float k = BLOCK_HEIGHT, f = 50;
		for (int j = 0; j < COL_ROW; j++)
		{
			for (int i = 0; i < COL_LINE; i++)
			{
				block[i][j].setSize(sf::Vector2f{ BLOCK_WIDTH, BLOCK_HEIGHT });
				block[i][j].setFillColor(BLOCK_COLOR);
				block[i][j].setPosition(f, k);
				f += BLOCK_WIDTH + 5;
			}
			f = 50;
			k += BLOCK_HEIGHT + 5;
		}
	}

	void checkCollisions() {}

	void draw()
	{
		window.clear();
		for (int j = 0; j < COL_ROW; j++)
		{
			for (int i = 0; i < COL_LINE; i++)
			{
				window.draw(block[i][j]);
			}
		}
		window.display();
	}
};