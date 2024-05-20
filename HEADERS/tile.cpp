#include "tile.h"

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
	sprite.setTextureRect(sf::IntRect(0, 0, 1920, 32));
	this->sprite.setScale(1.f, 1.f);
	return true;
}

void tile::settiles()
{
		//this->tiles.push_back(new tile("C:/Users/barto/OneDrive/Pulpit/Uni/PK4/PROJECT_INQ_L/TEXTURE/TILES/FLOOR.png", 0, 960, true));
		//this->tiles.push_back(new tile("C:/Users/barto/OneDrive/Pulpit/Uni/PK4/PROJECT_INQ_L/TEXTURE/TILES/GROUND.png", 0, 992, true));
		//this->tiles.push_back(new tile("C:/Users/barto/OneDrive/Pulpit/Uni/PK4/PROJECT_INQ_L/TEXTURE/TILES/GROUND.png", 0, 1024, true));
		//this->tiles.push_back(new tile("C:/Users/barto/OneDrive/Pulpit/Uni/PK4/PROJECT_INQ_L/TEXTURE/TILES/GROUND.png", 0, 1056, true));

		this->tiles.push_back(new tile("C:/Users/Bartosz Soœnica/source/repos/Zvki/PROJECT_INQ_L/TEXTURE/TILES/FLOOR.png", 0, 960, true));
		this->tiles.push_back(new tile("C:/Users/Bartosz Soœnica/source/repos/Zvki/PROJECT_INQ_L/TEXTURE/TILES/GROUND.png", 0, 992, true));
		this->tiles.push_back(new tile("C:/Users/Bartosz Soœnica/source/repos/Zvki/PROJECT_INQ_L/TEXTURE/TILES/GROUND.png", 0, 1024, true));
		this->tiles.push_back(new tile("C:/Users/Bartosz Soœnica/source/repos/Zvki/PROJECT_INQ_L/TEXTURE/TILES/GROUND.png", 0, 1056, true));
}