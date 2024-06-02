#include "switchscreens.h"

switchscreens::switchscreens()
{
	if (!this->ss_font.loadFromFile("TEXTURE/FONT/Pixellettersfull-BnJ5.ttf"))
	{
		//ERROR
	}
	this->set_add_nickname();
}

switchscreens::~switchscreens()
{

}

void switchscreens::set_add_nickname()
{
	this->ss_text.setFont(this->ss_font);
	this->ss_text.setCharacterSize(60);
	this->ss_text.setFillColor(sf::Color::White);
	this->ss_text.setString("Enter your nickname: ");
	this->ss_text.setPosition(1920 / 2 - 200, 1080 / 3);
}

void switchscreens::set_you_died()
{
	this->ss_text.setFont(this->ss_font);
	this->ss_text.setCharacterSize(120);
	this->ss_text.setFillColor(sf::Color::Red);
	this->ss_text.setString("YOU DIED");
	this->ss_text.setPosition(1920 / 2 - 60, 1080 / 2);
}

void switchscreens::render_add_nickname(sf::RenderTarget& window)
{
	window.draw(this->ss_text);
}

void switchscreens::render_you_died(sf::RenderTarget& window)
{
}
