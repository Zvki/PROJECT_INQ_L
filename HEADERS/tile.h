#pragma once

#include "SFML/Audio.hpp"
#include "SFML/Graphics.hpp"
#include "SFML/System.hpp"
#include "SFML/Window.hpp"
#include "SFML/Network.hpp"
#include <iostream>


class tile
{

private:

	bool collision = true;
	sf::Vector2f pos;
	sf::Texture texture;

public:

	std::vector<tile*> tiles;

	sf::Sprite sprite;
	tile();
	tile(std::string, float, float, bool);
	~tile();
	bool setupt(std::string);
	void settiles();
	void setground();

};