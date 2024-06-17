#pragma once

enum DIRECTION { LEFT, RIGHT };

class entity {
public:

	sf::Sprite sprite;
	sf::Texture texturesheet;
	sf::Clock animetimer;
	sf::IntRect currentframe;
	sf::Vector2f velocity;

	bool animeswitch;
	bool isalive = true;
	bool isdying = false;

	DIRECTION direction_lr;

	virtual void death_anime() = 0;

};