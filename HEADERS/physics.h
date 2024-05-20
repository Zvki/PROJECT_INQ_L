#pragma once

#include "player.h"
#include "SFML/Audio.hpp"
#include "SFML/Graphics.hpp"
#include "SFML/System.hpp"
#include "SFML/Window.hpp"
#include "SFML/Network.hpp"

class physics {
private:

	sf::Vector2f velocity;
	float velocitymax;
	float velocitymin;
	float velocitymaxy;
	float accel;
	float drag;
	float grav;
	bool canjump;

public:

	friend class player;
	friend class anime;

	physics();

	~physics();

	void innitruch();

	void resetvelocityY();

	void resetvelocityX();

	void ruch(const float dir_x, const float dir_y);

	void jump();

	void updateruch(player& p);

	void updatemove(player& p, anime& a);
};