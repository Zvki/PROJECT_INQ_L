#include "EnemyManager.h"

#include "skeleton.h"

void EnemyManager::innitenemies()
{
	for(int i = 0 ; i < 4 ; i++)
		enemy_vector.emplace_back(new skeleton());
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
}

void EnemyManager::update_enemy()
{
	for (auto& enemy : this->enemy_vector)
	{
		enemy->move(this->Player->sprite);
		//enemy->death(*Player, *Hub_, *Anime);
		enemy->animeenemy(this->Skeleton_->sprite, this->Player->sprite);
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
