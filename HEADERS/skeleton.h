#pragma once

#include "SFML/Audio.hpp"
#include "SFML/Graphics.hpp"
#include "SFML/System.hpp"
#include "SFML/Window.hpp"
#include "SFML/Network.hpp"
#include <iostream>
#include "enemy.h"
#include "hub.h"

class skeleton : public enemy
{
public:

	void srender(sf::RenderTarget& target);
	void physics();
	void attack(player& p, hub& h);

	skeleton();
	~skeleton();
};
