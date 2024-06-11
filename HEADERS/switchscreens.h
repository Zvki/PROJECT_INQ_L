#pragma once

#include "hub.h"
#include "iostream"

class switchscreens
{
public:

	static sf::Font ss_font;
	sf::Text ss_text[4];
	sf::Text bad_input;
	sf::Text scoreboard;
	static std::vector<sf::Text> scores;

	switchscreens();
	~switchscreens();

	void set_add_nickname();
	void set_you_died();
	void set_scoreboard(std::vector<player_score> ps_scores);

	void render_scoreboard(sf::RenderTarget& window);
	void render_add_nickname(sf::RenderTarget& window);
	void render_you_died(sf::RenderTarget& window);

};