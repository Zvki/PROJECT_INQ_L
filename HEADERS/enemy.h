#pragma once

#include "SFML/Audio.hpp"
#include "SFML/Graphics.hpp"
#include "SFML/System.hpp"
#include "SFML/Window.hpp"
#include "SFML/Network.hpp"
#include <iostream>
#include <random>

#include "hub.h"
#include "player.h"


class enemy
{
public:
	sf::Vector2f velocity;
	sf::Vector2f direction;

	sf::Texture texturesheet;

	sf::Sprite sprite;

	sf::IntRect currentframe;
	sf::IntRect currentframe_death;

	sf::Clock animetimer;

	sf::RectangleShape healthBar;
	sf::RectangleShape healthBarBackground;

	DIRECTION enemy_direction;

	int enemy_hp;

	float grav;
	float lenght;
	float speed = 3.f;

	bool attack_cond = false;
	bool animeswitch;
	bool animestarted = false;
	bool isAlive = true;
	bool isDying = false;

	void death_condition(hub& h);
	void enemy_hp_update(player& p);
	void makealive();
	void death_anime();
	void draw_hp_bar(sf::RenderWindow& window);

	int set_position_x();

	virtual void animeenemy(sf::Sprite s, player& p, hub& h);
	virtual void move(sf::Sprite s);
	virtual void innittexture(std::string s);
	virtual void innitsprite();
	virtual void resetanimetimer();
	virtual bool getanimeswitch();

	virtual ~enemy();

};
