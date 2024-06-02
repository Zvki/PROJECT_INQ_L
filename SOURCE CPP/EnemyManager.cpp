#include "EnemyManager.h"

#include "skeleton.h"

void EnemyManager::innitenemies()
{
	float x = 0;
	for(int i = 0 ; i < 4 ; i++)
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
		if (enemy->sprite.getPosition().y + enemy->sprite.getGlobalBounds().height >= window.getSize().y - 120)
		{
			enemy->sprite.setPosition(enemy->sprite.getPosition().x, window.getSize().y - enemy->sprite.getGlobalBounds().height - 120);
		}
	}
}
	

void EnemyManager::remove_enemy()
{
	auto isEnemyDead = [](enemy* e) { return e == nullptr || !e->isAlive; };

		enemy_vector.erase(std::remove_if(enemy_vector.begin(), enemy_vector.end(), isEnemyDead), enemy_vector.end());
}

void EnemyManager::update_enemy(player& p, hub& h, anime& a)
{
	for (auto& enemy : this->enemy_vector)
	{
		if(enemy != nullptr)
		{
			enemy->move(p.sprite);
			enemy->animeenemy(enemy->sprite, p.sprite, h);
			enemy->enemy_hp_update(p, a);
			if (enemy->death_condition(p, h, a))
			{
				remove_enemy();
				add_enemy();
			}
		}
	}
}

void EnemyManager::render_enemy(sf::RenderTarget& window)
{
	for(auto& enemy : this->enemy_vector)
	{
		window.draw(enemy->sprite);
	}
}

std::vector<enemy*> EnemyManager::get_enemies()
{
	return std::vector<enemy*>();
}

EnemyManager::EnemyManager()
{
	this->innitenemies();
}
