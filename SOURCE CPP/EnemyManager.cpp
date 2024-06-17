#include "EnemyManager.h"

#include "skeleton.h"

void EnemyManager::innitenemies()
{
	float x = 0;
	for(int i = 0 ; i < 2 ; i++)
	{
		enemy_vector.emplace_back(new skeleton());
	}
	
}

void EnemyManager::add_enemy()
{
	enemy_vector.emplace_back(new skeleton());
}

void EnemyManager::check_collision(sf::RenderTarget& window)
{
	for (auto& enemy : this->enemy_vector)
	{
		if (enemy->sprite.getPosition().y + enemy->sprite.getGlobalBounds().height >= 960)
		{
			enemy->sprite.setPosition(enemy->sprite.getPosition().x, window.getSize().y - enemy->sprite.getGlobalBounds().height - 120);
		}
	}
}
	

void EnemyManager::remove_enemy()
{
	auto isEnemyDead = [](enemy* e) { return e == nullptr || !e->isalive; };

		enemy_vector.erase(std::remove_if(enemy_vector.begin(), enemy_vector.end(), isEnemyDead), enemy_vector.end());
}

void EnemyManager::update_enemy(player& p, hub& h)
{
	for (auto& enemy : this->enemy_vector)
	{
		if(enemy != nullptr)
		{
			if (!enemy->isalive)
			{
				remove_enemy();
				h.setscore(100);
				add_enemy();
			}

			if (enemy->isdying)
			{
				enemy->death_anime();
			}
			else
			{
				enemy->death_condition(h);
				enemy->move(p.sprite);
				enemy->animation(enemy->sprite, p, h);
				enemy->enemy_hp_update(p);
			}
		}
	}
}

void EnemyManager::render_enemy(sf::RenderTarget& window)
{
	for(auto& enemy : this->enemy_vector)
	{
		window.draw(enemy->sprite);

		sf::Vector2f healthBarPos = enemy->sprite.getPosition();
		if(enemy->direction_lr == RIGHT)
		{
			healthBarPos.x += 70.f;
		}else
		{
			healthBarPos.x += 30.f;
		}

		healthBarPos.y += 60.f; // Adjust as needed
		enemy->healthBar.setPosition(healthBarPos);
		enemy->healthBarBackground.setPosition(healthBarPos);

		window.draw(enemy->healthBarBackground);
		window.draw(enemy->healthBar);
	}
}

void EnemyManager::attack()
{
}

std::vector<enemy*> EnemyManager::get_enemies()
{
	return std::vector<enemy*>();
}

EnemyManager::EnemyManager()
{
	this->innitenemies();
}

EnemyManager::~EnemyManager()
{
}
