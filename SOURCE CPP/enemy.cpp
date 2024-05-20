#include "enemy.h"

void enemy::move(sf::Sprite s)
{
	this->direction.x = s.getPosition().x - this->sprite.getPosition().x;
	this->direction.y = s.getPosition().y - this->sprite.getPosition().y + 500;
	this->lenght = std::sqrt(direction.x * direction.x + direction.y * direction.y);
	if (lenght != 0)
	{
		direction /= lenght;
	}

	if(this->lenght >= 500)
	{
		this->sprite.move(this->direction * this->speed);
	}
}

void enemy::anime(sf::Sprite s, sf::Sprite p)
{
	//IDLE
	if(this->lenght <= 500)
	{
		if (this->animetimer.getElapsedTime().asSeconds() >= 0.25f || this->getanimeswitch()) {
			this->currentframe.top = 0.f;
			this->currentframe.left += 128.f;
			if (this->currentframe.left >= 896.f) {
				this->currentframe.left = 0;
			}
			this->animetimer.restart();
			this->sprite.setTextureRect(this->currentframe);
		}
	}
	//MOVING RIGHT
	else if(p.getPosition().x > s.getPosition().x && this->lenght > 500)
	{
		if (this->animetimer.getElapsedTime().asSeconds() >= 0.125f || this->getanimeswitch()) {
			this->currentframe.top = 128.f;
			this->currentframe.left += 128.f;
			if (this->currentframe.left >= 896.f) {
				this->currentframe.left = 0;
			}
			this->animetimer.restart();
			this->sprite.setTextureRect(this->currentframe);
		}
		this->sprite.setScale(1.5f, 1.5f);
		this->sprite.setOrigin(0.f, 0.f);
	}
	//MOVING LEFT
	else if(p.getPosition().x < s.getPosition().x && this->lenght > 500)
	{
		if (this->animetimer.getElapsedTime().asSeconds() >= 0.125f || this->getanimeswitch()) {
			this->currentframe.top = 128.f;
			this->currentframe.left += 128.f;
			if (this->currentframe.left >= 896.f) {
				this->currentframe.left = 0;
			}
			this->animetimer.restart();
			this->sprite.setTextureRect(this->currentframe);
		}
		this->sprite.setScale(-1.5f, 1.5f);
		this->sprite.setOrigin(s.getGlobalBounds().width / 2.f, 0.f);
	}
}

void enemy::innittexture(std::string s)
{
	if(!this->texturesheet.loadFromFile(s))
	{
		std::cout << "Could not find enemy texture" << "\n";
	}
}

void enemy::innitsprite()
{
	this->sprite.setTexture(this->texturesheet);
	this->currentframe = sf::IntRect(0, 0, 128, 128);
	this->sprite.setTextureRect(sf::IntRect(this->currentframe));
	this->sprite.setScale(1.5f,1.5f);
}

enemy::~enemy()
{
}

void enemy::resetanimetimer()
{
		this->animetimer.restart();
		this->animeswitch = true;
}

bool enemy::getanimeswitch()
{
	bool animeswitch = this->animeswitch;

	if (this->animeswitch) {
		this->animeswitch = false;
	}

	return animeswitch;
}