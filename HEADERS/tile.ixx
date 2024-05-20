export module tile;

#include "SFML/Audio.hpp"
#include "SFML/Graphics.hpp"
#include "SFML/System.hpp"
#include "SFML/Window.hpp"
#include "SFML/Network.hpp"
#include <iostream>

export class tile {
	private:

		bool collision = true;
		sf::Vector2f pos;
		sf::Texture texture;

	public:

		std::vector<tile*> ground;
		std::vector<tile*> floor;

		sf::Sprite sprite;
		tile();
		tile(std::string, float, float, bool);
		~tile();
		bool setupt(std::string);
		void setfloor();
		void setground();
};