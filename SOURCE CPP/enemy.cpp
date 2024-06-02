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

bool enemy::death_condition(player& p, hub& h, anime& a)
{
		if (this->enemy_hp == 0)
		{
			h.setscore(100);
			this->isAlive = false;
			return true;
		}
		else
		{
			return false;
		}
}

void enemy::enemy_hp_update(player& p, anime& a)
{
	if(std::abs(p.sprite.getPosition().x - this->sprite.getPosition().x) < 150 && a.attack_anime)
	{
		this->enemy_hp -= 20;
	}
}

void enemy::makealive()
{
	this->isAlive = true;
}

int enemy::set_position_x()
{

	std::random_device rd;
	std::mt19937 gen(rd());

	// Definiowanie dystrybucji dla wyboru zakresu (0 lub 1)
	std::uniform_int_distribution<> range_choice(0, 1);

	// Definiowanie dystrybucji dla zakresu -100 do 100
	std::uniform_int_distribution<> distrib1(-100, 100);

	// Definiowanie dystrybucji dla zakresu 2000 do 2100
	std::uniform_int_distribution<> distrib2(2000, 2100);

	// Wybór zakresu
	int choice = range_choice(gen);

	// Generowanie liczby losowej w wybranym zakresie
	int random_number;
	if (choice == 0) {
		return distrib1(gen);
	}
	else if(choice == 1)
	{
		return distrib2(gen);
	}
}

void enemy::animeenemy(sf::Sprite s, sf::Sprite p, hub& h)
{
	//ATTACK
	if(this->lenght <= 80)
	{
		if (this->animetimer.getElapsedTime().asSeconds() >= 0.25f || this->getanimeswitch()) {
			this->currentframe.top = 256.f;
			this->currentframe.left += 128.f;
			if (this->currentframe.left >= 384.f && this->currentframe.left <= 512.f)
			{
				h.updatehpbar();
			}
			if (this->currentframe.left >= 896.f) {
				this->currentframe.left = 0;
			}

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
