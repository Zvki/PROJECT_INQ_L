#pragma once

#include "SFML/Audio.hpp"
#include "SFML/Graphics.hpp"
#include "SFML/System.hpp"
#include "SFML/Window.hpp"
#include "SFML/Network.hpp"
#include <iostream>

class enemy
{
public:

	sf::Vector2f direction;
	sf::Texture texturesheet;
	sf::Sprite sprite;
	sf::IntRect currentframe;
	sf::Clock animetimer;
	sf::Vector2f velocity;

	float grav;
	float lenght;
	float speed = 3.f;

	bool attack_cond = false;
	bool animeswitch;

	virtual void animeenemy(sf::Sprite s, sf::Sprite p);
	virtual void move(sf::Sprite s);
	virtual void innittexture(std::string s);
	virtual void innitsprite();
	virtual void resetanimetimer();
	virtual bool getanimeswitch();

	virtual ~enemy();

};