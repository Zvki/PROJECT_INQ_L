#pragma once

#include "physics.h"
#include "anime.h"
#include "SFML/Audio.hpp"
#include "SFML/Graphics.hpp"
#include "SFML/System.hpp"
#include "SFML/Window.hpp"
#include "SFML/Network.hpp"
#include <iostream>

enum PLAYER_ANIMATRION_STATES { IDLE = 0, MOVING_LEFT, MOVING_RIGHT, ATTACK_1 };


class player
{
private:

	sf::Texture texturesheet;

public:

	sf::Sprite sprite;

	friend class physics;
	friend class anime;

	void innitSprite(anime& a);
	void innitAnime(anime& a);
	void innitTexture();

	const sf::Vector2f getposition() const;
	const sf::FloatRect getglobalbounds() const;

	player(anime& a, physics& p);
	virtual ~player();

	void setPosition(const float x, const float y);
	void setCanJump(const bool canJump, physics& p);
	void update(physics& p, anime& a);
	void render(sf::RenderTarget& target);
};