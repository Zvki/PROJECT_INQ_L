#pragma once

#include "SFML/Graphics.hpp" 


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

	hub();
	~hub();

	void innithpbar();

	void innitscorebar();

	void updatehpbar();

	void updatescorebar();

	void renderhpbar(sf::RenderTarget& target);

	void renderscorebar(sf::RenderTarget& target);

	size_t getphp();

};
