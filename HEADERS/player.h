#pragma once

#include "SFML/Audio.hpp"
#include "SFML/Graphics.hpp"
#include "SFML/System.hpp"
#include "SFML/Window.hpp"
#include "SFML/Network.hpp"
#include <iostream>

enum PLAYER_ANIMATRION_STATES { IDLE = 0, MOVING_LEFT, MOVING_RIGHT, ATTACK_1, ATTACK_2 };
enum DIRECTION {LEFT, RIGHT};

class player
{
private:

	sf::Texture texturesheet;

	//PHYSICS
	sf::Vector2f velocity;
	float velocitymax;
	float velocitymin;
	float velocitymaxy;
	float accel;
	float drag;
	float grav;
	bool canjump;

	//ANIMATION
	short animestate;

	bool animationswitch;
	bool animestarted = false;


	sf::Time animationTime_;
	sf::Time animeDuration = sf::milliseconds(250.f);


	sf::Clock animationtimer;

	sf::IntRect currentFrame;

public:

	DIRECTION direction;

	bool attack_anime = false;
	bool player_alive = true;
	bool player_dying = false;

	sf::Time attack_cooldown = sf::seconds(1.f);

	sf::Clock attack_clock;
	sf::Clock clock;

	sf::Sprite sprite;

	void innitSprite();
	void innitAnime();
	void innitTexture();

	const sf::Vector2f getposition() const;
	const sf::FloatRect getglobalbounds() const;

	player();
	virtual ~player();

	void setPosition(const float x, const float y);
	void setCanJump(const bool canJump);
	void update();
	void render(sf::RenderTarget& target);

	//PHYSICS
	void innitruch();
	void resetvelocityY();
	void resetvelocityX();
	void ruch(const float dir_x, const float dir_y);
	void jump();
	void updateruch();
	void updatemove();

	//ANIMATION
	void setcurrentframe();
	void updateanime();
	void innitvariable();
	void resetanimetimer();
	void deathanime();

	bool getattackanime() { return attack_anime; }

	const bool& getanimeswitch();

};