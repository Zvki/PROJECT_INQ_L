#include "enemy.h"

void enemy::move(sf::Sprite s)
{
	this->direction.x = s.getPosition().x - this->sprite.getPosition().x;
	this->direction.y = 960.f;
	this->lenght = sqrt(this->direction.x * this->direction.x);

	if (lenght != 0)
	{
		direction /= lenght;
	}

	if(this->lenght >= 80)
	{
		this->sprite.move(this->direction * this->speed);
	}
}

void enemy::death(player& p, hub& h, anime& a)
{

	if (abs(p.sprite.getPosition().x - this->sprite.getPosition().x) < 120 && a.attack_anime)
	{
		h.setscore(100);
		this->sprite.setPosition(-400, 960);
	}

}

void enemy::animeenemy(sf::Sprite s, sf::Sprite p)
{
	//ATTACK
	if(this->lenght <= 80)
	{
		this->attack_cond = false;
		if (this->animetimer.getElapsedTime().asSeconds() >= 0.25f || this->getanimeswitch()) {
			this->currentframe.top = 256.f;
			this->currentframe.left += 128.f;
			if (this->currentframe.left >= 896.f) {
				this->currentframe.left = 0;
			}
			this->attack_cond = true;
			this->animetimer.restart();
			this->sprite.setTextureRect(this->currentframe);
		}
	}
	//MOVING RIGHT
	else if(p.getPosition().x > s.getPosition().x && this->lenght > 80)
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
	else if(p.getPosition().x < s.getPosition().x && this->lenght > 80)
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
