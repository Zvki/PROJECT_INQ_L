#pragma once

#include "SFML/Graphics.hpp"
#include <filesystem>


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

	bool nicknameset;
	sf::Text player_nickname_;
	std::string input_player_nickname;

	hub();
	~hub();

	void innithpbar();

	void innitscorebar();

	void innitplayernickname();

	void updatehpbar();

	void updatescorebar();

	void renderhpbar(sf::RenderTarget& target);

	void renderscorebar(sf::RenderTarget& target);

	void setscore(size_t addition);

	void savescore();

	size_t getphp();


};
