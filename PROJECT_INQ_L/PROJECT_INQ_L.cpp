#include "SFML/Graphics.hpp"
#include "game.h"


int main() {

	game game;

	while (game.getWindow().isOpen()) {
		game.rendermenu();
		game.updatemenu();
	}

	return 0;
}