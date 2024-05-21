#include "skeleton.h"

#include "anime.h"

void skeleton::srender(sf::RenderTarget& t)
{
	t.draw(this->sprite);
}

void skeleton::physics()
{
}

skeleton::skeleton()
{
	this->innittexture(/*"C:/Users/barto/OneDrive/Pulpit/Uni/PK4/PROJECT_INQ_L/TEXTURE/SKELETON/SKELETON.png"*/
		"C:/Users/Bartosz Soœnica/source/repos/Zvki/PROJECT_INQ_L/TEXTURE/SKELETON/SKELETON.png");
	this->innitsprite();
	this->speed = 3.f;
	this->grav = 2.f;
}

skeleton::~skeleton()
{
}
