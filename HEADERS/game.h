#pragma once

#include "playermanager.h"
#include "tile.h"
#include "hub.h"
#include "Entity.h"
#include "regex"
#include "switchscreens.h"
#include "EnemyManager.h"
#include "projectilemanager.h"

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
	sf::Music music_[2];

	std::regex allowed_;

	void innitw();
	void innitmusic();

	//PLAYER&ENTITY SECTION
	switchscreens* SS;
	hub* Hub_;
	EnemyManager* enemy_manager_;
	playermanager* player_manager_;

	void innitplayer();

	//MAP SECTION
	tile* Tile;

	void innitbackg();
	void innittile();

	//MENU SECTION
	const int mnof_ = 3;
	const int mnor_ = 2;
	int selecti_ = 0;
	bool music_state = false;
	bool resume_cnt;
	sf::Texture menubg_texture_;
	sf::Sprite menubg_sprite_;
	sf::Font font_;
	sf::Text Menu_[3];
	sf::Text Menu_RES[2];

	void innitmenu_background();
	void innitmenu_font();
	void innitmenu();
	void render_playernickname();

public:

	sf::RenderWindow window;

	game();
	virtual ~game();

	void gamestart();
	void you_died();
	void newgame();

	//UPDATE SECTION
	void updatecollision();
	void updateplayernickname();
	void updateplayer();
	void updateenemy();
	int updatemenu();
	void updateresmenu();
	void update_scoreboard();
	void update();

	//RENDER SECTION
	void renderworld();
	void renderplayer();
	void renderenemy();
	void rendermenu();
	void renderresmenu();
	void renderscore();
	void render();

	const sf::RenderWindow& getWindow() const;

	//MENU SECTION
	void playmusic(int i);
	void stopmusic(int i);
	void MoveUp(sf::Text menu[]);
	void MoveDown(sf::Text menu[], int mno);
	int GetPressedItem() { return selecti_; }

};