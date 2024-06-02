#pragma once

#include "SFML/Audio.hpp"
#include "SFML/Graphics.hpp"
#include "SFML/System.hpp"
#include "SFML/Window.hpp"
#include "SFML/Network.hpp"
#include <iostream>
#include <random>

#include "anime.h"
#include "hub.h"

class enemy
{
public:

	sf::Vector2f direction;
	sf::Texture texturesheet;
	sf::Sprite sprite;
	sf::IntRect currentframe;
	sf::Clock animetimer;
	sf::Vector2f velocity;

	int enemy_hp;

	float grav;
	float lenght;
	float speed = 3.f;

	bool attack_cond = false;
	bool animeswitch;
	bool isAlive;

	bool death_condition(player& p, hub& h, anime& a);

	void enemy_hp_update(player& p, anime& a);
	void makealive();

	int set_position_x();

	virtual void animeenemy(sf::Sprite s, sf::Sprite p, hub& h);
	virtual void move(sf::Sprite s);
	virtual void innittexture(std::string s);
	virtual void innitsprite();
	virtual void resetanimetimer();
	virtual bool getanimeswitch();

	virtual ~enemy();

};
