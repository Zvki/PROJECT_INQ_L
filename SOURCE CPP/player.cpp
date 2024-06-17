#include "player.h"


void player::innitTexture()
{

	if(!this->texturesheet.loadFromFile("TEXTURE/FIRE_WIZARD/fire_wiz.png")){
		std::cout << "ERROR: COULD NOT FIND THE PLAYER IDLE TEXTURE \n";
	}

}

void player::innitSprite()
{
	this->sprite.setTexture(this->texturesheet);
	currentFrame = sf::IntRect(0, 0, 128, 128);

	this->sprite.setTextureRect(sf::IntRect(currentFrame));
	this->sprite.setScale(2.f, 2.f);
}

void player::innitAnime()
{
	animationtimer.restart();
	animationswitch = true;
}

void player::setCanJump(const bool canJump)
{
	canjump = canJump;
}

player::player()
{
	innitvariable();
	this->innitTexture();
	this->innitSprite();
	this->innitAnime();
	innitruch();
}

player::~player()
{
}

void player::innitruch()
{
	this->velocitymax = 10.f;
	this->velocitymin = 0.5f;
	this->velocitymaxy = 15.f;
	this->accel = 1.05f;
	this->drag = 0.9f;
	this->grav = 2.f;
	this->canjump = false;
}

void player::resetvelocityY()
{
	this->velocity.y = 0.f;
}

void player::resetvelocityX()
{
	this->velocity.x = 0.f;
}

void player::ruch(const float dir_x, const float dir_y)
{
	//Acceleration

	this->velocity.x += dir_x * this->accel;


	//Limit Accel

	if (std::abs(this->velocity.x) > this->velocitymax) {
		this->velocity.x = this->velocitymax * ((this->velocity.x < 0.f) ? -1.f : 1.f);
	}
}

void player::jump()
{
	std::cout << "Jump executed\n";
	this->velocity.y = -200.f;
	this->canjump = false;
}

void player::updateruch()
{
	std::cout << "updateruch executed\n";
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

	sprite.move(this->velocity);
}

void player::updatemove()
{
	animestate = IDLE;
	//LEWO
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::A)) {
		this->ruch(-1.f, 0.f);
		animestate = MOVING_LEFT;
	}
	//PRAWO
	else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::D)) {
		this->ruch(1.f, 0.f);
		animestate = MOVING_RIGHT;
	}
	//SKOK
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::W) && canjump) {
		std::cout << "Jump condition met\n";
		this->jump();
	}
}

void player::setcurrentframe()
{
	this->currentFrame.left = 0;
}

void player::updateanime()
{
	//BASIC ATTACK
	if (this->attack_anime == true) {
		this->animationTime_ = clock.getElapsedTime();
		if (animationTime_ < animeDuration)
		{
			if (this->animationtimer.getElapsedTime().asMilliseconds() >= 50.f) {
				this->currentFrame.top = 384.f;
				this->currentFrame.left += 128.f;
				if (this->currentFrame.left > 384.f) {
					this->currentFrame.left = 0;
				}
				this->animationtimer.restart();
				sprite.setTextureRect(this->currentFrame);
			}
		}
		else
		{
			this->attack_anime = false;
			this->animestate = IDLE;
		}
	}
	if(this->fireball_attack_anime == true)
	{
		this->animationTime_ = clock.getElapsedTime();
		if (animationTime_ < animeDuration_fireball)
		{
			if (this->animationtimer.getElapsedTime().asMilliseconds() >= 50.f) {
				this->currentFrame.top = 640.f;
				this->currentFrame.left += 128.f;
				if (this->currentFrame.left > 896.f) {
					this->currentFrame.left = 0;
				}
				this->animationtimer.restart();
				sprite.setTextureRect(this->currentFrame);
			}
		}
		else
		{
			this->fireball_attack_anime = false;
			this->animestate = IDLE;
		}
		
	}
	//idle
	else if (this->animestate == IDLE) {
		if (this->animationtimer.getElapsedTime().asSeconds() >= 0.25f || this->getanimeswitch()) {
			this->currentFrame.top = 0.f;
			this->currentFrame.left += 128.f;
			if (this->currentFrame.left >= 768.f) {
				this->currentFrame.left = 0;
			}
			this->animationtimer.restart();
			sprite.setTextureRect(this->currentFrame);
		}
	}
	//run
	else if (this->animestate == MOVING_RIGHT) {
		if (this->animationtimer.getElapsedTime().asSeconds() >= 0.125f || this->getanimeswitch()) {
			this->currentFrame.top = 128.f;
			this->currentFrame.left += 128.f;
			if (this->currentFrame.left >= 896.f) {
				this->currentFrame.left = 0;
			}
			this->animationtimer.restart();
			sprite.setTextureRect(this->currentFrame);

		}
		direction = RIGHT;
		std::cout << "Going RIGHT\n";
		sprite.setScale(2.f, 2.f);
		sprite.setOrigin(0.f, 0.f);
	}
	else if (this->animestate == MOVING_LEFT) {
		if (this->animationtimer.getElapsedTime().asSeconds() >= 0.125f || this->getanimeswitch()) {
			this->currentFrame.top = 128.f;
			this->currentFrame.left += 128.f;
			if (this->currentFrame.left >= 896.f) {
				this->currentFrame.left = 0;
			}
			this->animationtimer.restart();
			sprite.setTextureRect(this->currentFrame);

		}
		std::cout << "Going LEFT\n";
		direction = LEFT;
		sprite.setScale(-2.f, 2.f);
		sprite.setOrigin(sprite.getGlobalBounds().width / 3.f, 0.f);
	}
	else {
		this->animationtimer.restart();
	}
}

void player::innitvariable()
{
	this->animestate = IDLE;
}

void player::resetanimetimer()
{
	this->animationtimer.restart();
	this->animationswitch = true;
}

void player::deathanime()
{
	if (!this->animestarted)
	{
		this->currentFrame.left = 0.f;
		this->animestarted = true;
	}

	if ((this->animationtimer.getElapsedTime().asSeconds() >= 0.5f || this->getanimeswitch()) && this->player_alive) {
		std::cout << "Player Death animation called\n";
		this->currentFrame.top = 512.f;
		this->currentFrame.left += 128.f;

		if (this->currentFrame.left >= 640.f) {
			this->player_alive = false;
			std::cout << "Player Animation finished\n";
		}

		this->animationtimer.restart();
		this->sprite.setTextureRect(this->currentFrame);
	}
}

const bool& player::getanimeswitch()
{
	bool animeswitch = this->animationswitch;

	if (this->animationswitch) {
		this->animationswitch = false;
	}

	return animeswitch;
}

const sf::FloatRect player::getglobalbounds() const
{
	return this->sprite.getGlobalBounds();
}

const sf::Vector2f player::getposition() const
{
	return this->sprite.getPosition();
}

void player::setPosition(const float x, const float y)
{
	this->sprite.setPosition(x, y);
}