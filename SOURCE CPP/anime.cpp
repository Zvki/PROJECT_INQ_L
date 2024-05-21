#include "anime.h"
#include "SFML/Audio.hpp"
#include "SFML/Graphics.hpp"
#include "SFML/System.hpp"
#include "SFML/Window.hpp"
#include "SFML/Network.hpp"

anime::anime()
{
}

anime::~anime()
{
}

void anime::updateanime(player& pl)
{
	if (this->attack_anime == true) {
		this->animationTime_ = clock.getElapsedTime();
		if (animationTime_ < animeDuration)
		{
			if (this->animationtimer.getElapsedTime().asMilliseconds() >= 50.f) {
				this->currentFrame.top = 384.f;
				this->currentFrame.left += 128.f;
				if (this->currentFrame.left >= 384.f) {
					this->currentFrame.left = 0;
				}
				this->animationtimer.restart();
				pl.sprite.setTextureRect(this->currentFrame);
			}
		}
		else
		{
				this->attack_anime = false;
				this->animestate = IDLE;
		}
	}
	//idle
	else if (this->animestate == IDLE) {
		if (this->animationtimer.getElapsedTime().asSeconds() >= 0.25f || this->getanimeswitch()) {
			this->currentFrame.top = 0.f;
			this->currentFrame.left += 128.f;
			if (this->currentFrame.left >= 768.f) {
				this->currentFrame.left = 0;
			}
			this->animationtimer.restart();
			pl.sprite.setTextureRect(this->currentFrame);
		}
	}
	//run
	else if (this->animestate == MOVING_RIGHT) {
		if (this->animationtimer.getElapsedTime().asSeconds() >= 0.125f || this->getanimeswitch()) {
			this->currentFrame.top = 128.f;
			this->currentFrame.left += 128.f;
			if (this->currentFrame.left >= 896.f) {
				this->currentFrame.left = 0;
			}
			this->animationtimer.restart();
			pl.sprite.setTextureRect(this->currentFrame);

		}
		pl.sprite.setScale(2.f, 2.f);
		pl.sprite.setOrigin(0.f, 0.f);
	}
	else if (this->animestate == MOVING_LEFT) {
		if (this->animationtimer.getElapsedTime().asSeconds() >= 0.125f || this->getanimeswitch()) {
			this->currentFrame.top = 128.f;
			this->currentFrame.left += 128.f;
			if (this->currentFrame.left >= 896.f) {
				this->currentFrame.left = 0;
			}
			this->animationtimer.restart();
			pl.sprite.setTextureRect(this->currentFrame);

		}
		pl.sprite.setScale(-2.f, 2.f);
		pl.sprite.setOrigin(pl.sprite.getGlobalBounds().width / 2.25f, 0.f);
	}
	else {
		this->animationtimer.restart();
	}
}

void anime::innitvariable()
{
	this->animestate = IDLE;
}

const bool& anime::getanimeswitch()
{
	bool animeswitch = this->animationswitch;

	if (this->animationswitch) {
		this->animationswitch = false;
	}

	return animeswitch;
}

void anime::resetanimetimer()
{
	this->animationtimer.restart();
	this->animationswitch = true;
}