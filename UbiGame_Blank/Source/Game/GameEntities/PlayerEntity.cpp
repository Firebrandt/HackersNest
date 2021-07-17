#include "PlayerEntity.h"


#include "GameEngine/EntitySystem/Components/CollidablePhysicsComponent.h"
#include "GameEngine/EntitySystem/Components/ParticleEmitterComponent.h"

using namespace Game;

PlayerEntity::PlayerEntity()
{
	//Movement
	m_playerMovementComponent = AddComponent<PlayerMovementComponent>();

	//Render 
	m_renderComponent = AddComponent<GameEngine::SpriteRenderComponent>();
	m_renderComponent->SetTexture(GameEngine::eTexture::Player);
	m_renderComponent->SetZLevel(2);

	//Collisions
	AddComponent<GameEngine::CollidablePhysicsComponent>();

}


PlayerEntity::~PlayerEntity()
{

}


void PlayerEntity::OnAddToWorld()
{
	Entity::OnAddToWorld();

}


void PlayerEntity::OnRemoveFromWorld()
{
	Entity::OnRemoveFromWorld();
}
