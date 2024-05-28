#include "SFML/Graphics.hpp"
#include "game.h"


int main() {

	game game;

	while (game.getWindow().isOpen()) {
		game.updatemenu();
	}

	return 0;
}