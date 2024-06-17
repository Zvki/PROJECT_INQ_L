#include "playermanager.h"

playermanager::playermanager()
{
	this->innitplayer();
}

void playermanager::innitplayer()
{
	this->player_ = new player;
	this->player_->setPosition(760.f, 960.f);
}

void playermanager::check_player_colision(sf::RenderTarget& window)
{
	if (this->player_->getposition().y + this->player_->getglobalbounds().height >= window.getSize().y - 120) {
		this->player_->setCanJump(true);
		this->player_->resetvelocityY();
		this->player_->setPosition(this->player_->getposition().x, window.getSize().y - player_->getglobalbounds().height - 120);
	}

	if (this->player_->getposition().x < -80.f)
	{
		this->player_->setPosition(-80.f, this->player_->getposition().y);
	}

	if (this->player_->getposition().x > 1780.f)
	{
		this->player_->setPosition(1780.f, this->player_->getposition().y);
	}
}

void playermanager::update_player()
{

	if(player_->isdying)
	{
		player_->death_anime();
	}
	else
	{
		this->player_->updateruch();
		this->player_->updatemove();
		this->player_->animation();
	}
}

void playermanager::render_player(sf::RenderTarget& target)
{
	target.draw(this->player_->sprite);
}
