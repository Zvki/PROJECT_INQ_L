#include "enemy.h"
#include "player.h"

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

void enemy::death_condition(hub& h)
{
		if ((this->enemy_hp > 150 || enemy_hp <= 0) && !isdying)
		{
			std::cout << "Enemy is dying\n";
			isdying = true;
		}
}

void enemy::enemy_hp_update(player& p)
{
	if(p.direction_lr != direction_lr && std::abs(p.sprite.getPosition().x - this->sprite.getPosition().x) < 150 && p.getattackanime())
	{
		this->enemy_hp -= 4;

		float healthPercentage = static_cast<float>(this->enemy_hp) / 100.0f; 
		this->healthBar.setSize(sf::Vector2f(50.f * healthPercentage, 5.f));
	}
}

void enemy::makealive()
{
	this->isalive= true;
}

int enemy::set_position_x()
{

	std::random_device rd;
	std::mt19937 gen(rd());

	std::uniform_int_distribution<> range_choice(0, 1);

	std::uniform_int_distribution<> distrib1(-100, 0);

	std::uniform_int_distribution<> distrib2(2100, 2200);

	int choice = range_choice(gen);

	int random_number;
	if (choice == 0) {
		return distrib1(gen);
	}
	else if(choice == 1)
	{
		return distrib2(gen);
	}
}

void enemy::death_anime()
{
	if(!this->animestarted)
	{
		this->currentframe.left = 0.f;
		this->animestarted = true;
	}

	if ((this->animetimer.getElapsedTime().asSeconds() >= 0.25f || this->getanimeswitch()) && this->isalive) {
		std::cout << "Death animation called\n";
		this->currentframe.top = 384.f;
		this->currentframe.left += 128.f;

		if (this->currentframe.left >= 384.f) {
			this->isalive = false;
			std::cout << "Animation finished\n";
		}

		this->animetimer.restart();
		this->sprite.setTextureRect(this->currentframe);
	}
}

void enemy::animation(sf::Sprite s, player& p, hub & h)
{
		//ATTACK
		if (this->lenght <= 80 && !p.isdying )
		{
			if (this->animetimer.getElapsedTime().asSeconds() >= 0.15f || this->getanimeswitch()) {
				this->currentframe.top = 256.f;
				this->currentframe.left += 128.f;
				if (this->currentframe.left >= 384.f && this->currentframe.left < 512.f)
				{
					h.updatehpbar(p);
				}
				if (this->currentframe.left >= 896.f) {
					this->currentframe.left = 0;
				}

				this->animetimer.restart();
				this->sprite.setTextureRect(this->currentframe);
			}
		}
		//MOVING RIGHT
		else if (p.sprite.getPosition().x > s.getPosition().x && this->lenght > 80 && !p.isdying)
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
			direction_lr = RIGHT;
			this->sprite.setScale(1.5f, 1.5f);
			this->sprite.setOrigin(s.getGlobalBounds().width * 0.05f, 0.f);
		}
		//MOVING LEFT
		else if (p.sprite.getPosition().x < s.getPosition().x && this->lenght > 80 && !p.isdying)
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
			direction_lr = LEFT;
			this->sprite.setScale(-1.5f, 1.5f);
			this->sprite.setOrigin(s.getGlobalBounds().width / 1.75f, 0.f);
		}else if(p.isdying)
		{
			if (this->animetimer.getElapsedTime().asSeconds() >= 0.125f || this->getanimeswitch()) {
				this->currentframe.top = 0.f;
				this->currentframe.left += 128.f;
				if (this->currentframe.left >= 896.f) {
					this->currentframe.left = 0;
				}
				this->animetimer.restart();
				this->sprite.setTextureRect(this->currentframe);
			}
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

	this->healthBar.setSize(sf::Vector2f(50.f, 5.f)); 
	this->healthBar.setFillColor(sf::Color::Green);

	this->healthBarBackground.setSize(sf::Vector2f(50.f, 5.f));
	this->healthBarBackground.setFillColor(sf::Color::Red);
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

void enemy::draw_hp_bar(sf::RenderWindow& window)
{
	sf::Vector2f healthBarPos = this->sprite.getPosition();
	healthBarPos.x += 200.f;
	healthBarPos.y -= 10.f; // Adjust as neededsw
	this->healthBar.setPosition(healthBarPos);
	this->healthBarBackground.setPosition(healthBarPos);

	window.draw(this->healthBarBackground);
	window.draw(this->healthBar);
}
