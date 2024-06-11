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
	sf::Time animationTime_;
	sf::Time animeDuration = sf::milliseconds(250.f);
	sf::Clock animationtimer;
	

	sf::IntRect currentFrame;
	bool animationswitch;

public:

	bool attack_anime = false;
	sf::Time attack_cooldown = sf::seconds(1.f);
	sf::Clock attack_clock;
	sf::Clock clock;
	friend class player;
	friend class physics;

	anime();

	~anime();

	void setcurrentframe();

	void updateanime(player& pl);

	void innitvariable();

	const bool& getanimeswitch();

	void resetanimetimer();

};
