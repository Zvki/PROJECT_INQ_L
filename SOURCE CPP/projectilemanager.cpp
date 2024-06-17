//#include "projectilemanager.h"
//
//projectilemanager::projectilemanager()
//{
//	
//}
//
//void projectilemanager::update_projectile(player& p)
//{
//	for(auto& fireball : projectile_)
//	{
//		if (fireball != nullptr)
//		{
//			fireball->move(p);
//		}
//	}
//
//}
//
//void projectilemanager::innit_fireball(player& p)
//{
//	projectile_.emplace_back(new projectile(p));
//}
//
//void projectilemanager::render_fireball(sf::RenderTarget& window)
//{
//	for (auto& fireball : projectile_)
//	{
//		if (fireball != nullptr)
//		{
//			window.draw(fireball->sprite);
//		}
//	}
//}
