#pragma once

#include "game.h"
#include "physics.h"
#include "anime.h"
#include <iostream>
#include <thread>


void game::innitw()
{
	this->window.create(sf::VideoMode(1920, 1080), "Inq", sf::Style::Close | sf::Style::Titlebar);
	this->window.setFramerateLimit(60);
}

void game::innitplayer()
{
	this->Anime = new anime();
	this->Physics = new physics();
	this->Player = new player(*Anime, *Physics);
	this->Player->setPosition(760.f, 960.f);
}

void game::innitbackg()
{
	if(!this->backgroundtexture_.loadFromFile("TEXTURE/BACKGROUND/bg.jpg")){
		std::cout << "ERROR: COULD NOT FIND THE BACKGROUND TEXTURE \n";
	}
	this->background.setTexture(this->backgroundtexture_);
	this->background.setScale(1.f, 1.f);
	this->Tile = new tile();

	this->Hub_ = new hub();
	this->SS = new switchscreens();
}

void game::innittile()
{
	Tile->settiles();
}

void game::innitmenu_background()
{
	if (!this->menubg_texture_.loadFromFile("TEXTURE/MENU/mbg.png_large")) {
		std::cout << "ERROR: COULD NOT FIND THE BACKGROUND TEXTURE \n";
	}
	this->menubg_sprite_.setTexture(this->menubg_texture_);
}

void game::innitmenu_font()
{
	if (!font_.loadFromFile("TEXTURE/FONT/Pixellettersfull-BnJ5.ttf")) {
		//ERROR
	}
	this->Menu_[0].setFont(this->font_);
}

void game::innitmenu()
{
	std::thread menu_background(&game::innitmenu_background, this);
	std::thread menu_font(&game::innitmenu_font, this);

	menu_background.join();
	menu_font.join();

	this->allowed_ = "[A-Za-z0-9]+";

	this->Menu_[0].setFillColor(sf::Color::White);
	this->Menu_[0].setCharacterSize(60);
	this->Menu_[0].setString("PLAY");
	this->Menu_[0].setPosition(sf::Vector2f(1920 / 2 - this->Menu_[0].getGlobalBounds().width / 2, 1080 / (this->mnof_ + 1) * 1));

	this->Menu_[1].setFont(this->font_);
	this->Menu_[1].setFillColor(sf::Color::White);
	this->Menu_[1].setCharacterSize(60);
	this->Menu_[1].setString("SCOREBOARD");
	this->Menu_[1].setPosition(sf::Vector2f(1920 / 2 - this->Menu_[1].getGlobalBounds().width / 2, 1080 / (this->mnof_ + 1) * 2));

	this->Menu_[2].setFont(this->font_);
	this->Menu_[2].setFillColor(sf::Color::White);
	this->Menu_[2].setCharacterSize(60);
	this->Menu_[2].setString("EXIT");
	this->Menu_[2].setPosition(sf::Vector2f(1920/2 - this->Menu_[2].getGlobalBounds().width/2, 1080 / (this->mnof_ + 1) * 3));

	this->Menu_RES[0].setFont(this->font_);
	this->Menu_RES[0].setFillColor(sf::Color::White);
	this->Menu_RES[0].setCharacterSize(60);
	this->Menu_RES[0].setString("RESUME");
	this->Menu_RES[0].setPosition(sf::Vector2f(1920 / 2 - this->Menu_RES[0].getGlobalBounds().width / 2, 1080 / (this->mnof_ + 1) * 1));

	this->Menu_RES[1].setFont(this->font_);
	this->Menu_RES[1].setFillColor(sf::Color::White);
	this->Menu_RES[1].setCharacterSize(60);
	this->Menu_RES[1].setString("EXIT TO MENU");
	this->Menu_RES[1].setPosition(sf::Vector2f(1920 / 2 - this->Menu_RES[1].getGlobalBounds().width / 2, 1080 / (this->mnof_ + 1) * 2));
}

void game::innitmusic()
{
	if(!this->music_.openFromFile("TEXTURE/MUSIC/main-music.mp3"))
	{
		std::cout << "ERROR: COULD NOT FIND THE MUSIC\n";
	}
}

game::game()
{
	this->innitmenu();
	this->innitw();

	/*this->innitmusic();*/
}

game::~game()
{
}

void game::gamestart()
{
	while(this->window.isOpen())
	{
		if (this->Hub_->nicknameset == true)
		{
			this->update();
		}
		else
		{
			if (!this->Hub_->score_saved == true)
			{
				this->Hub_->savescore();
			}
			this->SS->set_you_died();
			this->you_died();
		}
	}
}

void game::you_died()
{
	while(this->window.isOpen())
	{

		while (this->window.pollEvent(this->event))
		{
			if (event.type == sf::Event::KeyReleased && this->event.key.code == sf::Keyboard::Enter)
			{
				while (this->window.isOpen())
				{
					this->updatemenu();
				}
			}
		}

		this->window.clear();
		this->window.draw(this->SS->ss_text[1]);
		this->window.display();
	}
}

void game::newgame()
{
	this->enemy_manager_ = new EnemyManager;
	this->innitbackg();
	this->innitplayer();
	this->innittile();
}

void game::updatecollision()
{
	//Collision bottom
	//if (this->Player->sprite.getGlobalBounds().intersects(this->Tile->tiles[0]->sprite.getGlobalBounds())) {
	if (this->Player->getposition().y + this->Player->getglobalbounds().height >= this->window.getSize().y - 120) {
		this->Player->setCanJump(true, *Physics);
		this->Physics->resetvelocityY();
		this->Player->setPosition(this->Player->getposition().x, this->window.getSize().y - this->Player->getglobalbounds().height - 120);
	}

	if(this->Player->getposition().x < -80.f)
	{
		this->Player->setPosition(-80.f, this->Player->getposition().y);
	}

	if (this->Player->getposition().x > 1780.f)
	{
		this->Player->setPosition(1780.f, this->Player->getposition().y);
	}

}

void game::updateplayernickname()
{
	while (this->getWindow().isOpen()) {

		while (this->window.pollEvent(this->event))
		{
			if (event.type == sf::Event::TextEntered)
			{
				if (event.text.unicode < 128)
				{
					if (event.text.unicode == '\b')
					{
						if (!this->Hub_->input_player_nickname.empty())
						{
							this->Hub_->input_player_nickname.pop_back();
						}
					}
					else
					{
						this->Hub_->input_player_nickname += static_cast<char>(event.text.unicode);
					}
					this->Hub_->player_nickname_.setString(this->Hub_->input_player_nickname);
				}
			}
			if (this->event.type == sf::Event::KeyPressed && this->event.key.code == sf::Keyboard::Enter &&
				std::regex_match(this->Hub_->input_player_nickname, this->allowed_))
			{
				this->Hub_->nicknameset = true;
				this->Hub_->score_saved = false;
				while (this->window.isOpen())
				{
					this->gamestart();
				}
				break;
			}
		}
		this->render_playernickname();
	}
}

void game::updateplayer()
{
	this->Player->update(*Physics, *Anime);
}

void game::updateenemy()
{
	this->enemy_manager_->update_enemy(*Player, *Hub_, *Anime);
	this->enemy_manager_->check_collision(this->window);
}

int game::updatemenu()
{
	while (this->window.pollEvent(this->event)) {
		if (this->event.type == sf::Event::KeyReleased && this->event.key.code == sf::Keyboard::W) {
			this->MoveUp(Menu_);
		}
		else if (this->event.type == sf::Event::KeyReleased && this->event.key.code == sf::Keyboard::S) {
			this->MoveDown(Menu_, mnof_ );
		}
		else if (this->event.type == sf::Event::KeyReleased && this->event.key.code == sf::Keyboard::Enter) {
			switch (this->GetPressedItem()) {
			case 0: {
				delete enemy_manager_;
				this->newgame();
					this->updateplayernickname();
				break;
			}
			case 1: {
					this->Hub_->getscore();
					this->SS->set_scoreboard(this->Hub_->leaderboard);
					while(this->window.isOpen())
					{
						this->update_scoreboard();
					}
				break;
			}
			case 2: {
				this->window.close();
				return 0;
			}
			}
		}
	}
	this->rendermenu();
}

void game::update()
{
		while (this->window.pollEvent(this->event))
		{
			if (this->event.type == sf::Event::Closed) {
				this->window.close();
			}
			else if (this->event.type == sf::Event::KeyPressed && this->event.key.code == sf::Keyboard::Escape) {
				this->resume_cnt = true;
				while (this->window.isOpen())
				{
					if(resume_cnt)
					{
						this->updateresmenu();
					}else
					{
						break;
					}
				}
			}
			else if (this->event.type == sf::Event::KeyReleased &&
				(this->event.key.code == sf::Keyboard::W ||
					this->event.key.code == sf::Keyboard::S ||
					this->event.key.code == sf::Keyboard::A ||
					this->event.key.code == sf::Keyboard::D)) {
				this->Anime->resetanimetimer();
			}
			else if (this->event.type == sf::Event::KeyPressed)
			{
				if (this->event.key.code == sf::Keyboard::H)
				{
					this->Anime->setcurrentframe();
					if (!this->Anime->attack_anime && this->Anime->attack_clock.getElapsedTime() >= this->Anime->attack_cooldown)
					{
						this->Anime->attack_anime = true;
						this->Anime->clock.restart();
						this->Anime->attack_clock.restart();
					}
				}
			}
		}


		if (this->Hub_->getphp() == 0)
		{
			this->Hub_->nicknameset = false;
		}

		this->render();
		this->updateenemy();
		this->updateplayer();
		this->updatecollision();
}

void game::update_scoreboard()
{
	while (this->window.isOpen())
	{
		while (this->window.pollEvent(this->event))
		{
			if (event.type == sf::Event::KeyReleased && this->event.key.code == sf::Keyboard::Enter)
			{
				while (this->window.isOpen())
				{
					this->updatemenu();
				}
			}
		}
		this->renderscore();
	}
}

void game::updateresmenu()
{
		while (this->window.pollEvent(this->event)) {
			if (this->event.type == sf::Event::KeyReleased && this->event.key.code == sf::Keyboard::W) {
				this->MoveUp(Menu_RES);
			}
			else if (this->event.type == sf::Event::KeyReleased && this->event.key.code == sf::Keyboard::S) {
				this->MoveDown(Menu_RES, mnor_);
			}
			else if (this->event.type == sf::Event::KeyReleased && this->event.key.code == sf::Keyboard::Enter) {
				switch (this->GetPressedItem()) {
				case 0: {
					this->resume_cnt = false;
					return;
				}
				case 1: {
					while (this->window.isOpen())
					{
						this->updatemenu();
					}
					break;
				}
				}
			}
		}
		this->renderresmenu();
}

void game::renderworld()
{
	this->window.draw(this->background);
	this->window.draw(this->Tile->tiles[0]->sprite);
	this->window.draw(this->Tile->tiles[1]->sprite);
	this->window.draw(this->Tile->tiles[2]->sprite);
	this->window.draw(this->Tile->tiles[3]->sprite);

	this->Hub_->renderhpbar(this->window);
	this->Hub_->renderscorebar(this->window);
}

void game::renderplayer()
{
	this->Player->render(this->window);
}

void game::render_playernickname()
{
	this->window.clear();
	this->Hub_->player_nickname_.setPosition(1920 / 2 - this->Hub_->player_nickname_.getGlobalBounds().width/2, 1080 / 2);
	this->window.draw(this->SS->bad_input);
	this->window.draw(this->SS->ss_text[0]);
	this->window.draw(this->Hub_->player_nickname_);
	this->window.display();
}

void game::rendermenu()
{
	this->window.clear();

	this->window.draw(this->menubg_sprite_);

	for (int i = 0; i < this->mnof_; i++) {
		this->window.draw(this->Menu_[i]);
	}
	this->window.display();
}

void game::render()
{

	this->window.clear();

	this->renderworld();

	this->enemy_manager_->render_enemy(this->window);

	this->renderplayer();

	this->window.display();

}

const sf::RenderWindow& game::getWindow() const
{
	return this->window;
}

void game::renderresmenu()
{

	this->window.clear();

	this->window.draw(this->menubg_sprite_);

	this->window.draw(this->Menu_RES[0]);

	this->window.draw(this->Menu_RES[1]);

	this->window.display();
}

void game::MoveUp(sf::Text menu[])
{
	if (this->selecti_ - 1 >= 0)
	{
		menu[this->selecti_].setFillColor(sf::Color::White);
		this->selecti_--;
		menu[this->selecti_].setFillColor(sf::Color::Red);
	}
}

void game::MoveDown(sf::Text menu[], int mno)
{
	if (this->selecti_ + 1 < mno)
	{
		menu[this->selecti_].setFillColor(sf::Color::White);
		this->selecti_++;
		menu[this->selecti_].setFillColor(sf::Color::Red);
	}
}

void game::renderscore()
{
	window.clear();
	for (int i = 0; i < 5; i++)
	{
		std::cout << "render score active\n";
		window.draw(this->SS->scores[i]);
	}
	window.display();
}
