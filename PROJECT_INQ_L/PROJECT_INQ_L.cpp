#include "SFML/Audio.hpp"
#include "SFML/Graphics.hpp"
#include "SFML/System.hpp"
#include "SFML/Window.hpp"
#include "SFML/Network.hpp"
#include "game.h"
#include <iostream>
#include <thread>




int main() {

	game game;

	while (game.getWindow().isOpen()) {
		game.rendermenu();
		game.updatemenu();
	}

	return 0;
}