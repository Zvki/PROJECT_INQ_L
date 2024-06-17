#include "projectile.h"

projectile::projectile(sf::Sprite s)
{
	innittexture();
	innitsprite();
	this->sprite.setPosition(s.getPosition().x, 900);
}

void projectile::innittexture()
{
	if (!this->texturesheet.loadFromFile("TEXTURE/FIRE_WIZARD/Charge.png")) {
		std::cout << "ERROR: COULD NOT FIND THE PLAYER IDLE TEXTURE \n";
	}
}

void projectile::innitsprite()
{
	this->sprite.setTexture(this->texturesheet);
	currentframe = sf::IntRect(384, 0, 128, 128);

	this->sprite.setTextureRect(sf::IntRect(currentframe));
}

void projectile::death_anime()
{
}

void projectile::move(DIRECTION d)
{
	if(d == LEFT)
	{
		this->sprite.setScale(-1.f, 1.f);
	}else
	{
		this->sprite.setScale(1.f, 1.f);
	}
}
