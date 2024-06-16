#include "skeleton.h"

void skeleton::srender(sf::RenderTarget& t)
{
	t.draw(this->sprite);
}

void skeleton::physics()
{
}

skeleton::skeleton()
{
	this->innittexture("TEXTURE/SKELETON/SKELETON.png");
	this->innitsprite();
	this->speed = 3.f;
	this->enemy_hp = 100;
	this->makealive();
	this->sprite.setPosition(this->set_position_x(), 960);
}

skeleton::~skeleton()
{
}
