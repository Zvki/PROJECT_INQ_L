#include "skeleton.h"

void skeleton::srender(sf::RenderTarget& t)
{
	t.draw(this->sprite);
}

void skeleton::physics()
{
}

void skeleton::death(player& p, hub& h, anime& a)
{
	if (abs(p.sprite.getPosition().x - this->sprite.getPosition().x) < 120 && a.attack_anime)
	{
		h.setscore(100);
		this->sprite.setPosition(-400, 960);
	}
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
