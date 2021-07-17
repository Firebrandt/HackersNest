#include "Game/GameEntities/LollipopEntity.h"



#include "GameEngine/EntitySystem/Components/CollidablePhysicsComponent.h"

using namespace Game;

LollipopEntity::LollipopEntity()
{

	//Render 
	m_renderComponent = AddComponent<GameEngine::SpriteRenderComponent>();
	m_renderComponent->SetTexture(GameEngine::eTexture::Lollipop);
	m_renderComponent->SetZLevel(1);

	//Collisions
	AddComponent<GameEngine::CollidablePhysicsComponent>();

}


LollipopEntity::~LollipopEntity()
{

}


void LollipopEntity::OnAddToWorld()
{
	Entity::OnAddToWorld();

}


void LollipopEntity::OnRemoveFromWorld()
{
	Entity::OnRemoveFromWorld();
}
