#include "hub.h"

hub::hub()
{
	this->playerhp_ = 100;
	innithpbar();
}

hub::~hub()
{
}

void hub::innithpbar()
{
		//COMP PATH
	if (!this->heart_texture.loadFromFile("C:/Users/Bartosz Soœnica/source/repos/Zvki/PROJECT_INQ_L/TEXTURE/MENU/Transperent/Icon12.png"))
		//LAPTOP PATH 
	/*if(!this->heart_texture.loadFromFile("C:/Users/barto/OneDrive/Pulpit/Uni/PK4/PROJECT_INQ_L/TEXTURE/MENU/Transperent/Icon12.png"))*/
	{
		//ERROR
	}
		//COMP PATH
	if (!this->font_.loadFromFile("C:/Users/Bartosz Soœnica/source/repos/Zvki/PROJECT_INQ_L/TEXTURE/FONT/Pixellettersfull-BnJ5.ttf"))
		//LAPTOP PATH
	/*if(!this->font_.loadFromFile("C:/Users/barto/OneDrive/Pulpit/Uni/PK4/PROJECT_INQ_L/TEXTURE/FONT/Pixellettersfull-BnJ5.ttf"))*/
	{
		//ERROR
	}

	this->heart_sprite_.setTexture(this->heart_texture);
	this->heart_sprite_.setPosition(40, 60);
	this->heart_sprite_.setScale(2.f, 2.f);

	this->hpbar_.setFont(this->font_);
	this->hpbar_.setScale(2.f, 2.f);
	this->hpbar_.setFillColor(sf::Color::White);
	this->hpbar_.setString(std::to_string(this->playerhp_));
	this->hpbar_.setPosition(100, 50);
}

void hub::innitscorebar()
{
}



void hub::updatehpbar()
{
}

void hub::updatescorebar()
{
}

void hub::renderhpbar(sf::RenderTarget& target)
{
	target.draw(this->hpbar_);
	target.draw(this->heart_sprite_);
}

void hub::renderscorebar(sf::RenderTarget& target)
{
}

size_t hub::getphp()
{
	return playerhp_;
}
