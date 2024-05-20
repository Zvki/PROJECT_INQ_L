#pragma once

#include "player.h"
#include "SFML/Audio.hpp"
#include "SFML/Graphics.hpp"
#include "SFML/System.hpp"
#include "SFML/Window.hpp"
#include "SFML/Network.hpp"

class anime {
private:

	short animestate;
	sf::Clock animationtimer;
	sf::IntRect currentFrame;
	bool animationswitch;

public:

	friend class player;
	friend class physics;

	anime();

	~anime();

	void updateanime(player& pl);

	void innitvariable();

	const bool& getanimeswitch();

	void resetanimetimer();

};
