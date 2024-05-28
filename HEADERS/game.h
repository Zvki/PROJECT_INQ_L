#pragma once

#include "player.h"
#include "physics.h"
#include "anime.h"
#include "tile.h"
#include "skeleton.h"
#include "hub.h"
#include "SFML/Audio.hpp"
#include "SFML/Graphics.hpp"
#include "SFML/System.hpp"
#include "SFML/Window.hpp"
#include "SFML/Network.hpp"


class game
{
private:

	//WINDOW SECTION
	sf::Event event;
	sf::Sprite background;
	sf::Texture backgroundtexture_;
	sf::Music music_;

	void innitw();
	void innitmusic();

	//PLAYER&ENTITY SECTION
	hub* Hub_;
	player* Player;
	physics* Physics;
	anime* Anime;
	skeleton* Skeleton_;

	void innitplayer();
	void innitenemy();

	//MAP SECTION
	tile* Tile;

	void innitbackg();
	void innittile();

	//MENU SECTION
	const int mnof_ = 3;
	int selecti_;
	sf::Texture menubg_texture_;
	sf::Sprite menubg_sprite_;
	sf::Font font_;
	sf::Text Menu_[3];

	void innitmenu_background();
	void innitmenu_font();
	void innitmenu();
	void innitplayernickname();

public:

	sf::RenderWindow window;

	game();
	virtual ~game();

	void innitall();

	void gamestart();
	void newgame();

	void setnickname();

	//UPDATE SECTION
	void updatecollision();
	void updateplayernickname();
	void updateplayer();
	void updateenemy();
	void updatemenu();
	void update();

	//RENDER SECTION
	void renderworld();
	void renderplayer();
	void renderenemy();
	void rendermenu();
	void render();

	const sf::RenderWindow& getWindow() const;

	//MENU SECTION
	void MoveUp();
	void MoveDown();
	int GetPressedItem() { return selecti_; }

};