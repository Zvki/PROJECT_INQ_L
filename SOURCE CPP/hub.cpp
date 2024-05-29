#include "hub.h"
#include "skeleton.h"

#include <filesystem>
#include <iostream>
#include <fstream>



hub::hub()
{
	if (!this->font_.loadFromFile("TEXTURE/FONT/Pixellettersfull-BnJ5.ttf"))
	{
		//ERROR
	}
	this->score_ = 0;
	this->playerhp_ = 100;
	this->player_nickname_.setString("");
	innithpbar();
	innitscorebar();
	innitplayernickname();
}

hub::~hub()
{
}

void hub::innithpbar()
{
	if (!this->heart_texture.loadFromFile("TEXTURE/MENU/Transperent/Icon12.png"))
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

void hub::innitplayernickname()
{
	this->player_nickname_.setFont(this->font_);
	this->player_nickname_.setCharacterSize(24);
	this->player_nickname_.setFillColor(sf::Color::White);
	this->player_nickname_.setPosition(1920/2, 1080/2);
}

void hub::updatehpbar()
{
		this->playerhp_ -= 10;
		this->hpbar_.setString(std::to_string(this->playerhp_));
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

void hub::setscore(size_t addition)
{
	this->score_ += addition;
	this->scorebar_.setString("SCORE: " + std::to_string(this->score_));
}

void hub::savescore()
{	
	std::filesystem::path score_path("SCORE/" + input_player_nickname + ".txt");

	if (this->score_ > 0)
	{
		// Sprawdzanie, czy katalog SCORE istnieje
		if (!std::filesystem::exists(score_path))
		{
			// Próba utworzenia katalogu SCORE
			if (!std::filesystem::create_directory(score_path))
			{
				std::cerr << "Nie mo¿na utworzyæ katalogu SCORE!" << std::endl;
				return;
			}
		}
		else if (!std::filesystem::is_directory(score_path))
		{
			std::cerr << "Œcie¿ka SCORE nie jest katalogiem!" << std::endl;
			return;
		}

		// Otwarcie pliku w trybie dodawania
		std::ofstream score_txt(score_path);
		if (score_txt)
		{
			score_txt << std::to_string(this->score_) << "\n";
		}
		else
		{
			std::cerr << "Nie mo¿na otworzyæ pliku " << score_path << "!" << std::endl;
		}
	}
}


size_t hub::getphp()
{
	return playerhp_;
}
