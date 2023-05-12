#pragma once
#include "settings.h"
#include "game_object.h"
#include "Text.h"

class Player : public GameObject
{
private:
	float speedy = 0;
	int point0, point1;
public:
	Player()
	{
		texture.loadFromFile(PLAYER_FILE_NAME);
		sprite.setTexture(texture);
		sf::FloatRect bounds = sprite.getLocalBounds();
		sprite.setOrigin(bounds.width / 2, bounds.height / 2);
	}
	//void update() const;

	void draw(sf::RenderWindow window)
	{
		window.draw(sprite);
	}
};