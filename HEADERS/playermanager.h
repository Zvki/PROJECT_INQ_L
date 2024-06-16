#pragma once
#include "player.h"

class playermanager
{
public:

	player* player_;

	bool resume_cnt;

	playermanager();

	void innitplayer();
	void check_player_colision(sf::RenderTarget& window);
	void update_player();
	void update_player_interactions(sf::Window& window, sf::Event& event);
	void render_player(sf::RenderTarget& target);

};