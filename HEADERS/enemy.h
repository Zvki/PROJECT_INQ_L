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


class enemy: public entity
{
public:
	sf::Vector2f direction;

	sf::IntRect currentframe_death;

	sf::RectangleShape healthBar;
	sf::RectangleShape healthBarBackground;

	int enemy_hp;

	float grav;
	float lenght;
	float speed = 3.f;

	bool attack_cond = false;
	bool animestarted = false;

	void death_condition(hub& h);
	void enemy_hp_update(player& p);
	void makealive();
	void death_anime() override;
	void draw_hp_bar(sf::RenderWindow& window);

	int set_position_x();

	void animation(sf::Sprite s, player& p, hub& h);
	void move(sf::Sprite s);
	void innittexture(std::string s);
	void innitsprite();
	void resetanimetimer();
	bool getanimeswitch();

	virtual ~enemy();

};
