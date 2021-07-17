#include "CollidablePhysicsComponent.h"

#include "GameEngine/Util/CollisionManager.h"
#include "GameEngine/EntitySystem/Entity.h"
#include "Game/GameEntities/PlayerEntity.h"
#include "Game/GameEntities/LollipopEntity.h"
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


void CollidablePhysicsComponent::Update() //0 = nothing, 1 = lollipop, 2 = monster
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
			GameEngine::Entity* entity = colComponent->GetEntity();
			if (dynamic_cast<Game::LollipopEntity*>(entity)) { //try to turn whatever this is into a lollipop. If it fits -- it probably is one. 
				Game::PlayerEntity* playerEntity = dynamic_cast<Game::PlayerEntity*>(GetEntity());
				playerEntity->collectedLollipops++;
				//debug
				//std::cout << "we got one" << "\n";
			}


		}
	}
}