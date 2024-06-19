#pragma once

#include "SFML/Audio.hpp"
#include "SFML/Graphics.hpp"
#include "SFML/System.hpp"
#include "SFML/Window.hpp"
#include "SFML/Network.hpp"
#include <iostream>

#include "Entity.h"
#include "projectilemanager.h"
#include "projectile.h"

enum PLAYER_ANIMATRION_STATES { IDLE = 0, MOVING_LEFT, MOVING_RIGHT, ATTACK_1, ATTACK_2 };

class projectilemanager;

class player : public entity
{
private:

	//PHYSICS
	float velocitymax;
	float velocitymin;
	float velocitymaxy;
	float accel;
	float drag;
	float grav;
	bool canjump;

	//ANIMATION
	short animestate;

	bool animestarted = false;


	sf::Time animationTime_;
	sf::Time animeDuration = sf::milliseconds(250.f);
	sf::Time animeDuration_fireball = sf::milliseconds(400.f);


public:

	projectilemanager* projectile_manager_ ;

	bool attack_anime = false;
	bool fireball_attack_anime = false;

	sf::Time attack_cooldown = sf::seconds(1.f);
	sf::Time fireball_attack_cooldown = sf::seconds(3.f);

	sf::Clock attack_clock;
	sf::Clock fireball_attack_clock;
	sf::Clock clock;


	void innitsprite() override;
	void innitAnime();
	void innittexture();

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
	void animation();
	void innitvariable();
	void resetanimetimer();
	void death_anime() override;

	bool getattackanime() { return attack_anime; }

	const bool& getanimeswitch();

};

class projectile : public entity
{
public:

	bool animestarted;
	bool animestarted_flying = true;
	bool active = true;
	bool getanimeswitch();

	projectile(player& p);

	void innittexture();
	void innitsprite() override;
	void death_anime() override;
	void animation();
	void move();
};

class projectilemanager
{
public:

	std::vector<projectile*> projectile_;

	projectilemanager();

	void update_projectile(player& p);
	void innit_fireball(player& p);
	void render_fireball(sf::RenderTarget& window);

	void remove_projectile();
};



