#include "physics.h"
#include "player.h"

physics::physics()
{
}

physics::~physics()
{
}

void physics::innitruch()
{
	this->velocitymax = 10.f;
	this->velocitymin = 0.5f;
	this->velocitymaxy = 15.f;
	this->accel = 1.05f;
	this->drag = 0.9f;
	this->grav = 2.f;
	this->canjump = false;
}

void physics::resetvelocityY()
{
	this->velocity.y = 0.f;
}

void physics::resetvelocityX()
{
	this->velocity.x = 0.f;
}

void physics::ruch(const float dir_x, const float dir_y)
{
	//Acceleration

	this->velocity.x += dir_x * this->accel;


	//Limit Accel

	if (std::abs(this->velocity.x) > this->velocitymax) {
		this->velocity.x = this->velocitymax * ((this->velocity.x < 0.f) ? -1.f : 1.f);
	}
}

void physics::jump()
{
	this->velocity.y = -200.f;
	this->canjump = false;
}

void physics::updateruch(player& p)
{
	//Grav
	this->velocity.y += 0.3 * this->grav;

	//Limit Grav
	if (std::abs(this->velocity.y) > this->velocitymaxy) {
		this->velocity.y = this->velocitymaxy * ((this->velocity.y < 0.f) ? -1.f : 1.f);
	}

	//Drag
	this->velocity *= this->drag;

	//Limit drag
	if (std::abs(this->velocity.x) < this->velocitymin) {
		this->velocity.x = 0.f;
	}
	if (std::abs(this->velocity.y) < this->velocitymin) {
		this->velocity.y = 0.f;
	}

	p.sprite.move(this->velocity);
}

void physics::updatemove(player& p, anime& a)
{
	a.animestate = IDLE;
	//LEWO
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::A)) {
		this->ruch(-1.f, 0.f);
		a.animestate = MOVING_LEFT;
	}
	//PRAWO
	else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::D)) {
		this->ruch(1.f, 0.f);
		a.animestate = MOVING_RIGHT;
	}
	//SKOK
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::W) && canjump) {
		this->jump();
	}
}