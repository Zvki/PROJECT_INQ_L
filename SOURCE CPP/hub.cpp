#include "hub.h"

hub::hub()
{
	//COMP PATH
	if (!this->font_.loadFromFile("C:/Users/Bartosz Soœnica/source/repos/Zvki/PROJECT_INQ_L/TEXTURE/FONT/Pixellettersfull-BnJ5.ttf"))
		//LAPTOP PATH
	/*if(!this->font_.loadFromFile("C:/Users/barto/OneDrive/Pulpit/Uni/PK4/PROJECT_INQ_L/TEXTURE/FONT/Pixellettersfull-BnJ5.ttf"))*/
	{
		//ERROR
	}
	this->score_ = 0;
	this->playerhp_ = 100;
	innithpbar();
	innitscorebar();
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

	this->heart_sprite_.setTexture(this->heart_texture);
	this->heart_sprite_.setPosition(80, 60);
	this->heart_sprite_.setScale(2.f, 2.f);

	this->hpbar_.setFont(this->font_);
	this->hpbar_.setScale(2.f, 2.f);
	this->hpbar_.setFillColor(sf::Color::White);
	this->hpbar_.setString(std::to_string(this->playerhp_));
	this->hpbar_.setPosition(140, 50);
}

void hub::innitscorebar()
{
	this->scorebar_.setFont(this->font_);
	this->scorebar_.setScale(2.f, 2.f);
	this->scorebar_.setFillColor(sf::Color::White);
	this->scorebar_.setString("SCORE: " + std::to_string(this->score_));
	this->scorebar_.setPosition(1600, 50);
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
	target.draw(this->scorebar_);
}

size_t hub::getphp()
{
	return playerhp_;
}
