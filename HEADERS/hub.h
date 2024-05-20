#pragma once

#include "SFML/Graphics.hpp" 


class hub {

private:

	size_t playerhp_;
	sf::Text hpbar_;
	sf::Font font_;
	sf::Texture heart_texture;
	sf::Sprite heart_sprite_;

public:

	hub();
	~hub();

	void innithpbar();

	void updatehpbar();

	void renderhpbar(sf::RenderTarget& target);

	size_t getphp();

};
