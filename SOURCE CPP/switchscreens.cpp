#include "switchscreens.h"

std::vector<sf::Text> switchscreens::scores;
sf::Font switchscreens::ss_font;

switchscreens::switchscreens()
{
	if (!this->ss_font.loadFromFile("TEXTURE/FONT/Pixellettersfull-BnJ5.ttf"))
	{
		std::cout << "Nie za³adowano czcionki \n";
	}
	this->set_add_nickname();
}

switchscreens::~switchscreens()
{

}

void switchscreens::set_add_nickname()
{
	this->ss_text[0].setFont(this->ss_font);
	this->ss_text[0].setCharacterSize(60);
	this->ss_text[0].setFillColor(sf::Color::White);
	this->ss_text[0].setString("Enter your nickname: ");
	this->ss_text[0].setPosition(1920 / 2 - ss_text[0].getGlobalBounds().width / 2, 1080 / 3);

	this->bad_input.setFont(this->ss_font);
	this->bad_input.setCharacterSize(30);
	this->bad_input.setFillColor(sf::Color::Red);
	this->bad_input.setString("Avaible signs are A-Z and 0-9");
	this->bad_input.setPosition(1920 / 2 - bad_input.getGlobalBounds().width / 2, 1080 / 3 * 2);
}

void switchscreens::set_you_died()
{
	this->ss_text[1].setFont(this->ss_font);
	this->ss_text[1].setCharacterSize(120);
	this->ss_text[1].setFillColor(sf::Color::Red);
	this->ss_text[1].setString("YOU DIED");
	this->ss_text[1].setPosition(1920 / 2 - ss_text[1].getGlobalBounds().width / 2, 1080 / 2 - ss_text[1].getGlobalBounds().height / 2);
}

void switchscreens::set_scoreboard(std::vector<player_score> ps_scores)
{
	std::cout << "set score active\n";

	int j = 5;

	if(ps_scores.size() < 5)
	{
		j = ps_scores.size();
	}

	sf::Text temporarytext;

	for(int i = 0 ; i < j; i++ )	
	{
		temporarytext.setFont(this->ss_font);
		temporarytext.setCharacterSize(40);
		temporarytext.setFillColor(sf::Color::White);
		temporarytext.setString(std::to_string(i + 1)+ ". " + ps_scores[i].player_nickname + " - " + std::to_string(ps_scores[i].score_points));
		temporarytext.setPosition(1920 / 2 - temporarytext.getGlobalBounds().width / 2, 1080 / 6 * (i + 1) );

		scores.push_back(temporarytext);
	}
}

void switchscreens::render_add_nickname(sf::RenderTarget& window)
{
	window.draw(this->ss_text[0]);
}

void switchscreens::render_you_died(sf::RenderTarget& window)
{
}


