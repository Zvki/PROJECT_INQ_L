module tile;

#include <iostream>

tile::tile()
{
}

tile::tile(std::string tn, float x, float y, bool c)
{
	if (!setupt(tn)) {
		return;
	}
	this->pos = sf::Vector2f(x, y);
	this->sprite.setPosition(pos);
	this->collision = c;
}

tile::~tile()
{
}

bool tile::setupt(std::string tn)
{
	if (!this->texture.loadFromFile(tn)) {
		std::cout << "ERROR: COULD NOT FIND THE MAP TEXTURE \n";
		return false;
	}
	this->texture.setSmooth(true);
	this->sprite.setTexture(this->texture);
	sprite.setTextureRect(sf::IntRect(0, 0, 32, 32));
	this->sprite.setScale(1.f, 1.f);
	return true;
}

void tile::setfloor()
{
	int x = 0;
	for (int i = 0; i < 60; i++) {
		this->floor.push_back(new tile("texture/1 Tiles/Tile_10.png", x, 1024, true));
		x += 32;
	}

}

void tile::setground()
{

	int x = 0;
	for (int i = 0; i < 60; i++) {
		this->ground.push_back(new tile("texture/1 Tiles/Tile_04.png", x, 1056, true));
		x += 32;
	}

}