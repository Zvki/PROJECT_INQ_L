#include "player.h"


void player::innittexture()
{

	if(!this->texturesheet.loadFromFile("TEXTURE/FIRE_WIZARD/fire_wiz.png")){
		std::cout << "ERROR: COULD NOT FIND THE PLAYER IDLE TEXTURE \n";
	}

}

void player::innitsprite()
{
	this->sprite.setTexture(this->texturesheet);
	currentframe = sf::IntRect(0, 0, 128, 128);

	this->sprite.setTextureRect(sf::IntRect(currentframe));
	this->sprite.setScale(2.f, 2.f);
}

void player::innitAnime()
{
	animetimer.restart();
	animeswitch = true;
}

void player::setCanJump(const bool canJump)
{
	canjump = canJump;
}

player::player()
{
	this->projectile_manager_ = new projectilemanager();
	innitvariable();
	this->innittexture();
	this->innitsprite();
	this->innitAnime();
	innitruch();
}

player::~player()
{
}

void player::innitruch()
{
	this->velocitymax = 10.f;
	this->velocitymin = 0.5f;
	this->velocitymaxy = 15.f;
	this->accel = 1.05f;
	this->drag = 0.9f;
	this->grav = 2.f;
	this->canjump = false;
}

void player::resetvelocityY()
{
	this->velocity.y = 0.f;
}

void player::resetvelocityX()
{
	this->velocity.x = 0.f;
}

void player::ruch(const float dir_x, const float dir_y)
{
	//Acceleration

	this->velocity.x += dir_x * this->accel;


	//Limit Accel

	if (std::abs(this->velocity.x) > this->velocitymax) {
		this->velocity.x = this->velocitymax * ((this->velocity.x < 0.f) ? -1.f : 1.f);
	}
}

void player::jump()
{
	std::cout << "Jump executed\n";
	this->velocity.y = -200.f;
	this->canjump = false;
}

void player::updateruch()
{
	std::cout << "updateruch executed\n";
	//Grav
	this->velocity.y += 0.3 * this->grav;

	//Limit Grav
	if (std::abs(this->velocity.y) > this->velocitymaxy) {
		this->velocity.y = this->velocitymaxy * ((this->velocity.y < 0.f) ? -1.f : 1.f);
	}

	//Drag
	this->velocity *= this->drag;

	//Limit drag
	if (std::abs(this->velocity.x) < this->velocitymin) {
		this->velocity.x = 0.f;
	}
	if (std::abs(this->velocity.y) < this->velocitymin) {
		this->velocity.y = 0.f;
	}

	sprite.move(this->velocity);
}

void player::updatemove()
{
	animestate = IDLE;
	//LEWO
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::A)) {
		this->ruch(-1.f, 0.f);
		animestate = MOVING_LEFT;
	}
	//PRAWO
	else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::D)) {
		this->ruch(1.f, 0.f);
		animestate = MOVING_RIGHT;
	}
	//SKOK
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::W) && canjump) {
		std::cout << "Jump condition met\n";
		this->jump();
	}
}

void player::setcurrentframe()
{
	this->currentframe.left = 0;
}

void player::animation()
{
	//BASIC ATTACK
	if (this->attack_anime == true) {
		this->animationTime_ = clock.getElapsedTime();
		if (animationTime_ < animeDuration)
		{
			if (this->animetimer.getElapsedTime().asMilliseconds() >= 50.f) {
				this->currentframe.top = 384.f;
				this->currentframe.left += 128.f;
				if (this->currentframe.left > 384.f) {
					this->currentframe.left = 0;
				}
				this->animetimer.restart();
				sprite.setTextureRect(this->currentframe);
			}
		}
		else
		{
			this->attack_anime = false;
			this->animestate = IDLE;
		}
	}
	if(this->fireball_attack_anime == true)
	{
		this->animationTime_ = clock.getElapsedTime();
		if (animationTime_ < animeDuration_fireball)
		{
			if (this->animetimer.getElapsedTime().asMilliseconds() >= 50.f) {
				this->currentframe.top = 640.f;
				this->currentframe.left += 128.f;
				if (this->currentframe.left > 896.f) {
					this->currentframe.left = 0;
				}
				this->animetimer.restart();
				sprite.setTextureRect(this->currentframe);
			}
		}
		else
		{
			projectile_manager_->innit_fireball(*this);
			this->fireball_attack_anime = false;
			this->animestate = IDLE;
		}
		
	}
	//idle
	else if (this->animestate == IDLE) {
		if (this->animetimer.getElapsedTime().asSeconds() >= 0.25f || this->getanimeswitch()) {
			this->currentframe.top = 0.f;
			this->currentframe.left += 128.f;
			if (this->currentframe.left >= 768.f) {
				this->currentframe.left = 0;
			}
			this->animetimer.restart();
			sprite.setTextureRect(this->currentframe);
		}
	}
	//run
	else if (this->animestate == MOVING_RIGHT) {
		if (this->animetimer.getElapsedTime().asSeconds() >= 0.125f || this->getanimeswitch()) {
			this->currentframe.top = 128.f;
			this->currentframe.left += 128.f;
			if (this->currentframe.left >= 896.f) {
				this->currentframe.left = 0;
			}
			this->animetimer.restart();
			sprite.setTextureRect(this->currentframe);

		}
		direction_lr = RIGHT;
		std::cout << "Going RIGHT\n";
		sprite.setScale(2.f, 2.f);
		sprite.setOrigin(0.f, 0.f);
	}
	else if (this->animestate == MOVING_LEFT) {
		if (this->animetimer.getElapsedTime().asSeconds() >= 0.125f || this->getanimeswitch()) {
			this->currentframe.top = 128.f;
			this->currentframe.left += 128.f;
			if (this->currentframe.left >= 896.f) {
				this->currentframe.left = 0;
			}
			this->animetimer.restart();
			sprite.setTextureRect(this->currentframe);

		}
		std::cout << "Going LEFT\n";
		direction_lr = LEFT;
		sprite.setScale(-2.f, 2.f);
		sprite.setOrigin(sprite.getGlobalBounds().width / 3.f, 0.f);
	}
	else {
		this->animetimer.restart();
	}
}

void player::innitvariable()
{
	this->animestate = IDLE;
}

void player::resetanimetimer()
{
	this->animetimer.restart();
	this->animeswitch = true;
}

void player::death_anime()
{
	if (!this->animestarted)
	{
		this->currentframe.left = 0.f;
		this->animestarted = true;
	}

	if ((this->animetimer.getElapsedTime().asSeconds() >= 0.5f || this->getanimeswitch()) && this->isalive) {
		std::cout << "Player Death animation called\n";
		this->currentframe.top = 512.f;
		this->currentframe.left += 128.f;

		if (this->currentframe.left >= 640.f) {
			this->isalive = false;
			std::cout << "Player Animation finished\n";
		}

		this->animetimer.restart();
		this->sprite.setTextureRect(this->currentframe);
	}
}

const bool& player::getanimeswitch()
{
	bool animeswitch = this->animeswitch;

	if (this->animeswitch) {
		this->animeswitch = false;
	}

	return animeswitch;
}

const sf::FloatRect player::getglobalbounds() const
{
	return this->sprite.getGlobalBounds();
}

const sf::Vector2f player::getposition() const
{
	return this->sprite.getPosition();
}

void player::setPosition(const float x, const float y)
{
	this->sprite.setPosition(x, y);
}

//Projectile

projectile::projectile(player& p)
{
	innittexture();
	innitsprite();
	this->sprite.setPosition(p.sprite.getPosition().x, 830);
	if (p.direction_lr == LEFT)
	{
		this->direction_lr = LEFT;
		this->sprite.setScale(-1.f, 1.f);
	}
	else
	{
		this->direction_lr = RIGHT;
		this->sprite.setScale(1.f, 1.f);
		this->sprite.setOrigin(- sprite.getGlobalBounds().width * 2.f, 0.f);
	}
}

bool projectile::getanimeswitch()
{
	bool animeswitch = this->animeswitch;

	if (this->animeswitch) {
		this->animeswitch = false;
	}

	return animeswitch;
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
	currentframe = sf::IntRect(192, 0, 64, 64);

	this->sprite.setTextureRect(sf::IntRect(currentframe));
}

void projectile::death_anime()
{
	if (!this->animestarted)
	{
		this->currentframe.left = 320.f;
		this->animestarted = true;
	}

	if ((this->animetimer.getElapsedTime().asSeconds() >= 0.125f || this->getanimeswitch()) && this->isalive) {
		std::cout << "Death animation called\n";
		this->currentframe.top = 0.f;
		this->currentframe.left += 64.f;

		if (this->currentframe.left >= 768.f) {
			this->isalive = false;
			std::cout << "Animation finished\n";
		}

		this->animetimer.restart();
		this->sprite.setTextureRect(this->currentframe);
	}
}

void projectile::move()
{
	if (direction_lr == LEFT)
	{
		this->sprite.setPosition(sprite.getPosition().x - 10.f, sprite.getPosition().y);
	}
	else
	{
		this->sprite.setPosition(sprite.getPosition().x + 10.f, sprite.getPosition().y);
	}
}

void projectile::animation()
{

	if ((this->animetimer.getElapsedTime().asSeconds() >= 0.125f || this->getanimeswitch()) && this->animestarted_flying) {
		std::cout << "Death animation called\n";
		this->currentframe.top = 0.f;
		this->currentframe.left += 64.f;

		if (this->currentframe.left >= 256.f) {
			this->animestarted_flying = false;
			std::cout << "Animation finished\n";
		}

		this->animetimer.restart();
		this->sprite.setTextureRect(this->currentframe);
	}
}

//Projectile manager

projectilemanager::projectilemanager()
{

}

void projectilemanager::update_projectile(player& p)
{
	for (auto& fireball : projectile_)
	{
		if (fireball != nullptr)
		{
			if(!fireball->isalive)
			{
				remove_projectile();
			}

			if(fireball->isdying)
			{
				fireball->death_anime();
			}
			else
			{
				fireball->move();
				fireball->animation();
			}
		}
	}

}

void projectilemanager::innit_fireball(player& p)
{
	projectile_.emplace_back(new projectile(p));
}

void projectilemanager::render_fireball(sf::RenderTarget& window)
{
	for (auto& fireball : projectile_)
	{
		if (fireball != nullptr)
		{
			window.draw(fireball->sprite);
		}
	}
}

void projectilemanager::remove_projectile()
{
	auto isProjectileDead = [](projectile* e) { return e == nullptr || !e->isalive; };

	projectile_.erase(std::remove_if(projectile_.begin(), projectile_.end(), isProjectileDead), projectile_.end());
}

