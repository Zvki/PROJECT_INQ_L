#pragma once

#include "SFML/Graphics.hpp"
#include <filesystem>

#include "player.h"


struct player_score
{
	std::string player_nickname;
	int score_points;
};


class hub {

private:

	size_t playerhp_;
	size_t score_;
	sf::Text scorebar_;
	sf::Text hpbar_;
	sf::Font font_;
	sf::Texture heart_texture;
	sf::Sprite heart_sprite_;

public:

	bool score_saved;
	bool nicknameset;

	static std::vector<player_score> leaderboard;

	sf::Text player_nickname_;
	std::string input_player_nickname;

	hub();
	~hub();

	void innithpbar();
	void innitscorebar();
	void innitplayernickname();
	void updatehpbar(player& player);
	void updatescorebar();
	void renderhpbar(sf::RenderTarget& target);
	void renderscorebar(sf::RenderTarget& target);
	void setscore(size_t addition);
	void savescore();
	void getscore();

	size_t getphp();
	sf::Font getfont();


};
