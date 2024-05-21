#pragma once

#include "game.h"
#include "physics.h"
#include "anime.h"
#include <iostream>
#include <thread>


void game::innitw()
{
	this->window.create(sf::VideoMode(1920, 1080), "Inq", sf::Style::Close | sf::Style::Titlebar | sf::Style::Fullscreen);
	this->window.setFramerateLimit(60);
}

void game::innitplayer()
{
	this->Anime = new anime();
	this->Physics = new physics();
	this->Player = new player(*Anime, *Physics);
	this->Player->setPosition(760.f, 960.f);
}

void game::innitenemy()
{
	this->Skeleton_ = new skeleton();
	this->Skeleton_->sprite.setPosition(40.f, 930.f);
}

void game::innitbackg()
{
	if(!this->backgroundtexture_.loadFromFile("C:/Users/Bartosz Soœnica/source/repos/Zvki/PROJECT_INQ_L/TEXTURE/BACKGROUND/bg.jpg"))
	/*if (!this->backgroundtexture_.loadFromFile("C:/Users/barto/OneDrive/Pulpit/Uni/PK4/PROJECT_INQ_L/TEXTURE/background/1.png"))*/ {
		std::cout << "ERROR: COULD NOT FIND THE BACKGROUND TEXTURE \n";
	}
	this->background.setTexture(this->backgroundtexture_);
	this->background.setScale(1.f, 1.f);
	this->Tile = new tile();

	this->Hub_ = new hub();
}

void game::innittile()
{
	Tile->settiles();
}

void game::innitmenu_background()
{
	if (!this->menubg_texture_.loadFromFile("C:/Users/Bartosz Soœnica/source/repos/Zvki/PROJECT_INQ_L/TEXTURE/MENU/mbg.png_large")) {
		std::cout << "ERROR: COULD NOT FIND THE BACKGROUND TEXTURE \n";
	}
	this->menubg_sprite_.setTexture(this->menubg_texture_);
}

void game::innitmenu_font()
{
	if (!font_.loadFromFile("C:/Users/Bartosz Soœnica/source/repos/Zvki/PROJECT_INQ_L/TEXTURE/FONT/Pixellettersfull-BnJ5.ttf")) {
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
	
	this->Menu_[0].setFillColor(sf::Color::White);
	this->Menu_[0].setScale(2.f, 2.f);
	this->Menu_[0].setString("PLAY");
	this->Menu_[0].setPosition(sf::Vector2f(1920 / 2, 1080 / (this->mnof_ + 1) * 1));

	this->Menu_[1].setFont(this->font_);
	this->Menu_[1].setFillColor(sf::Color::White);
	this->Menu_[1].setScale(2.f, 2.f);
	this->Menu_[1].setString("OPTIONS");
	this->Menu_[1].setPosition(sf::Vector2f(1920 / 2, 1080 / (this->mnof_ + 1) * 2));

	this->Menu_[2].setFont(this->font_);
	this->Menu_[2].setFillColor(sf::Color::White);
	this->Menu_[2].setScale(2.f, 2.f);
	this->Menu_[2].setString("EXIT");
	this->Menu_[2].setPosition(sf::Vector2f(1920 / 2, 1080 / (this->mnof_ + 1) * 3));

}

void game::innitmusic()
{
	if(!this->music_.openFromFile("C:/Users/Bartosz Soœnica/source/repos/Zvki/PROJECT_INQ_L/TEXTURE/MUSIC/main-music.mp3"))
	{
		std::cout << "ERROR: COULD NOT FIND THE MUSIC\n";
	}
}

game::game()
{

	this->innitbackg();
	this->innitmenu();
	this->innitplayer();
	this->innitenemy();
	this->innittile();
	this->innitw();

	/*this->innitmusic();*/
}

game::~game()
{
	delete this->Player;
	delete this->Hub_;
	delete this->Anime;
	delete this->Skeleton_;
	delete this->Tile;
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

	if (this->Skeleton_->sprite.getPosition().y + this->Skeleton_->sprite.getGlobalBounds().height >= this->window.getSize().y - 120)
	{
		this->Skeleton_->sprite.setPosition(this->Skeleton_->sprite.getPosition().x, this->window.getSize().y - this->Skeleton_->sprite.getGlobalBounds().height - 120);
	}
}

void game::updateplayer()
{
	this->Player->update(*Physics, *Anime);
}

void game::updateenemy()
{
	this->Skeleton_->move(this->Player->sprite);
	this->Skeleton_->animeenemy(this->Skeleton_->sprite, this->Player->sprite);
}

void game::updatemenu()
{
	while (this->window.pollEvent(this->event)) {
		if (this->event.type == sf::Event::KeyReleased && this->event.key.code == sf::Keyboard::W) {
			this->MoveUp();
		}
		else if (this->event.type == sf::Event::KeyReleased && this->event.key.code == sf::Keyboard::S) {
			this->MoveDown();
		}
		else if (this->event.type == sf::Event::KeyReleased && this->event.key.code == sf::Keyboard::Enter) {
			switch (this->GetPressedItem()) {
			case 0: {
				while (this->getWindow().isOpen()) {
					this->update();
					this->render();
				}
				break;
			}
			case 1: {
				break;
			}
			case 2: {
				this->window.close();
				break;
			}
			}
		}
	}
}

void game::update()
{
	while (this->window.pollEvent(this->event))
	{
		if (this->event.type == sf::Event::Closed) {
			this->window.close();
		}
		else if (this->event.type == sf::Event::KeyPressed && this->event.key.code == sf::Keyboard::Escape) {
			this->window.close();
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
			if(this->event.key.code == sf::Keyboard::H)
			{
				if(!this->Anime->attack_anime)
				{
					this->Anime->attack_anime = true;
					this->Anime->clock.restart();
				}
			}
		}
	}

	this->updateenemy();
	this->updateplayer();
	this->updatecollision();
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

void game::renderenemy()
{
	this->Skeleton_->srender(this->window);
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

	this->renderenemy();

	this->renderplayer();

	this->window.display();

}

const sf::RenderWindow& game::getWindow() const
{
	return this->window;
}

void game::MoveUp()
{
	if (this->selecti_ - 1 >= 0)
	{
		this->Menu_[this->selecti_].setFillColor(sf::Color::White);
		this->selecti_--;
		this->Menu_[this->selecti_].setFillColor(sf::Color::Red);
	}
}

void game::MoveDown()
{
	if (this->selecti_ + 1 < this->mnof_)
	{
		this->Menu_[this->selecti_].setFillColor(sf::Color::White);
		this->selecti_++;
		this->Menu_[this->selecti_].setFillColor(sf::Color::Red);
	}
}
