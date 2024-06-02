#pragma once

#include "hub.h"

class switchscreens
{
public:

	sf::Font ss_font;
	sf::Text ss_text;

	switchscreens();
	~switchscreens();

	void set_add_nickname();
	void set_you_died();

	void render_add_nickname(sf::RenderTarget& window);
	void render_you_died(sf::RenderTarget& window);

};