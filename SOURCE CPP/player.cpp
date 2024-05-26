#include "player.h"


void player::innitTexture()
{

	if(!this->texturesheet.loadFromFile("TEXTURE/FIRE_WIZARD/fire_wiz.png")){
		std::cout << "ERROR: COULD NOT FIND THE PLAYER IDLE TEXTURE \n";
	}

}

void player::innitSprite(anime& a)
{
	this->sprite.setTexture(this->texturesheet);
	a.currentFrame = sf::IntRect(0, 0, 128, 128);

	this->sprite.setTextureRect(sf::IntRect(a.currentFrame));
	this->sprite.setScale(2.f, 2.f);
}

void player::innitAnime(anime& a)
{
	a.animationtimer.restart();
	a.animationswitch = true;
}

void player::setCanJump(const bool canJump, physics& p)
{
	p.canjump = canJump;
}

player::player(anime& a, physics& p)
{
	a.innitvariable();
	this->innitTexture();
	this->innitSprite(a);
	this->innitAnime(a);
	p.innitruch();
}

player::~player()
{
}

void player::update(physics& p, anime& a)
{
	p.updatemove(*this, a);
	a.updateanime(*this);
	p.updateruch(*this);
}

void player::render(sf::RenderTarget& target)
{
	target.draw(this->sprite);
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