#include "CollidablePhysicsComponent.h"

#include "GameEngine/Util/CollisionManager.h"
#include "GameEngine/EntitySystem/Entity.h"
#include "Game/GameEntities/PlayerEntity.h"
#include "Game/GameEntities/LollipopEntity.h"
#include "Game/GameEntities/MonsterEntity.h"
#include <iostream>
#include <vector>

using namespace GameEngine;

CollidablePhysicsComponent::CollidablePhysicsComponent()
{

}


CollidablePhysicsComponent::~CollidablePhysicsComponent()
{

}


void CollidablePhysicsComponent::OnAddToWorld()
{
	CollidableComponent::OnAddToWorld();
}


void CollidablePhysicsComponent::OnRemoveFromWorld()
{
	CollidableComponent::OnRemoveFromWorld();
}


void CollidablePhysicsComponent::Update() 
{
	//For the time being just a simple intersection check 
	std::vector<CollidableComponent*>& collidables = CollisionManager::GetInstance()->GetCollidables();

	for (int a = 0; a < collidables.size(); ++a)
	{
		CollidableComponent* colComponent = collidables[a];
		if (colComponent == this)
			continue;

		AABBRect intersection;
		AABBRect myBox = GetWorldAABB();
		AABBRect colideBox = colComponent->GetWorldAABB();
		//colcomponent = what we're (possibly) hitting
		if (myBox.intersects(colideBox, intersection))
		{
			sf::Vector2f pos = GetEntity()->GetPos();
			//inform the player entity that a collision has happened.
			GameEngine::Entity* collidedEntity = colComponent->GetEntity();

			if (dynamic_cast<Game::PlayerEntity*>(GetEntity())) {
				Game::PlayerEntity* playerEntity = dynamic_cast<Game::PlayerEntity*>(GetEntity());
				if (dynamic_cast<Game::LollipopEntity*>(collidedEntity)) { //try to turn whatever this is into a lollipop. If it fits -- it probably is one. 
					Game::LollipopEntity* thisLollipop = dynamic_cast<Game::LollipopEntity*>(collidedEntity);
					if (thisLollipop->lollipop_alive == true) {
						playerEntity->collectedLollipops++;
						thisLollipop->lollipop_alive = false;
						std::cout << "we got one" << "\n";
					}
				}
				else if (dynamic_cast<Game::MonsterEntity*>(collidedEntity)) {
					playerEntity->alive = false;
				}
			}
		}
	}
}