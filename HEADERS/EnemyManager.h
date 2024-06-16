#pragma once
#include <vector>
#include "enemy.h"

class EnemyManager
{
private:

	std::vector<enemy*> enemy_vector;

public:

	void innitenemies();
	void add_enemy();
	void check_collision(sf::RenderTarget& window);
	void remove_enemy();
	void update_enemy(player& p, hub& h);
	void render_enemy(sf::RenderTarget& window);
	void attack();

	std::vector<enemy*> get_enemies();

	EnemyManager();
	~EnemyManager();

};
