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
	this->grav = 2.f;
}

skeleton::~skeleton()
{
}
